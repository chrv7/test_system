#pragma once
#include <string>
#include "question.h"

struct Topic {
    int id;
    std::string name;
    Question *questions = new Question[10];
};