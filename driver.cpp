#include <iostream>
#include "database.h"

using namespace std;

int main (void)
{
    cout << "0: Add student\n1: Read database\n2: Save database\n3: Display data\n4: Grade student\nq: quit" << endl;
    for (;;) { 
        cout << "Enter a number (or q to quit) and press return..." << endl;
        string option;
        cin >> option;
        if (option == "q") break;
    }
    
    return 0;
}