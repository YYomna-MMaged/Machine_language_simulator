
#ifndef OOP_ASSIGNMENT2_TASK3_SIMULATOR_H
#define OOP_ASSIGNMENT2_TASK3_SIMULATOR_H

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Memory;
class CPU {
private:
    map<string ,string >registers;
    string IR ="00";
    string ProgramCounter;
public:
    CPU();
    void executeInstructions(const Memory& memory,int print );
//    void displayRegisters() const;
    void Menu_of_instructions(char op , char o1 , string o2 , int& i, const vector<pair<string,string>>& k);
    void loadcontant(char R , string address,const vector<pair <string,string>>& lo);
    void loadbit(char R , string pattern);
    void storeincell(char R , string address, vector<pair<string,string>>& st);
    void store00(char R);
    void movecontant(string address );
    void add(char R,string address);
    void jump(char R,string addrass,int cou);
    void Halt(int& end,const vector<pair<string ,string>>& hl);
    void displayStatus();
    void displayRegistersandMemory(const vector<pair< string ,string>>&pr );
};

class Memory {
private:
    vector<pair< string ,string>> instructions;

public:
    Memory();
    bool loadInstructionsFromFile(const std::string& filename);
    const vector<pair<string ,string>>& getInstructions() const;
};

#endif //OOP_ASSIGNMENT2_TASK3_SIMULATOR_H

