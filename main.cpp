// File: A2_Task3_S19_20221196-20221062-20221041.cpp
// Purpose:
// Author: Yomna Maged Ali 20221196
//         Rawan Amr Nabil 20221062
//         Tasnem Mamdoh 20221041
// Section: S19
// TA: Mohamed Talaat

#include <iostream>
#include <bits/stdc++.h>
#include "Simulator.h"
using namespace std;


int main() {
    Memory memory;
    if (memory.loadInstructionsFromFile("test.txt")) {
        CPU cpu;
        cpu.executeInstructions(memory);
        cpu.displayRegisters();
    }

    return 0;
}
