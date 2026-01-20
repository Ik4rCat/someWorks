#include <iostream>  
#include <string>
using namespace std; 

int task1() {         
    string text;     
    int pos;         

    cout << "Enter string: ";      
    cin >> text;                    
    
    cout << "Position to delete: "; 
    cin >> pos;                      
    
    if (pos >= 0 && pos < (int)text.length()) {
        text.erase(pos, 1);              // Delete 1 character at specified position
        cout << "Result: " << text << endl;
    } else {
        cout << "Error: invalid position!" << endl;
    }
    
    return 0;                        
}

int task2() {        
    string text;     // Declare variable for string
    char x;     // Declare variable for character to delete
    
    cout << "Enter string: ";      
    cin >> text;                     
    
    cout << "Character to delete: "; 
    cin >> x;                   
    
    for (int i = 0; i < text.length(); i++) { 
        if (text[i] == x) {     // If current character equals the one to delete
            text.erase(i, 1);        // Delete this character
            i--;                     // Decrease counter, because we deleted a character
        }
    }
    
    cout << "Result: " << text << endl;  
    return 0;                     
}

int task3() {       
    string text;    
    char x;     
    int pos;         
    
    cout << "Enter string: ";      
    cin >> text;                     
    
    cout << "Position to insert: "; 
    cin >> pos;                      
    cout << "Character to insert: ";  
    cin >> x;                  
    
    if (pos >= 0 && pos <= (int)text.length()) {
        text.insert(pos, 1, x);     // Insert character at specified position
        cout << "Result: " << text << endl;
    } else {
        cout << "Error: invalid position!" << endl;
    }
    
    return 0;                        
}

int task4() {         
    string text;     
    
    cout << "Enter string: ";     
    cin >> text;                     
    
    for (int i = 0; i < text.length(); i++) { 
        if (text[i] == '.') {        // If character is a dot
            text[i] = '!';           // Replace with exclamation mark
        }
    }
    
    cout << "Result: " << text << endl;   
    return 0;                        
}

int task5() {         
    string text;     
    char x;     
    int count = 0;   // counter 
    
    cout << "Enter string: ";      
    cin >> text;                     
    
    cout << "Character to find: ";      
    cin >> x;                   
    
    for (int i = 0; i < text.length(); i++) { 
        if (text[i] == x) {     
            count++;                 
        }
    }
    
    cout << "Character appears " << count << " time(s)" << endl; 
    return 0;                      
}

int task6() {       
    string text;     
    int letters = 0; // Counter for letters
    int digits = 0;  // Counter for digits
    int others = 0;  // Counter for other characters
    
    cout << "Enter string: ";  
    cin >> text;                
    
    for (int i = 0; i < text.length(); i++) { 
        char c = text[i];            // Save current character in variable
        
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) { 
            letters++;               // Increase letter counter
        }
        else if (c >= '0' && c <= '9') { 
            digits++;                // Increase digit counter
        }
        else {                       
            others++;                // Increase other characters counter
        }
    }
    
    cout << "Letters: " << letters << endl;     
    cout << "Digits: " << digits << endl;    
    cout << "Others: " << others << endl;            
    
    return 0;               
}

void task7() {        
    int M;           
    int N;           
    
    cout << "Array A size: "; 
    cin >> M;                     
    cout << "Array B size: "; 
    cin >> N;                     
    
    int A[M];        
    int B[N];       
    
    cout << "Elements of A: ";       
    for (int i = 0; i < M; i++) { 
        cin >> A[i];              
    }
    
    cout << "Elements of B: ";       
    for (int i = 0; i < N; i++) { 
        cin >> B[i];              
    }
    
    cout << "Result: ";       
    
    for (int i = 0; i < M; i++) { 
        bool foundInB = false;    // Flag - is element found in B
        bool duplicate = false;   // Flag - is element a duplicate
        
        for (int j = 0; j < N; j++) { 
            if (A[i] == B[j]) {   
                foundInB = true;  
                break;            
        }
    }
        
        for (int k = 0; k < i; k++) { 
            if (A[k] == A[i]) {   
                duplicate = true; 
                break;            
            }
        }
        
        if (!foundInB && !duplicate) { // If not found in B and not a duplicate
            cout << A[i] << " "; 
        }
    }            
}

int main(){ 


       while (true) {
        int choice;

        cout << "\nChoose task:" << endl;
        cout << "1 - Task1 " << endl;
        cout << "2 - Task2 " << endl;
        cout << "3 - Task3 " << endl;
        cout << "4 - Task4 " << endl;
        cout << "5 - Task5 " << endl;
        cout << "6 - Task6 " << endl;
        cout << "7 - Task7 " << endl;
        cout << "0 - Exit" << endl;

        cin >> choice;

        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 6:
            task6();
            break;
        case 7:
            task7();
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid value, try again" << endl;
            break;
        }
    }
}
