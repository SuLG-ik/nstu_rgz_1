//
// Created by Володя on 25.05.2024.
//

#include <stdlib.h>
#include "LinkedListItem.h"

LinkedListItem *CreateItem(Monitor *value) {
    LinkedListItem *item = malloc(sizeof(LinkedListItem));
    item->value = value;
    item->next = NULL;
    return item;
}

void DeepRemove(LinkedListItem **list) {
    if (*list == NULL)
        return;
    DeepRemove(&((*list)->next));
    free((*list)->value);
    free(*list);
    *list = NULL;
}
