/* ******************************* */
/* Chris Doucette, Stephen Demeule */
/* Machine Learning    4/5/16      */
/* Final Project: ReviewParser.hpp */
/* ******************************* */

/* #include <windows.h> "No such file or directory" */
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include <dirent.h>
#include <algorithm>

using namespace std;
/* (this is probably unnecessary)
void Find_Review();
int Read_Review(sting Rev);
string Lower(String W);
void Report( int val);
*/

/**
 * Main Function from which
 * everything is executed.
 */
int main( int argc, char* argv[] );



/**
* Read_Review scans text given for key words
* or phrases that are checked case by case for
* an increment or decrement in value of an
* overall score.
* @param string Rev -- path of file to read from.
* @return int score -- resulting score from adding each line's individual scores.
*/
string Read_Review(string Rev);


/**
* Line_Value function checks words given from
* the line against case statements for each
* expected key word. This results in incrementing
* or decrementing the LV (line value) integer value.
* @param string Line -- the given line to evaluate.
* @return LV -- the resulting numerical line value.
*/
int Line_Value( string Line );

/**
* Report function checks the numerical score
* obtained from previous text parsing and
* determines POSITIVE for scores above zero,
* and NEGATIVE for scores below zero.
* @param int value -- given overall score of review
*/
string Report( int value);

/**
* Changes characters from uppercase to lowercase.
* Used for easy matching of keywords, which are all
* lowercase.
* @param string W -- given string to chance chars to lowercase.
* @return string W -- altered, lowercase version of given string.
*/
string Lower( string W);

/**
* Clears word of unneeded markings
* ' .!-_/?"', etc. '
*/
string Cleaner( string Wor);
