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

#pragma region Inserting and deleting a node at the front of the list
// Insert a node at the front of the list
void pushFront(Node** head_ref, int new_data)
{
    Node* new_node = new Node(); // Allocate node
    new_node->data = new_data; // Put in the data
    new_node->next = (*head_ref); // Make next of new node as head and previous as NULL
    new_node->prev = NULL;

    if (*head_ref != NULL) // Change prev of head node to new node
    {
        (*head_ref)->prev = new_node;
    }

    (*head_ref) = new_node; // Move the head to point to the new node
}

// Delete a node at the front of the list
void popFront(Node** head_ref, Node* del)
{
    if (*head_ref == NULL || del == NULL) //base case
        return;

    if (*head_ref == del) // If node to be deleted is head node
        *head_ref = del->next;

    free(del); // free the memory occupied by del
    return;
}
#pragma endregion

#pragma region Inserting and deleting a node at the end of the list
void pushBack(Node** head_ref, int new_data) // Insert a node at the end of the list
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

void popBack(Node** head_ref, Node* del) // Delete a node at the end of the list.
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
#pragma endregion

#pragma region Returning a count of how many nodes are in the list
int countList(class Node* head)
{
    // Declare temp pointer to
    // traverse the list
    class Node* temp = head;

    // Variable to store the count
    int count = 0;

    // Iterate the list and increment the count
    while (temp->next != head && temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    // As the list is circular, increment the
    // counter at last
    count++;

    return count;
}
#pragma endregion

#pragma region Inserting and deleting a node at an arbitrary location in the list
bool insertAtLocation(class Node** head_ref, int data, int loc)
{

    class Node* temp = new Node(); // Declare two nodes
    class Node* newNode = new Node();
    int counter;

    temp = *head_ref; // Point temp to head_ref

    // count of total elements in the list
    counter = countList(*head_ref);

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

void deleteNode(class Node** head_ref, class Node* del)
{
    /* base case */
    if (*head_ref == NULL || del == NULL)
        return;

    /* If node to be deleted is head node */
    if (*head_ref == del)
        *head_ref = del->next;

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
void erase(class Node** head_ref, int position)
{
    if (*head_ref == NULL || position <= 0) // if list in NULL or invalid position is given
        return;

    class Node* current = *head_ref;

    for (int i = 1; current != NULL && i < position; i++) // traverse up to the node at position 'n' from the beginning
        current = current->next;

    if (current == NULL) // if 'n' is greater than the number of nodes in the doubly linked list
        return;

    deleteNode(head_ref, current); // delete the node pointed to by 'current'
}

// Remove all elements with matching value
void remove(class Node** head_ref, int key)
{
    if (*head_ref == NULL) // if list in NULL or invalid position is given
        return;

    class Node* current = *head_ref;
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

    deleteNode(head_ref, current); // delete the node pointed to by 'current'
}
#pragma endregion

#pragma region Checking if the list is empty
void empty(Node** head_ref)
{
    if (*head_ref == NULL)
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
void begin(Node* firstNode)
{  
    if (firstNode == NULL) // check if given prevNode is NULL
    {
        cout << "the first node is NULL" << endl;
        return;
    }

    cout << "The first element is: " << firstNode->data << endl;
}

// Return an iterator to a null element
void end(Node* lastNode)
{
    Node* last = new Node();
    // check if given prevNode is NULL
    if (lastNode == NULL)
    {
        cout << "the last node cannot be NULL";
        return;
    }

    do
    {
        lastNode = lastNode->next;
        last->data = lastNode->data;
    } while (lastNode->next != NULL);

    cout << "The last element is: " << last->data << endl;
}
#pragma endregion

#pragma region Sorting the list (as appropriate)
void sortedInsert(class Node** head_ref, class Node* newNode)
{
    class Node* current;

    // if list is empty
    if (*head_ref == NULL)
        *head_ref = newNode;

    // if the node is to be inserted at the beginning
    // of the doubly linked list
    else if ((*head_ref)->data >= newNode->data) {
        newNode->next = *head_ref;
        newNode->next->prev = newNode;
        *head_ref = newNode;
    }

    else {
        current = *head_ref;

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

void insertionSort(class Node** head_ref)
{
    // Initialize 'sorted' - a sorted doubly linked list
    class Node* sorted = NULL;

    // Traverse the given doubly linked list and
    // insert every node to 'sorted'
    class Node* current = *head_ref;
    while (current != NULL) {

        // Store next for next iteration
        class Node* next = current->next;

        // removing all the links so as to create 'current'
        // as a new node for insertion
        current->prev = current->next = NULL;

        // insert current in 'sorted' doubly linked list
        sortedInsert(&sorted, current);

        // Update current
        current = next;
    }

    // Update head_ref to point to sorted doubly linked list
    *head_ref = sorted;
}
#pragma endregion

#pragma region Clearing and printing the list
// Remove all elements from the list
void clear(class Node** head_ref)
{  
    while (*head_ref != NULL)
    {
        class Node* current = *head_ref;
        *head_ref = current->next;
        deleteNode(head_ref, current);       
    }
}

void printList(Node* node)
{
    Node* last;
    cout << "|";
    while (node != NULL)
    {
        cout << " " << node->data << " ";
        last = node;
        node = node->next;
    }
    cout << "|" << endl;
}
#pragma endregion


int main()
{
    Node* head = NULL;
    int choice;

    do
    {
        cout << endl
            << " 1 - Insert a node at the front of the list.\n"
            << " 2 - Delete a node at the front of the list.\n"
            << " 3 - Insert a node at the end of the list.\n"
            << " 4 - Delete a node at the end of the list.\n"
            << " 5 - Insert a node at an arbitrary location in the list.\n"
            << " 6 - Delete a node at an arbitrary location in the list.\n"
            << " 7 - Delete a node with a specific value in the list.\n"
            << " 8 - Return a count of how many nodes are in the list.\n"
            << " 9 - Check if the list is empty.\n"
            << " 10 - Return the first node in the list.\n"
            << " 11 - Return the last node in the list.\n"
            << " 12 - Sort the list.\n"
            << " 13 - Clear the contents of the list.\n"
            << " 14 - Print the list.\n"
            << " 15 - Exit Program.\n\n"
            << " Enter your choice and press return: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            int insertFront;
            cout << "Enter a value to put at the front of the list and press return: ";
            cin >> insertFront;
            pushFront(&head, insertFront);
            break;

        case 2:
            cout << "Deleted the node at the front of the list.\n";
            popFront(&head, head);
            break;

        case 3:
            //code
            break;
        case 4:
            //code
            break;
        case 5:
            //code
            break;
        case 6:
            //code
            break;
        case 7:
            //code
            break;
        case 8:
            //code
            break;
        case 9:
            //code
            break;
        case 10:
            //code
            break;
        case 11:
            //code
            break;
        case 12:
            //code
            break;
        case 13:
            //code
            break;

        case 14:
            cout << "Contents of list >> ";
            printList(head);
            break;

        case 15:
            cout << "End of Program.\n";
            break;

        default:
            cout << "Not a Valid Choice. \n"
                 << "Choose again.\n";
            break;
        }

    } while (choice != 15);
    return 0;
      
    /*pushBack(&head, 6);
    pushFront(&head, 7);
    pushFront(&head, 1);
    pushBack(&head, 4);

    cout << "Created DLL is:";
    printList(head);

    popFront(&head, head);

    cout << "popFront DLL is:";
    printList(head);

    popBack(&head, head);
    cout << "popBack DLL is:";
    printList(head);

    begin(head);
    end(head);
    cout << "The number of nodes in the list is: " << countList(head) << endl;

    pushFront(&head, 3);
    pushFront(&head, 4);
    pushFront(&head, 5);

    cout << "New DLL is: ";
    printList(head);

    insertAtLocation(&head, 24, 3);

    cout << "Inserted DLL is: ";
    printList(head);

    erase(&head, 5);

    cout << "Removed DLL is: ";
    printList(head);

    remove(&head, 8);

    cout << "Deleted DLL is: ";
    printList(head);

    remove(&head, 4);

    cout << "Deleted DLL is: ";
    printList(head);

    cout << "The number of nodes in the list is: " << countList(head) << endl;

    pushBack(&head, 45);
    pushBack(&head, 32);
    printList(head);

    erase(&head, 1);
    printList(head);

    begin(head);

    
    end(head);

    pushFront(&head, 69);
    begin(head);

    insertionSort(&head);
    cout << "Doubly Linked List After Sorting:";
    printList(head);

    clear(&head);
    empty(&head);

    return 0;*/
}
