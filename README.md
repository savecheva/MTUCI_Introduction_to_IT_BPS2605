# MTUCI_Introduction_to_IT_BPS2605

Лабораторные работы по дисциплине «Введение в информационные технологии».
МТУСИ, группа БПС2605, вариант 13.

**Студент:** Савичева Анастасия Сергеевна

## Состав репозитория

| № | Лабораторная работа | Отчёт | Исходный код |
|---|---------------------|-------|--------------|
| 1 | Экосистема языка программирования C++: конфигурирование среды разработки и сборка кроссплатформенных приложений | [DOCX](lab1-ecosystem-cpp/report/lab_report_Savicheva_BPS2605.docx) · [PDF](lab1-ecosystem-cpp/report/lab_report_Savicheva_BPS2605.pdf) | [lab1-ecosystem-cpp](lab1-ecosystem-cpp) |
| 3 | Разработка простейших проектов с использованием основных средств языка программирования VC++ | [DOCX](lab3-data-types/report/lab_report3_Savicheva_BPS2605.docx) · [PDF](lab3-data-types/report/lab_report3_Savicheva_BPS2605.pdf) | [lab3-data-types](lab3-data-types) |

## Лабораторная работа № 1

Освоение инструментов экосистемы C++: создание, сборка и запуск приложений
в Microsoft Visual Studio, CMake, Qt и Qt Creator, а также работа с платформой
GitVerse.

| Проект | Описание |
|--------|----------|
| `HelloConsole` | Консольное приложение в Microsoft Visual Studio (C++) |
| `HelloCMake` | Кроссплатформенный проект, собираемый системой CMake |
| `HelloQt` | GUI-приложение на Qt Widgets, сборка через CMake в Visual Studio |
| `HelloQtCreator` | GUI-приложение на Qt Widgets в среде Qt Creator |

Сборка проектов CMake:

```powershell
cmake -S HelloCMake -B HelloCMake/build
cmake --build HelloCMake/build
```

## Лабораторная работа № 3

Вариант 13 — вычисление значения функции

```
h = (sin³x + e^(−sin y)) / (0,6 · x² · y²)
```

при x = 0,68, y = −0,848. Программа также выполняет четыре вида преобразования
вещественного результата в целый тип (неявное и явное усечение, округление
в большую и в меньшую сторону) и демонстрирует работу операций префиксного
и постфиксного инкремента.

Проект `Lab3` — консольное приложение Visual C++ (конфигурация Debug, x64),
исходный код находится в файле `main.cpp`.

## Требования

- Microsoft Visual Studio 2022/2026 с рабочей нагрузкой «Разработка классических
  приложений на C++»;
- CMake 3.20 или новее;
- Qt 6 (для проектов `HelloQt` и `HelloQtCreator`).
