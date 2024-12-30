#include <iostream>
using namespace std;

// Definition for a singly-linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Recursive function to reverse the linked list
void reverse(Node** head) {
    if (*head == nullptr || (*head)->next == nullptr) {
        return; // Base case: empty list or single node list
    }

    Node* rest = (*head)->next;
    reverse(&rest); // Recursively reverse the rest of the list

    (*head)->next->next = *head; // Adjust the next pointer of the following node
    (*head)->next = nullptr;    // Set the current node's next pointer to null

    *head = rest; // Update the head pointer to the new head
}

// Utility function to print the list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original list: ";
    printList(head);

    reverse(&head); // Reverse the list

    cout << "Reversed list: ";
    printList(head);

    return 0;
}
