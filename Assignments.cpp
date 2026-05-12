#include "Assignments.h"
#include <fstream>
#include <numeric>

//задание 2: проверка на вхождение (set)
void AssignmentManager::RunTask2() {
    std::cout << "\n--- Задание 2 (YES/NO) ---" << std::endl;
    int number;
    std::set<int> history;
    std::cout << "Введите числа (0 для выхода): ";
    while (std::cin >> number && number != 0) {
        if (history.count(number)) std::cout << "YES" << std::endl;
        else {
            std::cout << "NO" << std::endl;
            history.insert(number);
        }
    }
}
//задание 3: общие буквы
void AssignmentManager::RunTask3() {
    std::cout << "\n--- Задание 3 (Общие буквы) ---" << std::endl;
    std::vector<std::string> words;
    std::string word;
    std::cout << "Введите слова (слово 'end' для конца): ";
    while (std::cin >> word && word != "end") words.push_back(word);

    if (words.empty()) return;

    std::set<char> common;
    for (char c : words[0]) common.insert(c);

    for (size_t i = 1; i < words.size(); ++i) {
        std::set<char> current, intersect;
        for (char c : words[i]) current.insert(c);
        std::set_intersection(common.begin(), common.end(),
            current.begin(), current.end(),
            std::inserter(intersect, intersect.begin()));
        common = intersect;
    }
    for (char c : common) std::cout << c;
    std::cout << std::endl;
}
//задание 4: порядковый номер слова
void AssignmentManager::RunTask4() {
    std::cout << "\n--- Задание 4 (Счетчик слов) ---" << std::endl;
    std::map<std::string, int> counter;
    std::string word;
    std::cout << "Введите слова ('end' для завершения): ";
    while (std::cin >> word && word != "end") {
        std::cout << ++counter[word] << " ";
    }
    std::cout << std::endl;
}
//Задание 8: работа с файлом и алгоритмами
void AssignmentManager::RunTask8() {
    std::cout << "\n--- Задание 8 (Файл и Алгоритмы) ---" << std::endl;
    std::vector<int> data;
    std::ifstream file("input.txt");

    if (!file) {
        std::cout << "Ошибка: создайте файл input.txt!" << std::endl;
        return;
    }

    int val;
    while (file >> val) data.push_back(val);
    file.close();

    // a. Поиск n
    int n;
    std::cout << "Введите число n: ";
    if (!(std::cin >> n)) return;
    std::cout << "Встречается: " << std::count(data.begin(), data.end(), n) << " раз.\n";

    // b. Четные
    int evens = std::count_if(data.begin(), data.end(), [](int x) { return x % 2 == 0; });
    if (evens > (data.size() - evens)) {
        std::cout << "Сумма всех: " << std::accumulate(data.begin(), data.end(), 0LL) << std::endl;
    }

    // c. Сортировка
    std::cout << "Исходный: "; Print(data, " ");
    std::sort(data.begin(), data.end());
    std::cout << "Сортированный: "; Print(data, " ");

    // d. Swap
    if (data.size() >= 2) std::swap(data.front(), data.back());
    std::cout << "После swap: "; Print(data, " ");
}