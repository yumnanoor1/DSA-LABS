#include <iostream>
using namespace std;

class node {
	public:
    int data;
    node *next;
    node(int value) {
        data = value;
        next = nullptr;
    }
};

void insertAtEnd(node *&head, int value) {
    node *newnode = new node(value);
    if (head == nullptr) {
        head = newnode;
        newnode->next = head; 
    } else {
        node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head; 
    }
}

void deleteAtStart(node *&head) {
    if (head == nullptr) return;

    node *temp = head;
    if (head->next == head) { 
        delete head;
        head = nullptr;
    } else {
    
        while (temp->next != head) {
            temp = temp->next;
        }
        
        temp->next = head->next;
        delete head;
        head = temp->next;
    }
}

void deleteAtEnd(node *&head) {
    if (head == nullptr) return;

    node *temp = head;
    if (head->next == head) { 
        delete head;
        head = nullptr;
    } else {
        node *prev = nullptr;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        delete temp; 
    }
}

void deleteAtMid(node *&head, int position) {
    if (head == nullptr || position < 1) return; 

    if (position == 1) {
        deleteAtStart(head);
        return;
    }

    node *temp = head;
    node *prev = nullptr;
    int count = 1;

    while (temp->next != head && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (count == position) {
        prev->next = temp->next; 
        delete temp; 
    } else {
        cout << "Position not found" << endl;
    }
}

void printList(node *head) {
    if (head == nullptr) return; 

    node *temp = head;
    do {
        cout << temp->data<<"  ";
        temp = temp->next;
    } while (temp != head);
    cout<<endl;
}

int main() {
    node *head = nullptr;
    int value;

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
     insertAtEnd(head,4);
    insertAtEnd(head, 5);
    
    cout << "List before any deletion:" << endl;
    printList(head);

    deleteAtStart(head);
    cout << "after deletion at start:" << endl;
    printList(head);

    
    deleteAtEnd(head);
    cout << "after deletion at end:" << endl;
    printList(head);

    
    
    int position;
    cout << "Enter position to delete : ";
    cin >> position;
    deleteAtMid(head, position);
    
    cout << "List after deleting at position " << position << ":" << endl;
    printList(head);

    return 0;
}

