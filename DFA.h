#pragma once
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>

template <typename State, typename Symbol>
class DFA {
private:
    std::unordered_map<State, std::unordered_map<Symbol, State>> transitions;
    State initialState;
    State outputState;

public:
    DFA(const std::unordered_set<State>& states,
        const std::unordered_set<Symbol>& alphabet,
        const State& initial,
        const State& output,
        const std::unordered_map<State, std::unordered_map<Symbol, State>>& transitionTable);

    bool checkString(const std::vector<Symbol>& input);
};

#ifndef DFA_CPP
#include "DFA.cpp"
#endif