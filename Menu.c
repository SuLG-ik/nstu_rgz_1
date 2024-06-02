//
// Created by Володя on 25.05.2024.
//

#include "Menu.h"

Menu IntToMenu(int value) {
    switch (value) {
        case ADD:
            return ADD;
        case REMOVE:
            return REMOVE;
        case PRINT:
            return PRINT;
        case QUIT:
            return QUIT;
    }
    return UNKNOWN;
}
