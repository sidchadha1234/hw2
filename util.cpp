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

std::set<std::string> parseStringToWords(string rawWords)
{   
  
    std::set<std::string> parsedString;
    string r = "";
    for(unsigned int i = 0; i < rawWords.length(); i++){
      //check all the nessecary conditions and insert the current string you have
        if(ispunct(rawWords[i]) || isspace(rawWords[i])){
          if(r.length() >= 2){
            parsedString.insert(convToLower(r)); //make sure its lowercase
            //reset the string and move on
            r="";
          }
        }
        else{
          //if conditions not met, just keep adding to string r 
          r+=rawWords[i];
        }
    }
  if(r.size()>=2){ //if r is still lowercase at the end, convert it to lower and insert it in the new set
    convToLower(r);
    parsedString.insert(convToLower(r));
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
