#include <stdlib.h>
#include <Windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include "initialization/initialization_header.h"
#define DEFAULT_SIZE 20

void clear()
{
    system("cls");
}


void print_student(Student* student) {
    printf("%s %s %s %d %d %d %d %d %d %d %d %d %.2lf\n",
        student->login.c_str(),
        student->password.c_str(),
        student->name.c_str(),
        student->grades[0],
        student->grades[1],
        student->grades[2],
        student->grades[3],
        student->grades[4],
        student->grades[5],
        student->grades[6],
        student->grades[7],
        student->final,
        student->average);

}

int get_student_index_by_login(Student* students, std::string login)
{
    for (int i = 0; i < DEFAULT_SIZE; i++)
    {
        if ((students + i)->login.compare(login) == 0)
        {
            return i;
        }
    }
    return -1;
}

bool check_pass(Student* students, std::string pass)
{
    for (int i = 0; i < DEFAULT_SIZE; i++)
    {
        if ((students + i)->password.compare(pass) == 0)
        {
            return true;
        }
    }
    return false;
}

void sign_in_system(Student *students) {
    int index = -1;

    bool pass_is_correct = false;
    std::string login;
    std::string password;
    std::string name;
    while (index == -1)
    {
        clear();
        std::cout << "Введите свой логин: ", std::cin>>login;
        index = get_student_index_by_login(students, login);
    }

    while (!pass_is_correct)
    {
        clear();
        std::cout << "Введите свой пароль: ", std::cin >> password;
        pass_is_correct = (students + index)->password.compare(password) == 0;

    }
    clear();
    std::cout << "Добро пожаловать, "<<(students + index)->name << "!";

}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    Student* students = new Student[DEFAULT_SIZE];
    read_file(students, "D:/data.txt");

    sign_in_system(students);
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        print_student(students + i);
    }
    return 0;
}