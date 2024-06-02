//
// Created by Володя on 25.05.2024.
//

#ifndef RGZ1_LINKEDLIST_H
#define RGZ1_LINKEDLIST_H

#include <stdlib.h>
#include "LinkedListItem.h"

typedef struct LinkedList {
    LinkedListItem *head;
} LinkedList;

LinkedList *CreateList();

/**
 * sorted insert to LinkedList
 * @param list
 * @param value
 */
void Insert(LinkedList *list, Monitor *value);

/**
 * Count size of LinkedList
 * @param list
 * @return
 */
int Count(LinkedList *list);

/**
 * Get LinkedListItem from position or NULL if index is out of range
 * @param index
 * @return
 */
LinkedListItem *Get(LinkedList *list, int index);

int Remove(LinkedList *list, int index);

void RemoveAll(LinkedList **list);

void PrintList(LinkedList *list);

void WriteList(int fd, LinkedList *list);

int ReadList(int fd, LinkedList *list);

#endif //RGZ1_LINKEDLIST_H
