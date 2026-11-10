// =======================================================
// Лабораторная работа №1
// Консольное приложение "Hello, Экосистема C++"
// Проект: HelloCMake (кроссплатформенная сборка CMake)
// =======================================================
#include "HelloCMake.h"

#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;

const char* studentInfo()
{
    return "Студент: Савичева А.С., группа БПС2605, вариант 13";
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    cout << "Hello, Экосистема C++!" << endl;
    cout << "Компилятор: MSVC " << _MSC_VER << endl;
    cout << "Стандарт C++: " << __cplusplus << endl;
    cout << studentInfo() << endl;

#ifdef PLATFORM_WINDOWS
    cout << "Платформа: Windows" << endl;
#elif defined(PLATFORM_LINUX)
    cout << "Платформа: Linux" << endl;
#elif defined(PLATFORM_MACOS)
    cout << "Платформа: macOS" << endl;
#endif

    system("PAUSE");
    return 0;
}
