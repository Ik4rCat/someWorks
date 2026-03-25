#pragma once

#include <iostream>
#include <vector>
#include "Violation.h"

using namespace std;

class TreeNode {
private:
    string licensePlate;
    vector<Violation> violations;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(string licensePlate);
    
    string getLicensePlate() const;
    vector<Violation>& getViolations();
    TreeNode* getLeft();
    TreeNode* getRight();
    
    void setLeft(TreeNode* left);
    void setRight(TreeNode* right);
    
    void addViolation(Violation violation);
    int getViolationCount() const;
    double getTotalFines() const;
    
    void displayViolations() const;
};
