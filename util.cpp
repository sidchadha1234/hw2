#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <set>
#include <string>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
//    template <typename T>
std::set<std::string> parseStringToWords(string rawWords)
{   
  //split it based on whitesapce, split it based on puntuation, and if that is greater than 2, put into parsed stirng
    //use getline to split it based on whitespace 
    //put results into a set
    //copy chars from front of the string till you got punctuation
    //check to see if length is 2 or greater
    //keep advancing till you get a non punctuation character 
    std::set<std::string> parsedString;
    string r = "";
    for(unsigned int i = 0; i < rawWords.length(); i++){
        if(ispunct(rawWords[i] !=0) && isspace(rawWords[i]) != 0){
          if(r.length() >= 2){
            parsedString.insert(r);
            r="";
          }
        }
        else{
          r+=rawWords[i];
        }
    }
    return parsedString;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
