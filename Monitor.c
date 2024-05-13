//
// Created by Володя on 13.05.2024.
//

#include "Monitor.h"
#include <string.h>
#include <stdio.h>

void InitMonitor(Monitor *monitor, char *vendor, char *model, int price, int amountLeft) {
    strncpy(monitor->vendor, strlen(vendor) >= VENDOR_SIZE_MIN ? vendor : VENDOR_DEFAULT, VENDOR_SIZE_MAX);
    strncpy(monitor->model, strlen(model) >= MODEL_SIZE_MIN ? model : MODEL_DEFAULT, MODEL_SIZE_MAX);
    monitor->price = price >= PRICE_MIN ? price : PRICE_DEFAULT;
    monitor->amountLeft = amountLeft >= AMOUNT_LEFT_MIN ? amountLeft : AMOUNT_LEFT_DEFAULT;
    monitor->isInitialized = 1;
}

void PrintMonitor(Monitor monitor) {
    if (!monitor.isInitialized) {
        printf("Monitor does not initialized yet. Nothing to print\n");
        return;
    }
    printf("Monitor{ vendor=%s, model=%s, price=%d, amountLeft=%d }\n", monitor.vendor, monitor.model, monitor.price,
           monitor.amountLeft);
}

int IsMonitorsEqual(Monitor *monitor1, Monitor *monitor2) {
    return (monitor1 == monitor2) ||
           (monitor1->isInitialized && monitor2->isInitialized && strcmp(monitor1->model, monitor2->model) == 0 &&
            strcmp(monitor1->vendor, monitor2->vendor) == 0 && monitor1->price == monitor2->price &&
            monitor1->amountLeft == monitor2->amountLeft);
}

int IsMonitorLess(Monitor monitor1, Monitor monitor2) {
    return CalculateHash(monitor1) < CalculateHash(monitor2);
}

long CalculateHash(Monitor monitor) {
    if (!monitor.isInitialized)
        return -1;
    long hash;
    hash = strlen(monitor.vendor);
    hash += strlen(monitor.model) * 100;
    hash += monitor.price * monitor.amountLeft * 10000;
    return hash;
}

