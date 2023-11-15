// File: A2_Task3_S19_20221196-20221062-20221041.cpp
// Purpose: Design simulating the machine language
// Author: Yomna Maged Ali 20221196
//         Rawan Amr Nabil 20221062
//         Tasnem Mamdoh 20221041
// Section: S19
// TA: Mohamed Talaat

#include <iostream>
#include <bits/stdc++.h>
#include "Simulator.h"
using namespace std;


int main (){
    Memory memory;
    cout << "select 0 or 1 :" << endl
         << "0 --> Display at the end of program execution" << endl
         << "1 --> Display after each step" << endl;
    int flag;
    cin >> flag;
    while (flag != 1 && flag != 0){
        cout << "Selection not available" << endl;
        cin >> flag;
    }

    if (memory.loadInstructionsFromFile("test.txt")) {
        CPU cpu;
        cpu.executeInstructions(memory,flag);
    }
    return 0;
}
