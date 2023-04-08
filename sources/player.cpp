#include "player.hpp"
#include <stdexcept>
#include <cstring>
#define NUM_OF_CARDS 26

using namespace ariel;
using namespace std;

namespace ariel {
    Player::Player() {
        this->name="avi";
    }

    Player::Player(string name) {
        if(name.empty()){
            throw invalid_argument("you did not enter a name");
        }
        this->name = name;
    }

    int Player::cardesTaken() const {
        return this->winnings;
    }

    int Player::stacksize() const {
        return this->CardIndex + 1;
    }
}
