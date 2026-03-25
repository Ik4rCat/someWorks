#include <iostream>
#include "TrafficPoliceDB.h"

using namespace std;

TrafficPoliceDB::TrafficPoliceDB() {
    root = nullptr;
    nodeCount = 0;
}

TrafficPoliceDB::~TrafficPoliceDB() {
    destroyTree(root);
}

TreeNode* TrafficPoliceDB::insert(TreeNode* node, string licensePlate, Violation violation) {
    if (node == nullptr) {
        nodeCount++;
        TreeNode* newNode = new TreeNode(licensePlate);
        newNode->addViolation(violation);
        return newNode;
    }
    
    if (licensePlate < node->getLicensePlate()) {
        node->setLeft(insert(node->getLeft(), licensePlate, violation));
    } else if (licensePlate > node->getLicensePlate()) {
        node->setRight(insert(node->getRight(), licensePlate, violation));
    } else {
        node->addViolation(violation);
    }
    
    return node;
}

TreeNode* TrafficPoliceDB::search(TreeNode* node, string licensePlate) {
    if (node == nullptr || node->getLicensePlate() == licensePlate) {
        return node;
    }
    
    if (licensePlate < node->getLicensePlate()) {
        return search(node->getLeft(), licensePlate);
    } else {
        return search(node->getRight(), licensePlate);
    }
}

void TrafficPoliceDB::inorderPrint(TreeNode* node) {
    if (node != nullptr) {
        inorderPrint(node->getLeft());
        node->displayViolations();
        inorderPrint(node->getRight());
    }
}

void TrafficPoliceDB::rangeSearch(TreeNode* node, string startPlate, string endPlate) {
    if (node == nullptr) {
        return;
    }
    
    if (startPlate < node->getLicensePlate()) {
        rangeSearch(node->getLeft(), startPlate, endPlate);
    }
    
    if (node->getLicensePlate() >= startPlate && node->getLicensePlate() <= endPlate) {
        node->displayViolations();
    }
    
    if (endPlate > node->getLicensePlate()) {
        rangeSearch(node->getRight(), startPlate, endPlate);
    }
}

void TrafficPoliceDB::destroyTree(TreeNode* node) {
    if (node != nullptr) {
        destroyTree(node->getLeft());
        destroyTree(node->getRight());
        delete node;
    }
}

void TrafficPoliceDB::addViolation(string licensePlate, Violation violation) {
    root = insert(root, licensePlate, violation);
}

TreeNode* TrafficPoliceDB::findCar(string licensePlate) {
    return search(root, licensePlate);
}

void TrafficPoliceDB::printAll() {
    if (root == nullptr) {
        cout << "Database is empty" << endl;
        return;
    }
    cout << "\n========== ALL VIOLATIONS DATABASE ==========" << endl;
    inorderPrint(root);
    cout << "Total cars in database: " << nodeCount << endl;
}

void TrafficPoliceDB::printByRange(string startPlate, string endPlate) {
    if (root == nullptr) {
        cout << "Database is empty" << endl;
        return;
    }
    cout << "\n========== VIOLATIONS IN RANGE: " 
         << startPlate << " - " << endPlate << " ==========" << endl;
    rangeSearch(root, startPlate, endPlate);
}

int TrafficPoliceDB::getNodeCount() const {
    return nodeCount;
}

bool TrafficPoliceDB::isEmpty() const {
    return root == nullptr;
}
