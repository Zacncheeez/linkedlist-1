#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;


Node* addStudent(Node* current, Student* student);
Node* removeStudent(Node* current, int id);
void printStudent(Node* current); 

int main() {
    Node* head = NULL;
    int choice;

    for (;;) {
        cout << "What would you like to do?: " << endl;
        cout << "1 = Add student" << endl;
        cout << "2 = Print students" << endl;
        cout << "3 = Delete student" << endl;
        cout << "4 = Quit" << endl;

        cin >> choice;

        if (choice == 1) {
            char first[50], last[50];
            int id;
            float gpa;

            cout << "Please enter first name, last name, ID, and GPA:" << endl;
            cin >> first >> last >> id >> gpa;

            head = addStudent(head, new Student(first, last, id, gpa));
        }
        else if (choice == 2) {
            printStudent(head);
        }
        else if (choice == 3) {
            int id;
            cout << "ID of student you want removed: " << endl;
            cin >> id;
            head = removeStudent(head, id);
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice, try again." << endl;
        }
    }


    while (head != NULL) {
        Node* temp = head;
        head = head->getNext();
        delete temp;
    }

    return 0;
}



Node* addStudent(Node* current, Student* student) {
    if (current == NULL) return new Node(student);      
    if (current->getNext() == NULL) {
        current->setNext(new Node(student)); 
        return current;
    }
    addStudent(current->getNext(), student);
    return current;
}

Node* removeStudent(Node* current, int id) {
    if (current == NULL) return NULL;
    if (current->getStudent()->getID() == id) {
        Node* temp = current->getNext();
        cout << "Removed: ";
        current->getStudent()->print();
        delete current;
        return temp;
    }
    current->setNext(removeStudent(current->getNext(), id));
    return current;
}

void printStudent(Node* current) {
    if (current == NULL) return;
    current->getStudent()->print();
    printStudent(current->getNext());
}
