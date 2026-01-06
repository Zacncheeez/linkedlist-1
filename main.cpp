#include <iostream>
#include "Node.h"

using namespace std;


int main() {
  // Create students
  Student* s1 = new Student("Zach", "Tobin", 12345, 3.8);
  Student* s2 = new Student("Alex", "Smith", 67890, 3.5);

  // Create nodes
  Node* head = new Node(s1);
  Node* second = new Node(s2);

  // Link nodes
  head->setNext(second);

  // Test getStudent()
  cout << "First student:" << endl;
  head->getStudent()->print();

  cout << "\nSecond student:" << endl;
  head->getNext()->getStudent()->print();

  // Clean up
  delete head;
  delete second;

  return 0;
  
}
