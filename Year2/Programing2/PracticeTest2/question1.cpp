#include <iostream>
using namespace std;

class Course {
  int courseCode;
  string courseName;

public:
  Course(){};
  Course(int code, string name) : courseCode(code), courseName(name) {}
  void describe() {
    cout << "Course Code: " << courseCode << endl
         << "Course Name: " << courseName << endl;
  }
};

// Case a:
class Student1 {
  string name;
  int studentID;
  Course course;

public:
  Student1(string inputName, int inputID, int code, string name) {
    this->name = inputName;
    this->studentID = inputID;
    this->course = Course(code, name);
  }
  void describe() {
    cout << "Name: " << name << endl << "ID: " << studentID << endl;
    course.describe();
  }
};

// Case b:
class Student2 {
  string name;
  int studentID;
  Course *course;

public:
  Student2(string inputName, int inputID, Course *inputCourse) {
    this->name = inputName;
    this->studentID = inputID;
    this->course = inputCourse;
  }
  void describe() {
    cout << "Name: " << name << endl << "ID: " << studentID << endl;
    course->describe();
  }
};

int main() {
  Student1 John("John", 001, 010, "C++");
  Course OS(100, "Operating System");
  Student2 Jane("Jane", 011, &OS);
  John.describe();
  Jane.describe();
}
