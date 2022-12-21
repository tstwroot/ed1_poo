#include <iostream>
#include "ll.hpp"

Node::Node(int value)
{
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
}

LinkedList::LinkedList(int capacity)
{
    this->capacity = capacity;
    this->size = 0;
    this->start = nullptr;
}

LinkedList::~LinkedList()
{
    if(this->start == nullptr || this->size == 0)
    {
        return;
    }
    Node *aux = this->start;
    while(aux->next != nullptr)
    {
        aux = aux->next;
    }
    while(aux != this->start)
    {
        aux = aux->prev;
        delete aux->next;
        this->size--;
    }
    delete aux;
    this->size--;
}

void LinkedList::insert(int value)
{
    if(this->start == nullptr || this->size == 0)
    {
        this->start = new Node(value);
        this->start->prev = nullptr;
        this->size++;
        return;
    }
    Node *aux = this->start;
    while(aux->next != nullptr)
    {
        aux = aux->next;
    }
    aux->next = new Node(value);
    aux->next->prev = aux;
    this->size++;
    return;
}

void LinkedList::insert(int *values, int size)
{
    for(int i = 0; i < size; i++)
    {
        LinkedList::insert(values[i]);
    }
}

void LinkedList::removeLast()
{
    if(this->size == 0 || this->start == nullptr)
    {
        return;
    }
    Node *aux = this->start;
    while(aux->next != nullptr)
    {
        aux = aux->next;
    }
    aux->prev->next = nullptr;
    delete aux;
    this->size--;
    return;
}

void LinkedList::showList()
{
    if(this->size == 0 || this->start == nullptr)
    {
        return;
    }
    Node *aux = this->start;
    std::cout << "[";
    while(aux != nullptr)
    {
        std::cout << aux->value << " -> ";
        aux = aux->next;
    }
    std::cout << "nullptr]\n";
}