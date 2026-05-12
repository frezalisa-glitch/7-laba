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

//задание 1: шаблонная функция Print (реализация в .h)
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
//задание 5: исправленный Duplicate (шаблон)
template <typename T>
void Duplicate(std::vector<T>& v) {
    size_t initialSize = v.size();
    for (size_t i = 0; i < initialSize; ++i) {
        v.push_back(v[i]);
    }
}
//задание 7: своя реализация Unique (шаблон)
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
//класс для решения заданий 2, 3, 4, 8
class AssignmentManager {
public:
    void RunTask2(); //ассоциативные контейнеры 1
    void RunTask3(); //ассоциативные контейнеры 2
    void RunTask4(); //ассоциативные контейнеры 3
    void RunTask8(); //обобщенные алгоритмы 4
};
#endif