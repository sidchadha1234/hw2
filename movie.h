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

class Movie:public Product{
   public:
      Movie(const std::string category, const std::string name_, double price, int qty, std::string genre, std::string rating);
       std::set<std::string> keywords() const;
       std::string displayString() const;
       void dump(std::ostream& os) const;
   private:
      std::string category = "movie";
      std::string bGenre;
      std::string bRating;


      
   //   string name;
  /*    string userName;
      double creditAmount;
      int typePrime;
      */
};