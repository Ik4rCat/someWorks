#pragma once

#include <iostream>
#include "TreeNode.h"

using namespace std;

class TrafficPoliceDB {
private:
    TreeNode* root;
    int nodeCount;
    
    TreeNode* insert(TreeNode* node, string licensePlate, Violation violation);
    TreeNode* search(TreeNode* node, string licensePlate);
    void inorderPrint(TreeNode* node);
    void rangeSearch(TreeNode* node, string startPlate, string endPlate);
    void destroyTree(TreeNode* node);

public:
    TrafficPoliceDB();
    ~TrafficPoliceDB();
    
    void addViolation(string licensePlate, Violation violation);
    TreeNode* findCar(string licensePlate);
    void printAll();
    void printByRange(string startPlate, string endPlate);
    int getNodeCount() const;
    bool isEmpty() const;
};
