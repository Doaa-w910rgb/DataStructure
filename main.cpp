#include <iostream>
#include "Student.h"
using namespace std;

int main() {
    StudentList list;
    int choice, id;
    string name;

    do {
        cout << "\n=== Student List Menu ===\n";
        cout << "1. Add student at end\n";
        cout << "2. Add student at start\n";
        cout << "3. Search student by ID\n";
        cout << "4. Update current student name\n";
        cout << "5. Delete current student\n";
        cout << "6. Print all students\n";
        cout << "7. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter ID: "; cin >> id;
                cout << "Enter Name: "; cin.ignore(); getline(cin, name);
                list.insertLast(id, name);
                break;
            case 2:
                cout << "Enter ID: "; cin >> id;
                cout << "Enter Name: "; cin.ignore(); getline(cin, name);
                list.insertFirst(id, name);
                break;
            case 3:
                cout << "Enter ID to search: "; cin >> id;
                if (list.searchById(id))
                    cout << "Found: " << list.searchById(id)->name << endl;
                else
                    cout << "Not found\n";
                break;
            case 4:
                cout << "Enter new name: "; cin.ignore(); getline(cin, name);
                list.updateCurrentName(name);
                break;
            case 5:
                list.deleteCurrent();
                break;
            case 6:
                list.printList();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    } while(choice != 7);

    return 0;
}

