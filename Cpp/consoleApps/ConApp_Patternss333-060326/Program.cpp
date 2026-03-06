#include <iostream>

using namespace std;


class Product{
private:
    int price;
    string about;
public:
    Product() : price(0), about("") {}

    Product(int p, int q){
        price = p;
        about = q;
    }

    ~Product(){}

    void setPrice(int newPrice){
        price = newPrice;
    }

    void setQuantity(string newAbout){
        about = newAbout;
    }

    int getPrice() const{
        return price;
    }

    string getQuantity() const{
        return about;
    }


    //controller part
    friend std::ostream& operator<<(std::ostream& out, const Product& p) {  
        out << "Price: " << p.getPrice() 
            << ", Quantity: " << p.getQuantity() << endl;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Product& p) {
        int price;
        string about;
 
        in >> price >> about;
 
        p.setPrice(price);
        p.setQuantity(about);
 
        return in;
    }


};



class ProductSelling
{
private:
    double middlePrice;
    int count;
public:

    Product p;

    void setMiddlePrice(){
        middlePrice = p.getPrice() * count;
    }

    double getMiddlePrice() const{
        return middlePrice;
    }

    void setCount(int newCount){
        count = newCount;
    }

    int getCount() const{
        return count;
    }


    //controller part
    friend std::ostream& operator<<(std::ostream& out, const ProductSelling& p) {
        out << "Product price: " << p.p.getPrice()
            << ", Product quantity: " << p.p.getQuantity()
            << ", Count: " << p.getCount()
            << ", Middle price: " << p.getMiddlePrice() << endl;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, ProductSelling& p) {
        int price;
        int quantity;
        int count;

        in >> price >> quantity >> count;

        // p.p.setPrice();
        // p.p.setQuantity();
        p.setCount(count);

        return in;
    }
};


class Selling
{
private: 
    int date;
    int time;
    double price;
public:

    ProductSelling pS;

    void SellingSummary(){
        price = pS.getMiddlePrice();
    }

    void Creator(int newCount){
        pS.setCount(newCount);
    }

    void setDate(int newDate){
        date = newDate;
    }

    void setTime(int newTime){
        time = newTime;
    }


    int getDate() const{
        return date;
    }

    int getTime() const{
        return time;
    }

    double getPrice() const{
        return price;
    }


    //controller part
    friend std::ostream& operator<<(std::ostream& out, const Selling& p) {
        out << "Date: " << p.getDate() 
            << ", Time: " << p.getTime() 
            << ", Price: " << p.getPrice() << endl;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Selling& p) {
        int date;
        int time;
        double price;

        in >> date >> time >> price;

        p.setDate(date);
        p.setTime(time);
        p.SellingSummary();

        return in;
    }

};




int main()
{

    Selling s;
    Product p;
    ProductSelling ps;

    cin >> s;
    cin >> p;
    cin >> ps;

    
    cout << s;
    cout << p;
    cout << ps;

    return 0;
}