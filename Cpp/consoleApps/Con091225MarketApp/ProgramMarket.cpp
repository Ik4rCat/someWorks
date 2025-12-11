#include <iostream>
#include <string>
#include <vector>
using namespace std;

static vector<string> allCategory;
static vector<string> foodCategory;
static bool isFood;

class ProductData
{
    struct FoodInternals
    {
        double expirationDate;
        bool fridgeNeeded;
    };

    struct Product
    {
        char name[50];
        char category[50];
        int quantity;
        double price;

        FoodInternals fi;

        void info(){
            cout << endl;
            cout << "PRODUCT-INFO:" << endl;
            cout << "name - " << name << endl;
            cout << "category - " << category << endl;
            cout << "quantity - " << quantity << endl;
            cout << "price - " << price << endl;

            if(isFood){
                cout << "Expiration date:" << fi.expirationDate << endl;
                if(fi.fridgeNeeded) cout << "Product need a fridge!" << endl;
                else cout << "Product don't need a fridge" << endl;
            }
        }
    }_Product;

                                  
    public: 
        Product GetStruct(){
            return _Product;
        }

        void UpdateDepotCategory(){
            allCategory = {"Electronic", "household chemicals", "hygiene products"};
            foodCategory = {"Pet food", "Meat", "fish", "vegetables",
                            "fruits", "cereals", "dairy products",
                            "fats", "sweets", "drinks", "fast food",
                            "confectionery", "semi-finished products", "national cuisines"};
        }

        // void CUTT(string category){
        //     _Product.category = category;
        // }

};

class Depot
{
    ProductData pd;

    void CheckDepot(){
        auto product = pd.GetStruct();

    }

    void AddProduct(){
        auto product = pd.GetStruct();
        string categoryChoice;
        bool generalC = false;

        vector<string> abcd = {"a", "b", "c", "d", 
            "e", "f", "g", "h",
             "i", "j", "k", "l",
              "m", "n", "o", "p",
               "q", "r", "s", "t",
                "u", "v", "w", "x",
                 "y", "z"};
        
        cout << "What Product do u want to add" << endl;
        cout << "  -product name: ";
        cin >> product.name;

        cout << endl;

        cout << "  -product category (choice one from list): " << endl;
        cout << " ==general categories" << endl;
        for(int i = 0; i < allCategory.size(); i++){
            cout << "  " << abcd[i] << "-" << allCategory[i] << endl;
        }
        cout << endl;
        cout << " ==food&drinks categories" << endl;
        for(int i = 0; i < foodCategory.size(); i++){
            cout <<  "  " << i << "-" << foodCategory[i] << endl;
        }
        cin >> categoryChoice;
        
        for (int i = 0; i < abcd.size(); i++)
        {
            if (abcd[i] == categoryChoice){
                generalC = true;
                //product.category = allCategory[i];
            }
        }

        if(!generalC) //product.category = foodCategory[stoi(categoryChoice)];
        
        
        for(int i = 0; i < foodCategory.size(); i++){
            if(product.category == foodCategory[i]){
                string ch;

                isFood = true;
                cout << "  -product expirationDate: ";
                cin >> product.fi.expirationDate;
                while (true)
                {
                    cout << "  -product need fridge [yes/no{FINGERPRINT}]: " ;
                    cin >> ch;

                    if(ch == "y" || ch == "yes" || ch == "Y" || ch == "YES") {
                        product.fi.fridgeNeeded = true;
                        break;
                    }
                    else if(ch == "n" || ch == "no" || ch == "not" || ch == "N" || ch == "No" || ch == "Not"){
                        product.fi.fridgeNeeded = false;
                        break;
                    } 
                    else cout << "error, try again" << endl;
                }
            }
        }        

        cout << "  -product quantity: ";
        cin >> product.quantity;

        cout << "  -product price (one thing): ";
        cin >> product.price;

        cout << endl;
        product.info();
    }

    void RemoveProduct(){

    }

    void SaveData(){
        cout << endl;
        cout << "Data saved (just a joke, this function don't realized)" << endl;
    }

    public:
        void UpdateDepot(){
            auto product = pd.GetStruct();
            product = {};
        }

        void Manager(int usrChoice)
        {
            switch (usrChoice){
                case 1: CheckDepot(); break;
                case 2: AddProduct(); break;
                case 3: RemoveProduct(); break;
                case 4: SaveData(); break;
                case 0: exit(0);
                default: cout << "error value, try again pls" << endl; break;
            }
        }
};


class ProgramStarted
{
    ProductData pd;
    Depot dp;

    void CheckDepotOnStarted(){

    }

    public: void Program()
    {
        while(true){
            int choice;

            cout << endl;
            cout << "<==Welcome to Depot Manager CLI==>" << endl;
            cout << "What u want to do with depot today?" << endl;
            cout << "  - 1. check depot" << endl;
            cout << "  - 2. add new product in depot" << endl;
            cout << "  - 3. remove product from depot" << endl;
            cout << "  - 4. save data" << endl;
            cout << "  - 0. exit program" << endl;
            
            cout << "Choice: ";
            cin >> choice;
            dp.Manager(choice);
        }
    }
};



int main()
{
    ProductData pd;
    ProgramStarted ps;

    pd.UpdateDepotCategory();
    ps.Program();
}