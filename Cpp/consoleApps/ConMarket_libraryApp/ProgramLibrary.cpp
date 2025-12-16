#include <iostream>
#include <string>
#include <vector>
using namespace std;

static vector<string> allCategory;

class Data
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
        int capacity;
        int pastCapacity;
        int count = 0;

        Book* books;

        void LInfo(){
            cout << endl;
            cout << "Library-INFO:" << endl;
            cout << "We have: " << endl;
            cout << "  - " << count << " books" << endl;
            cout << "  - library capacity: " << capacity << endl;

        }
    };
     

    
    public:
        Library lib;    
    
        int bench = 25, booksOnBench = 15, cap = bench * booksOnBench;

        vector<Book> books;
        
        Library GetLibraryData(){
             return lib;
        }

        void UpdateBooksCategory(){
            allCategory = {"Novel", "Short story", "Novelette", "Fantasy", 
                "Science Fiction", "Detective", "Mystery", "Thriller",
                "Horror", "Romance", "Historical Fiction",
                "Adventure", "Biography", "Autobiography",
                "Poetry", "Drama", "Satire",
                "Dystopian", "Gothic Fiction", "Noir",
                "Action", "Western", "Cyberpunk",
                "Post-Apocalyptic", "Memoir", "Popular Science",
                "Fairy Tale", "Mythology", "Self-Help",
                "Travel", "Philosophy", "Humor"};
        }

        Book CreateNewBook(string name, string cat, string author, int NOfP, double price, bool TemporarilyTaken){
            Book book = {name, cat, author, NOfP, price, TemporarilyTaken};
            books.push_back(book);
            return book;
        }

        void IniLibrary(){
            lib = { cap, 0, int(books.size())};
        }
};


class LibFunc
{
    Data data;

    void CheckLibrary(){
        // auto product = pd.GetStruct();
        if (data.books.empty()){
            cout << "No books in Library" << endl;
        }
        else{
            cout << "Now in Library" << endl;
            for (int i = 0; i < data.books.size(); i ++){
                cout << "Book #" << i << endl;
                data.books[i].BookInfo();
            }
            cout << "End of Depot" << endl;
        }
    }

    void AddBook(){
        string name;
        string category;
        string author;
        
        int categoryChoice;
        int numberOfPages;
        int cTT;

        double price;
        bool canBeTakenTemporarily;
        
        cout << endl;
        cout << "What Book do u want to add" << endl;
        
        cout << "  -book name: ";
        cin >> name;
        cout << endl;

        cout << "  -book author: ";
        cin >>  author;
        cout << endl;

        cout << "  -book number of pages: ";
        cin >> numberOfPages;
        cout << endl;

        cout << "  -Book category (choice one from list): " << endl;

        for(int i = 0; i < allCategory.size(); i++){
            cout << "  " << i << "-" << allCategory[i] << endl;
        }

        cout << endl;

        cin >> categoryChoice;
        
        if(categoryChoice < 0 || categoryChoice >=  allCategory.size()){
            cout << "Invalid category choice!" << endl;
            return;
        }

        cout << endl;
        
        cout << "  -you chose category: " << allCategory[categoryChoice] << endl;

        cout << endl;

        cout << "  -can this book be taken temporarily? (1-yes, 0-no): ";
        cin >> cTT;

        if (cTT == 1) canBeTakenTemporarily = true;
        else canBeTakenTemporarily = false;

        cout << endl;

        cout << "  -product price (one thing): ";
        cin >> price;

        cout << endl;   

        

        auto newBook = data.CreateNewBook(name, category, author, numberOfPages, price, canBeTakenTemporarily);
        data.lib.count ++;
        data.lib.pastCapacity; 
        newBook.BookInfo();
    }

    void RemoveBook(){
        int ch;

        CheckLibrary();
        cout << endl;
        cout << "What product u want delete: " << endl;
        cin >> ch;

        data.books.erase(data.books.begin() + (ch-1));
    }

    void SaveData(){
        cout << endl;
        cout << "Data saved (just a joke, this function don't realized)" << endl;
    }

    public:
        void Manager(int usrChoice)
        {
            switch (usrChoice){
                case 1: data.lib.LInfo();
                case 2: CheckLibrary(); break;
                case 3: AddBook(); break;
                case 4: RemoveBook(); break;
                case 5: SaveData(); break;
                case 0: exit(0);
                default: cout << "error value, try again pls" << endl; break;
            }
        }
};


class ProgramStarted
{
    Data data;
    LibFunc libF;

    public: void Program()
    {
        while(true){
            int choice;

            cout << endl;
            cout << "<==Welcome to Library Manager CLI==>" << endl;
            cout << "What u want to do with books today?" << endl;
            cout << "  - 1. about library" << endl; 
            cout << "  - 2. check books in library" << endl;
            cout << "  - 3. add new product in depot" << endl;
            cout << "  - 4. remove product from depot" << endl;
            cout << "  - 5. save data" << endl;
            cout << "  - 0. exit program" << endl;
            
            cout << "Choice: ";
            cin >> choice;
            libF.Manager(choice);
        }
    }
};



int main()
{
    Data data;
    ProgramStarted ps;

    data.UpdateBooksCategory();
    ps.Program();
}