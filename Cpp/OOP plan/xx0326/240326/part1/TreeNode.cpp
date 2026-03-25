#include <iostream>
#include "TreeNode.h"
using namespace std;

TreeNode::TreeNode(string licensePlate) {
    this->licensePlate = licensePlate;
    left = nullptr;
    right = nullptr;
}

string TreeNode::getLicensePlate() const {
    return licensePlate;
}

vector<Violation>& TreeNode::getViolations() {
    return violations;
}

TreeNode* TreeNode::getLeft() {
    return left;
}

TreeNode* TreeNode::getRight() {
    return right;
}

void TreeNode::setLeft(TreeNode* left) {
    this->left = left;
}

void TreeNode::setRight(TreeNode* right) {
    this->right = right;
}

void TreeNode::addViolation(Violation violation) {
    violations.push_back(violation);
}

int TreeNode::getViolationCount() const {
    return violations.size();
}

double TreeNode::getTotalFines() const {
    double total = 0.0;
    for (const Violation& v : violations) {
        total += v.getFineAmount();
    }
    return total;
}

void TreeNode::displayViolations() const {
    cout << "License Plate: " << licensePlate << endl;
    cout << "Number of violations: " << violations.size() << endl;
    cout << "Total fines: $" << getTotalFines() << endl;
    cout << "Violations:" << endl;
    for (size_t i = 0; i < violations.size(); i++) {
        cout << "  [" << (i + 1) << "]" << endl;
        violations[i].display();
    }
    cout << "------------------------" << endl;
}
