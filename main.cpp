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

void createRandomList(Node *&, const int);
void deleteNodeByIndex(Node *&, const int);
void insertNodeAfterIndex(Node *&, const int);
void deleteList(Node *&);
void output(Node *);           // Outputs entire list to console
bool validNodeIndex(int);      // Tests whether a user given index is valid or out of bounds.
                               // In this case, [1,size of list)
int getLinkedListSize(Node *); // Returns the size of a linked list

int main()
{
    Node *head = nullptr;
    const int SIZE = 7; // Changed from global variable to a local variable in main
    int entry;          // To collect user input

    // int count = 0;int entry;

    // Create a linked list of size SIZE with random numbers 0-99
    cout << "Initial linked list:" << endl;
    createRandomList(head, SIZE);
    output(head);

    // Get user input asking which node to delete
    // Node *current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    // Delete selected node and output modified list
    deleteNodeByIndex(head, entry);
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    // Insert node based on user given index, and output modified list
    insertNodeAfterIndex(head, entry);
    output(head);

    // Delete the linked list and output
    deleteList(head);
    output(head);

    return 0;
}

// Creates a linked list of size SIZE with random integers
void createRandomList(Node *&head, const int SIZE)
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
    // TODO: But what if the first element was selected for deletion? Reroute head to next element
    if (current && current == head)
    {
        head = head->next;
    }
    // at this point, delete current and reroute pointers
    if (current)
    { // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
}

void insertNodeAfterIndex(Node *&head, const int index)
{
    Node *current = head;
    Node *prev = head;
    for (int i = 0; i < (index); i++)
    {
        if (i == 0)
            current = current->next;
        else
        {
            current = current->next;
            prev = prev->next;
        }
    }
    // at this point, insert a node between prev and current
    if (current != head)
    {
        Node *newnode = new Node;
        newnode->value = 10000;
        newnode->next = current;
        prev->next = newnode;
    }
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

// Returns whether a given node index is valid
bool validNodeIndex(int userInput)
{
}

// Returns size of a given linked list
int getLinkedListSize(Node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}