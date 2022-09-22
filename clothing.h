#include <string>
#include <vector>
#include <set>
#include "util.h"
#include "product.h"

using std::string;


class Clothing:public Product{
   public:
      Clothing(const std::string category, const std::string name_, double price, int qty, std::string size, std::string brand);
       std::set<std::string> keywords() const;
       std::string displayString() const;
       void dump(std::ostream& os) const;
   private:
      std::string category = "clothing";
      std::string bSize;
      std::string bBrand;
};