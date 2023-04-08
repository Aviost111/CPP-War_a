
#include "doctest.h"
#include <iostream>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <stdexcept>

using namespace ariel;
using namespace std;

TEST_CASE("illegal player") {
    CHECK_THROWS(Player(""));

}

TEST_CASE("illegal game") {
    Player p1("Alice");
    CHECK_THROWS(Game(p1, p1));
}

TEST_CASE("no turns left") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    CHECK_NOTHROW(game.playTurn());
    CHECK_NOTHROW(game.playAll());
    CHECK_THROWS(game.playTurn());
    CHECK_THROWS(game.playAll());

}

TEST_CASE("no previous turn/has previous turn") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    CHECK_THROWS(game.printLastTurn());
    CHECK_THROWS(game.printLog());
    game.playTurn();
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
}

TEST_CASE("game over/not over") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playTurn();
    CHECK_THROWS(game.printWiner());
    game.playAll();
    CHECK_NOTHROW(game.printWiner());
}
//10
TEST_CASE("Stack size") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    CHECK((p1.stacksize() == 26));
    CHECK((p2.stacksize() == 26));
    game.playAll();
    CHECK((p2.stacksize() == 0));
    CHECK((p1.stacksize() == 0));
    CHECK((p1.cardesTaken()+p2.cardesTaken()==52));
}

TEST_CASE("cards taken") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    CHECK((p1.cardesTaken() == 0));
    CHECK((p2.cardesTaken() == 0));
    game.playTurn();
    CHECK((p2.cardesTaken() != p1.cardesTaken()));
}
//19

TEST_CASE("stats works") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playTurn();
    CHECK_NOTHROW(game.printStats());
}
