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

void SortPairVector(std::vector<std::pair<int, int>>& pair_vector) {
  std::pair<int, int> temp;

  for (auto& i : pair_vector) {
    for (auto& j : pair_vector) {
      if (j.second > i.second) {
        temp = j;
        j = i;
        i = j;
      }
    }
  }
}

std::vector<std::pair<int, int>> MapToVector(std::unordered_map<int, int> map) {
  std::vector<std::pair<int, int>> pair_vector(map.size());

  for (int i = 0; i < map.size(); i++) {
    pair_vector.at(i).first = i;
    pair_vector.at(i).second = map[i];
  }

  SortPairVector(pair_vector);

  return pair_vector;
}
// TO-DO: Rewrite AssignStudents() so that each group has 3 - 5 students, currently can have
// less than 3 students
std::vector<Student> AssignStudents(std::vector<Student>& s, std::unordered_map<int, int>& g) {
  // If there are more stoudants than available spots do nothing
  if (AvailableSpots(g) < s.size()) {
    return s;
  }
  // Create a vector of goups by number of students in each group (high to low)
  std::vector<std::pair<int, int>> g_vector = MapToVector(g);
  // Random number generation
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0, g.size() - 1);

  int rand_num;
  int current_group{0};
  for (int i = 0; i < s.size();) {
    rand_num = distrib(gen);

    if (g_vector.at(current_group).second < 5) {
      s.at(i).group = i;                   // Assign student i to group current group
      g[current_group]++;                  // Increment members in current group
      g_vector.at(current_group).second++; // Increment members in current group

      i++; // Move on to next student
    }
    else {
      current_group++; // If current group is full, move one to next group
    }
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
