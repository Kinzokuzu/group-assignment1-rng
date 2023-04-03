#ifndef PART_2_CPP_INCLUDE
#define PART_2_CPP_INCLUDE

#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>

struct Student {
  int id = -1;
  int group = -1;
}; // End Student

int TotalStudentsInGroups(const std::unordered_map<int, int>& g) {
  int student_count{0};
  
  for (const auto& [key, value] : g) {
    student_count += value;
  }

  return student_count;
}

int AvailableSpots(const std::unordered_map<int, int>& g) {
  return (g.size() * 5) - TotalStudentsInGroups(g);
}
// TO-DO: Rewrite AssignStudents() so that each group has 3 - 5 students, currently can have
// less than 3 students
std::vector<Student> AssignStudents(std::vector<Student>& s, std::unordered_map<int, int>& g) {
  // If there are more stoudants than available spots do nothing
  if (AvailableSpots(g) < s.size()) {
    return s;
  }
  // Random number generation
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0, g.size() - 1);

  int rand_num;
  for (int i = 0; i < s.size();) {
    rand_num = distrib(gen);

    if (g[rand_num] < 5) {
      s.at(i).group = rand_num; // Assign student i to group rand_num
      g[rand_num]++;            // Increment the number of students in group rand_num
      i++;                      // Move onto next student
    }
    // Else produce another rand_num and try again
  }

  return s;
}

void PrintStudents(const std::vector<Student>& s) {
  for (const auto& student : s) {
    std::cout << "Student: " << student.id << " Group: " << student.group << std::endl;
  }
}

void PrintGroup(const std::unordered_map<int, int> g) {
  for (const auto& [key, value] : g) {
    std::cout << "Group: " << key << " # of Students: " << value << std::endl;
  }
}

#endif
