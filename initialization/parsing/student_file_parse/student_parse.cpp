#include <algorithm>
#include <string>
#include "../../parsing_header.h"

bool is_number(std::string& str)
{
    return !str.empty() && str.find_first_not_of("0123456789") == str.npos;
}

void remove_space_and_alpha(std::string& str)
{
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
    str.erase(std::remove_if(str.begin(), str.end(), isalpha), str.end());
}

int parse_topic_or_final_and_get_grade(std::string topic, std::string str)
{
    str.erase(0, topic.length() + 1);
    remove_space_and_alpha(str);
    if (!is_number(str)) {
        return 0;
    }
    return stoi(str);
}

double parse_average(std::string topic, std::string str)
{
    str.erase(0, topic.length() + 1);
    remove_space_and_alpha(str);
    if (!is_number(str)) {
        return 0;
    }
    return stod(str);
}

void read_grade_from_row(Student* student, std::string str)
{
    std::string prefix = str.substr(0, str.find(':'));
    if (prefix.compare("cycles") == 0) {
        student->grades[0] = parse_topic_or_final_and_get_grade(prefix, str);
        if (student->grades[0] < 0 || student->grades[0] > 5)
            printf("Несуществующая оценка!\n");
    }
    else if(prefix.compare("array") == 0)
    {
        student->grades[1] = parse_topic_or_final_and_get_grade(prefix, str);
        if (student->grades[1] < 0 || student->grades[1] > 5)
            printf("Несуществующая оценка!\n");
    }
    else if (prefix.compare("string") == 0)
    {
        student->grades[2] = parse_topic_or_final_and_get_grade(prefix, str);
        if (student->grades[2] < 0 || student->grades[2] > 5)
            printf("Несуществующая оценка!\n");
    }
    else if (prefix.compare("recursion") == 0)
    {
        student->grades[3] = parse_topic_or_final_and_get_grade(prefix, str);
        if (student->grades[3] < 0 || student->grades[3] > 5)
            printf("Несуществующая оценка!\n");
    }
    else if (prefix.compare("struct") == 0)
    {
        student->grades[4] = parse_topic_or_final_and_get_grade(prefix, str);
        if (student->grades[4] < 0 || student->grades[4] > 5)
            printf("Несуществующая оценка!\n");
    }
    else if (prefix.compare("files") == 0)
    {
        student->grades[5] = parse_topic_or_final_and_get_grade(prefix, str);
        if (student->grades[5] < 0 || student->grades[5] > 5)
            printf("Несуществующая оценка!\n");
    }
    else if (prefix.compare("address") == 0)
    {
        student->grades[6] = parse_topic_or_final_and_get_grade(prefix, str);
        if (student->grades[6] < 0 || student->grades[6] > 5)
            printf("Несуществующая оценка!\n");
    }
    else if (prefix.compare("dinamic") == 0)
    {
        student->grades[7] = parse_topic_or_final_and_get_grade(prefix, str);
        if (student->grades[7] < 0 || student->grades[7] > 5)
            printf("Несуществующая оценка!\n");
    }
    else if (prefix.compare("final") == 0)
    {
        student->final = parse_topic_or_final_and_get_grade(prefix, str);
        if (student->final < 0 || student->final > 5)
            printf("Несуществующая оценка!\n");
    }
    else if (prefix.compare("average") == 0)
    {
        student->average = parse_average(prefix, str);
        if (student->average < 0 || student->average > 5)
            printf("Несуществующая оценка!\n");
    }
    else {
        printf("Вы указали несуществующую строку!\n");
    }
}

void read_file_row(Student* student, std::string str, int rowNum) {
    switch (rowNum) {
        case 1: {
            student->login = str;
            break;
        }
        case 2: {
            student->password = str;
            break;
        }
        case 3: {
            student->name = str;
            break;
        }
        default: {
            read_grade_from_row(student, str);
        }
    }
}