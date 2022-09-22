#include <sstream>
#include <iomanip>
#include "book.h"
#include "product.h"
#include "util.h"
#include <algorithm>    // std::transform


using namespace std;


Book::Book(const std::string category, const std::string name_, double price, int qty, std::string ISBN, std::string Author)
:Product(category, name_, price, qty)
{
    
    bISBN=ISBN;
    bAuthor=Author;
  
}



 std::set<std::string> Book::keywords() const{
   //insert all the keywords into set, beside name, parse the name into a set, create a union betw other keywords and parsed name, and return that result
  set<std::string> hits;
  set<std::string> inputauth;
  inputauth = parseStringToWords(convToLower(bAuthor));
  inputauth.insert(bISBN);
  set<std::string> nameparsed;
  nameparsed = parseStringToWords(convToLower(name_));
  hits = setUnion(inputauth, nameparsed);
  return hits;
  }
  
  


 std::string Book::displayString() const{
   //display all the components of a book
  std::string g;
  std::string pricestr = std::to_string(price_);
  std::string quantitystr = std::to_string(qty_);
  g+=(name_+"\n" + "Author: "+bAuthor + " ISBN: " + bISBN+"\n" +pricestr+" " + quantitystr + " left.");
  return g;
  }


 void Book::dump(std::ostream& os) const{
    //dump all the components of a book
    os << category << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << bAuthor << "\n" << bISBN << endl;

}

