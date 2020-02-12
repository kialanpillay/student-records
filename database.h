#ifndef DATABASE_H
#define DATABASE_H
#include <sstream>
#include <vector>

using namespace std;

namespace PLLKIA010 {
    void add_student(string name, string surname, string student_number, string class_record);
    ostringstream& read_database(void);
    void save_database(vector<string> &student_records);
    ostringstream& display_data(string student_number);
    double grade_student(string student_number);
    void clear(void);
}


#endif