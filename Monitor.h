//
// Created by Володя on 13.05.2024.
//

#ifndef RGZ1_MONITOR_H
#define RGZ1_MONITOR_H
#define VENDOR_SIZE 20
#define MODEL_SIZE 20

/**
 * vendor, model - size between 1 to 20
 * price – between 1 to INT_MAX, amountLeft – between 0 to INT_MAX
 */
typedef struct Monitor {
    char vendor[VENDOR_SIZE], model[MODEL_SIZE];
    int price, amountLeft;
} Monitor;

#endif //RGZ1_MONITOR_H
