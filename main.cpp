/* Lab 17: Refactor linked list to modularize code into functions.
    IDE: Vscode
*/

#include <iostream>
using namespace std;

// Linked list node struct
struct Node
{
    float value;
    Node *next;
};

Node *createList(Node *, const int);
void deleteNodeByIndex(Node *, const int);
void insertNodeByIndex(Node *, const int);
void deleteList(Node *);
void output(Node *);

int main()
{
    Node *head = nullptr;
    int count = 0;
    const int SIZE = 7; // Changed from global variable to a local variable in main

    // Create a linked list of size SIZE with random numbers 0-99
    createList(head, SIZE);
    output(head);

    // Get user input asking which node to delete
    Node *current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    deleteNodeByIndex(head, entry);
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current)
    {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    // Inserts node based on index of the list
    insertNodeByIndex(head, entry);
    output(head);

    // Delete the linked list and output
    deleteList(head);
    output(head);

    return 0;
}

// Creates a linked list of size SIZE with random integers
void createList(Node *&head, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;

        // adds node at head
        if (!head)
        { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else
        { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
}

// Deletes a node based on it's index in the linked list
void deleteNodeByIndex(Node *&head, int index)
{
    Node *current = head;
    Node *prev = head;
    for (int i = 0; i < (index - 1); i++)
        if (i == 0)
            current = current->next;
        else
        {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current)
    { // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    head = prev;
}

void insertNodeByIndex(Node *&head, const int index)
{
    Node *current = head;
    Node *prev = head;
    for (int i = 0; i < (index); i++)
        if (i == 0)
            current = current->next;
        else
        {
            current = current->next;
            prev = prev->next;
        }
    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
}

// Deletes an entire linked list node by node starting at head
void deleteList(Node *&head)
{
    Node *current = head;
    while (current)
    {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}

// Outputs linked list starting at head element
void output(Node *hd)
{
    if (!hd)
    {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current)
    {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}