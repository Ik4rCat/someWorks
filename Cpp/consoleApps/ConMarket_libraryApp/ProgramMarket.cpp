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
        string name;
        string category;

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
        // Product GetStruct(){
        //     return buferProduct;
        // }

        void UpdateDepotCategory(){
            allCategory = {"Electronic", "household chemicals", "hygiene products"};
            foodCategory = {"Pet food", "Meat", "fish", "vegetables",
                            "fruits", "cereals", "dairy products",
                            "fats", "sweets", "drinks", "fast food",
                            "confectionery", "semi-finished products", "national cuisines"};
        }

        Product CreateProduct(string n, string cat, int quant, double pr, double expD, bool frgN){
            Product prd = {n, cat, quant, pr};
            if (isFood) prd.fi = {expD, frgN};
            products.push_back(prd);
            return prd;
        }

        vector<Product> products;


};

class Depot
{
    ProductData pd;

    void CheckDepot(){
        // auto product = pd.GetStruct();
        if (pd.products.empty()){
            cout << "No product in Depot" << endl;
        }
        else{
            cout << "Now in Depot" << endl;
            for (int i = 0; i < pd.products.size(); i ++){
                cout << "product #" << i << endl;
                pd.products[i].info();
            }
            cout << "End of Depot" << endl;
        }
    }

    void AddProduct(){
        string name;
        string category = "";
        
        int categoryChoice;
        int quantity;

        double price;
        double expirationDate;

        bool fridgeNeeded;
        
        cout << endl;
        cout << "What Product do u want to add" << endl;
        cout << "  -product name: ";
        cin >> name;

        cout << endl;

        cout << "  -product category (choice one from list): " << endl;
        cout << " ==general categories" << endl;

        for(int i = 0; i < allCategory.size(); i++){
            cout << "  " << i << "-" << allCategory[i] << endl;
        }

        cout << endl;

        cout << " ==food&drinks categories" << endl;
        for(int i = 0; i < foodCategory.size(); i++){
            cout <<  "  " << i + allCategory.size() << "-" << foodCategory[i] << endl;
        }

        cin >> categoryChoice;
        
        int totalCategories = allCategory.size() + foodCategory.size();
        if(categoryChoice < 0 || categoryChoice >= totalCategories) {
            cout << "Invalid category choice!" << endl;
            return;
        }

        if(categoryChoice < allCategory.size()) {
            category = allCategory[categoryChoice];
            isFood = false;
        } 
        else{
            int foodIndex = categoryChoice - allCategory.size();
            category = foodCategory[foodIndex];
            isFood = true;
        }
        
        if(isFood){
            string ch;

            cout << "  -product expirationDate: ";
            cin >> expirationDate;
            while (true)
            {
                cout << "  -product need fridge [yes/no{FINGERPRINT}]: " ;
                cin >> ch;

                if(ch == "y" || ch == "yes" || ch == "Y" || ch == "YES") {
                    fridgeNeeded = true;
                    break;
                }
                else if(ch == "n" || ch == "no" || ch == "not" || ch == "N" || ch == "No" || ch == "Not"){
                    fridgeNeeded = false;
                    break;
                } 
                else cout << "error, try again" << endl;
            }
            
        }        

        cout << "  -product quantity: ";
        cin >> quantity;

        cout << "  -product price (one thing): ";
        cin >> price;

        cout << endl;   

        auto newPrd = pd.CreateProduct(name, category, quantity, price, expirationDate, fridgeNeeded);
        newPrd.info();
    }

    void RemoveProduct(){
        int ch;

        CheckDepot();
        cout << endl;
        cout << "What product u want delete: " << endl;
        cin >> ch;

        pd.products.erase(pd.products.begin() + (ch-1));
    }

    void SaveData(){
        cout << endl;
        cout << "Data saved (just a joke, this function don't realized)" << endl;
    }

    public:
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