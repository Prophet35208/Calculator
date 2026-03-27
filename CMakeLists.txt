cmake_minimum_required(VERSION 3.14)
project(CalculatorProject)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Устанавливаем пути для выходных файлов
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Включаем тестирование
enable_testing()


# Библиотека калькулятора
add_library(calculator STATIC
    src/Calculator.cpp
)

target_include_directories(calculator
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)


# Основное приложение
add_executable(calculator_app
    src/CalculatorMain.cpp
)

target_link_libraries(calculator_app
    calculator
)

target_include_directories(calculator_app
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)


# Юнит-Тесты (Google Test)
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(calculator_tests
    tests/test_calculator.cpp
)

target_link_libraries(calculator_tests
    calculator
    gtest_main
)

target_include_directories(calculator_tests
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Регистрируем тесты в CTest
include(GoogleTest)
gtest_discover_tests(calculator_tests)