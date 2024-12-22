
# Указываем минимальную версию CMake
cmake_minimum_required(VERSION 3.10)

# Указываем имя проекта и его версию
project(KURSACH VERSION 1.0)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем исполняемый файл
add_executable(MyExecutable main.cpp)

# Если у вас есть дополнительные директории с заголовочными файлами
include_directories(include)

# Добавляем подкаталог для библиотеки spdlog
add_subdirectory(C:/_LABY_/Kursach/fmt ${CMAKE_CURRENT_BINARY_DIR}/fmt)

# Подключаем библиотеку spdlog к исполняемому файлу MyExecutable
target_link_libraries(MyExecutable PRIVATE fmt::fmt)

# Указываем директорию заголовочных файлов для logger.h
target_include_directories(MyExecutable PRIVATE ${CMAKE_SOURCE_DIR}/include)