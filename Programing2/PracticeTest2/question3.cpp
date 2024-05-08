#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Member {
protected:
  string name;
  int yearOfBirth;

public:
  Member(string inputName, int inputYear)
      : name(inputName), yearOfBirth(inputYear) {}
  virtual void describe() const {
    cout << "Name: " << name << endl << "Born: " << yearOfBirth << endl;
  }
  int getYearOfBirth() const { return yearOfBirth; }
};

class Participant : public Member {
  string field;

public:
  Participant(string inputName, int inputYear, string inputField)
      : Member(inputName, inputYear), field(inputField) {}
  void describe() const override {
    Member::describe();
    cout << "Field: " << field << endl << endl;
  }
};

class Mentor : public Member {
  string subject;

public:
  Mentor(string inputName, int inputYear, string inputSubject)
      : Member(inputName, inputYear), subject(inputSubject) {}
  void describe() const override {
    Member::describe();
    cout << "Subject: " << subject << endl << endl;
  }
};

class Coordinator : public Member {
  string division;

public:
  Coordinator(string inputName, int inputYear, string inputDivision)
      : Member(inputName, inputYear), division(inputDivision) {}
  void describe() const override {
    Member::describe();
    cout << "Division: " << division << endl << endl;
  }
};
class Society {
  string name;
  vector<Member *> members;

public:
  Society(string inputName) : name(inputName) {}
  void addMember(Member *member) { members.push_back(member); }
  void describe() const {
    cout << "Society Name: " << name << endl;
    cout << "----------------------" << endl;
    for (auto member : members) {
      member->describe();
    }
  }

  int countSpecific(const type_info &memberType) const {
    int count = 0;
    for (auto member : members) {
      if (typeid(*member) == memberType) {
        count++;
      }
    }
    return count;
  }
  int countCoordinators() const {
    int count = 0;
    for (auto member : members) {
      if (dynamic_cast<Coordinator *>(member) != nullptr) {
        count++;
      }
    }
    return count;
  }
  int countMentors() const {
    int count = 0;
    for (auto member : members) {
      if (dynamic_cast<Mentor *>(member) != nullptr) {
        count++;
      }
    }
    return count;
  }
  int countParticipants() const {
    int count = 0;
    for (auto member : members) {
      if (dynamic_cast<Participant *>(member) != nullptr) {
        count++;
      }
    }
    return count;
  }
  void sortBirthYear() {
    sort(members.begin(), members.end(), [](Member *a, Member *b) {
      return a->getYearOfBirth() < b->getYearOfBirth();
    });
  }
  int aveMentorYearOfBirth() const {
    int sum = 0;
    int count = 0;
    for (auto member : members) {
      if (dynamic_cast<Mentor *>(member) != nullptr) {
        sum += member->getYearOfBirth();
        count++;
      }
    }
    if (count == 0) {
      return 0;
    }
    return sum / count;
  }
};

int main() {
  Society society("Society");
  Participant participant1("Liam", 2005, "field0");
  Mentor mentor1("Jane", 1990, "Liam");
  Mentor mentor2("John", 1995, "Liam");
  Coordinator coordinator1("Bob", 1993, "Logistic");
  Coordinator coordinator2("Jen", 2000, "Media");

  society.addMember(&participant1);
  society.addMember(&mentor1);
  society.addMember(&mentor2);
  society.addMember(&coordinator1);
  society.addMember(&coordinator2);
  society.describe();

  cout << "Number of participants: " << society.countParticipants() << endl;
  cout << "Number of mentors: " << society.countMentors() << endl;
  cout << "Number of coordinators: " << society.countCoordinators() << endl;
  //  cout << "Number of specific type: "
  //       << society.countSpecific(typeid(Participant)) << endl;
  society.sortBirthYear();
  cout << "\nSorted by Year of Birth:" << endl;
  society.describe();
  cout << "Average Year of Birth of Mentors: " << society.aveMentorYearOfBirth()
       << endl;

  return 0;
}
