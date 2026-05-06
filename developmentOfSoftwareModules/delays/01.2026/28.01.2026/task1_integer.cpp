#include <iostream>
using namespace std;

class Integer {
  private:
    int value;
  public:
    Integer() {
        value = 0;
        cout << "Объект Integer создан!" << endl;
    }

    void set(int v) { value = v; }
    int get() { return value; }
    void show() { cout << "Значение: " << value << endl; }
};

int main() {
    Integer obj;
    obj.set(42);
    obj.show();
    cout << "get(): " << obj.get() << endl;
    return 0;
}
