#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Equation {
protected:
    string name;
public:
    Equation(const string& n = "Equation") : name(n) {}
    virtual ~Equation() = default;
    virtual void findRoots() const = 0;
    virtual void display() const = 0;
    string getName() const { return name; }
};

class LinearEquation : public Equation {
private:
    double a, b;
public:
    LinearEquation(double coefA, double coefB) 
        : Equation("Linear Equation"), a(coefA), b(coefB) {}
    
    void findRoots() const override {
        cout << "\n" << name << ": " << a << "x + " << b << " = 0" << endl;
        if (a == 0) {
            if (b == 0) {
                cout << "Infinite solutions" << endl;
            } else {
                cout << "No solution" << endl;
            }
        } else {
            double x = -b / a;
            cout << "Root: x = " << x << endl;
        }
    }
    
    void display() const override {
        cout << name << ": " << a << "x + " << b << " = 0" << endl;
    }
};

class QuadraticEquation : public Equation {
private:
    double a, b, c;
public:
    QuadraticEquation(double coefA, double coefB, double coefC) 
        : Equation("Quadratic Equation"), a(coefA), b(coefB), c(coefC) {}
    
    void findRoots() const override {
        cout << "\n" << name << ": " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
        double d = b * b - 4 * a * c;
        cout << "Discriminant: D = " << d << endl;
        
        if (d > 0) {
            double x1 = (-b + sqrt(d)) / (2 * a);
            double x2 = (-b - sqrt(d)) / (2 * a);
            cout << "Two roots:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        } else if (d == 0) {
            double x = -b / (2 * a);
            cout << "One root: x = " << x << endl;
        } else {
            cout << "No real roots" << endl;
            cout << "Complex roots:" << endl;
            double real = -b / (2 * a);
            double imag = sqrt(-d) / (2 * a);
            cout << "x1 = " << real << " + " << imag << "i" << endl;
            cout << "x2 = " << real << " - " << imag << "i" << endl;
        }
    }
    
    void display() const override {
        cout << name << ": " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
    }
};

class Shape {
protected:
    string type;
public:
    Shape(const string& t = "Shape") : type(t) {}
    virtual ~Shape() = default;
    virtual void Show() const = 0;
    virtual void Save(ofstream& file) const = 0;
    virtual void Load(ifstream& file) = 0;
    string getType() const { return type; }
};

class Square : public Shape {
private:
    double x, y;
    double side;
public:
    Square(double xCoord = 0, double yCoord = 0, double s = 1) 
        : Shape("Square"), x(xCoord), y(yCoord), side(s) {}
    
    void Show() const override {
        cout << "Square: Top-Left(" << x << ", " << y 
             << "), Side = " << side 
             << ", Area = " << side * side << endl;
    }
    
    void Save(ofstream& file) const override {
        file << "Square\n";
        file << x << " " << y << " " << side << "\n";
    }
    
    void Load(ifstream& file) override {
        file >> x >> y >> side;
    }
};

class Rectangle : public Shape {
private:
    double x, y;
    double width;
    double height;
public:
    Rectangle(double xCoord = 0, double yCoord = 0, double w = 1, double h = 1) 
        : Shape("Rectangle"), x(xCoord), y(yCoord), width(w), height(h) {}
    
    void Show() const override {
        cout << "Rectangle: Top-Left(" << x << ", " << y 
             << "), Width = " << width << ", Height = " << height
             << ", Area = " << width * height << endl;
    }
    
    void Save(ofstream& file) const override {
        file << "Rectangle\n";
        file << x << " " << y << " " << width << " " << height << "\n";
    }
    
    void Load(ifstream& file) override {
        file >> x >> y >> width >> height;
    }
};

class Circle : public Shape {
private:
    double centerX, centerY;
    double radius;
public:
    Circle(double x = 0, double y = 0, double r = 1) 
        : Shape("Circle"), centerX(x), centerY(y), radius(r) {}
    
    void Show() const override {
        cout << "Circle: Center(" << centerX << ", " << centerY 
             << "), Radius = " << radius
             << ", Area = " << 3.14159 * radius * radius << endl;
    }
    
    void Save(ofstream& file) const override {
        file << "Circle\n";
        file << centerX << " " << centerY << " " << radius << "\n";
    }
    
    void Load(ifstream& file) override {
        file >> centerX >> centerY >> radius;
    }
};

class Ellipse : public Shape {
private:
    double x, y;
    double width;
    double height;
public:
    Ellipse(double xCoord = 0, double yCoord = 0, double w = 2, double h = 1) 
        : Shape("Ellipse"), x(xCoord), y(yCoord), width(w), height(h) {}
    
    void Show() const override {
        cout << "Ellipse: Top-Left(" << x << ", " << y 
             << "), Width = " << width << ", Height = " << height
             << ", Area ≈ " << 3.14159 * (width/2) * (height/2) << endl;
    }
    
    void Save(ofstream& file) const override {
        file << "Ellipse\n";
        file << x << " " << y << " " << width << " " << height << "\n";
    }
    
    void Load(ifstream& file) override {
        file >> x >> y >> width >> height;
    }
};

void testTask1() {
    cout << "\n========== TASK 1 ==========\n";
    LinearEquation eq1(2, -4);
    LinearEquation eq2(0, 5);
    LinearEquation eq3(0, 0);
    eq1.findRoots();
    eq2.findRoots();
    eq3.findRoots();

    QuadraticEquation eq4(1, -5, 6);
    QuadraticEquation eq5(1, -4, 4);
    QuadraticEquation eq6(1, 2, 5);
    eq4.findRoots();
    eq5.findRoots();
    eq6.findRoots();
}

void testTask2() {
    cout << "\n========== TASK 2 ==========\n";
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Square>(0, 0, 5));
    shapes.push_back(make_unique<Rectangle>(1, 2, 4, 6));
    shapes.push_back(make_unique<Circle>(3, 3, 2.5));
    shapes.push_back(make_unique<Ellipse>(0, 0, 6, 4));

    cout << "\nOriginal shapes:" << endl;
    for (const auto& shape : shapes) {
        shape->Show();
    }

    cout << "\nSaving shapes to file..." << endl;
    ofstream outFile("shapes.txt");
    if (outFile.is_open()) {
        outFile << shapes.size() << "\n";
        for (const auto& shape : shapes) {
            shape->Save(outFile);
        }
        outFile.close();
        cout << "Saved!" << endl;
    }

    cout << "\nLoading shapes from file..." << endl;
    vector<unique_ptr<Shape>> loadedShapes;
    ifstream inFile("shapes.txt");
    if (inFile.is_open()) {
        size_t count;
        inFile >> count;
        for (size_t i = 0; i < count; i++) {
            string type;
            inFile >> type;
            if (type == "Square") {
                auto square = make_unique<Square>();
                square->Load(inFile);
                loadedShapes.push_back(move(square));
            } else if (type == "Rectangle") {
                auto rect = make_unique<Rectangle>();
                rect->Load(inFile);
                loadedShapes.push_back(move(rect));
            } else if (type == "Circle") {
                auto circle = make_unique<Circle>();
                circle->Load(inFile);
                loadedShapes.push_back(move(circle));
            } else if (type == "Ellipse") {
                auto ellipse = make_unique<Ellipse>();
                ellipse->Load(inFile);
                loadedShapes.push_back(move(ellipse));
            }
        }
        inFile.close();
        cout << "Loaded!" << endl;
    }

    cout << "\nLoaded shapes:" << endl;
    for (const auto& shape : loadedShapes) {
        shape->Show();
    }
}

int main() {
    testTask1();
    testTask2();
    return 0;
}