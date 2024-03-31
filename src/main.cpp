// Copyright 2024 Andrew

#include "Automata.h"

int main() {
    Automata coffee;
    coffee.on();
    coffee.coin(25);
    coffee.choice(2);
    coffee.cancel();
    coffee.coin(25);
    coffee.choice(5);
    coffee.check();
    coffee.cook();
    coffee.finish();
    coffee.off();
}
