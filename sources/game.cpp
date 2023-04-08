#include "game.hpp"
#include <stdexcept>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <random>
#include <array>

#define DECK_SIZE 52

using namespace ariel;
using namespace std;

namespace ariel {

    //why const ?is it even ok?
    Game::Game(ariel::Player &player1, ariel::Player &player2):
    player1(player1),player2(player2){

    }

    void Game::playAll() {

    }

    void Game::playTurn() {

    }

    void Game::printLastTurn() const {

    }

    void Game::printLog() {

    }

    void Game::printStats() {

    }

    void Game::printWiner() {

    }

}
