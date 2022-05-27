#include "Event.h"
#include "SDL.h"
#include <iostream>
#include <bits/stdc++.h>
#include <BuildGame.h>
#include <Table.h>

using namespace std;

Event e;

bool Table::CheckQuit() {
    return e.GetEvent();
}



