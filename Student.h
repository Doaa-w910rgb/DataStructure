#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

// Class Node for each student
struct StudentNode {
    int id;             // Student ID
    string name;        // Student name
    StudentNode* next;  // Pointer to the next node
};

// Class LinkedList
class StudentList {
private:
    StudentNode* head;  // Pointer to the first node
    StudentNode* tail;  // Pointer to the last node
    StudentNode* current; // Pointer to the current node

public:
    StudentList();               // Constructor
    ~StudentList();              // Destructor to free memory

    bool isEmpty();              // Check if the list is empty
    void moveToStart();          // Set current to first node
    bool isAtStart();            // Check if current is first node
    void moveNext();             // Move current to next node
    bool isAtEnd();              // Check if current is last node

    void insertFirst(int id, string name);  // Insert at start
    void insertLast(int id, string name);   // Insert at end
    void insertAfterCurrent(int id, string name); // Insert after current

    void deleteFirst();          // Delete first node
    void deleteLast();           // Delete last node
    void deleteCurrent();        // Delete current node

    void updateCurrentName(string name); // Update current node's name
    StudentNode* searchById(int id);    // Search by ID

    void printList();            // Print all nodes
};

#endif

