#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include "database.h"

using namespace std;

std::vector<PLLKIA010::StudentRecord> PLLKIA010::database = {};

void PLLKIA010::add_student(string name, string surname, string student_number, string class_record)
{
    bool exists = false;
    int count, index = 0;
    for(PLLKIA010::StudentRecord r : PLLKIA010::database)
    {
        if(r.StudentNumber == student_number)
        {
            exists = true;
            index = count;
        }
        count++;

    }
    if(exists)
    {
        PLLKIA010::StudentRecord record = {
            name,
            surname,
            student_number,
            class_record,
        };
        database[index] = record;
    }
    else
    {
        PLLKIA010::StudentRecord record = {
            name,
            surname,
            student_number,
            class_record,
        };
        database.push_back(record);  
    }
     

    
}

void PLLKIA010::read_database(void)
{   
    ifstream file("database.txt"); // argument is ‘‘char*’’ NOT String
    
    string str, value; 
    while (getline(file, str))
    {
        PLLKIA010::StudentRecord record = {};
        string line = str;
        istringstream iss(line);
        iss >> record.Name >> record.Surname >> record.StudentNumber;
        while (!iss.eof())
        {
            iss >> value;
            record.ClassRecord += value + " ";
        }
        string formattedRecord = record.ClassRecord.substr(0,record.ClassRecord.length()-1);
        record.ClassRecord = formattedRecord;
        database.push_back(record);
    };
}

void PLLKIA010::save_database(void){
    ofstream file("database.txt"); // argument is ‘‘char*’’ NOT String
    for(PLLKIA010::StudentRecord r : PLLKIA010::database)
    {
        file << r.Name << " " << r.Surname << " " << r.StudentNumber << " " << r.ClassRecord << '\n';
    } 
    file.close();
}

PLLKIA010::StudentRecord PLLKIA010::display_data(string student_number)
{
    PLLKIA010::StudentRecord record = {};
    for(PLLKIA010::StudentRecord r : PLLKIA010::database)
    {
        if(r.StudentNumber == student_number)
        {
            record = {
                r.Name,
                r.Surname,
                r.StudentNumber,
                r.ClassRecord,
            };
        }

    }
     
    return record;
        
}

double PLLKIA010::grade_student(string student_number)
{
    int total_grade, count, value = 0;
    PLLKIA010::StudentRecord record = {};
    for(PLLKIA010::StudentRecord r : PLLKIA010::database)
    {
        if(r.StudentNumber == student_number)
        {
            record = r;
        }

    }
    if(record.ClassRecord != ""){ //If record is found in Vector, thus field is not-empty
        istringstream iss(record.ClassRecord);
        cout << iss.str();
        while (!iss.eof())
        {
            iss >> value;
            total_grade += value;
            count++;
        }
        double average = total_grade/count;
        return average;
    }
    return 0; //If no student found return 0


}

void PLLKIA010::clear(void)
{
    system("clear"); 
}