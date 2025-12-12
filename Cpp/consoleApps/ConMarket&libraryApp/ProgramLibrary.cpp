#include <iostream>
#include <string>
#include <vector>
using namespace std;

static vector<string> allCategory;

static bool isFood;

class ProductData
{
    struct Book
    {
        string name;
        string category;
        string author;

        int numberOfPages;
        double price;
        bool canBeTakenTemporarily;

        void BookInfo(){
            cout << endl;
            cout << "BOOK-INFO:" << endl;
            
            cout << "name - " << name << endl;
            cout << "Author - " << author << endl;
            cout << "Book have { " << numberOfPages << "} pages" << endl;

            cout << "category - " << category << endl;
            cout << "price - " << price << endl;
            
            if(canBeTakenTemporarily) cout << "You can take this book Temporarily"<< endl;
            else cout << "You can't take this book Temporarily"<< endl;

        }

    };

    struct Library
    {
        Book* books;

        int capacity;
        int count;

        void LInfo(){
            cout << endl;
            cout << "Library-INFO:" << endl;
            cout << "We have: " << endl;
            cout << "  - " << count << "books" << endl;

        }
    };
     
    Library lib;
    
    public:
        int bench = 25, booksOnBench = 15;

        vector<Book> books();    
        

        Library GetLibraryData(){
            return lib;
        }

        void UpdateBooksCategory(){
            allCategory = {"Electronic", "household chemicals", "hygiene products"};
        }

        Book CreateNewBook(string name, string cat, string author, int NOfP, int price, bool TemporarilyTaken){
            Book book = {name, cat, author, NOfP, price};
            books.push_back(book);
            return book;
        }

        

        void IniLibrary(){
            lib = {(bench*booksOnBench), books.size()}
        }

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
            cout << "<==Welcome to Library Manager CLI==>" << endl;
            cout << "What u want to do with books today?" << endl;
            cout << "  - 1. check " << endl;
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

    pd.UpdateBooksCategory();
    ps.Program();
}