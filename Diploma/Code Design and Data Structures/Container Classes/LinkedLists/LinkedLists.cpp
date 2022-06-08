#include <iostream>
#include "LinkedLists.h"
using namespace std;


LinkedList::LinkedList()
{
    head = NULL;
}

#pragma region Inserting and deleting a node at the front of the list
// Insert a node at the front of the list
void LinkedList::pushFront(int new_data)
{
    Node* new_node = new Node(); // Allocate node
    new_node->data = new_data; // Put in the data
    new_node->next = (head); // Make next of new node as head and previous as NULL
    new_node->prev = NULL;

    if (head != NULL) // Change prev of head node to new node
    {
        (head)->prev = new_node;
    }

    (head) = new_node; // Move the head to point to the new node
}

// Delete a node at the front of the list
void LinkedList::popFront()
{
    Node* del = head;
    if (head == NULL) //base case
        return;

        head = del->next;

    free(del); // free the memory occupied by del
    return;
}
#pragma endregion

#pragma region Inserting and deleting a node at the end of the list
void LinkedList::pushBack(int new_data) // Insert a node at the end of the list
{
    Node* new_node = new Node(); /* 1. allocate node */
    Node* last = head; /* used in step 5*/
    new_node->data = new_data; /* 2. put in the data */
    new_node->next = NULL; /* 3. This new node is going to be the last node, so make next of it as NULL*/
    
    if (head == NULL) /* 4. If the Linked List is empty, then make the node as head */
    {
        new_node->prev = NULL;
        head = new_node;
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

void LinkedList::popBack() // Delete a node at the end of the list.
{
    
    if (head == NULL)
        return;

    Node* del = head;
    Node* last = head;

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
#pragma endregion

#pragma region Returning a count of how many nodes are in the list
int LinkedList::countList()
{
    // Declare temp pointer to
    // traverse the list
    class Node* temp = head;

    // Variable to store the count
    int count = 0;

    // Iterate the list and increment the count
    while (temp != NULL) 
    {
        count++;
        temp = temp->next;
    }
    return count;
}
#pragma endregion

#pragma region Inserting and deleting a node at an arbitrary location in the list
bool LinkedList::insertAtLocation(int data, int loc)
{

    class Node* temp = new Node(); // Declare two nodes
    class Node* newNode = new Node();
    int counter;

    temp = head; // Point temp to head_ref

    // count of total elements in the list
    counter = countList();

    // If list is empty or the position is
    // not valid, return false
    if (temp == NULL || counter < loc)
        return false;

    else {
        // Assign the data
        newNode->data = data;

        // Iterate till the loc
        for (int i = 1; i < loc - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next; // insert new node
        (temp->next)->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;

        return true;
    }

    return false;
}

void LinkedList::deleteNode(Node* del)
{
    
    /* base case */
    if (head == NULL || del == NULL)
        return;

    /* If node to be deleted is head node */
    if (head == del)
        head = del->next;

    /* Change next only if node to be deleted is NOT
       the last node */
    if (del->next != NULL)
        del->next->prev = del->prev;

    /* Change prev only if node to be deleted is NOT
       the first node */
    if (del->prev != NULL)
        del->prev->next = del->next;

    /* Finally, free the memory occupied by del*/
    free(del);
}

// Remove an element by its iterator
void LinkedList::erase(int position)
{
    if (head == NULL || position <= 0) // if list in NULL or invalid position is given
        return;

    class Node* current = head;

    for (int i = 1; current != NULL && i < position; i++) // traverse up to the node at position 'n' from the beginning
        current = current->next;

    if (current == NULL) // if 'n' is greater than the number of nodes in the doubly linked list
        return;

    deleteNode(current); // delete the node pointed to by 'current'
}

// Remove all elements with matching value
void LinkedList::remove(int key)
{
    if (head == NULL) // if list in NULL or invalid position is given
        return;

    class Node* current = head;
    class Node* newNode = new Node(); // allocate new node
    newNode->data = key;

    while (current != NULL)
    {
        if (current->data == newNode->data)
        {
            break;
        }
        current = current->next;
    }

    if (current == NULL) // if the value you want to delete is not in the doubly linked list
        return;

    deleteNode(current); // delete the node pointed to by 'current'
}
#pragma endregion

#pragma region Checking if the list is empty
void LinkedList::empty()
{
    if (head == NULL)
    {
        cout << "This list is empty" << endl;
    }
    else
    {
        cout << "The list is not empty" << endl;
    }
}
#pragma endregion

#pragma region Returning the first or last node in the list
// Return the first element
void LinkedList::begin()
{  
    if (head == NULL) // check if given prevNode is NULL
    {
        cout << "the first node is NULL" << endl;
        return;
    }

    cout << "The first element is: " << head->data << endl;
}

// Return an iterator to a null element
void LinkedList::end()
{
    Node* last = new Node();
    // check if given prevNode is NULL
    if (head == NULL)
    {
        cout << "the last node cannot be NULL";
        return;
    }

    do
    {
        head = head->next;
        last->data = head->data;
    } while (head->next != NULL);

    cout << "The last element is: " << last->data << endl;
}
#pragma endregion

#pragma region Sorting the list (as appropriate)
void LinkedList::sortedInsert(class Node* newNode)
{
    class Node* current;

    // if list is empty
    if (head == NULL)
        head = newNode;

    // if the node is to be inserted at the beginning
    // of the doubly linked list
    else if (head->data >= newNode->data) {
        newNode->next = head;
        newNode->next->prev = newNode;
        head = newNode;
    }

    else {
        current = head;

        // locate the node after which the new node
        // is to be inserted
        while (current->next != NULL &&
            current->next->data < newNode->data)
            current = current->next;

        /*Make the appropriate links */

        newNode->next = current->next;

        // if the new node is not inserted
        // at the end of the list
        if (current->next != NULL)
            newNode->next->prev = newNode;

        current->next = newNode;
        newNode->prev = current;
    }
}

void LinkedList::insertionSort()
{
    // Initialize 'sorted' - a sorted doubly linked list
    class Node* sorted = NULL;

    // Traverse the given doubly linked list and
    // insert every node to 'sorted'
    class Node* current = head;
    while (current != NULL) {

        // Store next for next iteration
        class Node* next = current->next;

        // removing all the links so as to create 'current'
        // as a new node for insertion
        current->prev = current->next = NULL;

        // insert current in 'sorted' doubly linked list
        sortedInsert(current);

        // Update current
        current = next;
    }

    // Update head_ref to point to sorted doubly linked list
    head = sorted;
}
#pragma endregion

#pragma region Clearing and printing the list
// Remove all elements from the list
void LinkedList::clear()
{  
    while (head != NULL)
    {
        class Node* current = head;
        head = current->next;
        deleteNode(current);
    }
}

void LinkedList::printList()
{
    Node* temp = head;
    cout << "|";
    while (temp != NULL)
    {
        cout << " " << temp->data << " ";
        
        temp = temp->next;
    }
    cout << "|" << endl;
    delete temp;
}
#pragma endregion


