#include <string>
#include <vector>
#include <set>
#include "util.h"
#include "product.h"


// importing a whole namespace in a header is frowned upon
// this will at least let us write 'string'/'vector' below
using std::string;
//using std::vector;
//using std::set;

class Clothing:public Product{
   public:
      Clothing(const std::string category, const std::string name_, double price, int qty, std::string size, std::string brand);
       std::set<std::string> keywords() const;
       std::string displayString() const;
       void dump(std::ostream& os) const;
   private:
      std::string category = "Clothing";
      std::string bSize;
      std::string bBrand;
      double price;
      int quantity;

      
   //   string name;
  /*    string userName;
      double creditAmount;
      int typePrime;
      */
};