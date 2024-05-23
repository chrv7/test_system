#include "initialization_header.h"

void read_file_row(Student* student, std::string str, int rowNum);
void read_grade_from_row(Student* student, std::string str);
double parse_average(std::string topic, std::string str);
int parse_topic_or_final_and_get_grade(std::string topic, std::string str);
void remove_space_and_alpha(std::string& str);
bool is_number(std::string& str);