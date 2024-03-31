#include <gtest/gtest.h>
#include "Automata.h"
TEST(BASE, sleep) {
    Automata coffee;
    EXPECT_EQ(0, coffee.getState());
}

TEST(BASE, turn_on) {
    Automata coffee;
    coffee.on();
    EXPECT_EQ(1, coffee.getState());
}

TEST(BASE, accept_money) {
    Automata coffee;
    coffee.on();
    coffee.coin(50);
    EXPECT_EQ(2, coffee.getState());
}

TEST(BASE, choice) {
    Automata coffee;
    coffee.on();
    coffee.coin(50);
    coffee.coin(50);
    EXPECT_EQ(2, coffee.getState());
}

TEST(BASE, check) {
    Automata coffee;
    coffee.on();
    coffee.coin(50);
    coffee.cancel();
    EXPECT_EQ(1, coffee.getState());
}

TEST(BASE, cook) {
    Automata coffee;
    coffee.on();
    coffee.coin(50);
    coffee.choice(1);
    EXPECT_EQ(3, coffee.getState());
}

TEST(BASE, finish) {
    Automata coffee;
    coffee.on();
    coffee.coin(50);
    coffee.choice(1);
    coffee.cancel();
    EXPECT_EQ(1, coffee.getState());
}

TEST(BASE, off) {
    Automata coffee;
    coffee.on();
    coffee.coin(50);
    coffee.choice(1);
    coffee.check();
    coffee.cook();
    EXPECT_EQ(4, coffee.getState());
}

TEST(BASE, insufficient_funds) {
    Automata coffee;
    coffee.on();
    coffee.coin(50);
    coffee.choice(2);
    coffee.check();
    coffee.cook();
    coffee.finish();
    coffee.off();
    EXPECT_EQ(0, coffee.getState());
}

TEST(BASE, get_money_back) {
    Automata coffee;
    coffee.on();
    coffee.coin(50);
    coffee.choice(1);
    coffee.cancel();
    coffee.off();
    EXPECT_EQ(0, coffee.getState());
}