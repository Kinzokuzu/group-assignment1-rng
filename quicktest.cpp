#include <iostream>
#include "part2.cpp"

int main() {
  // Generate an amount of students students
  std::vector<Student> students(15);
  int id = 0;
  for (auto& student : students) {
    student.id = id++;
  }

  // Generate an amount of groups to class 11 AM
  std::unordered_map<int, int> groups_11am;
  for (int i = 0; i < 4; i++) {
    groups_11am.insert(std::make_pair(i, 0));
  }

  // Generate an amount of groups to class  12 PM
  std::unordered_map<int, int> groups_12pm;
  for (int i = 0; i < 4; i++) {
    groups_12pm.insert(std::make_pair(i, 0));
  }

  // Assign students to groups
  std::vector<Student> assigned_students_11am = AssignStudents(students, groups_11am);
  std::vector<Student> assigned_students_12pm = AssignStudents(students, groups_12pm);

  // Prints everything, like where the students were assigned to. then what the groups are. 
  std::cout << "Assigned Students 11am:\n";
  PrintStudents(assigned_students_11am);

  std::cout << "\nAssigned Students 12am:\n";
  PrintStudents(assigned_students_12pm);

  std::cout << "\nGroups 11 AM:\n";
  PrintGroups(groups_11am);

  std::cout << "\nGroups 12 PM:\n";
  PrintGroups(groups_12pm);

  return 0;
}
