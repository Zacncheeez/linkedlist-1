#include "Student.h"
#include <cstring>

// Constructor
Student::Student(const char* first, const char* last, int id, float gpa) {
  strcpy(firstName, first);
  strcpy(lastName, last);
  studentID = id;
  studentGPA = gpa;
}

// Print student info
void Student::print() const {
  cout << firstName << " " << lastName
       << " | ID: " << studentID
       << " | GPA: " << studentGPA << endl;
}
