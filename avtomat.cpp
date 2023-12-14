#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>

template <typename State, typename Symbol>
class DFA {
private:
    // Таблица переходов между состояниями по символам
    std::unordered_map<State, std::unordered_map<Symbol, State>> transitions;

    State initialState;
    State outputState;

public:
    // Конструктор DFA, принимающий множества состояний и алфавита,начальное и конечное состояния, а также таблицу переходов
    DFA(const std::unordered_set<State>& states,
        const std::unordered_set<Symbol>& alphabet,
        const State& initial,
        const State& output,
        const std::unordered_map<State, std::unordered_map<Symbol, State>>& transitionTable)
        : initialState(initial), outputState(output), transitions(transitionTable) {

        // Проверка входных данных
        if (states.find(initial) == states.end() ||
            states.find(output) == states.end() ||
            alphabet.size() != 4) {
            throw std::invalid_argument("Неверные параметры DFA");
        }
    }

    // Метод для проверки строки на принадлежность языку, определенному DFA
    bool checkString(const std::vector<Symbol>& input) {
        State currentState = initialState;
        size_t currentIndex = 0;

        for (const Symbol& symbol : input) {
            // Если нет перехода для текущего состояния и символа
            if (transitions[currentState].find(symbol) == transitions[currentState].end()) {
                return false;
            }

            currentState = transitions[currentState][symbol];

            // Проверка, является ли текущее состояние конечным и индекс находится в конце
            if (currentState == outputState && currentIndex == input.size() - 1) {
                return true;
            }

            currentIndex++;
        }

        return false;
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    std::unordered_set<int> states = { 1, 2, 3, 4 };

    // Используемые слова 
    std::unordered_set<std::string> alphabet = { "hockey", "basketball", "football", "100" };

    int initialState = 1;
    int outputState = 4;

    //Таблица переходов для DFA
    std::unordered_map<int, std::unordered_map<std::string, int>> transitionTable = {
        {1, {{"hockey", 2}, {"basketball", 2}, {"football", 3}, {"100", 4}}},
        {2, {{"hockey", 3}, {"basketball", 4}, {"football", 1}, {"100", 2}}},
        {3, {{"hockey", 4}, {"basketball", 1}, {"football", 2}, {"100", 3}}},
        {4, {{"hockey", 1}, {"basketball", 3}, {"football", 4}, {"100", 1}}},
    };

    // Создание объекта DFA
    DFA<int, std::string> dfa(states, alphabet, initialState, outputState, transitionTable);

    // Проверка строки
    std::vector<std::string> testInput = { "basketball", "hockey", "100", "football", "hockey", "basketball","100" };
    bool result = dfa.checkString(testInput);

    // Вывод результата
    std::cout << "Строка " << (result ? "принята" : "отклонена") << " автоматом." << std::endl;

    return 0;
}