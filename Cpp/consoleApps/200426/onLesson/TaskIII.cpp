#include <iostream>
#include <string>

using namespace std;

bool IsValidEmail(const string& email){
    if(email.find('@') != string::npos && email.find(".com") != string::npos) {
        return true;
    } 
    else 
    {
        return false;
    }
}

int main(){
    string emails[] = {"test@exmaple.com", "admin@","@domain"};
    for (const auto& e : emails){
        cout << e << " - " << (IsValidEmail(e) ? "OK" : "NOT OK") << endl;
    }
    return 0;
}
