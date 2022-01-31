#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <functions.h>
#include <engine.h>

void loop(monster mon1, monster mon2) {
    moves moveChosen;
    moves moveChosen2;
    
    intro();

    while(true) {
        moveChosen = chooseMove(mon1);
        moveChosen2 = chooseMove(mon2);

        battle(&mon1, &mon2, moveChosen, moveChosen2);

        if(mon1.hp <= 0 || mon2.hp <= 0) {
            break;
        }
    }

}

int main() {
    types grass = {"grass", 0, 1, 2};
    types fire = {"fire", 1, 2, 0};
    //types water = {"water", 2, 3, 1};
    types normal = {"normal", 3, 10, 10};

    // Variables for debugging purposes
    types noType = {"no type", 99, 99, 99};
    moves noMove = {"no move", 0, false, 99, noType, false};
    effects noEffect = {"no effect", true, 99};
    abilities noAbility = {"no ability", false, noEffect, false };

    effects burn = { "burn", false, 0 };
    //effects paralysis = { "paralysis", false, 1 };
    //effects poison = { "poison", false, 2 };

    moves growl = { "growl", 0, true, 0, normal, false };
    moves attack = { "attack", 5, true, 1, normal, true };
    moves ember = { "ember", 8, true, 2, fire, false };
    //moves spray = { "spray", 8, true, 3, water };
    moves cut = { "cut", 8, true, 4, grass, true };

    //abilities toxic = { "toxic", false, poison, false };
    abilities blaze = { "blaze", false, burn, false };

    monster mon1 = { "Archie", 20, 5, 8, 12, {growl, attack, ember, noMove}, {fire, noType}, blaze, noEffect, 0 };
    monster mon2 = { "Denchi", 24, 6, 6, 10, {growl, attack, cut, noMove}, {grass, noType}, noAbility, noEffect, 1 };
    //monster mon3 = { "Enty", 22, 5, 12, 8, growl, attack, spray, water, 2 };

    // Main game loop
    loop(mon1, mon2);

    // Make sure terminal doesn't close forcefully
    clearScreen();

    // Exit gracefully
    return 0;
}