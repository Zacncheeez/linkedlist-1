#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

// Student class holds basic student data
class Student {
 public:
  Student(const char* first, const char* last, int id, float gpa);

  void print() const;

 private:
  char firstName[50];
  char lastName[50];
  int studentID;
  float studentGPA;
};

#endif
