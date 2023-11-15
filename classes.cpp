#include "Simulator.h"
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

//__________________(Constructors)__________________
CPU::CPU() {
    ProgramCounter = "00";
}

Memory::Memory() {}

//__________________(Load Program)__________________

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
    }

    file.close();
    return true;
}

//__________________(Execute Instructions)__________________

const vector<pair<string, string>>& Memory::getInstructions() const {
    return instructions;
}

void CPU::executeInstructions(const Memory& memory,int print) {
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

        Menu_of_instructions(opcode, operad1, operad2, i, instructions);
        if ((i+2<instructions.size())){
            ProgramCounter = instructions[i+2].first;
        }
        if (print ==1){
            cout << "_______________________________________" << endl;
            cout <<"content of IR ="<< IR <<'\n'<<"ProgramCounter ="<<ProgramCounter<<endl;
            cout << "_______________________________________" << endl;

            displaystatue(instructions);
        }
    }

    if(!print)
    {
        cout << "_______________________________________" << endl;
        cout <<"content of IR ="<< IR <<'\n'<<"ProgramCounter ="<<ProgramCounter<<endl;
        cout << "_______________________________________" << endl;

        displaystatue(instructions);
    }
}
void CPU::Menu_of_instructions(char op, char o1, string o2, int &i, const vector<pair<string,string>>& k)  {

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
        storeincell(o1 , o2, const_cast<vector<pair<std::string, std::string>> &>(k));
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
    string x = "0";
    x.push_back(o1);
    registers[x] = lo[memindex].second;
}

//Operation 2---------------
void CPU :: loadbit(char o1 , string o2) {
    string x = "0";
    x.push_back(o1);
    registers[x] = o2;
}

//Operation 3---------------
void CPU ::storeincell(char o1 , string o2, vector<pair<string,string>>& st) {
    int memindex = stoi(o2 , 0 , 16);
    string x = "0";
    x.push_back(o1);
    st[memindex].second = x;
}

//Operation 4---------------
void CPU ::store00(char o1) {
    string x = "0";
    x.push_back(o1);
    cout <<  registers[x] << endl;
}

//operation 5----------------
void CPU ::movecontant(string o2){
    string x = "0";
    x.push_back(o2[1]);
    string y = "0";
    x.push_back(o2[0]);
    registers[x] = registers[y];
}
//operation 6----------------
void CPU ::add(char o1 , string o2) {
    string ind = "0";
    ind.push_back(o2[1]);
    string ind2 = "0";
    ind2.push_back(o2[0]);

    int x =  stoi (registers [ind]);
    int y= stoi( registers[ind2]) ;
    string rind = "0";
    rind.push_back(o1);
    int num=char (x)+char (y) - char(256);
    stringstream take ;
    take << hex << num;
    string result = (take.str().size() == 2)? take.str() : '0'+ take.str();
    registers[rind]=result;
}

//Operation B---------------
void CPU::jump(char o1, string o2,int i) {
    string x = "0";
    x.push_back(o1);
    if (registers[x] == registers["00"]) {
        int memindex = stoi(o2, 0, 16);
        i =memindex;
    }

}

//Operation C---------------
void CPU ::Halt(int& i,const vector<pair<string,string>>& hl){
//    cout << "end of the program" << endl;

    i = hl.size();
}

//__________________(Display)_________________


void CPU::displaystatue (const vector<pair< string ,string>>  &pr ) {
    cout << "_______________Registers_______________" << endl;
    for (auto item : registers) {
        std::cout << "Register " << item.first << ": " <<  item.second << std::endl;
    }

    cout << "______________Memory___________________" << endl;
    for (int i=0;i<pr.size();i++){
        cout<< "memory "<< pr[i].first<<":"<<pr[i].second<<endl;
    }
}








//    for (const auto& instruction : instructions) {
//        // Implement your instruction execution logic here
//        // For simplicity, let's just print the instruction for now
//        std::cout << "Executing: " << instruction.first << " " << instruction.second << std::endl;
//    }


//            registers[to_string(o1)];
