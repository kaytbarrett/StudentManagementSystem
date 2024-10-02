/*
    Author: Katherine Barrett
    Date: September 30, 2024
    Purpose: Create a console student management system to practice C++
*/

#include "Student.h"

void Student::setId(int id) {
    this->id = id;
};

void Student::setName(const std::string& name) {
    this->name = name;
};

void Student::setAge(int age){
    this->age = age;
};

void Student::setMajor(std::string& major){
    this->major = major;
};

void Student::setGpa(double gpa){
    this->gpa = gpa;
};

int Student::getId() const {
    return id;
};

std::string Student::getName() const {
    return name;
};

int Student::getAge() const {
    return age;
};

std::string Student::getMajor() const {
    return major;
};

double Student::getGpa() const {
    return gpa;
};

void Student::addStudent(int id, const std::string& name, int age, std::string major, double gpa){
    this->id = id;
    this->name = name;
    this->age = age;
    this->major = major;
    this->gpa = gpa;
};