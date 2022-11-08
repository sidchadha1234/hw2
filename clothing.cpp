#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "product.h"

using namespace std;


Clothing::Clothing(const std::string category, const std::string name_, double price, int qty, std::string size, std::string brand)
:Product(category, name_, price, qty)
{
    bSize=size;
    bBrand=brand;
  
}


 std::set<std::string> Clothing::keywords() const{
   //insert all the keywords into set, beside name, parse the name into a set, create a union betw other keywords and parsed name, and return that result

  set<std::string> hits;
  set<std::string> inputauth;
  inputauth = parseStringToWords(convToLower(bBrand));
  inputauth.insert(bSize);
  set<std::string> nameparsed;
  nameparsed = parseStringToWords(convToLower(name_));
  hits = setUnion(inputauth, nameparsed);
  return hits;
  }
 


 std::string Clothing::displayString() const{
  //display all the components of a piece of clothing

  std::string g;
  std::string pricestr = std::to_string(price_);
  std::string quantitystr = std::to_string(qty_);
  pricestr = pricestr.substr(0, pricestr.find(".")+3);
  quantitystr = quantitystr.substr(0,quantitystr.find(".")+3);    
  g+=(name_+"\n" + "Size: "+bSize + " Brand: " + bBrand+"\n" +pricestr+" " + quantitystr + " left.");
  return g;
  }


 void Clothing::dump(std::ostream& os) const{
  //dump all the components of a piece of clothing

    os << category << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << bSize << "\n" << bBrand << endl;

}

