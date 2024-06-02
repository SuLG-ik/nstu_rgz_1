#include <stdio.h>
#include <sys/file.h>
#include <libc.h>
#include "Monitor.h"
#include "Menu.h"
#include "LinkedList.h"

//int main1(void) {
//    Monitor monitor1, monitor2, monitor3, monitor4, monitor5;
//    InitMonitor(&monitor1, "ABC", "DEF", 100, 1);
//    InitMonitor(&monitor2, "ABC", "DEF", 100, 1);
//    InitMonitor(&monitor3, "A", "EF", 5100, 12);
//    InitMonitor(&monitor4, "AB", "DEF", 104210, 43);
//    InitMonitor(&monitor5, "", "E", -10, 0);
//    PrintMonitor(monitor1);
//    PrintMonitor(monitor2);
//    PrintMonitor(monitor3);
//    PrintMonitor(monitor4);
//    PrintMonitor(monitor5);
//    printf("%d", IsMonitorsEqual(&monitor1, &monitor2));
//    printf("%d", IsMonitorsEqual(&monitor1, &monitor3));
//    printf("%d\n", IsMonitorsEqual(&monitor1, &monitor1));
//    printf("%d", IsMonitorLess(monitor1, monitor2));
//    printf("%d", IsMonitorLess(monitor2, monitor3));
//    printf("%d", IsMonitorLess(monitor3, monitor4));
//    printf("%d", IsMonitorLess(monitor4, monitor5));
//    return 0;
//}

Monitor *InputMonitor() {
    char vendor[VENDOR_SIZE_MAX], model[MODEL_SIZE_MAX];
    int amount, price;
    printf("Vendor name: ");
    scanf("%s", vendor);
    printf("Model: ");
    scanf("%s", model);
    printf("Amount left: ");
    scanf("%d", &amount);
    printf("Price: ");
    scanf("%d", &price);
    return InitMonitor(vendor, model, price, amount);
}

Menu SelectionMenu(LinkedList *list) {
    int input;
    printf("Select option:\n\n");
    printf("0. Quit\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. Print item\n");
    printf("\nUser input: ");
    scanf("%d", &input);
    return IntToMenu(input);
}

Menu InitMenu(LinkedList *list) {
    printf("Reading from file...\n");
    int fd = open("data.bin", O_RDWR);
    if (ReadList(fd, list) > 0) {
        printf("Loaded data from file\n");
    } else {
        printf("Data does not loaded\n");
    }
    close(fd);
    return SELECTION;
}

Menu UnknownMenu(LinkedList *list) {
    printf("Unknown option. Try again\n");
    return SELECTION;
}

Menu AddMenu(LinkedList *list) {
    Monitor *monitor = InputMonitor();
    Insert(list, monitor);
    return SELECTION;
}

Menu RemoveMenu(LinkedList *list) {
    int index;
    printf("Index to remove: ");
    scanf("%d", &index);
    if (Remove(list, index) != 0) {
        printf("Successfully removed\n");
    } else {
        printf("No item with index %d\n", index);
    }
    return SELECTION;
}

Menu PrintMenu(LinkedList *list) {
    PrintList(list);
    return SELECTION;
}

Menu QuitMenu(LinkedList *list) {
    printf("\n Quiting. Saving to File\n");
    int fd = open("data.bin", O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR);
    WriteList(fd, list);
    close(fd);
    RemoveAll(&list);
    return DESTROY;
}

int main(void) {
    LinkedList *list = CreateList();
    Menu menu = INIT;
    while (menu != DESTROY) {
        switch (menu) {
            case INIT:
                menu = InitMenu(list);
                break;
            case ADD:
                menu = AddMenu(list);
                break;
            case REMOVE:
                menu = RemoveMenu(list);
                break;
            case PRINT:
                menu = PrintMenu(list);
                break;
            case SELECTION:
                menu = SelectionMenu(list);
                break;
            case UNKNOWN:
                menu = UnknownMenu(list);
                break;
            case QUIT:
                menu = QuitMenu(list);
                break;
            case DESTROY:
                break;
        }
    }
    return 0;
}
