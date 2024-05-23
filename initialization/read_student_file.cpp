#include "initialization_header.h"
#include "parsing_header.h"

void read_file(Student* students, std::string filename) {
    std::ifstream file;
    file.open(filename);
    int ordinal = 0;
    Student* sPtr = &students[ordinal];

    if (file.is_open()) {
        std::string line;
        int rowNum = 1;
        while (file) {
            std::getline(file, line);

            read_file_row(sPtr, line, rowNum);
            if (rowNum == 13) {
                rowNum = 0;
                ordinal++;
                sPtr = &students[ordinal];
            }
            if (file.eof())
                break;
            rowNum++;
        }
    }
    else {
        std::cout << "Невозможно прочесть файл!\n";
    }
    file.close();
    sPtr = nullptr;
    delete sPtr;
}