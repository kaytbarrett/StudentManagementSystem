/*
    Author: Katherine Barrett
    Date: September 30, 2024
    Purpose: Create a console student management system to practice C++
*/

#include "StudentManager.h"
#include "Student.h"
#include <iostream>

int main () {
    StudentManager manager;
    int choice;

    std::cout << "\n\n=== Student Management System ===" << std::endl;

    do {
    std::cout << "\n1. Add Student\n"
                  << "2. Edit Student\n"
                  << "3. Delete Student\n"
                  << "4. Display All Students\n"
                  << "5. Save Data\n"
                  << "6. Load Data\n"
                  << "7. Exit\n\n"
                  << "Choose an option: ";
    std::cin >> choice;

        switch (choice) {
            case 1:
                manager.addStudent();
                break;
            case 2:
                manager.editStudent();
                break;
            case 3:
                manager.deleteStudent();
                break;
            case 4:
                manager.displayAllStudents();
                break;
            case 5: 
                std::cout << "\nThis is not configured yet. Please choose another option from the menu." << std::endl;
                break;
            case 6:
                manager.loadData();
                break;
            case 7:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "\nInvalid choice. Please try again." << std::endl;
        }

    } while (choice != 7);

    return 0;

};