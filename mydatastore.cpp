#include "mydatastore.h"
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include "product.h"
#include "book.h"
#include "clothing.h"
#include "movie.h"


using namespace std;

MyDataStore::MyDataStore()
{

}
MyDataStore::~MyDataStore(){
//Using .clear to delete the whole set/map
  for(unsigned int i = 0; i < prodset.size(); i++){
    delete prodset[i];
  }
  map<string, User*>::iterator it;
  for(it = nametouser.begin(); it!=nametouser.end();++it){
    delete it->second;
  }
}

void MyDataStore::addProduct(Product* p){

  prodset.push_back(p);
  std::set<std::string> g = p->keywords();

  for(auto i:g){ 
  //if the product exists in the set just push it back
    if(stringtoproduct.find(i) != stringtoproduct.end()){ 
      stringtoproduct[i].insert(p); 
    }
    //if it doesnt just create a new pair with the nessecary information
    //note: string to product is <keyword, every product that matches it>
    else{
      std::set<Product*> z;
      z.insert(p);
      stringtoproduct.insert(make_pair(i, z));
    }
  }
}

void MyDataStore::addUser(User* u){
  // add the user the to nametouser map <username, user>
  std::string username = u->getName();
  nametouser.insert(make_pair(username, u));
}

void MyDataStore::addCart(std::string username, Product* g){
  //if there isnt a valid username do nothing
  if(isValidUserName(username) == false) return ;
  
  else{
    //if the user has a cart just push it to the back of a cart
    if(usertocart.find(username)!=usertocart.end()){
      usertocart[username].push_back(g);
    }
    
    else{
      //if the user doesnt have a cart, create a new cart 
      //note: usertocart is <User, cart-Vector of products>
      vector<Product*> p;
      p.push_back(g);
      usertocart.insert(make_pair(username,p));
    }
  }
 
}

void MyDataStore::buyCart(std::string username){

  //if the username isnt valid, do nothing
  if(isValidUserName(username) == false) return ; 

//if the user has a cart enter this
  if(usertocart.find(username)!=usertocart.end()){
    std::vector<Product*> temp;
      //iterate through each product in the users cart

    for(auto i:usertocart[username]){

        double price = i->getPrice();
        //if theres enough stock and if the user has a sufficient balance, buy it
        if((i->getQty()>=1) && (nametouser[username]->getBalance()>=price)){
          nametouser[username]->deductAmount(price);
          i->subtractQty(1);
        }
        else{
          //otherwise add it to a temp vector that will be the "new" cart for that user
          temp.push_back(i);
        }
      }
    //if there are more than one items in the cart, make temp its new cart

    if(temp.size()>=1){
      usertocart[username] = temp;
    }
    //if there are no more items in the cart erase it

    else{
      usertocart.erase(username);
    }
  }
  
}

void MyDataStore::viewCart(std::string username){
  //if there isnt a valid username, do nothing
  if(isValidUserName(username) == false) return ;
  //if there is and there is a cart, iterate through and display the info for each cart item
  if(usertocart.find(username)!=usertocart.end()){
    int count = 1;
    
    for(auto i:usertocart[username]){
      cout<<"Item: " << count<<endl;
      cout<<i->displayString()<<endl;
      count++;
    }
  }
  //if there isnt a valid cart, do nothing
  else{
    return ;
  }
}

 


bool MyDataStore::isValidUserName(std::string username){
  //check to see if the username exists in the nametouser database
  if(nametouser.find(username)!=nametouser.end()){
    return true;
    //cout<<"ERROR: USERNAME DOES NOT EXIST";
  }
  return false;
}

/**
* Performs a search of products whose keywords match the given "terms"
*  type 0 = AND search (intersection of results for each term) while
*  type 1 = OR search (union of results for each term)
*/
  std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
    //a vector of set of products, each set is for a certain keyword
    
    std::vector<std::set<Product*>> result;
    std::vector<Product*> resprod;


    for(std::vector<std::string>::iterator it=terms.begin(); it != terms.end(); ++it){
      //Add the set of products that match a given keyword to the vector of the set of products
      if(stringtoproduct.find(*it)!=stringtoproduct.end()){
          
          result.push_back(stringtoproduct[*it]);
      }
    }


    if(result.size()==0) return resprod; //if the size is 0 and the type is or, it should end automatically

    //compare the first index against the rest of it and intersect/union it all into the first index
    for(unsigned int i = 1; i<result.size();i++){
        if(type == 0){
          result[0] = setIntersection(result[0], result[i]);
        }else if(type == 1){
          result[0] = setUnion(result[0], result[i]);
        }    
    }

    //first index is just a vector so push that into a simple vector and return it 
    for(std::set<Product*>::iterator it=result[0].begin(); it != result[0].end(); ++it){
      resprod.push_back(*it);
    }

    return resprod;
  }
  void MyDataStore::dump(std::ostream& ofile){
    //simply just dump all the updated data into a txt file, should have a seperated one for users and products
        ofile<<"<products>\n";
        for(auto i:prodset){
          i->dump(ofile);
        }
        ofile<<"</products>\n";
        ofile<<"<users>\n";
        for(std::map<std::string, User*>::iterator it=nametouser.begin(); it != nametouser.end(); ++it){
          it->second->dump(ofile);
        }

        ofile<<"</users>\n";

    }
