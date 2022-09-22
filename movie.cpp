#include <sstream>
#include <iomanip>
#include "movie.h"
#include "product.h"

using namespace std;


Movie::Movie(const std::string category, const std::string name_, double price, int qty, std::string genre, std::string rating)
:Product(category, name_, price, qty)
{
    bGenre=genre;
    bRating=rating;
}




 std::set<std::string> Movie::keywords() const{
//insert all the keywords into set, beside name, parse the name into a set, create a union betw other keywords and parsed name, and return that result
  set<std::string> hits;
  set<std::string> inputauth;
  inputauth = parseStringToWords(convToLower(bGenre));
  inputauth.insert(bRating);
  set<std::string> nameparsed;
  nameparsed = parseStringToWords(convToLower(name_));
  hits = setUnion(inputauth, nameparsed);
  return hits;
  }

 std::string Movie::displayString() const{
   //display all the components of a book
  std::string g;
  std::string pricestr = std::to_string(price_);
  std::string quantitystr = std::to_string(qty_);


  g+=(name_+"\n" + "Genre: "+bGenre + " Rating: " + bRating+"\n" +pricestr+" " + quantitystr + " left.");
  return g;
  }


 void Movie::dump(std::ostream& os) const{
    //dump all the components of a book
    os << category << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << bGenre << "\n" << bRating << endl;

}

