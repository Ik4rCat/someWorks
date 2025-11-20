#include <iostream>
using namespace std;

void Task() {
    int v, i;                

    int mas[3] = { 1, 2, 3 };  

    int* pv = &v;            // указатель на v
    int* p = mas;            // указатель на начало массива

    *pv = 5;                 // запись значения через указатель
    cout << "v = " << v << endl;

    cout << "sample massiv: ";
    for (i = 0; i < 3; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;

    // Работа с указателем на массив
    *p = 10;                 // изменили первый элемент массива
    cout << "after *p = 10: " << mas[0] << endl;

    p++;                     // переместили указатель на следующий элемент
    *p = 20;                 // изменили второй элемент
    cout << "after p++ и *p = 20: " << mas[1] << endl;

    (*p)++;                  // увеличили второй элемент на 1
    cout << "after (*p)++: " << mas[1] << endl;

    p++;                     // переместили указатель на третий элемент
    *p = 30;                 // изменили третий элемент

    cout << "Result massiv: ";
    for (i = 0; i < 3; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;
}

int main()
{
    int usip;

    while (true) {
        cout << "\nstart task? write 1 \n exit - 0" << endl;
        cin >> usip;

        switch (usip)
        {
        case 1:
            Task();
            break;
        case 0:
            return 0; 
        default:
            cout << "wrong input, try again" << endl;
        }
    }
}