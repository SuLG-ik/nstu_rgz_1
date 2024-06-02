cmake_minimum_required(VERSION 3.28)
project(rgz1 C)

set(CMAKE_C_STANDARD 11)

add_executable(rgz1 main.c
        Monitor.c
        Monitor.h
        LinkedList.c
        LinkedList.h
        LinkedListItem.c
        LinkedListItem.h
        Menu.c
        Menu.h
)
