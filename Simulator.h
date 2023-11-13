
#ifndef OOP_ASSIGNMENT2_TASK3_SIMULATOR_H
#define OOP_ASSIGNMENT2_TASK3_SIMULATOR_H

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class memory;
class Machine{
private:
    memory* mainmemory;
    map<string , string> Register;
    string ProgramCounter = "00";

public:
    string IR;
    void loadProgram(const string& filename);
    void execute();
    void instructions(char op , char o1 , string o2);
    void loadcontant(char R , string address);
    void loadbit(char R , string pattern);
    void storeincell(char R , string address);
    void store00(char R);
    void displayStatus(); // Display the final status
};

class memory{
public:
    vector<pair<string , string>> insrtuctions;
    int size = insrtuctions.size();
};
#endif //OOP_ASSIGNMENT2_TASK3_SIMULATOR_H
