#include <iostream>

#include "part2.cpp"

int main() {
  std::vector<Student> test_list(9);

  for (int i = 0; i < test_list.size(); i++) {
    test_list.at(i).id = i;
  }  

  std::unordered_map<int, int> test_map;

  for (int i = 0; i < 2; i++) {
    test_map[i] = i * 1;
  }
  std::cout << "Before\n";
  PrintStudents(test_list);
  PrintGroup(test_map);

  std::cout << std::endl;

  test_list = AssignStudents(test_list, test_map);

  std::cout << "After\n";
  PrintStudents(test_list);
  PrintGroup(test_map);

  return 0;
}