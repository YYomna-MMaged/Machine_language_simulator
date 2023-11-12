
#ifndef OOP_ASSIGNMENT2_TASK3_SIMULATOR_H
#define OOP_ASSIGNMENT2_TASK3_SIMULATOR_H

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Machine{
private:
    vector<pair<int , string>> Register;
    int programCounter;
    string IR;
public:
    void loadProgram(const string& filename);
//    void execute();
    void displayStatus(); // Display the final status
};

class execute{
private:
    int opcode;
    int operad1;
    int operad2;
public:
    void loadcontant();
    void loadbit();
    void storeincell();
};


class memory{

};
#endif //OOP_ASSIGNMENT2_TASK3_SIMULATOR_H
