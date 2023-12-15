#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
#include "DFA.h"

int main() {
    setlocale(LC_ALL, "RU");

    std::unordered_set<int> states = { 1, 2, 3, 4 };

    // Первый алфавит (изменено на 5 символов)
    std::unordered_set<std::string> alphabet1 = { "hockey", "basketball", "football", "100", "new" };

    // Второй алфавит (изменено на 4 символа)
    std::unordered_set<size_t> alphabet2 = { '+', 20, '-', 40 };

    int initialState = 1;
    int outputState = 4;

    // Таблица переходов для алфавита
    std::unordered_map<int, std::unordered_map<std::string, int>> transitionTable1 = {
        {1, {{"hockey", 2}, {"basketball", 2}, {"football", 3}, {"100", 5},{"new",4}}},
        {2, {{"hockey", 3}, {"basketball", 5}, {"football", 1}, {"100", 2},{"new",4}}},
        {3, {{"hockey", 4}, {"basketball", 1}, {"football", 2}, {"100", 3},{"new",5}}},
        {4, {{"hockey", 1}, {"basketball", 3}, {"football", 4}, {"100", 1},{"new",4}}},
        {5, {{"hockey", 2}, {"basketball", 5}, {"football", 1}, {"100", 3},{"new",4}}},
    };

    std::unordered_map<int, std::unordered_map<size_t, int>> transitionTable2 = {
        {1, {{'+', 2}, {20, 4}, {'-', 4}, {40, 3}}},
        {2, {{'+', 4}, {20, 3}, {'-', 2}, {40, 2}}},
        {3, {{'+', 1}, {20, 2}, {'-', 1}, {40, 4}}},
        {4, {{'+', 3}, {20, 1}, {'-', 3}, {40, 1}}},
    };

    // Создание объекта DFA для алфавита
    DFA<int, std::string> dfa1(states, alphabet1, initialState, outputState, transitionTable1, 5);

    // Проверка строки для алфавита
    std::vector<std::string> testInput1 = { "basketball", "hockey", "100", "football", "hockey", "basketball", "100" ,"new" };
    bool result1 = dfa1.checkString(testInput1);

    // Вывод результата для алфавита
    std::cout << "Строка " << (result1 ? "принята" : "отклонена") << " автоматом." << std::endl;

    // Создание объекта DFA для второго алфавита
    DFA<int, size_t> dfa2(states, alphabet2, initialState, outputState, transitionTable2, 4);

    std::vector<size_t> testInput2 = { '+', 20, '+', 40, '-', 20 };
    bool result2 = dfa2.checkString(testInput2);

    std::cout << "Строка 2 " << (result2 ? "принята" : "отклонена") << " автоматом." << std::endl;

    return 0;
}