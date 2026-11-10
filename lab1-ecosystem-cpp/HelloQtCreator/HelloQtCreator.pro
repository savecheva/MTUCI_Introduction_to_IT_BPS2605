# =======================================================
# HelloQtCreator.pro
# Лабораторная работа №1
# GUI-приложение на Qt Widgets (сборка qmake)
# Студент: Савичева А.С., группа БПС2605, вариант 13
# =======================================================

QT       += core gui widgets

CONFIG   += c++20

TARGET    = HelloQtCreator
TEMPLATE  = app

SOURCES  += main.cpp

# Кодировка исходных текстов UTF-8 для MSVC
msvc {
    QMAKE_CXXFLAGS += /utf-8
}
