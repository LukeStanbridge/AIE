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

// Add new value to the front of the list
void pushFront(Node** head_ref, int new_data)
{
    Node* new_node = new Node(); // Allocate node
    new_node->data = new_data; // Put in the data
    new_node->next = (*head_ref); // Make next of new node as head and previous as NULL
    new_node->prev = NULL;

    if ((*head_ref) != NULL) // Change prev of head node to new node
    {
        (*head_ref)->prev = new_node;
    }

    (*head_ref) = new_node; // Move the head to point to the new node
}

// Add new value to the end of the list
void pushBack(Node** head_ref, int new_data)
{
    Node* new_node = new Node(); /* 1. allocate node */
    Node* last = *head_ref; /* used in step 5*/
    new_node->data = new_data; /* 2. put in the data */
    new_node->next = NULL; /* 3. This new node is going to be the last node, so make next of it as NULL*/
    
    if (*head_ref == NULL) /* 4. If the Linked List is empty, then make the node as head */
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
 
    while (last->next != NULL) /* 5. Else traverse till the last node */
    {
        last = last->next;
    }     

    last->next = new_node; /* 6. Change the next of last node */
    new_node->prev = last; /* 7. Make last node as previous of new node */
    return;
}

// Add a new value one-past the specified iterator location
void insert(Node* prevNode, int newData)
{
    if (prevNode == NULL) // check if given prevNode is NULL
    {
        cout << "the given previous node cannot be NULL";
        return;
    }

    Node* newNode = new Node(); // allocate new node
    newNode->data = newData; // put in the 
    newNode->next = prevNode->next; // make next of new node as next of 
    prevNode->next = newNode; // make the next of prevNode as 
    newNode->prev = prevNode; // make prevNode as previous of newNode

    if (newNode->next != NULL) // change previous of newNode's next node
    {
        newNode->next->prev = newNode;
    }
}

// Return an iterator to the first element
void begin(Node* firstNode)
{  
    if (firstNode == NULL) // check if given prevNode is NULL
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

// Return an iterator to a null element
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

// Return the first element by value, assert if no elements
void first()
{

}

// Return the last element by value, assert if no elements
void last()
{

}

// Return how many elements exist in the list
void count(Node* node)
{
    int count = 0;
    
    while (node != NULL)
    {
        node = node->next;
        count++;
    }

    cout << "The number of elements in the list are: " << count << endl;
}

// Remove an element by its iterator
void erase(Node* deleteNode)
{

}

// Remove all elements with matching value
void remove(Node** head, int key)
{
    Node* temp;
    while ((*head) != NULL)
    {
        if ((*head)->data == key)
        {
            temp = *head;    //backup the head to free its memory
            
            free(temp);
        }
        (*head) = (*head)->next;
    }
}

// Remove the last element
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

// Remove the first element
void popFront(Node** head_ref, Node* del)
{
    if (*head_ref == NULL || del == NULL) /* base case */
        return;
  
    if (*head_ref == del) /* If node to be deleted is head node */
        *head_ref = del->next;
    
    free(del); /* Finally, free the memory occupied by del*/
    return;
}

// Return a Boolean, true if the list is empty, false otherwise
void empty()
{

}

// Remove all elements from the list
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

    // Insert 4 at the tail. So linked
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

    pushFront(&head, 3);
    pushFront(&head, 4);
    pushFront(&head, 5);

    cout << "New DLL is: ";
    printList(head);
    cout << endl;

    remove(&head, 5);

    cout << "Removed DLL is: ";
    printList(head);
    cout << endl;

    remove(&head, 8);

    cout << "Removed DLL is: ";
    printList(head);
    cout << endl;

    return 0;
}
