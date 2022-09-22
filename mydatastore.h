#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include <string>
#include <vector>
#include <set>
#include <map>
#include "datastore.h"
#include "product.h"
#include "user.h"
#include "util.h"

class MyDataStore : public DataStore{
  public:
    MyDataStore();
     ~MyDataStore();
    void addProduct(Product* p);
    void viewCart(std::string username); 

void addCart(std::string username, Product* g);
    void buyCart(std::string username);

     void addUser(User* u);

     bool isValidUserName(std::string username);

     std::vector<Product*> search(std::vector<std::string>& terms, int type);

    virtual void dump(std::ostream& ofile);
  private:
    std::vector<Product*> prodset; //set of products
    std::map<std::string, std::set<Product*>> stringtoproduct; //result of products for each keyword
    std::map<std::string, User*> nametouser; //user that matches each username
    std::map<std::string, std::vector<Product*>> usertocart; //cart for each user




};
#endif
