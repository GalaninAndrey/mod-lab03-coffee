// Copyright 2024 Andrew

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

class Automata {
 public:
    enum states {
        OFF,
        WAIT,
        ACCEPT,
        CHECK,
        COOK
    };
    Automata();
    void on();
    void off();
    void coin(const int money);
    void getMenu();
    int getState();
    void choice(int number);
    bool check();
    void cancel();
    void cook();
    void finish();

 private:
    struct coffe {
        std::string name;
        int price;
    };
    std::map<int, coffe> menu;
    int cash;
    states state;
    coffe product;
};

#endif //INCLUDE_AUTOMATA_H_
