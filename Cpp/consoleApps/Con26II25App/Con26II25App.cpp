#include <iostream>
using namespace std;


void TaskI() 
{
	int i=0,j=0,snp=0;
	
	while (true) {
		cout << "Enter num" << endl;
		cin >> snp;
		cout << endl;

		if (snp < 100) {
			break;
		}
		cout << "Your num bigger 100, try again" << endl;
	}

	double** mas = new double* [snp];


	for (i = 0;i < snp; i++) {
		mas[i] = new double[snp];

		for (int j = 0; j < snp; j++) {
		

			switch (abs(i - j)) {
			case 0:
				mas[i][j] = 0;
				break;
			case 1:
				mas[i][j] = 1;
				break;
			case 2:
				mas[i][j] = 2;
				break;
			case 3:
				mas[i][j] = 3;
				break;
			case 4:
				mas[i][j] = 4;
				break;
			case 5:
				mas[i][j] = 5;
				break;
			}

			//if (abs(i-j)==0) {
			//	mas[i][j] = 0;
			//	break;
			//}
			//else if (abs(i - j) == 1) {
			//	mas[i][j] = 1;
			//	break;
			//}
			//else if (abs(i - j) == 2) {
			//	mas[i][j] = 2;
			//	break;
			//}
			//else if (abs(i - j) == 3) {
			//	mas[i][j] = 3;
			//	break;
			//}
			//else if (abs(i - j) == 4) {
			//	mas[i][j] = 4;
			//	break;
			//}
			//else if (abs(i - j) == 5) {
			//	mas[i][j] = 5;
			//	break;
			//}
			cout << mas[i][j] << "\t";

		}

		cout << endl;

	}

}


void TaskII() {
    int srpX, srpY, i, j;

    while (true) {
        cout << "Enter X for mas: ";
        cin >> srpX;
        cout << "Enter y for mas: ";
        cin >> srpY;

        if (srpX <= 100 && srpY <= 100 && srpX > 0 && srpY > 0) {
            break;
        }
        cout << "nums must be between 1 and 100, try again" << endl;
    }

    double** mas = new double* [srpX];

    cout << "Enter array elements:" << endl;

    for (int i = 0; i < srpX; i++) {
        mas[i] = new double[srpY];
        for (int j = 0; j < srpY; j++) {
            cin >> mas[i][j];
        }
    }

    cout << "Enter column i to swap: ";
    cin >> i;
    cout << "Enter column j to swap: ";
    cin >> j;

    if (i < 0 || i >= srpY || j < 0 || j >= srpY) {
        cout << "Invalid column indices!" << endl;
        return;
    }

    for (int row = 0; row < srpX; row++) {
        swap(mas[row][i], mas[row][j]);
    }

    cout << "Result:" << endl;
    for (int i = 0; i < srpX; i++) {
        for (int j = 0; j < srpY; j++) {
            cout << mas[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < srpX; i++) {
        delete[] mas[i];
    }
    delete[] mas;
}

class Cinema {
private:
    int rows;
    int seatsPerRow;
    bool** hall;

public:
    Cinema() : rows(0), seatsPerRow(0), hall(nullptr) {}

    ~Cinema() {
        clearHall();
    }

    void createHall(int r, int s) {
        clearHall();
        rows = r;
        seatsPerRow = s;

        hall = new bool* [rows];
        for (int i = 0; i < rows; i++) {
            hall[i] = new bool[seatsPerRow];
            for (int j = 0; j < seatsPerRow; j++) {
                hall[i][j] = false;
            }
        }
        cout << "Cinema hall created with " << rows << " rows and " << seatsPerRow << " seats per row." << endl;
    }

    void addSeatsToAllRows(int numSeats) {
        if (hall == nullptr) {
            cout << "Hall not created yet!" << endl;
            return;
        }

        bool** newHall = new bool* [rows];
        for (int i = 0; i < rows; i++) {
            newHall[i] = new bool[seatsPerRow + numSeats];

            for (int j = 0; j < seatsPerRow; j++) {
                newHall[i][j] = hall[i][j];
            }
            
            for (int j = seatsPerRow; j < seatsPerRow + numSeats; j++) {
                newHall[i][j] = false;
            }
            delete[] hall[i];
        }
        delete[] hall;

        hall = newHall;
        seatsPerRow += numSeats;
        cout << "Added " << numSeats << " seats to all rows. Total seats per row: " << seatsPerRow << endl;
    }

    void addSeatsToRow(int row, int numSeats) {
        if (hall == nullptr || row < 0 || row >= rows) {
            cout << "Invalid row or hall not created!" << endl;
            return;
        }

        bool* newRow = new bool[seatsPerRow + numSeats];
        for (int j = 0; j < seatsPerRow; j++) {
            newRow[j] = hall[row][j];
        }
        for (int j = seatsPerRow; j < seatsPerRow + numSeats; j++) {
            newRow[j] = false;
        }

        delete[] hall[row];
        hall[row] = newRow;
        cout << "Added " << numSeats << " seats to row " << row << endl;
    }

    void removeSeatsFromAllRows(int numSeats) {
        if (hall == nullptr || numSeats >= seatsPerRow) {
            cout << "Cannot remove that many seats!" << endl;
            return;
        }

        bool** newHall = new bool* [rows];
        for (int i = 0; i < rows; i++) {
            newHall[i] = new bool[seatsPerRow - numSeats];
            for (int j = 0; j < seatsPerRow - numSeats; j++) {
                newHall[i][j] = hall[i][j];
            }
            delete[] hall[i];
        }
        delete[] hall;

        hall = newHall;
        seatsPerRow -= numSeats;
        cout << "Removed " << numSeats << " seats from all rows. Total seats per row: " << seatsPerRow << endl;
    }

    void removeRow(int row) {
        if (hall == nullptr || row < 0 || row >= rows) {
            cout << "Invalid row!" << endl;
            return;
        }

        bool** newHall = new bool* [rows - 1];
        int newIndex = 0;
        for (int i = 0; i < rows; i++) {
            if (i != row) {
                newHall[newIndex] = hall[i];
                newIndex++;
            }
            else {
                delete[] hall[i];
            }
        }
        delete[] hall;

        hall = newHall;
        rows--;
        cout << "Row " << row << " removed. Total rows: " << rows << endl;
    }

    void displayHall() {
        if (hall == nullptr) {
            cout << "Hall not created yet!" << endl;
            return;
        }

        cout << "\nCinema Hall (O=free, X=occupied):" << endl;
        for (int i = 0; i < rows; i++) {
            cout << "Row " << i << ": ";
            for (int j = 0; j < seatsPerRow; j++) {
                cout << (hall[i][j] ? "X " : "O ");
            }
            cout << endl;
        }
    }

    void bookSeat(int row, int seat) {
        if (hall == nullptr || row < 0 || row >= rows || seat < 0 || seat >= seatsPerRow) {
            cout << "Invalid seat!" << endl;
            return;
        }
        if (hall[row][seat]) {
            cout << "Seat already occupied!" << endl;
        }
        else {
            hall[row][seat] = true;
            cout << "Seat booked successfully!" << endl;
        }
    }

private:
    void clearHall() {
        if (hall != nullptr) {
            for (int i = 0; i < rows; i++) {
                delete[] hall[i];
            }
            delete[] hall;
            hall = nullptr;
        }
    }
};

void TaskIII() {
    Cinema cinema;
    int choice, rows, seats, num, row, seat;

    while (true) {
        cout << "\n=== Cinema Management System ===" << endl;
        cout << "1. Create hall" << endl;
        cout << "2. Add seats to all rows" << endl;
        cout << "3. Add seats to specific row" << endl;
        cout << "4. Remove seats from all rows" << endl;
        cout << "5. Remove row" << endl;
        cout << "6. Book seat" << endl;
        cout << "7. Display hall" << endl;
        cout << "0. Back to main menu" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of seats per row: ";
            cin >> seats;
            cinema.createHall(rows, seats);
            break;
        case 2:
            cout << "Enter number of seats to add: ";
            cin >> num;
            cinema.addSeatsToAllRows(num);
            break;
        case 3:
            cout << "Enter row number: ";
            cin >> row;
            cout << "Enter number of seats to add: ";
            cin >> num;
            cinema.addSeatsToRow(row, num);
            break;
        case 4:
            cout << "Enter number of seats to remove: ";
            cin >> num;
            cinema.removeSeatsFromAllRows(num);
            break;
        case 5:
            cout << "Enter row number to remove: ";
            cin >> row;
            cinema.removeRow(row);
            break;
        case 6:
            cout << "Enter row number: ";
            cin >> row;
            cout << "Enter seat number: ";
            cin >> seat;
            cinema.bookSeat(row, seat);
            break;
        case 7:
            cinema.displayHall();
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}

int main()
{
    srand(time(0));
    int userChoice = 0;

    while (true)
    {
        cout << "\nChoice task: " << endl;
        cout << " 1 - task I  " << endl;
        cout << " 2 - task II " << endl;
        cout << " 3 - task III" << endl;
        cout << "0 - exit" << endl;
        cout << "Your choice: ";

        cin >> userChoice;

        switch (userChoice) {
        case 1: TaskI(); break;
        case 2: TaskII(); break;
        case 3: TaskIII(); break;
        case 0: return 0;
        default:
            cout << "No such task. Please try again." << endl;
            break;
        }
    }
}