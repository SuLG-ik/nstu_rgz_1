//
// Created by Володя on 25.05.2024.
//

#ifndef RGZ1_LINKEDLISTITEM_H
#define RGZ1_LINKEDLISTITEM_H


#include "Monitor.h"

typedef struct LinkedListItem{
    Monitor *value;
    struct LinkedListItem *next;
} LinkedListItem;

LinkedListItem* CreateItem(Monitor *value);

void DeepRemove(LinkedListItem **list);

#endif //RGZ1_LINKEDLISTITEM_H
