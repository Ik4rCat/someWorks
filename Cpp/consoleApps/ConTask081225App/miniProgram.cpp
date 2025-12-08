#include <iostream>
#include <vector>
using namespace std;


class PSM
{
    public:
        void PStack(vector<int>& st){
            if(st.empty()) {
                cout << "Stack is empty!" << endl;
                return;
            }

            cout << "stack: " << endl;
            for(int n : st) {
                cout << n << "\t";
            }            
        }

        void AddNum(vector<int>& st){
            int x;
            
            cout << "Enter num: ";
            cin >> x;

            st.push_back(x);
            PStack(st);
        }

        void DelNum(vector<int>& st){
            if(st.empty()) {
                cout << "Stack is already empty!" << endl;
                return;
            }

            st.pop_back();

            PStack(st);
        }

};

class UserInp
{
    public :
        void UserChoiceCheck(int choice, vector<int>& st){
            PSM psm;

            switch(choice){
                case 1: psm.AddNum(st); break;
                case 2: psm.PStack(st); break;
                case 3: psm.DelNum(st); break;
                case 0: return;

                default: cout << "error value, try again" << endl; break;
            }
        }

        void UserMenu(int choice, vector<int>& st){
            while (true)
            {
                cout << endl;
                cout << "<==Welcome to mini stackGarage!==>" << endl;
                cout << "What u want to do with stack?" << endl;
                cout << "  - [+] add num in stack (press 1)" << endl; 
                cout << "  - {...} print stack (press 2)" << endl;
                cout << "  - [-] del num from end of stack (press 3)" << endl;
                cout << "  - {exit} exit program (press 0)" << endl;

                cin >> choice;
                UserChoiceCheck(choice, st);
            }
            

        }

};



int main()
{
    UserInp usrInp;

    vector<int> stack;
    int choice;

    usrInp.UserMenu(choice, stack);

}