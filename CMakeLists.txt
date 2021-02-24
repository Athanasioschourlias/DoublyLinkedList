cmake_minimum_required(VERSION 3.17)
project(LinkedList_C C)

set(CMAKE_C_STANDARD 99)

add_library(LinkedList_C DoublyLinkedList.c DoublyLinkedList.h)