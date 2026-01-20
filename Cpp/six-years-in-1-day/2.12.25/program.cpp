#include <iostream>
#include <string>
using namespace std;

class Task1
{
public:
    void Program() {
        string text;
        int pos;
        
        cout << "Task 1" << endl;
        cout << "Enter string: ";
        getline(cin, text);
        
        cout << "Enter position to delete (starting from 0): ";
        cin >> pos;
        cin.ignore();
        
        if (pos >= 0 && pos < (int)text.length()) {
            text.erase(pos, 1);
            cout << "Result: " << text << endl;
        } else {
            cout << "Error: invalid position!" << endl;
        }
        cout << endl;
    }
};

class Task2
{
public:
    void Program() {
        string text;
        char ch;
        
        cout << "Task 2" << endl;
        cout << "Enter string: ";
        getline(cin, text);
        
        cout << "Enter character to delete: ";
        cin >> ch;
        cin.ignore();
        
        string result = "";
        for (int i = 0; i < (int)text.length(); i++) {
            if (text[i] != ch) {
                result += text[i];
            }
        }
        
        cout << "Result: " << result << endl;
        cout << endl;
    }
};

class Task3
{
public:
    void Program() {
        string text;
        int pos;
        char ch;
        
        cout << "Task 3" << endl;
        cout << "Enter string: ";
        getline(cin, text);
        
        cout << "Enter position to insert: ";
        cin >> pos;
        cout << "Enter character to insert: ";
        cin >> ch;
        cin.ignore();
        
        if (pos >= 0 && pos <= (int)text.length()) {
            text.insert(pos, 1, ch);
            cout << "Result: " << text << endl;
        } else {
            cout << "Error: invalid position!" << endl;
        }
        cout << endl;
    }
};

class Task4
{
public:
    void Program() {
        string text;
        
        cout << "Task 4" << endl;
        cout << "Enter string: ";
        getline(cin, text);
        
        for (int i = 0; i < (int)text.length(); i++) {
            if (text[i] == '.') {
                text[i] = '!';
            }
        }
        
        cout << "Result: " << text << endl;
        cout << endl;
    }
};

class Task5
{
public:
    void Program() {
        string text;
        char ch;
        
        cout << "Task 5" << endl;
        cout << "Enter string: ";
        getline(cin, text);
        
        cout << "Enter character to find: ";
        cin >> ch;
        cin.ignore();
        
        int count = 0;
        for (int i = 0; i < (int)text.length(); i++) {
            if (text[i] == ch) {
                count++;
            }
        }
        
        cout << "Character '" << ch << "' appears " << count << " time(s)" << endl;
        cout << endl;
    }
};

class Task6
{
public:
    void Program() {
        string text;
        
        cout << "Task 6" << endl;
        cout << "Enter string: ";
        getline(cin, text);
        
        int letters = 0, digits = 0, others = 0;
        
        for (int i = 0; i < (int)text.length(); i++) {
            char c = text[i];

            if (c >= '0' && c <= '9') {
                digits++;
            }
            else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                letters++;
            }
            else {
                others++;
            }
        }
        
        cout << "Letters: " << letters << endl;
        cout << "Digits: " << digits << endl;
        cout << "Other characters: " << others << endl;
        cout << endl;
    }
};

int main() {
    Task1 task1;
    Task2 task2;
    Task3 task3;
    Task4 task4;
    Task5 task5;
    Task6 task6;

    while (true) {
        int choice;

        cout << "Choose task:" << endl;
        cout << "1 - Task1" << endl;
        cout << "2 - Task2" << endl;
        cout << "3 - Task3" << endl;
        cout << "4 - Task4" << endl;
        cout << "5 - Task5" << endl;
        cout << "6 - Task6" << endl;
        cout << "0 - Exit" << endl;

        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            task1.Program();
            break;
        case 2:
            task2.Program();
            break;
        case 3:
            task3.Program();
            break;
        case 4:
            task4.Program();
            break;
        case 5:
            task5.Program();
            break;
        case 6:
            task6.Program();
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }
}
