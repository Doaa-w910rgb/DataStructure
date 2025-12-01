#include "Student.h"

// Constructor
StudentList::StudentList() {
    head = tail = current = NULL; // List initially empty
}

// Destructor to free all nodes
StudentList::~StudentList() {
    while (!isEmpty()) {
        deleteFirst();
    }
}

// Check if list is empty
bool StudentList::isEmpty() {
    return head == NULL;
}

// Move current to start
void StudentList::moveToStart() {
    current = head;
}

// Check if current is start
bool StudentList::isAtStart() {
    return current == head;
}

// Move current to next node
void StudentList::moveNext() {
    if (current != NULL)
        current = current->next;
}

// Check if current is end
bool StudentList::isAtEnd() {
    return current == tail;
}

// Insert at start
void StudentList::insertFirst(int id, string name) {
    StudentNode* newNode = new StudentNode;
    newNode->id = id;
    newNode->name = name;
    newNode->next = head;
    head = newNode;
    if (tail == NULL)
        tail = newNode;
    current = newNode;
}

// Insert at end
void StudentList::insertLast(int id, string name) {
    StudentNode* newNode = new StudentNode;
    newNode->id = id;
    newNode->name = name;
    newNode->next = NULL;
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    current = newNode;
}

// Insert after current
void StudentList::insertAfterCurrent(int id, string name) {
    if (current == NULL) return;
    StudentNode* newNode = new StudentNode;
    newNode->id = id;
    newNode->name = name;
    newNode->next = current->next;
    current->next = newNode;
    if (current == tail)
        tail = newNode;
}

// Delete first node
void StudentList::deleteFirst() {
    if (isEmpty()) return;
    StudentNode* temp = head;
    head = head->next;
    if (head == NULL) tail = NULL;
    if (current == temp) current = head;
    delete temp;
}

// Delete last node
void StudentList::deleteLast() {
    if (isEmpty()) return;
    if (head == tail) { // only one node
        deleteFirst();
        return;
    }
    StudentNode* temp = head;
    while (temp->next != tail)
        temp = temp->next;
    delete tail;
    tail = temp;
    tail->next = NULL;
    current = tail;
}

// Delete current node
void StudentList::deleteCurrent() {
    if (current == NULL) return;
    if (current == head) {
        deleteFirst();
        return;
    }
    StudentNode* temp = head;
    while (temp->next != current)
        temp = temp->next;
    temp->next = current->next;
    if (current == tail) tail = temp;
    delete current;
    current = temp->next;
}

// Update current node name
void StudentList::updateCurrentName(string name) {
    if (current != NULL)
        current->name = name;
}

// Search node by ID
StudentNode* StudentList::searchById(int id) {
    StudentNode* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            current = temp;
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Print all nodes
void StudentList::printList() {
    if (isEmpty()) {
        cout << "List is empty.\n";
        return;
    }
    StudentNode* temp = head;
    cout << "Student List:\n";
    while (temp != NULL) {
        cout << "ID: " << temp->id << ", Name: " << temp->name << endl;
        temp = temp->next;
    }
}

