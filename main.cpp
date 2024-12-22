// #include <iostream>
// #include <vector>
// #include <string>
// #include <fmt/core.h>
// #include <fmt/ranges.h>
// #include <fmt/color.h>

// struct Student {
//     std::string name;
//     int age;
//     std::vector<double> grades;

//     // Метод для вычисления среднего балла
//     double averageGrade() const {
//         double sum = 0;
//         for (double grade : grades) {
//             sum += grade;
//         }
//         return grades.empty() ? 0 : sum / grades.size();
//     }
// };

// void printStudentInfo(const Student& student) {
//     fmt::print(fg(fmt::color::cyan), "Имя: {}\n", student.name); // Цвет для имени
//     fmt::print(fg(fmt::color::blue), "Возраст: {}\n", student.age); // Цвет для возраста
    
//     // Вывод оценок с цветом
//     fmt::print("Оценки: ");
//     for (const auto& grade : student.grades) {
//         // Устанавливаем цвет в зависимости от оценки
//         if (grade == 5.0) {
//             fmt::print(fg(fmt::color::green), "{:.1f} ", grade); // Зелёный для 5
//         } else if (grade >= 4.0 && grade < 5.0) {
//             fmt::print(fg(fmt::color::orange), "{:.1f} ", grade); // Оранжевый для оценок от 4 до 4.9
//         } else if (grade >= 3.0 && grade < 4.0) {
//             fmt::print(fg(fmt::color::yellow), "{:.1f} ", grade); // Жёлтый для оценок от 3 до 3.9
//         } else {
//             fmt::print(fg(fmt::color::red), "{:.1f} ", grade); // Красный для оценок ниже 3
//         }
//     }
//     fmt::print("\n");
    
//     double avgGrade = student.averageGrade();
    
//     // Устанавливаем цвет для среднего балла в зависимости от его значения
//     if (avgGrade == 5.0) {
//         fmt::print(fg(fmt::color::green), "Средний балл: {:.2f}\n\n", avgGrade); // Зелёный для 5
//     } else if (avgGrade >= 4.0 && avgGrade < 5.0) {
//         fmt::print(fg(fmt::color::orange), "Средний балл: {:.2f}\n\n", avgGrade); // Оранжевый для оценок от 4 до 4.9
//     } else if (avgGrade >= 3.0 && avgGrade < 4.0) {
//         fmt::print(fg(fmt::color::yellow), "Средний балл: {:.2f}\n\n", avgGrade); // Жёлтый для оценок от 3 до 3.9
//     } else {
//         fmt::print(fg(fmt::color::red), "Средний балл: {:.2f}\n\n", avgGrade); // Красный для оценок ниже 3
//     }
// }

// int main() {
//     // Создание списка студентов
//     std::vector<Student> students = {
//         {"Алексей", 20, {4.5, 3.7, 4.8}},
//         {"Мария", 22, {5.0, 4.8, 4.9}},
//         {"Иван", 19, {3.5, 4.0, 3.8}},
//         {"Елена", 21, {4.2, 4.6, 2.5}} 
//     };

//     // Заголовок таблицы с цветами
//     fmt::print(fg(fmt::color::white), "{:<10} | {:<6} | {:<20} | {:<15}\n", "Имя", "Возраст", "Оценки", "Средний балл");
//     fmt::print("{:-<10}-|-{:-<7}-|-{:-<20}-|-{:-<15}\n", "", "", "", "");

//     for (const auto& student : students) {
//         fmt::print("{:<10} | {:<7} | ", student.name, student.age);
        
//         // Вывод оценок с цветом
//         for (const auto& grade : student.grades) {
//             if (grade == 5.0) {
//                 fmt::print(fg(fmt::color::green), "{:.1f} ", grade);
//             } else if (grade >= 4.0 && grade < 5.0) {
//                 fmt::print(fg(fmt::color::orange), "{:.1f} ", grade);
//             } else if (grade >= 3.0 && grade < 4.0) {
//                 fmt::print(fg(fmt::color::yellow), "{:.1f} ", grade);
//             } else {
//                 fmt::print(fg(fmt::color::red), "{:.1f} ", grade);
//             }
//         }

//         double avgGrade = student.averageGrade();
        
//         // Устанавливаем цвет для среднего балла в зависимости от его значения
//         if (avgGrade == 5.0) {
//             fmt::print(fg(fmt::color::green), "| {:.2f}\n", avgGrade); // Зелёный для среднего балла
//         } else if (avgGrade >= 4.0 && avgGrade < 5.0) {
//             fmt::print(fg(fmt::color::orange), "| {:.2f}\n", avgGrade); // Оранжевый для среднего балла
//         } else if (avgGrade >= 3.0 && avgGrade < 4.0) {
//             fmt::print(fg(fmt::color::yellow), "| {:.2f}\n", avgGrade); // Жёлтый для среднего балла
//         } else {
//             fmt::print(fg(fmt::color::red), "| {:.2f}\n", avgGrade); // Красный для среднего балла
//         }
//     }

//     return 0;
// }


// форматирования строк 
#include <fmt/format.h>
// работа с диапазонами
#include <fmt/ranges.h>

#include <vector>
#include <iostream>


// Определение структуры для представления человека
struct Person {
    std::string name;
    int age;
    double height;

    // Метод для форматирования вывода структуры
    std::string format() const {
         // Форматирование строки
        return fmt::format("Имя: {}, Возраст: {}, Рост: {:.2f} см", name, age, height);
    }
};


int main() {

// Создание вектора людей
    std::vector<Person> people = {
        {"Алексей", 30, 175.5},
        {"Мария", 25, 160.0},
        {"Иван", 28, 180.3}
    };

    // Вывод информации о каждом человеке
    for (const auto& person : people) {
// Этот метод возвращает строку с отформатированными данными о человеке
        std::cout << person.format() << std::endl;
    }

    // Форматирование и вывод статистики
    int totalAge = 0;
    double totalHeight = 0.0;
// Цикл для подсчета общего возраста и роста всех людей
    for (const auto& person : people) {
// Добавление общего возраста и роста 
        totalAge += person.age;
        totalHeight += person.height;
    }
    
// Вычисление среднего возраста
    double averageAge = static_cast<double>(totalAge) / people.size();
// Вычисление среднего роста
    double averageHeight = totalHeight / people.size();

// Вывод среднего возраста и роста с форматированием до двух знаков после запятой
    fmt::print("Средний возраст: {:.2f} лет\n", averageAge);
    fmt::print("Средний рост: {:.2f} см\n", averageHeight);
    std::cout << std::endl;


// 1 Форматирование чисел
    double pi = 3.141592653589793;
    std::cout << fmt::format("Pi с двумя знаками после запятой: {:.2f}\n", pi) << std::endl;
    std::cout << fmt::format("Pi с четырьмя знаками после запятой: {:.4f}\n", pi) << std::endl;
    
// 2 Форматирование и вывод вектора
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << fmt::format("Числа: {}\n", numbers) << std::endl;
    
// 3 Форматирование строки с позиционными аргументами
    std::string s = fmt::format("Я бы предпочел быть {1} чем {0}.", "грустным", "счастливым");
    fmt::print("{}", s);
    std::cout << std::endl;

// 4. Форматирование с использованием ширины и выравнивания
    int width = 10;
    fmt::print("|{:^{}}|\n", "Центр", width);   // Центрирование
    fmt::print("|{:>{}}|\n", "Право", width);   // Выравнивание вправо
    fmt::print("|{:<{}}|\n", "Лево", width);     // Выравнивание влево

    return 0;
}
