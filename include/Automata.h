#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
using namespace std;
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
        string name;
        int price;
    };
    map<int, coffe> menu;
    int cash;
    states state;
    coffe product;
};
