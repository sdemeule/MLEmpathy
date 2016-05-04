/* ******************************* */
/* Chris Doucette, Stephen Demeule */
/* Machine Learning    4/27/16     */
/* Final Project: ReviewParser.cpp */
/* ******************************* */

#include "ReviewParser.hpp"

/* #include <windows.h> "No such file or directory" */
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include <dirent.h>
#include <algorithm>
#include <dirent.h>

using namespace std;

/**
 * Main Function from which
 * everything is executed.
 */
int main( int argc, char* argv[] ){

        struct dirent *pDirent;
        DIR *pDir;
        string Doc;
        string Source;
        string name;
        string res;
        int i;
        ofstream Results;
        Results.open ("Results.csv");

        Results<< "File,Output\n";

        if (argc < 2) {
            printf ("Usage: testprog <dirname>\n");
            return 1;
        }
        pDir = opendir (argv[1]);
        if (pDir == NULL) {
            printf ("Cannot open directory '%s'\n", argv[1]);
            return 1;
        }
        Source = argv[1];
        while ((pDirent = readdir(pDir)) != NULL) {
            Doc = Source + "\\" + pDirent->d_name;
            res = Read_Review(Doc);
            name = pDirent->d_name;
            i = name.find(".");
            name =name.substr( 0, i);
            Results<< name + "," + res + "\n";
        }
        closedir (pDir);
        Results.close();

        return 0;
}

/**
* Read_Review scans text given for key words
* or phrases that are checked case by case for
* an increment or decrement in value of an
* overall score.
* @param string Rev -- path of file to read from.
* @return int score -- resulting score from adding each line's individual scores.
*/

string Read_Review(string Rev){
	string line;
	int score = 0;

	ifstream Review; //opens file at filepath matching string Rev
	 Review.open(Rev.c_str());
    if( Review.is_open() == false ) cout<< "ERROR FILE FAILED TO OPEN" << endl;
    while( getline (Review, line)){
		score += Line_Value(line);
    }
	Review.close();
	if(Review.is_open() == false) cout<< "File Closed"<< endl;
	return Report(score);
}

/**
* Line_Value function checks words given from
* the line against case statements for each
* expected key word. This results in incrementing
* or decrementing the LV (line value) integer value.
* @param string Line -- the given line to evaluate.
* @return LV -- the resulting numerical line value.
*/
int Line_Value( string Line ){
	string word;
	string rest;
	int next;
	int space = 1; //initializing to 1 to avoid inital while loop failure
	int LV = 0; //score of the line
	int OPPOSITE_CASE = 0; //Simple int to check if last word gives next word opposite context.

	while( space != -1 ){
		space = Line.find(" ");
		if( space == -1 ){
			//cout << "Words found on line: " << wordcount << endl;
			return LV;
		}
		word = Line.substr( 0, space);
		word = Lower(word);
		Cleaner(word);
		next = space + 1;
		rest = Line.substr( next );
		Line = rest;
		/*
			SPECIAL CASES:
			for words such as "not", "without", "doesn't", etc ...
			we have a flag, OPPOSITE_CASE, to indicate that the next
			word should be considered for the opposite of is normal
			value. Also, consecutive OPPOSITE_CASEs cancel out due
			to it being a double negative.
		*/

			if( word == "bored" ){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if( word == "boredom" ){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if( word == "boring" ){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if( word == "bore" ){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if( word == "dislike" ){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if( word == "disliked" ){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if( word == "dull" ){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if( word == "sloppiness" ){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if( word == "sloppy" ){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if( word == "slop" ){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if( word == "bad" ){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if( word == "worst"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "disappointed"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word =="sucks"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "faked"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

            }
			else if(word == "stupid"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "trash"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "trashed"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "negative"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "dislike"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "awful"){
                if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

            }
			else if(word == "hate"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "dated"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "lacks"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "awful"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "amature"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "amatureish"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "waste"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "good"){
				if(OPPOSITE_CASE == 0){
					LV = LV + 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV - 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "recommend"){
				if(OPPOSITE_CASE == 0){
					LV = LV + 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV - 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "recommended"){
				if(OPPOSITE_CASE == 0){
					LV = LV + 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV - 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "success"){
				if(OPPOSITE_CASE == 0){
					LV = LV + 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV - 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "great"){
				if(OPPOSITE_CASE == 0){
					LV = LV + 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV - 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "excellent"){
				if(OPPOSITE_CASE == 0){
					LV = LV + 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV - 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "priceless"){
				if(OPPOSITE_CASE == 0){
					LV = LV + 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV - 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "wonderful"){
				if(OPPOSITE_CASE == 0){
					LV = LV + 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV - 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "wonderous"){
				if(OPPOSITE_CASE == 0){
					LV = LV + 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV - 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "wonderously"){
				if(OPPOSITE_CASE == 0){
					LV = LV + 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV - 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "gorgeous"){
				if(OPPOSITE_CASE == 0){
					LV = LV + 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV - 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "finest"){
				if(OPPOSITE_CASE == 0){
					LV = LV + 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV - 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "brilliant"){
				if(OPPOSITE_CASE == 0){
					LV = LV + 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV - 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "stunning"){
				if(OPPOSITE_CASE == 0){
					LV = LV + 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV - 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "magnificent"){
				if(OPPOSITE_CASE == 0){
					LV = LV + 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV - 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "successfully"){
				if(OPPOSITE_CASE == 0){
					LV = LV + 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV - 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "successful"){
				if(OPPOSITE_CASE == 0){
					LV = LV + 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV - 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "better"){
				if(OPPOSITE_CASE == 0){
					LV = LV + 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV - 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "beauty"){
				if(OPPOSITE_CASE == 0){
					LV = LV + 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV - 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "beautiful"){
				if(OPPOSITE_CASE == 0){
					LV = LV + 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV - 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "best"){
				if(OPPOSITE_CASE == 0){
					LV = LV + 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV - 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "fail"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "failure"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "fails"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "failed"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "failing"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

            }
            else if(word == "absurd"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

            }
            else if(word == "unfortunately"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

            }
            else if(word == "unbearably"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

            }
			else if(word == "unbearable"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

            }
            else if(word == "pretentious"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

            }
            else if(word == "embarrassing"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

            }
            else if(word == "timid"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

            }
            else if(word == "clueless"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

            }
            else if(word == "weak"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

            }
            else if(word == "outdated"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

            }
            else if(word == "painful"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

            }
            else if(word == "unpalatable"){
				if(OPPOSITE_CASE == 0){
					LV = LV - 1;
				}else if(OPPOSITE_CASE == 1){
					LV = LV + 1;
					OPPOSITE_CASE = 0;
				}

            }
			else if(word == "not"){
				if(OPPOSITE_CASE == 0){
					OPPOSITE_CASE = 1;
				}else if(OPPOSITE_CASE == 1){
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "without"){
				if(OPPOSITE_CASE == 0){
					OPPOSITE_CASE = 1;
				}else if(OPPOSITE_CASE == 1){
					OPPOSITE_CASE = 0;
				}

			}
			else if(word == "doesn't"){
				if(OPPOSITE_CASE == 0){
					OPPOSITE_CASE = 1;
				}else if(OPPOSITE_CASE == 1){
					OPPOSITE_CASE = 0;
				}

			}
			else{
				LV = LV; /*Do nothing*/
				OPPOSITE_CASE = 0;
			}

		}
		return LV;

	}

/**
* Report function checks the numerical score
* obtained from previous text parsing and
* determines POSITIVE for scores above zero,
* and NEGATIVE for scores below zero.
* @param int value -- given overall score of review
*/
string Report( int value){

	if (value <= 0){ //NEGATIVE REVIEW
		return "0";

	}
	if (value > 0 ){ //POSITIVE REVIEW
		return "1";
	}
	return "2";
}

/**
* Changes characters from uppercase to lowercase.
* Used for easy matching of keywords, which are all
* lowercase.
* @param string W -- given string to chance chars to lowercase.
* @return string W -- altered, lowercase version of given string.
*/
string Lower( string W){
	transform(W.begin(), W.end(), W.begin(), ::tolower);

	return W;
}

string Cleaner(string Wor){
    string editor1;
    string editor2;
    int holder;

    holder = Wor.find(".");
    if(holder != -1){
        editor1 = Wor.substr( 0, holder);
		holder ++;
		editor2 = Wor.substr( holder );
		Wor = editor1 + editor2;
		Cleaner(Wor);
    }
    holder = Wor.find("!");
    if(holder != -1){
        editor1 = Wor.substr( 0, holder);
		holder ++;
		editor2 = Wor.substr( holder );
		Wor = editor1 + editor2;
		Cleaner(Wor);
    }
    holder = Wor.find("?");
    if(holder != -1){
        editor1 = Wor.substr( 0, holder);
		holder ++;
		editor2 = Wor.substr( holder );
		Wor = editor1 + editor2;
		Cleaner(Wor);
    }
    holder = Wor.find("(");
    if(holder != -1){
        editor1 = Wor.substr( 0, holder);
		holder ++;
		editor2 = Wor.substr( holder );
		Wor = editor1 + editor2;
		Cleaner(Wor);
    }
    holder = Wor.find(")");
    if(holder != -1){
        editor1 = Wor.substr( 0, holder);
		holder ++;
		editor2 = Wor.substr( holder );
		Wor = editor1 + editor2;
		Cleaner(Wor);
    }
    holder = Wor.find("\\");
    if(holder != -1){
        editor1 = Wor.substr( 0, holder);
		holder ++;
		editor2 = Wor.substr( holder );
		Wor = editor1 + editor2;
		Cleaner(Wor);
    }
    holder = Wor.find("/");
    if(holder != -1){
        editor1 = Wor.substr( 0, holder);
		holder ++;
		editor2 = Wor.substr( holder );
		Wor = editor1 + editor2;
		Cleaner(Wor);
    }

    return Wor;

}
