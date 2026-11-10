# =======================================================
# CMakeLists.txt
# Лабораторная работа №1
# Проект: HelloQt (GUI-приложение на Qt Widgets)
# =======================================================

cmake_minimum_required(VERSION 3.21)

project(HelloQt
        VERSION 1.0
        DESCRIPTION "GUI-приложение Qt Widgets для ЛР №1"
        LANGUAGES CXX)

# ----------------------------------------------------------
# Стандарт языка C++
# ----------------------------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ----------------------------------------------------------
# Автоматическая обработка метаобъектов Qt (moc), форм (uic)
# и ресурсов (rcc)
# ----------------------------------------------------------
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# ----------------------------------------------------------
# Поиск библиотек Qt 6 (модуль Widgets)
# ----------------------------------------------------------
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# ----------------------------------------------------------
# Исполняемый файл GUI-приложения
# WIN32 — приложение без консольного окна
# ----------------------------------------------------------
add_executable(HelloQt WIN32 "main.cpp")

target_link_libraries(HelloQt PRIVATE Qt6::Widgets)

# ----------------------------------------------------------
# Для MSVC: предупреждения и кодировка исходных текстов UTF-8
# ----------------------------------------------------------
if(MSVC)
  target_compile_options(HelloQt PRIVATE /W4 /utf-8)
endif()

# ----------------------------------------------------------
# Единый выходной каталог bin/ для всех конфигураций
# ----------------------------------------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set_target_properties(HelloQt PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY         ${CMAKE_BINARY_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_BINARY_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
