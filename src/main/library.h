#ifndef LIBRARY_H
#define LIBRARY_H

#define WINDOWS // comment out when compiling for other OS's

#ifdef WINDOWS
#include <windows.h>
#endif

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>

// characters
#include "../character files/character.h"
#include "../character files/player.h"
#include "../character files/enemy.h"

// locations
#include "../location files/location.h"
#include "../location files/devilsCross.h"
#include "../location files/silverGate.h"
#include "../location files/wizardsTower.h"
#include "../location files/darkWoods.h"
#include "../location files/arena.h"
#include "../location files/world.h"

#include "loadSave.h"
#include "gameObj.h"

using namespace std;

#endif
