#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
#include "DFA.h"

int main() {
    setlocale(LC_ALL, "RU");

    std::unordered_set<int> states = { 1, 2, 3, 4 };

    // Первый алфавит
    std::unordered_set<std::string> alphabet1 = { "hockey", "basketball", "football", "100" };

    // Второй алфавит
    std::unordered_set<size_t> alphabet2 = { '+', '-',10 , 40 };

    int initialState = 1;
    int outputState = 4;

    // Таблица переходов для алфавита
    std::unordered_map<int, std::unordered_map<std::string, int>> transitionTable1 = {
        {1, {{"hockey", 2}, {"basketball", 2}, {"football", 3}, {"100", 4}}},
        {2, {{"hockey", 3}, {"basketball", 4}, {"football", 1}, {"100", 2}}},
        {3, {{"hockey", 4}, {"basketball", 1}, {"football", 2}, {"100", 3}}},
        {4, {{"hockey", 1}, {"basketball", 3}, {"football", 4}, {"100", 1}}},
    };

    std::unordered_map<int, std::unordered_map<size_t, int>> transitionTable2 = {
        {1, {{'+', 2}, {10, 4}, {'-', 4}, {40, 3}}},
        {2, {{'+', 4}, {10, 3}, {'-', 2}, {40, 2}}},
        {3, {{'+', 1}, {10, 2}, {'-', 1}, {40, 4}}},
        {4, {{'+', 3}, {10, 1}, {'-', 3}, {40, 1}}},
        {5, {{'+', 3}, {10, 2}, {'-', 1}, {40, 3}}},
        {6, {{'+', 1}, {10, 3}, {'-', 4}, {40, 2}}},
    };

    // Создание объекта DFA для алфавита
    DFA<int, std::string> dfa1(states, alphabet1, initialState, outputState, transitionTable1);

    // Проверка строки для алфавита
    std::vector<std::string> testInput1 = { "basketball", "hockey", "100", "football", "hockey", "basketball", "100" };
    bool result1 = dfa1.checkString(testInput1);

    // Вывод результата для алфавита
    std::cout << "Строка " << (result1 ? "принята" : "отклонена") << " автоматом." << std::endl;

    DFA<int, size_t> dfa2(states, alphabet2, initialState, outputState, transitionTable2);

    std::vector<size_t> testInput2 = { '+', 10, '+', 40,'-', 10 };
    bool result2 = dfa2.checkString(testInput2);

    std::cout << "Строка 2 " << (result2 ? "принята" : "отклонена") << " автоматом." << std::endl;

    return 0;
}