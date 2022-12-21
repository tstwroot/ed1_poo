#pragma once

class Node
{
public:
    int value;
    Node *next, *prev;
    Node(int value);
};

class LinkedList
{
public:
    void insert(int value);
    void insert(int *values, int size);
    void removeLast();
    void showList();
    LinkedList(int capacity);
    ~LinkedList();

private:
    int capacity, size;
    Node *start;
};