#ifndef CPP_HW2_PLAYER_HPP
#define CPP_HW2_PLAYER_HPP

#include "card.hpp"
#include <cstring>
#include <array>

const int numOfCards = 26;
const int lastIndex = 25;

using namespace std;
namespace ariel {
    class Player {
        array<Card, numOfCards> cards;
        int CardIndex = lastIndex;
        int winnings = 0;
        string name;

    public:
        Player();

        explicit Player(string name);

        int stacksize() const;

        int cardesTaken() const;

    };
}

#endif //CPP_HW2_PLAYER_HPP
