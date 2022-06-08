#pragma once
class LinkedList
{
private:
    class Node
    {
    public:
        int data;
        Node* next; // Pointer to next node in DLL
        Node* prev; // Pointer to previous node in DLL
    };
    Node* head;


public:
    LinkedList();


    void pushFront(int new_data);
    void popFront();
    void pushBack(int new_data);
    void popBack();
    int countList();
    bool insertAtLocation(int data, int loc);
    void deleteNode(Node* del);
    void erase(int position);
    void remove(int key);
    void empty();
    void begin();
    void end();
    void sortedInsert(Node* newNode);
    void insertionSort();
    void clear();
    void printList();
};



