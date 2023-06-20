// Path: C++\Searching\sublist_search.c
// C++ program to check whether the first list is present in 2nd list or not, when two linked lists are given.
// Time-Complexity: O(M*N), where M is the number of nodes in the second list and N in the first.
// Auxiliary-Space: O(1).

#include <iostream>
using namespace std;

// Structure for a node
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a node at the end of a linked list
void insertAtEnd(Node **head, int data)
{
    // Create a new node
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    // Traverse to the last node
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = newNode;
}

// Function to display a linked list
void displayList(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
        cout << "NULL";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Returns true if first list is present in second list else false
bool isSublist(Node *list1, Node *list2)
{
    // If both linked lists are empty, return true
    if (list1 == NULL && list2 == NULL)
        return true;

    // Else, if one is empty and the other is not, return false
    if (list1 == NULL || (list1 != NULL && list2 == NULL))
        return false;

    // current1 is to traverse in list1 and current2 in list2
    Node *current1 = list1;
    Node *current2 = list2;

    // Traverse the second list by picking nodes one by one
    while (list2 != NULL)
    {
        // Initialize current2 pointer with the current node of the second list
        current2 = list2;

        // Start matching the first list with the second list
        while (current1 != NULL)
        {
            // If the second list becomes empty and the first list does not, return false
            if (current2 == NULL)
                return false;

            // If the data part is the same, go to the next nodes of both lists
            else if (current1->data == current2->data)
            {
                current1 = current1->next;
                current2 = current2->next;
            }

            // If they are not equal, break the loop
            else
                break;
        }

        // Return true if the first list gets traversed completely, indicating it is matched
        if (current1 == NULL)
            return true;

        // Initialize current1 pointer with first again
        current1 = list1;

        // Move to the next node of the second list
        list2 = list2->next;
    }

    return false;
}

// Program starts here
int main()
{
    // Create the first linked list
    Node *list1 = NULL;

    // Size of list1
    int N;
    cout << "No of Nodes in the first list: ";
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int data;
        cout << "data " << i + 1 << ": ";
        cin >> data;

        insertAtEnd(&list1, data);
    }
    cout << endl;

    // insertAtEnd(&list1, 1);
    // insertAtEnd(&list1, 2);
    // insertAtEnd(&list1, 4);

    // for (int i = 1; i <= 10; i++) {
    // insertAtEnd(&list2, i);
    // }

    // Create the second linked list
    Node *list2 = NULL;

    // Size of list2
    int M;
    cout << "No of Nodes in the second list: ";
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int data;
        cout << "data " << i + 1 << ": ";
        cin >> data;

        insertAtEnd(&list2, data);
    }
    cout << endl;

    // Display the first linked list
    cout << "List 1: ";
    displayList(list1);

    // Display the second linked list
    cout << "List 2: ";
    displayList(list2);
    cout << endl;

    // Check if the first list is a sublist of the second list
    bool result = isSublist(list1, list2);
    cout << "Is the first list a sublist of the second list? ";

    if (result)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}
