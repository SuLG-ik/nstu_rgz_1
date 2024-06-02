//
// Created by Володя on 25.05.2024.
//

#ifndef RGZ1_MENU_H
#define RGZ1_MENU_H

typedef enum Menu {
    INIT = -1, QUIT = 0, ADD = 1, REMOVE = 2, PRINT = 3, SELECTION,
    UNKNOWN, DESTROY,
} Menu;

Menu IntToMenu(int value);

#endif //RGZ1_MENU_H
