#include "Level.h"

Level* Level::instance = nullptr;

void Level::reset() {
    level = 2;
}

void Level::inc() {
    level += 2;
}

int Level::getLevel() {
    return level;
}
