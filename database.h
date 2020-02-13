#ifndef DATABASE_H
#define DATABASE_H
#include <sstream>
#include <vector>

namespace PLLKIA010 {
    
    //Data Members
    struct StudentRecord{
        std::string Name;
        std::string Surname;
        std::string StudentNumber;
        std::string ClassRecord;
    };

    extern std::vector<StudentRecord> database;

    //Methods

    void add_student(std::string name, std::string surname, std::string student_number, std::string class_record);
    void read_database(void);
    void save_database(void);
    StudentRecord& display_data(std::string student_number);
    double grade_student(std::string student_number);
    void clear(void);
}


#endif