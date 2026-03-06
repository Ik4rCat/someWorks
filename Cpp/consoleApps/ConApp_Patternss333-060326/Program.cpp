#include <iostream>

using namespace std;


class Product{
private:
    int price;
    int quantity;
public:
    Product() : price(0), quantity(0) {}

    Product(int p, int q){
        price = p;
        quantity = q;
    }

    ~Product(){}

    void setPrice(int newPrice){
        price = newPrice;
    }

    void setQuantity(int newQuantity){
        quantity = newQuantity;
    }

    int getPrice() const{
        return price;
    }

    int getQuantity() const{
        return quantity;
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

    void setPrice(double newPrice){
        price = newPrice;
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
};

// needed for cout and cin 
class Controller
{
    //Selling part
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
        p.setPrice(price);

        return in;
    }

    //Product part
    friend std::ostream& operator<<(std::ostream& out, const Product& p) {  
        out << "Price: " << p.getPrice() 
            << ", Quantity: " << p.getQuantity() << endl;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Product& p) {
        int price;
        int quantity;
 
        in >> price >> quantity;
 
        p.setPrice(price);
        p.setQuantity(quantity);
 
        return in;
    }

    //ProductSelling part
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

        p.p.setPrice(price);
        p.p.setQuantity(quantity);
        p.setCount(count);
        p.setMiddlePrice();

        return in;
    }
};



int main()
{
    return 0;
}