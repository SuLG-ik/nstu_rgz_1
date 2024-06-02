//
// Created by Володя on 25.05.2024.
//

#include <sys/file.h>
#include <unistd.h>
#include <tclDecls.h>
#include "LinkedList.h"

LinkedList *CreateList() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

void Insert(LinkedList *list, Monitor *value) {
    if (list == NULL) {
        return;
    }
    if (list->head == NULL) {
        list->head = CreateItem(value);
        return;
    }
    LinkedListItem *q = list->head;
    while (q->next != NULL) {
        if (IsMonitorLess(*value, *(q->value))) {
            list->head = CreateItem(value);
            list->head->next = q;
            return;
        }
    }
    q->next = CreateItem(value);
}

int Count(LinkedList *list) {
    int count = 0;
    LinkedListItem *q = list->head;
    while (q != NULL) {
        count++;
        q = q->next;
    }
    return count;
}

LinkedListItem *Get(LinkedList *list, int index) {
    int count = 0;
    LinkedListItem *q = list->head;
    while (q != NULL) {
        if (count == index)
            return q;
        count++;
        q = q->next;
    }
    return NULL;
}

void RemoveAll(LinkedList **list) {
    DeepRemove(&((*list)->head));
    free(*list);
    (*list) = NULL;
}

int Remove(LinkedList *list, int index) {
    if (index == 0) {
        LinkedListItem *next = list->head->next;
        free(list->head);
        list->head = next;
        return 1;
    }
    int count = 0;
    LinkedListItem *prev = list->head;
    LinkedListItem *q = list->head->next;
    while (q != NULL) {
        if (count == index) {
            LinkedListItem *next = q->next;
            prev->next = next;
            free(q);
            return 1;
        }
        count++;
        prev = q;
        q = q->next;
    }
    return 0;
}

void PrintList(LinkedList *list) {
    LinkedListItem *q = list->head;
    int c = 0;
    while (q != NULL) {
        printf("[%d] ", c);
        PrintMonitor(*(q->value));
        q = q->next;
        c++;
    }
}

void WriteList(int fd, LinkedList *list) {
    LinkedListItem *q = list->head;
    int size = Count(list);
    write(fd, &size, sizeof(int));
    while (q != NULL) {
        WriteLaptop(fd, q->value);
        q = q->next;
    }
}

int ReadList(int fd, LinkedList *list) {
    int size = 0;
    if (read(fd, &size, sizeof(int)) == EOF || size == 0) {
        return size;
    }
    for (int i = 0; i < size; ++i) {
        Monitor *monitor = ReadMonitor(fd);
        if (monitor == NULL)
            return size;
        Insert(list, monitor);
    }
    return size;
}
