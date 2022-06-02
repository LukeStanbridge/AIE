#include <iostream>
#include "LinkedLists.h"
using namespace std;

class Node
{
public:
    int data;
    Node* next; // Pointer to next node in DLL
    Node* prev; // Pointer to previous node in DLL
};

// Add a node at the front
void pushFront(Node** head_ref, int new_data)
{
    // Allocate node
    Node* new_node = new Node();

    // Put in the data
    new_node->data = new_data;

    // Make next of new node as head and previous as NULL
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    // Change prev of head node to new node
    if ((*head_ref) != NULL)
    {
        (*head_ref)->prev = new_node;
    }

    // Move the head to point to the new node
    (*head_ref) = new_node;
}

// Add node to the back
void pushBack(Node** head_ref, int new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node();

    Node* last = *head_ref; /* used in step 5*/

    /* 2. put in the data */
    new_node->data = new_data;

    /* 3. This new node is going to be the last node, so
        make next of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new
        node as head */
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
    {
        last = last->next;
    }     

    /* 6. Change the next of last node */
    last->next = new_node;

    /* 7. Make last node as previous of new node */
    new_node->prev = last;

    return;
}

// Insert a node
void insert(Node* prevNode, int newData)
{
    // check if given prevNode is NULL
    if (prevNode == NULL)
    {
        cout << "the given previous node cannot be NULL";
        return;
    }

    // allocate new node
    Node* newNode = new Node();

    // put in the data
    newNode->data = newData;

    // make next of new node as next of prevNode
    newNode->next = prevNode->next;

    // make the next of prevNode as newNode
    prevNode->next = newNode;

    // make prevNode as previous of newNode
    newNode->prev = prevNode;

    // change previous of newNode's next node
    if (newNode->next != NULL)
    {
        newNode->next->prev = newNode;
    }
}

void begin(Node* firstNode)
{
    // check if given prevNode is NULL
    if (firstNode == NULL)
    {
        cout << "the first node cannot be NULL";
        return;
    }
    Node* first;
    firstNode->prev = NULL;
    cout << "The first element is: ";
    while (firstNode->prev == NULL)
    {
        cout << firstNode->data << "\n";
        first = firstNode;
        firstNode->prev = firstNode;
        firstNode = firstNode->next;
    }
}

void end(Node* nullNode)
{
    // check if given prevNode is NULL
    if (nullNode == NULL)
    {
        cout << "the first node cannot be NULL";
        return;
    }
    Node* last;
    cout << "";
    while (nullNode != NULL)
    {
        last = nullNode;
        if (nullNode->next == NULL)
        {
            cout << "This node is null\n";
        }
        nullNode = nullNode->next;
    }
}

void first()
{

}

void last()
{

}

void count(Node* node)
{
    Node* last;
    int count = 0;
    
    while (node != NULL)
    {
        last = node;
        node = node->next;
        count++;
    }
    cout << "The number of elements in the list are: " << count << endl;
}

void erase(Node* deleteNode)
{

}

void remove(int sameValue)
{

}

// remove the last element
void popBack(Node** head_ref, Node* del)
{
    if (*head_ref == NULL || del == NULL)
        return;

    Node* last = *head_ref;

    while (last->next != NULL)
    {
        last = last->next;
    }

    del = last;
    last = last->prev;
    last->next = NULL;
    last->prev = last->prev;

    free(del);
    return;
}

// remove the first element
void popFront(Node** head_ref, Node* del)
{
    /* base case */
    if (*head_ref == NULL || del == NULL)
        return;

    /* If node to be deleted is head node */
    if (*head_ref == del)
        *head_ref = del->next;

    /* Finally, free the memory occupied by del*/
    free(del);
    return;
}

void empty()
{

}

void clear()
{

}

void printList(Node* node)
{
    Node* last;
    while (node != NULL)
    {
        cout << " " << node->data << " ";
        last = node;
        node = node->next;
    }

    /*cout << "\nTraversal in reverse direction \n";
    while (&last != NULL)
    {
        cout << " " << last->data << " ";
        last = last->prev;
    }*/
}

int main()
{
    /* Start with the empty list */
    Node* head = NULL;

    // Insert 6. So linked list becomes 6->NULL
    pushBack(&head, 6);

    // Insert 7 at the beginning. So
    // linked list becomes 7->6->NULL
    pushFront(&head, 7);

    // Insert 1 at the beginning. So
    // linked list becomes 1->7->6->NULL
    pushFront(&head, 1);

    // Insert 4 at the end. So linked
    // list becomes 1->7->6->4->NULL
    pushBack(&head, 4);

    // Insert 8, after 7. So linked
    // list becomes 1->7->8->6->4->NULL
    insert(head->next, 8);

    cout << "Created DLL is: ";
    printList(head);
    cout << endl;

    popFront(&head, head);/*delete first node*/

    cout << "popFront DLL is: ";
    printList(head);
    cout << endl;

    popBack(&head, head);
    cout << "popBack DLL is: ";
    printList(head);
    cout << endl;

    begin(head);
    end(head);
    count(head);

    return 0;
}
