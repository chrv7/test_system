// #pragma once
#include <string>

struct Question {
    int topic_id;
    int id;
    std::string* variants = new std::string[4];
    int correct_index;
};