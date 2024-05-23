#pragma once
#include <string>

struct Student {
    std::string login;
    std::string password;
    std::string name;
    int* grades = new int[8];
    int final;
    double average;
};

