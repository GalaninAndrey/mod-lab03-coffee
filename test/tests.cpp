// Copyright 2024 Andrew

#include <gtest/gtest.h>
#include "Automata.h"

TEST(BASE, 1) {
    Automata coffee;
    EXPECT_EQ(0, coffee.getState());
}

TEST(BASE, 2) {
    Automata coffee;
    coffee.on();
    EXPECT_EQ(1, coffee.getState());
}

TEST(BASE, 3) {
    Automata coffee;
    coffee.on();
    coffee.coin(50);
    EXPECT_EQ(2, coffee.getState());
}

TEST(BASE, 4) {
    Automata coffee;
    coffee.on();
    coffee.coin(50);
    coffee.coin(50);
    EXPECT_EQ(2, coffee.getState());
}

TEST(BASE, 5) {
    Automata coffee;
    coffee.on();
    coffee.coin(50);
    coffee.cancel();
    EXPECT_EQ(1, coffee.getState());
}

TEST(BASE, 6) {
    Automata coffee;
    coffee.on();
    coffee.coin(50);
    coffee.choice(1);
    EXPECT_EQ(3, coffee.getState());
}

TEST(BASE, 7) {
    Automata coffee;
    coffee.on();
    coffee.coin(50);
    coffee.choice(1);
    coffee.cancel();
    EXPECT_EQ(1, coffee.getState());
}

TEST(BASE, 8) {
    Automata coffee;
    coffee.on();
    coffee.coin(50);
    coffee.choice(1);
    coffee.check();
    coffee.cook();
    EXPECT_EQ(4, coffee.getState());
}

TEST(BASE, 9) {
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

TEST(BASE, 10) {
    Automata coffee;
    coffee.on();
    coffee.coin(50);
    coffee.choice(1);
    coffee.cancel();
    coffee.off();
    EXPECT_EQ(0, coffee.getState());
}
