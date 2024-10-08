/*
    Author: Katherine Barrett
    Date: September 30, 2024
    Purpose: Create a console student management system to practice C++
*/

#include "StudentManager.h"
#include "Student.h"
#include <iostream>
#include <fstream>
#include <sstream>

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

void StudentManager::editStudent(){

    int id;

    std::cout << "Please enter the id of the student you wish to edit: " << std::endl;
    std::cin >> id;

    bool isVerified = false;

    for (auto it = students.begin(); it != students.end(); it++){
        if (it->getId() == id){
            isVerified = true;

            int choice;

            do {
                std::cout << "\n1. Edit Name\n"
                            << "2. Edit Age\n"
                            << "3. Edit Major\n"
                            << "4. Edit GPA\n"
                            << "5. Exit\n\n"
                            << "Choose an option: ";
                std::cin >> choice;
                std::cin.ignore();

                switch (choice) {
                    case 1:{
                        std::string newName;
                        std::cout << "\nEnter new student name: (currently: " << it->getName() << "): " << std::endl;
                        std::getline(std::cin, newName);
                        it->setName(newName);
                        break;
                    }
                    case 2:{
                        int newAge;
                        std::cout << "\nEnter new student age: (currently: " << it->getAge() << "): " << std::endl;
                        std::cin >> newAge;
                        std::cin.ignore();
                        it->setAge(newAge);
                        break;
                    }
                    case 3:{
                        std::string newMajor;
                        std::cout << "\nEnter new student major (currently: " << it->getMajor() << "): " << std::endl;
                        std::getline(std::cin, newMajor);
                        it->setMajor(newMajor);
                        break;
                    }
                    case 4:{
                        int newGpa;
                        std::cout << "\nEnter new student GPA: (currently: " << it->getGpa() << "): " << std::endl;
                        std::cin >> newGpa;
                        std::cin.ignore();
                        it->setAge(newGpa);
                        break;
                    }
                    case 5:
                        std::cout << "Exiting..." << std::endl;
                        break;
                    default:
                        std::cout << "\nInvalid choice. Please try again." << std::endl;
                }

            } while (choice != 5);
        }
    }

    if (!isVerified){
        std::cout << "\nStudent with id " << id << " could not be verified\n" << std::endl;
    } 

};

void StudentManager::displayAllStudents() {

    std::cout << "\n=============================================" << std::endl;

    std::cout << "\nInformation about all students: " << std::endl;

    for (Student student: students) {
        std::cout << "\nId: " << student.getId() << "\n" 
                  << "Name: " << student.getName() << "\n"
                  << "Age: " << student.getAge() << "\n"
                  << "Major: " << student.getMajor() << "\n"
                  << "GPA: " << student.getGpa() << "\n"
                  << std::endl;
    }   

    std::cout << "=============================================" << std::endl;

};

void StudentManager::deleteStudent(){

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
        std::cout << "\nStudent with id " << id << " could not be verified\n" << std::endl;
    } else {
        std::cout << "\nStudent with id " << id << " was removed." << std::endl;
    }

};

void StudentManager::loadData(){

    std::string file;

    std::cout << "Please enter the CSV file name that you would like to load the data of (ex: data.csv): " << std::endl;
    std::cin >> file;

    std::ifstream inputFile(file);   

    // Handle error if no file 
    if(!inputFile){
        std::cerr << "Error opening file: " << file << std::endl;
        return; 
    }

    std::string line;
    while(std::getline(inputFile, line)){

        std::stringstream ss(line);
        std::string token;

        // Vector to store all values in the CSV line
        std::vector<std::string> tokens;

        // Extract tokens separated by commas and store them in the vector
        while(std::getline(ss, token, ',')){
            tokens.push_back(token);
        }

        // Make sure the correct number of tokens are present
        if (tokens.size() == 5) {
            int id = std::stoi(tokens[0]);
            std::string name = tokens[1];
            int age = std::stoi(tokens[2]);
            std::string major = tokens[3];
            double gpa = std::stod(tokens[4]);

            // Create a new Student and set its data using addStudent
            Student newStudent;
            newStudent.addStudent(id, name, age, major, gpa);

            // Add the new student to the collection
            students.push_back(newStudent);
        } else {
            std::cout << "Invalid data format in line: " << line << std::endl;
        }
    } 

    inputFile.close();
    std::cout << "\nData loaded successfully!\n" << std::endl;
};


void StudentManager::saveData(){

    std::ofstream outputFile("data_output.csv");
    
    if (!outputFile) {
        std::cerr << "Error opening output file!" << std::endl;
        return;
    }

    for (Student student: students){
        outputFile << student.toString() << '\n';
    }

    std::cout << "Data saved to data_output.csv" << std::endl;

};