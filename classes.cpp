#include "Simulator.h"
#include <bits/stdc++.h>
#include <iomanip>

//__________________(Load Program)__________________
void Machine ::loadProgram(const string &filename) {

    int count = 0;
    string line;
    ifstream file;
    file.open(filename);

    if (!file.is_open()) {
        cerr << "Error opening the file." << endl;
    }

    while (getline(file , line)){

        stringstream hexacount;
        hexacount >> hex >> count;
        string hexaddress = (hexacount.str().size() == 2)? hexacount.str() : '0'+ hexacount.str();

        mainmemory->insrtuctions[count] = make_pair(hexaddress , line.substr(0 , 2));

        count++;
        hexacount >> hex >> count;
        hexaddress = (hexacount.str().size() == 2)? hexacount.str() : '0'+ hexacount.str();

        mainmemory->insrtuctions[count] = make_pair(hexaddress , line.substr(2 , 2));
        count++;
    }
}

void Machine :: execute() {
    char opcode;
    char operad1;
    string operad2;

    for (int i = 0; i < mainmemory->size; i+=2) {
        IR = mainmemory->insrtuctions[i].second + mainmemory->insrtuctions[i+1].second;

        opcode = IR[0];
        operad1 = IR[1];
        operad2 = IR.substr(2, 2);

        instructions(opcode , operad1 , operad2);
    }
}

void Machine::instructions(char op, char o1, string o2) {

    if(op == '1')
    {
        loadcontant(o1, o2);
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
        storeincell(o1 , o2);
    }
    else if(op == '4')
    {
        // code
    }
    else if(op == '5')
    {
        // code
    }
    else if(op == 'B')
    {
        // code
    }
    else if(op == 'C')
    {
        // code
    }

}

//__________________(INSTRUCTIONS)_________________
// Operation 1--------------
void Machine :: loadcontant(char o1, string o2) {

    int memindex = stoi(o2 , 0 , 16);
    Register[to_string(o1)] = mainmemory->insrtuctions[memindex].second;

}
//Operation 2---------------
void Machine :: loadbit(char o1 , string o2) {

    Register[to_string(o1)] = o2;
}
//Operation 3---------------
void Machine ::storeincell(char o1 , string o2) {
    int memindex = stoi(o2 , 0 , 16);
    mainmemory->insrtuctions[memindex].second = Register[to_string(o1)];
}
//Operation 4---------------
void Machine ::store00(char o1) {

}