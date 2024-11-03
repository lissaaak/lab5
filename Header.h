#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <set>

struct Student
{
    std::string Name;               // имя студента
    std::string GroupId;            // название группы
    std::vector<unsigned> Ratings;  // оценки по предметам
    std::vector<std::string> Subjects; // список предметов
};




void PrintStudents(const std::vector<Student>& students);
void SortByName(std::vector<Student>& students);
void SortByRating(std::vector<Student>& students);
size_t CountTwoness(const std::vector<Student>& students);
size_t CountExcellent(const std::vector<Student>& students);
std::vector<Student> VectorMathExcellent(const std::vector<Student>& students);
std::vector<std::string> GroupsId(const std::vector<Student>& students);