#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>
#include <set>
#include "util.h"
#include "product.h"

#include <algorithm> 

using std::string; 

class Book : public Product{
   public:
      Book(const std::string category, const std::string name_, double price, int qty, std::string ISBN, std::string Author);
       std::set<std::string> keywords() const;
       std::string displayString() const;
       void dump(std::ostream& os) const;
   private:
      std::string category = "book";
      std::string bISBN;
      std::string bAuthor;
};

#endif