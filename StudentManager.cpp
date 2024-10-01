/*
    Author: Katherine Barrett
    Date: September 30, 2024
    Purpose: Create a console student management system to practice C++
*/

#include "StudentManager.h"
#include "Student.h"
#include <iostream>

void StudentManager::addStudent(){

    // Creates a new student object from the Student class
    Student newStudent;

    // Variables to hold info related to the new student object
    int id;
    std::string name;
    int age;
    std::string major;
    double gpa;

    // Set info about the student (id, name, age, major, gpa) from user input
    std::cout << "\nEnter student id: " << std::endl;
    std::cin >> id;
    std::cin.ignore(); // Ignore leftover newline
    newStudent.setId(id);

    std::cout << "Enter student name: " << std::endl;
    std::getline(std::cin, name);
    newStudent.setName(name);

    std::cout << "Enter student age: " << std::endl;
    std::cin >> age;
    std::cin.ignore(); // Ignore leftover newline
    newStudent.setAge(age);

    std::cout << "Enter student major: " << std::endl;
    std::getline(std::cin, major);
    newStudent.setMajor(major);

    std::cout << "Enter student gpa: " << std::endl;
    std::cin >> gpa;
    std::cin.ignore(); // Ignore leftover newline
    newStudent.setGpa(gpa);

    students.push_back(newStudent); // Add to the collection

    std::cout << "\nStudent added successfully!" << std::endl;

};

void StudentManager::displayAllStudents() {

    std::cout << "\nInformation about all students: " << std::endl;

    for (Student student: students) {
        std::cout << "\nId: " << student.getId() << "\n" 
                  << "Name: " << student.getName() << "\n"
                  << "Age: " << student.getAge() << "\n"
                  << "Major: " << student.getMajor() << "\n"
                  << "GPA: " << student.getGpa() << "\n"
                  << std::endl;
    }   
};

void StudentManager::deleteStudent() {

    int id;

    std::cout << "Please enter the Id of the student you would like to delete: " << std::endl;
    std::cin >> id; 

    bool isVerified = false;

    for (auto it = students.begin(); it != students.end(); it++)
        if (it->getId() == id ){
            students.erase(it);
            isVerified = true;
        }
    
    if (!isVerified){
        std::cout << "\nStudent id could not be verified\n" << std::endl;
    } else {
        std::cout << "\nStudent with id: " << id << " was removed." << std::endl;
    }

};