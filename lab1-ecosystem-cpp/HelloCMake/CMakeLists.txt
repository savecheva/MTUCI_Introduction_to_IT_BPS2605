# =======================================================
# CMakeLists.txt
# Лабораторная работа №1
# Проект: HelloCMake
# Демонстрация основ CMake и кроссплатформенной сборки
# =======================================================

# ----------------------------------------------------------
# 1. МИНИМАЛЬНАЯ ВЕРСИЯ CMAKE
# ----------------------------------------------------------
# Указывает минимально необходимую версию CMake для сборки.
# Если у пользователя более старая версия — сборка прервётся
# с понятным сообщением об ошибке.
cmake_minimum_required(VERSION 3.8)

# ----------------------------------------------------------
# 2. ОБЪЯВЛЕНИЕ ПРОЕКТА
# ----------------------------------------------------------
# project() — обязательная команда. Задаёт:
#   - имя проекта (HelloCMake);
#   - версию (1.0);
#   - языки программирования (CXX — C++).
# VERSION позволяет использовать переменные
#   PROJECT_VERSION, PROJECT_VERSION_MAJOR, ... в коде.
# LANGUAGES указывает, какие языки используются. Это влияет
#   на проверку наличия соответствующих компиляторов.
project(HelloCMake
        VERSION 1.0
        DESCRIPTION "Демонстрационное приложение для ЛР №1"
        LANGUAGES CXX)

# ----------------------------------------------------------
# 3. СТАНДАРТ ЯЗЫКА C++
# ----------------------------------------------------------
# CXX_STANDARD — устанавливает стандарт C++ для всего проекта.
# CXX_STANDARD_REQUIRED — если ON, CMake требует от компилятора
#   полной поддержки указанного стандарта. При отсутствии —
#   сборка завершится с ошибкой.
# CXX_EXTENSIONS — отключает расширения компилятора (например,
#   специфичные для MSVC или GCC). Делает код более
#   переносимым между платформами.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ----------------------------------------------------------
# 4. ОПРЕДЕЛЕНИЕ ЦЕЛЕВОГО ИСПОЛНЯЕМОГО ФАЙЛА
# ----------------------------------------------------------
# add_executable() — создаёт цель (target) — исполняемый файл.
# Первый аргумент: имя цели (HelloCMake).
# Далее: список исходных файлов (.cpp, .h).
# CMake автоматически определит зависимости по #include.
add_executable(HelloCMake
               "HelloCMake.cpp"
               "HelloCMake.h")

# ----------------------------------------------------------
# 5. ВКЛЮЧЕНИЕ ЗАГОЛОВОЧНЫХ ФАЙЛОВ В ЦЕЛЬ
# ----------------------------------------------------------
# target_include_directories() — указывает каталоги,
#   в которых компилятор будет искать заголовочные файлы.
# PRIVATE — директория доступна только самой цели.
# ${CMAKE_CURRENT_SOURCE_DIR} — переменная CMake, содержащая
#   абсолютный путь к каталогу с текущим CMakeLists.txt.
target_include_directories(HelloCMake PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# ----------------------------------------------------------
# 6. КРОССПЛАТФОРМЕННЫЕ ОПРЕДЕЛЕНИЯ ПРЕПРОЦЕССОРА
# ----------------------------------------------------------
# target_compile_definitions() — добавляет макросы препроцессора
#   для конкретной цели.
# В зависимости от операционной системы определяется разный
#   макрос, что позволяет писать платформозависимый код.
if(WIN32)
  target_compile_definitions(HelloCMake PRIVATE PLATFORM_WINDOWS)
elseif(UNIX AND NOT APPLE)
  target_compile_definitions(HelloCMake PRIVATE PLATFORM_LINUX)
elseif(APPLE)
  target_compile_definitions(HelloCMake PRIVATE PLATFORM_MACOS)
endif()

# ----------------------------------------------------------
# 7. КОМПИЛЯТОР-СПЕЦИФИЧНЫЕ ФЛАГИ
# ----------------------------------------------------------
# Для MSVC: установка уровня предупреждений /W4 и кодировки
#   исходных текстов UTF-8 (/utf-8), чтобы кириллица в
#   строковых литералах не искажалась.
if(MSVC)
  target_compile_options(HelloCMake PRIVATE /W4 /utf-8 /Zc:__cplusplus)
endif()
# Для GCC/Clang: флаги -Wall -Wextra -Wpedantic
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(HelloCMake PRIVATE -Wall -Wextra -Wpedantic)
endif()

# ----------------------------------------------------------
# 8. УСТАНОВКА ВЫХОДНОГО КАТАЛОГА
# ----------------------------------------------------------
# По умолчанию CMake размещает исполняемые файлы в сложной
# иерархии (в зависимости от конфигурации). Свойства
# RUNTIME_OUTPUT_DIRECTORY задают единый выходной каталог
# bin/ для всех конфигураций (в том числе для многоконфигура-
# ционного генератора Visual Studio).
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set_target_properties(HelloCMake PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY         ${CMAKE_BINARY_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_BINARY_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)

# ----------------------------------------------------------
# 9. ВЫВОД ИТОГОВОЙ ИНФОРМАЦИИ ПРИ КОНФИГУРАЦИИ
# ----------------------------------------------------------
# message() — выводит сообщения при запуске cmake.
# STATUS — информационное сообщение (не ошибка).
message(STATUS "========================================")
message(STATUS "Проект:               ${PROJECT_NAME}")
message(STATUS "Версия:               ${PROJECT_VERSION}")
message(STATUS "Стандарт C++:         ${CMAKE_CXX_STANDARD}")
message(STATUS "Компилятор C++:       ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Сборочный каталог:    ${CMAKE_BINARY_DIR}")
message(STATUS "Исходный каталог:     ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "Выходной каталог:     ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "Платформа:            ${CMAKE_SYSTEM_NAME}")
message(STATUS "========================================")
