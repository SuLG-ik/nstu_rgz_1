//
// Created by Володя on 13.05.2024.
//

#ifndef RGZ1_MONITOR_H
#define RGZ1_MONITOR_H

#include <stdio.h>

#define VENDOR_SIZE_MAX 20
#define VENDOR_SIZE_MIN 1

#define MODEL_SIZE_MAX 20
#define MODEL_SIZE_MIN 1

#define VENDOR_DEFAULT "no data"
#define MODEL_DEFAULT "no data"

#define PRICE_DEFAULT 100000000
#define PRICE_MIN 1

#define AMOUNT_LEFT_DEFAULT 0
#define AMOUNT_LEFT_MIN 1

/**
 * vendor - size between VENDOR_SIZE_MIN to VENDOR_SIZE_MAX
 * model - size between MODEL_SIZE_MIN to MODEL_SIZE
 * price – between 1 to INT_MAX
 * amountLeft – between 0 to INT_MAX
 */
typedef struct Monitor {
    char vendor[VENDOR_SIZE_MAX], model[MODEL_SIZE_MAX];
    int price, amountLeft, isInitialized;
} Monitor;

/**
 * Initialization function for Monitor
 * @param monitor pointer to initialize
 * @param vendor size between VENDOR_SIZE_MIN to VENDOR_SIZE_MAX
 * @param model size between MODEL_SIZE_MIN to MODEL_SIZE
 * @param price between 1 to INT_MAX
 * @param amountLeft between 0 to INT_MAX
 */
Monitor *InitMonitor(char *vendor, char *model, int price, int amountLeft);

/**
 * Print monitor debug info into default output stream.
 * @param monitor
 */
void PrintMonitor(Monitor monitor);

/**
 * Compare two monitors of equality
 * @param monitor1 first element to compare
 * @param monitor2 second element to compare
 * @return 1 if monitors content equals and both initialized, 0 if not or at least one is not initialized
 */
int IsMonitorsEqual(Monitor *monitor1, Monitor *monitor2);


/**
 * Calculate hash that represent logical size of Monitor
 * @param monitor for what hash should be calculated
 * @return calculated hash that represent logical size of Monitor or -1 if not initialized
 */
long CalculateHash(Monitor monitor);

/**
 * Compare two monitors that left less that right
 * @param monitor1 left element to compare
 * @param monitor2 right element to compare
 * @return 1 if left less than right, 0 if not
 */
int IsMonitorLess(Monitor monitor1, Monitor monitor2);

void WriteLaptop(int fd, Monitor *monitor);

Monitor *ReadMonitor(int fd);

#endif //RGZ1_MONITOR_H
