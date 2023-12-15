
#define DFA_CPP  

#include "DFA.h"
#include <iostream>

template <typename State, typename Symbol>
DFA<State, Symbol>::DFA(const std::unordered_set<State>& states,
    const std::unordered_set<Symbol>& alphabet,
    const State& initial,
    const State& output,
    const std::unordered_map<State, std::unordered_map<Symbol, State>>& transitionTable)
    : initialState(initial), outputState(output), transitions(transitionTable) {

    if (states.find(initial) == states.end() ||
        states.find(output) == states.end() ||
        alphabet.size() != 4) {
        throw std::invalid_argument("Неверные параметры DFA");
    }
}

template <typename State, typename Symbol>
bool DFA<State, Symbol>::checkString(const std::vector<Symbol>& input) {
    State currentState = initialState;
    size_t currentIndex = 0;

    for (const Symbol& symbol : input) {
        if (transitions[currentState].find(symbol) == transitions[currentState].end()) {
            return false;
        }

        currentState = transitions[currentState][symbol];

        if (currentState == outputState && currentIndex == input.size() - 1) {
            return true;
        }

        currentIndex++;
    }

    return false;
}