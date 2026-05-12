#include "Assignments.h"

int main() {
    setlocale(LC_ALL, "Russian");
    AssignmentManager manager;

    // Демонстрация заданий

    // Задание 1
    std::vector<int> v = { 1, 2, 3 };
    std::cout << "Задание 1: "; Print(v, ", ");

    // Задание 5
    Duplicate(v);
    std::cout << "Задание 5 (Duplicate): "; Print(v, " ");

    // Задание 7
    std::vector<int> v2 = { 1, 1, 2, 2, 3, 1, 1 };
    auto last = Unique(v2.begin(), v2.end());
    std::cout << "Задание 7 (Unique): ";
    for (auto it = v2.begin(); it != last; ++it) std::cout << *it << " ";
    std::cout << "\n";

    // Вызов интерактивных заданий
    manager.RunTask2();
    manager.RunTask3();
    manager.RunTask4();
    manager.RunTask8();
    return 0;
}