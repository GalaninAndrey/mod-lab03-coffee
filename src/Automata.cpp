// Copyright 2024 Andrew

#include "Automata.h"

Automata::Automata() {
    state = states::OFF;
    cash = 0;
    menu = {
        { 1, { "Latte", 50 } },
        { 2, { "Cappuccino", 25 } },
        { 3, { "Water", 30 } },
        { 4, { "Espresso", 40 } },
        { 5, { "Tea", 50 } },
    };
}

void Automata::on() {
    if (state == states::OFF) {
        state = states::WAIT;
        std::cout << "Ready" << std::endl;
    }
}

void Automata::off() {
    if (state == states::WAIT) {
        state = states::OFF;
        std::cout << "Turned off" << std::endl;
    }
}

void Automata::coin(int money) {
    if (state == Automata::WAIT) {
        state = Automata::ACCEPT;
    }
    if (state == Automata::ACCEPT) {
        cash += money;
        std::cout << "Accepted" << std::endl;
    }
}

void Automata::getMenu() {
    for (const auto& [k, v] : menu)
        std::cout << k << " " << v.name << " " << v.price << "\n";
}

int Automata::getState() {
    return state;
}

void Automata::choice(int number) {
    if (state == states::ACCEPT) {
        product = menu.at(number);
        std::cout << product.name << " " << product.price << std::endl;
        state = states::CHECK;
    }
}

bool Automata::check() {
    bool result = false;
    if (state == states::CHECK) {
        if (product.price <= cash) {
            result = true;
        }
    }
    return result;
}

void Automata::cancel() {
    if (state == states::ACCEPT || state == states::CHECK) {
        product = {};
        state = states::WAIT;
    }
}

void Automata::cook() {
    if (state == states::CHECK) {
        if (check()) {
            cash -= product.price;
            std::cout << "Cooking" << std::endl;
            state = states::COOK;
        }
    }
}

void Automata::finish() {
    if (state == states::COOK) {
        std::cout << "Ready" << std::endl;
        state = states::WAIT;
    }
}
