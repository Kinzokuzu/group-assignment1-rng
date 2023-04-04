#include <iostream>
#include "part2.cpp"

void Test_AssignStudents1(); // Test students <= available spots
void Test_AssignStudents2(); // Test students > available spots

int main() {
  Test_AssignStudents1();
  Test_AssignStudents2();

  return 0;
}

void Test_AssignStudents1() { // Test students <= available spots
  int num_students{9};
  int num_groups{3};

  std::vector<Student> test_list(num_students);
  for (int i = 0; i < test_list.size(); i++) {
    test_list.at(i).id = i;
  }  

  std::unordered_map<int, int> test_map;
  for (int i = 0; i < num_groups; i++) { 
    test_map[i] = 0;
  }

  // 9 students, 15 available spots
  AssignStudents(test_list, test_map);

  for (const auto& student : test_list) {
    if (student.group < 0) {
      std::cout << "TEST 1 FAILED: student " << student.id << " not " <<
      "assigned to a group\n";

      return;
    }
  }

  for (const auto& [key, value] : test_map) {
    if (value > 5) {
      std::cout << "TEST 1 FAILED: group " << key << " has " << value <<
      " students\n";

      return;
    }

    if (value < 0 && value < 3) {
      std::cout << "TEST 1 FAILED: group " << key << " has " << value <<
      "students\n";

      return;
    }
  }

  std::cout << "TEST 1 PASSED\n";
}

void Test_AssignStudents2() { // Test students < available spots
  int num_students{12};
  int num_groups{2};

  std::vector<Student> test_list(num_students);
  for (int i = 0; i < test_list.size(); i++) {
    test_list.at(i).id = i;
  }  

  std::unordered_map<int, int> test_map;
  for (int i = 0; i < num_groups; i++) { 
    test_map[i] = 0;
  }

  // 12 students, 10 available spots
  AssignStudents(test_list, test_map);

  for (const auto& student : test_list) {
    if (student.group < 0) {
      std::cout << "TEST 2 FAILED: student " << student.id << " not " <<
      "assigned to a group\n";

      return;
    }
  }

  for (const auto& [key, value] : test_map) {
    if (value > 5) {
      std::cout << "TEST 2 FAILED: group " << key << " has " << value <<
      " students\n";

      return;
    }

    if (value < 0 && value < 3) {
      std::cout << "TEST 2 FAILED: group " << key << " has " << value <<
      "students\n";

      return;
    }
  }

  std::cout << "TEST 2 PASSED\n";
}