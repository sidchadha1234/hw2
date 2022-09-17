#include <sstream>
#include <iomanip>
#include "movie.h"
#include "product.h"

using namespace std;


Movie::Movie(const std::string category, const std::string name_, double price, int qty, std::string genre, std::string rating)
:Product(category, name_, price, quantity)
{
    bGenre=genre;
    bRating=rating;
}


//  template <typename T>

 std::set<std::string> Movie::keywords() const{
  set<std::string> hits;
  set<std::string> inputauth;
  inputauth = parseStringToWords(bGenre);
  inputauth.insert(bRating);
  set<std::string> nameparsed;
  nameparsed = parseStringToWords(name_);
  hits = setUnion(inputauth, nameparsed);
  return hits;
  }
  /*
set<string> result;
  if(type == "or"){
    set<string> inputvector = parseStringTowards(s);
    set<string> parsedName = parseStringToWords(name_);
     result.insert(setUnion(inputvector, parsedname));

    set<string> parsedAuthor = parseStringToWords(bAuthor);
    result.insert(setUnion(inputvector, parsedAuthor));

     for(set<string>::iterator it=parsedString.begin(); it != parsedString.end(); ++it){
      if(*it==ISBN){
        result.insert(*it);
      }
  }
    vector<Book> r = result. ???

    displayProducts(r); //how do i make a result a vector of books

  if(s == ISBN){
    result.insert(input);
  }

  }else if(type = "and"){
    set<string> inputvector = parseStringTowards(s);
    set<string> parsedName = parseStringToWords(name_);
     result.insert(setIntersection(inputvector, parsedname));
    set<string> parsedAuthor = parseStringToWords(bAuthor);
    result.insert(setIntersection(inputvector, parsedAuthor));
     for(set<string>::iterator it=parsedString.begin(); it != parsedString.end(); ++it){
      if(*it==ISBN){
        result.insert(*it);
      }
  }
    vector<Book> r = result. ???
    displayProducts(r); //how do i make a result a vector of books



  }else{
    return NULL;
  }
  

  //test the name

  for(set<string>::iterator it=parsedString.begin(); it != parsedString.end(); ++it){
      if(*it.find(inputvector)){

        //how do you find the oriignal book here 

        hits.insert(?);

      }
  }
//test the author 
  for(set<string>::iterator it=parsedAuthor.begin(); it != parsedAuthor.end(); ++it){
    if(*it.find(inputvector)){


      //need a way to insert the specific book 
        hits.insert(?);

    }
  }
//test the ISBN



  displayProducts(hits);
  */
  


 std::string Movie::displayString() const{
  std::string g;
  std::string pricestr = std::to_string(price);
  std::string quantitystr = std::to_string(quantity);


  g+=(name_+"\n" + "Genre: "+bGenre + "Rating: " + bRating+"\n" +pricestr+" " + quantitystr + "left.");
  return g;
  }


 void Movie::dump(std::ostream& os) const{
//how do you go about this 
  //that outputs the database format of the product info
  //replicate database.txt
    os << category << "\n" << name_ << "\n" << price << "\n" << quantity << "\n" << bGenre << "\n" << bRating << endl;

}

