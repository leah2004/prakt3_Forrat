#pragma once
#include "Node.h"
#include <iostream>
class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_front(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        if (tail == nullptr) tail = newNode;
        head = newNode;   
    }

    void push_back(int data) {
        Node* newNode = new Node(data);
        newNode->prev = tail;
        if (tail != nullptr) {
            tail->next = newNode;
        }
        if (head == nullptr) head = newNode;
        tail = newNode;
    }

    void pop_front() {
        if (head == nullptr) { 
            std::cout << "Ой! Список пустой, нам нечего удалять" << std::endl;
            return;
        }
        Node* temp = head; 
        head = head->next; 
        if (head != nullptr) { 
            head->prev = nullptr; 
        }
        else {
            tail = nullptr; 
        }
        delete temp; 
    }

    void pop_back() {
        if (tail == nullptr) {
            std::cout << "Список пуст, удалять нечего." << std::endl;
            return;
        }
        Node* temp = tail; 
        tail = tail->prev; 
        if (tail != nullptr) {
            tail->next = nullptr; 
        }
        else {
            head = nullptr;
        }
        delete temp; 
    }

    void display() {
        Node* current = head;
        if (current == nullptr) {
            std::cout << "Список пустой" << std::endl;
            return;
        }

        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    void sort() {
        if (head == nullptr) return; 
        Node* current = head->next; 
        while (current != nullptr) {
            Node* key = current; 
            Node* prev = current->prev; 
            while (prev != nullptr && prev->data > key->data) {
                if (prev->prev != nullptr) {
                    prev->prev->next = key; 
                }
                else {
                    head = key; 
                }
                key->prev = prev->prev;
                prev->next = key->next; 

                if (key->next != nullptr) {
                    key->next->prev = prev; 
                }
                else {
                    tail = prev; 
                }
                key->next = prev; 
                prev->prev = key; 
                prev = key->prev;
            }
            current = current->next;
        }
    }

    void remove_duplicates() {
        if (head == nullptr) return; 
        Node* current = head; 

        while (current != nullptr) {
            Node* runner = current->next; 

            while (runner != nullptr) {
                if (runner->data == current->data) { 
                    Node* toDelete = runner; 
                    runner = runner->next; 
                    if (toDelete->prev != nullptr) {
                        toDelete->prev->next = toDelete->next; 
                    }
                    else {
                        head = toDelete->next; 
                    }
                    if (toDelete->next != nullptr) {
                        toDelete->next->prev = toDelete->prev; 
                    }
                    else {
                        tail = toDelete->prev; 
                    }
                    delete toDelete; 
                }
                else {
                    runner = runner->next; 
                }
            }
            current = current->next; 
        }
    }
};

