#pragma once

#include "Document.h"
#include <iostream>
#include <vector>

using namespace std;

class ExcelDocument : public Document {
private:
    int rowCount;
    int columnCount;
    vector<vector<double>> data;
    
public:
    ExcelDocument() : Document(), rowCount(0), columnCount(0) {}
    ExcelDocument(string name, int pages, int rows, int cols)
        : Document(name, pages), rowCount(rows), columnCount(cols) {
        data.resize(rows, vector<double>(cols, 0.0));
    }
    
    void create() override {
        cout << "Creating Excel document: " << fileName << endl;
        cout << "Grid size: " << rowCount << "x" << columnCount << endl;
        cout << "Total cells: " << (rowCount * columnCount) << endl;
    }
    
    void open() override {
        cout << "Opening Excel: " << fileName << endl;
        cout << "Loading spreadsheet data" << endl;
    }
    
    void save() override {
        cout << "Saving Excel document: " << fileName << ".xlsx" << endl;
        cout << "Rows saved: " << rowCount << endl;
    }
    
    string getType() const override {
        return "Excel";
    }
    
    void setCell(int row, int col, double value) {
        if (row >= 0 && row < rowCount && col >= 0 && col < columnCount) {
            data[row][col] = value;
        }
    }
    
    double getCell(int row, int col) const {
        if (row >= 0 && row < rowCount && col >= 0 && col < columnCount) {
            return data[row][col];
        }
        return 0.0;
    }
    
    void calculate() {
        cout << "Calculating formulas..." << endl;
        cout << "Excel calculations completed" << endl;
    }
};
