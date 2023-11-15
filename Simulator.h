
#ifndef OOP_ASSIGNMENT2_TASK3_SIMULATOR_H
#define OOP_ASSIGNMENT2_TASK3_SIMULATOR_H

#include <iostream>
#include <bits/stdc++.h>
#include <utility>
//
//using namespace std;
//class memory;
//class Machine{
//private:
//    memory* mainmemory;
//    map<string , string> Register;
//    string ProgramCounter = "00";
//
//public:
//    //Machine(memory& mainmemory):mainmemory(),Register(),ProgramCounter(){};
//    string IR;
//    void loadProgram(const string& filename );
//    void execute();
//    void instructions(char op , char o1 , string o2 , int& i);
//    void loadcontant(char R , string address);
//    void loadbit(char R , string pattern);
//    void storeincell(char R , string address);
//    void store00(char R);
//    void movecontant(string address );
//    void add(char R,string address);
//    void jump(char R,string addrass,int cou);
//    void Halt(int& end);
//    void displayStatus(); // Display the final status
//};
//
//class memory{
//private:
//    int n = 256;
//public:
//    vector<pair<string , string>> instructios;
//    int size;
//    memory(int size = 256);
//    memory(){
//        instructios.resize(256);
//    }
//};
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <utility>
using namespace std;
class Memory;
class CPU {
private:
    map<string ,string >registers;
    string IR ="00";
public:
    CPU();
    void executeInstructions(const Memory& memory);
    void displayRegisters() const;
    void Minstructions(char op , char o1 , string o2 , int& i,const vector<pair<string,string>>& k);
    void loadcontant(char R , string address,const vector<pair <string,string>>& lo);
    void loadbit(char R , string pattern);
    void storeincell(char R , string address, vector<pair<string,string>>& st);
    void store00(char R);
    void movecontant(string address );
    void add(char R,string address);
    void jump(char R,string addrass,int cou);
    void Halt(int& end,const vector<pair<string ,string>>& hl);
    void displayStatus();
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

