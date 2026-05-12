#pragma once
#ifndef ASSIGNMENTS_H
#define ASSIGNMENTS_H

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>

// Задание 1: Шаблонная функция Print (реализация в .h)
template <typename T>
void Print(const T& container, const std::string& delimiter) {
    bool first = true;
    for (const auto& item : container) {
        if (!first) std::cout << delimiter;
        std::cout << item;
        first = false;
    }
    std::cout << "\n";
}

// Задание 5: Исправленный Duplicate (шаблон)
template <typename T>
void Duplicate(std::vector<T>& v) {
    size_t initialSize = v.size();
    for (size_t i = 0; i < initialSize; ++i) {
        v.push_back(v[i]);
    }
}

// Задание 7: Своя реализация Unique (шаблон)
template <typename Iter>
Iter Unique(Iter first, Iter last) {
    if (first == last) return last;
    Iter result = first;
    while (++first != last) {
        if (!(*result == *first)) {
            *(++result) = *first;
        }
    }
    return ++result;
}

// Вспомогательная функция для Задания 6 (шаблон)
template <typename Iter>
void PrintResults(Iter first, Iter last) {
    for (Iter it = first; it != last; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

// Задание 6: Исправленный Process (шаблон)
template <typename T>
void Process(const std::vector<T>& data) {
    std::vector<T> filtered;
    std::copy_if(data.begin(), data.end(), std::back_inserter(filtered),
        [](const T& x) { return x > 0; });
    PrintResults(filtered.begin(), filtered.end());
}

// Класс для решения нешаблонных задач (Задания 2, 3, 4, 8)
class AssignmentManager {
public:
    void RunTask2(); // Ассоциативные контейнеры 1
    void RunTask3(); // Ассоциативные контейнеры 2
    void RunTask4(); // Ассоциативные контейнеры 3
    void RunTask8(); // Обобщенные алгоритмы 4
};
#endif