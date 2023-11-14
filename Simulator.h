
#ifndef OOP_ASSIGNMENT2_TASK3_SIMULATOR_H
#define OOP_ASSIGNMENT2_TASK3_SIMULATOR_H

#include <iostream>
#include <bits/stdc++.h>
#include <utility>

using namespace std;
class memory;
class Machine{
private:
    memory* mainmemory;
    map<string , string> Register;
    string ProgramCounter = "00";

public:
    //Machine(memory& mainmemory):mainmemory(),Register(),ProgramCounter(){};
    string IR;
    void loadProgram(const string& filename );
    void execute();
    void instructions(char op , char o1 , string o2 , int& i);
    void loadcontant(char R , string address);
    void loadbit(char R , string pattern);
    void storeincell(char R , string address);
    void store00(char R);
    void movecontant(string address );
    void add(char R,string address);
    void jump(char R,string addrass,int cou);
    void Halt(int& end);
    void displayStatus(); // Display the final status
};

class memory{
private:
    int n = 256;
public:
    vector<pair<string , string>> instructios;
    int size;
    memory(int size = 256);
    memory(){
        instructios.resize(256);
    }
};
#endif //OOP_ASSIGNMENT2_TASK3_SIMULATOR_H
