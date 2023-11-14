#include "Simulator.h"
#include <bits/stdc++.h>
//#include <iomanip>
//
////__________________(Load Program)__________________
//void Machine ::loadProgram(const string &filename ) {
//
//    int count = 0;
//    string line;
//    ifstream file;
//    file.open(filename);
//
//    if (!file.is_open()) {
//        cerr << "Error opening the file." << endl;
//    }
//
//    while (getline(file , line)){
//
//        stringstream hexacount;
//        hexacount >> hex >> count;
//        string hexaddress = (hexacount.str().size() == 2)? hexacount.str() : '0'+ hexacount.str();
//
//        mainmemory->instructios[count]=make_pair(hexaddress , line.substr(0 , 2));
//
//        count++;
//        hexacount >> hex >> count;
//        hexaddress = (hexacount.str().size() == 2)? hexacount.str() : '0'+ hexacount.str();
//
//        mainmemory->instructios[count] = make_pair(hexaddress , line.substr(2 , 2));
//        count++;
//    }
//}
//
//void Machine :: execute() {
//    char opcode;
//    char operad1;
//    string operad2;
//    int i;
//    for (i = 0; i < mainmemory->size; i+=2) {
//        IR = mainmemory->instructios[i].second + mainmemory->instructios[i+1].second;
//
//        opcode = IR[0];
//        operad1 = IR[1];
//        operad2 = IR.substr(2, 2);
//
//        instructions(opcode , operad1 , operad2, i);
//        if (!(i+2<mainmemory->size)){
//            ProgramCounter = mainmemory->instructios[i+2].first;
//        }
//    }
//}
//
//void Machine::instructions(char op, char o1, string o2,int& i) {
//
//    if(op == '1')
//    {
//        loadcontant(o1, o2);
//    }
//
//    else if(op == '2')
//    {
//       loadbit(o1 , o2);
//    }
//    else if(op == '3' && o2 == "00")
//    {
//        store00(o1);
//    }
//    else if(op == '3')
//    {
//        storeincell(o1 , o2);
//    }
//    else if(op == '4')
//    {
//        movecontant(o2);
//    }
//    else if(op == '5')
//    {
//        add(o1,o2);
//    }
//    else if(op == 'B')
//    {
//         jump(o1,o2,i);
//    }
//    else if(op == 'C')
//    {
//        Halt(i);
//    }
//
//}
//
////__________________(INSTRUCTIONS)_________________
//// Operation 1--------------
//void Machine :: loadcontant(char o1, string o2) {
//
//    int memindex = stoi(o2 , 0 , 16);
//    Register[to_string(o1)] = mainmemory->instructios[memindex].second;
//}
////Operation 2---------------
//void Machine :: loadbit(char o1 , string o2) {
//
//    Register[to_string(o1)] = o2;
//}
////Operation 3---------------
//void Machine ::storeincell(char o1 , string o2) {
//    int memindex = stoi(o2 , 0 , 16);
//    mainmemory->instructios[memindex].second = Register[to_string(o1)];
//}
////Operation 4---------------
//void Machine ::store00(char o1) {
//    cout << Register[to_string(o1)] << endl;
//}
////operation 5----------------
//void Machine ::movecontant(string o2){
//   Register [to_string(o2[1])] = Register[to_string(o2[0])];
//}
////operation 6----------------
//void Machine ::add(char o1 , string o2) {
//     int x =  stoi (Register [to_string(o2[1])]);
//     int y= stoi( Register[to_string(o2[0])]) ;
//    Register[to_string(o1)]=to_string(char (x)+char (y) - char(256));
//}
////Operation B---------------
//void Machine::jump(char o1, string o2,int i) {
//    if (Register[to_string(o1)] == Register["00"]) {
//        int memindex = stoi(o2, 0, 16);
//        i =memindex;
//    }
//
//}
////Operation C---------------
//void Machine ::Halt(int& i){
//    cout << "end of the program";
//    i = mainmemory->size;
//}
//
////__________________(Display)__________________
//void Machine :: displayStatus() {
//
//}
//
//memory::memory(int size) : n(size), instructios(size) {}
// cpu.cpp

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
CPU::CPU() {
    // Constructor logic if needed
    registers; // Assuming 8 registers
}

void CPU::executeInstructions(const Memory& memory) {
    const vector<pair<string, string>>& instructions = memory.getInstructions();
    char opcode;
    char operad1;
    string operad2;
    int i;
    for (i = 0; i < instructions.size(); i+=2) {
        IR = instructions[i].second + instructions[i+1].second;

        opcode = IR[0];
        operad1 = IR[1];
        operad2 = IR.substr(2, 2);

        Minstructions(opcode , operad1 , operad2,i, instructions);
        // if (!(i+2<mainmemory->size)){
        //   ProgramCounter = mainmemory->instructios[i+2];
        //}
    }
//    for (const auto& instruction : instructions) {
//        // Implement your instruction execution logic here
//        // For simplicity, let's just print the instruction for now
//        std::cout << "Executing: " << instruction.first << " " << instruction.second << std::endl;
//    }
}

void CPU::displayRegisters() const {
    for (auto item : registers) {
        std::cout << "Register " << item.first << ": " <<  item.second << std::endl;
    }
}

Memory::Memory() {
    // Constructor logic if needed
}

bool Memory::loadInstructionsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }
    int count=0;
    string line ;
    while (file >> line ) {
        stringstream hexacount,hex2;
        hexacount << hex << count;
        string hexaddress = (hexacount.str().size() == 2)? hexacount.str() : '0'+ hexacount.str();

        instructions.push_back( make_pair(hexaddress , line.substr(0 , 2)));

        count++;
        hex2 << hex << count;
        hexaddress = (hex2.str().size() == 2)? hex2.str() : '0'+ hex2.str();

        instructions.push_back(make_pair(hexaddress , line.substr(2 , 2)));
        count++;
        //  instructions.emplace_back(line.substr(0,2),line.substr(2,2));
    }

    file.close();
    return true;
}

const vector<pair<string, string>>& Memory::getInstructions() const {
    return instructions;
}

void CPU::Minstructions(char op, char o1, string o2, int &i,const vector<pair<string,string>>& k)  {

    if(op == '1')
    {
        loadcontant(o1, o2, k);
    }

    else if(op == '2')
    {
        loadbit(o1 , o2);
    }
    else if(op == '3' && o2 == "00")
    {
        store00(o1);
    }
    else if(op == '3')
    {
        storeincell(o1 , o2,k);
    }
    else if(op == '4')
    {
        movecontant(o2);
    }
    else if(op == '5')
    {
        add(o1,o2);
    }
    else if(op == 'B')
    {
        jump(o1,o2,i);
    }
    else if(op == 'C')
    {
        Halt(i,k);
    }

}

//__________________(INSTRUCTIONS)_________________
// Operation 1--------------
void CPU :: loadcontant(char o1, string o2,const vector<pair<string,string>>& lo) {

    int memindex = stoi(o2 , 0 , 16);
    registers[to_string(o1)] = lo[memindex].second;
}
//Operation 2---------------
void CPU :: loadbit(char o1 , string o2) {

    registers[to_string(o1)] = o2;
}
//Operation 3---------------
void CPU ::storeincell(char o1 , string o2,const vector<pair<string,string>>& st) {
    int memindex = stoi(o2 , 0 , 16);
    st[memindex].second = registers[to_string(o1)];
}
//Operation 4---------------
void CPU ::store00(char o1) {
    cout <<  registers[to_string(o1)] << endl;
}
//operation 5----------------
void CPU ::movecontant(string o2){
    registers[to_string(o2[1])] = registers[to_string(o2[0])];
}
//operation 6----------------
void CPU ::add(char o1 , string o2) {
    int x =  stoi (registers [to_string(o2[1])]);
    int y= stoi( registers[to_string(o2[0])]) ;
    registers[to_string(o1)]=to_string(char (x)+char (y) - char(256));
}
//Operation B---------------
void CPU::jump(char o1, string o2,int i) {
    if (registers[to_string(o1)] == registers["00"]) {
        int memindex = stoi(o2, 0, 16);
        i =memindex;
    }

}
//Operation C---------------
void CPU ::Halt(int& i,const vector<pair<string,string>>& hl){
    cout << "end of the program";
    i = hl.size();
}
