#include <vector>
#include <string>

using namespace std;

struct Order {
    int id;
    string customer;
    double amount;
    int status; // 1=new, 2=paid, 3=shipped, 4=done
};

class OrderProcessor {
    vector<Order> orders;
    
public:
    void process(int id, int action) 
    {
        for (int i = 0; i < orders.size(); i++)
        {
            if (orders[i].id == id) 
            {
                if (action == 1) // new
                {
                    if (orders[i].status == 1) 
                    {
                        orders[i].status = 2;
                        sendEmail(orders[i].customer, "Order paid");
                    }
                } 
                else if (action == 2) // paid
                {
                    if (orders[i].status == 2) 
                    {
                        orders[i].status = 3;
                        sendEmail(orders[i].customer, "Order shipped");
                    }
                } 
                else if (action == 3) // shipped
                {
                    if (orders[i].status == 3) orders[i].status = 4;
                }
                else if (action == 4) // done
                {
                    if (orders[i].status == 1) orders.erase(orders.begin() + i);
                }
                break;
            }
        }
    }
    
    void sendEmail(std::string to, std::string msg) {
        // sending email...
    }
};
