/*
    Author: Katherine Barrett
    Date: September 30, 2024
    Purpose: Create a console student management system to practice C++
*/

#ifndef STUDENT_MANAGER_H // Start of include guard
#define STUDENT_MANAGER_H

#include "Student.h"
#include <vector>

class StudentManager {

private:
    std::vector<Student> students;


public:
    void addStudent();
    void editStudent();
    void displayAllStudents();
    void deleteStudent();
    
};

#endif // STUDENT_MANAGER_H // End of include guard
