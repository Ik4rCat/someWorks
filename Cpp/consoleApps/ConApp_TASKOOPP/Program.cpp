#include <iostream>
#include "Figure.h"

using namespace std;

int main()
{
    Count Count;

    while (true) {

        int choice;
        double a= 0, b= 0, h= 0;

		cout << "\nSelect task: " << endl;
		cout << " 1 - Area of​​ a triangle" << endl;
		cout << " 2 - Area of​​ a right triangle" << endl;
		cout << " 3 - Area of​​ a rhombus" << endl;
		cout << " 4 - Area of​​ a square" << endl;
		cout << " 5 - Area of​​ a rectangle" << endl;
        cout << "0 - exit" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
            cout << endl;
			cout << "a size: " << endl;
            cin >> a;
            cout << "b size: " << endl;
            cin >> b;

            cout << "answer:" << Count.AreaOf​​ATriangle(a,b) << endl;
			break; 
        case 2:
            cout << endl;
			cout << "a size: " << endl;
            cin >> a;
            cout << "b size: " << endl;
            cin >> b;

            cout << "answer:" << Count.AreaOf​​ARightTriangle(a,b) << endl;
			break; 
        case 3:
            cout << endl;
			cout << "a size: " << endl;
            cin >> a;
            cout << "h size: " << endl;
            cin >> h;

            cout << "answer:" << Count.AreaOf​​ARhombus(a,h) << endl;
			break; 
        case 4:
            cout << endl;
			cout << "a size: " << endl;
            cin >> a;

            cout << "answer:" << Count.AreaOfASquare(a) << endl;
            break;
        case 5:
            cout << endl;
			cout << "a size: " << endl;
            cin >> a;
            cout << "b size: " << endl;
            cin >> b;

            cout << "answer:" << Count.AreaOfARectangle(a,b) << endl;
            break;
        case 0: return 0;
		default:
			cout << "Invalid choice!" << endl;
		}
	}

}
