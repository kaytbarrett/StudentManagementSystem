/*
    Author: Katherine Barrett
    Date: September 30, 2024
    Purpose: Create a console student management system to practice C++
*/

#ifndef STUDENT_H // Start of include guard
#define STUDENT_H

#include <string>

class Student {

private:
    int id;
    std::string name;
    int age;
    std::string major;
    double gpa;

public:

    // Setter methods for student info
    void setId(int id);
    void setName(const std::string& name);
    void setAge(int age);
    void setMajor(std::string& major);
    void setGpa(double gpa);
    
    // Getter method for student info
    int getId() const;
    std::string getName() const;
    int getAge() const;
    std::string getMajor() const;
    double getGpa() const;

    void addStudent(int id, const std::string& name, int age, std::string major, double gpa);
    void editStudent();

};

#endif // STUDENT_H // End of include guard