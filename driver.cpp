#include <iostream>
#include "database.h"

using namespace std;
using namespace PLLKIA010;

int main (void)
{
    bool readDB = false;
    for (;;) { 
        cout << "0: Add student\n1: Read database\n2: Save database\n3: Display data\n4: Grade student\nq: quit" << endl;
        cout << "Enter a number (or q to quit) and press return...\n" << endl;
        string option;
        cin >> option;
        if(option == "0")
        {
            string name, surname, student_number, grade, student_record;
            cout << "Enter the name of the student:" << endl;
            cin >> name;
            cout << "Enter the surname of the student:" << endl;
            cin >> surname;
            cout << "Enter the student number of the student:" << endl;
            cin >> student_number;

            cout << "Enter grades for the student (or q to quit)" << endl;
            cin >> grade;
            while(grade != "q"){
                student_record.append(grade);
                student_record.append(" ");
                cin >> grade;
            };
            student_record = student_record.substr(0,student_record.length()-1);
            cout << endl;
            add_student(name, surname, student_number, student_record);

        }
        else if(option == "1")
        {   
            if(readDB)
            {
                cout << "Database already read in!\n" << endl;
            }
            else
            {
                read_database();
                cout << "Database read!\n" << endl; 
                readDB = true;
            }
            
        }
        else if(option == "2")
        {
            save_database();
            cout << "Database saved!\n" << endl;
        }
        else if(option == "3")
        {
            string student_number;
            cout << "Enter the student number of the student:" << endl;
            cin >> student_number;
            PLLKIA010::StudentRecord record = {};
            cout << record.Name;
            record = display_data(student_number);
            if(record.StudentNumber != "")
            {
                cout << "\nRecord: " <<record.Name << " " << record.Surname << " " << record.StudentNumber << " " << record.ClassRecord  << "\n"<< endl;
            }
            else
            {
                cout << "Student does not exist in database!\n" << endl;
            }
            
            
        }
        else if(option == "4")
        {
            string student_number;
            cout << "Enter the student number of the student:" << endl;
            cin >> student_number;
            double average = grade_student(student_number);
            if (average == 0)
            {
                cout << "Student does not exist in database!\n" << endl;
            }
            else
            {
                cout << "Average Grade: " << average << "\n" << endl;
            }
            
        }
        if (option == "q") break;
    }
    clear();
    
    return 0;
}