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
    std::unordered_set<std::string> alphabet2 = { "sport", "aqua", "chess", "animal"};

    int initialState = 1;
    int outputState = 4;

    // Таблица переходов для алфавита
    std::unordered_map<int, std::unordered_map<std::string, int>> transitionTable1 = {
        {1, {{"hockey", 2}, {"basketball", 2}, {"football", 3}, {"100", 4}}},
        {2, {{"hockey", 3}, {"basketball", 4}, {"football", 1}, {"100", 2}}},
        {3, {{"hockey", 4}, {"basketball", 1}, {"football", 2}, {"100", 3}}},
        {4, {{"hockey", 1}, {"basketball", 3}, {"football", 4}, {"100", 1}}},
    };

    std::unordered_map<int, std::unordered_map<std::string, int>> transitionTable2 = {
        {1, {{"sport", 2}, {"aqua", 4}, {"chess", 4}, {"animal", 3}}},
        {2, {{"sport", 4}, {"aqua", 3}, {"chess", 2}, {"animal", 2}}},
        {3, {{"sport", 1}, {"aqua", 2}, {"chess", 1}, {"animal", 4}}},
        {4, {{"sport", 3}, {"aqua", 1}, {"chess", 3}, {"animal", 1}}},
    };

    // Создание объекта DFA для алфавита
    DFA<int, std::string> dfa1(states, alphabet1, initialState, outputState, transitionTable1);

    // Проверка строки для алфавита
    std::vector<std::string> testInput1 = { "basketball", "hockey", "100", "football", "hockey", "basketball", "100" };
    bool result1 = dfa1.checkString(testInput1);

    // Вывод результата для алфавита
    std::cout << "Строка " << (result1 ? "принята" : "отклонена") << " автоматом." << std::endl;

    DFA<int, std::string> dfa2(states, alphabet2, initialState, outputState, transitionTable2);

    std::vector<std::string> testInput2 = { "sport","aqua","sport","animal","chess","aqua" };
    bool result2 = dfa2.checkString(testInput2);

    std::cout << "Строка 2 " << (result2 ? "принята" : "отклонена") << " автоматом." << std::endl;

    return 0;
}