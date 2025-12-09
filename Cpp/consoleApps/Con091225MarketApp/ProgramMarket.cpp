#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ProductData
{
    struct Product
    {
        char name[50];
        char category[50];
        int quantity;
        double price;

        void info(){
            cout << endl;
            cout << "PRODUCT-INFO:" << endl;
            cout << "name - " << name << endl;
            cout << "category - " << category << endl;
            cout << "quantity - " << quantity << endl;
            cout << "price - " << price << endl;
        }
    }_Product;

    vector<string> category = {"Electronic", "Food", "Pet food", "Drinks"};
    // vector<string>

    public: Product GetStruct(){
        return _Product;
    }
};

class Depot
{
    ProductData pd;

    void CheckDepot(){
        auto product = pd.GetStruct();

    }

    void AddProduct(){
        auto product = pd.GetStruct();
        
        cout << "What Product do u want to add" << endl;
        cout << "  -product name: ";
        cin >> product.name ; 
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

        void UpdateDepotCategory(){
            auto product = pd.GetStruct();
            
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
    ProgramStarted ps;

    // if (product.category == NULL) dp.UpdateDepotCategory();
    ps.Program();
}