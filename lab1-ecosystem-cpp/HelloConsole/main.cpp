// =======================================================
// Лабораторная работа №1
// Консольное приложение "Hello, Экосистема C++"
// =======================================================
#include <iostream>
#include <clocale>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    std::cout << "Hello, Экосистема C++!" << std::endl;
    std::cout << "Компилятор: MSVC " << _MSC_VER << std::endl;
    std::cout << "Стандарт C++: " << __cplusplus << std::endl;
    std::cout << "Студент: Савичева А.С., группа БПС2605, вариант 13" << std::endl;

    system("PAUSE");
    return 0;
}
