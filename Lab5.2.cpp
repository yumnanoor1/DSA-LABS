#include <iostream>
using namespace std;
class node {
public:
int data;
node* next;
node* prev;
node(int val) {
data = val;
next = NULL;
prev = NULL;
}
};
void insertnode(node* &head, int val) {
node* newNode = new node(val);
if (head != NULL) {
head->prev = newNode;
}
newNode->next = head;
head = newNode;
}
void insertAtStart(node* &head, int val) {
node* newNode = new node(val);
if (head == NULL) {
head = newNode;
} else {
newNode->next = head;
head->prev = newNode;
head = newNode;
}
}
void insertAtEnd(node* &head, int val) {
node* newNode = new node(val);
if (head == NULL) {
head = newNode;
} else {
node* current = head;
while (current->next != NULL) {
current = current->next;
}
current->next = newNode;
newNode->prev = current;
}
}
void display(node* head) {
node* current = head;
while (current != NULL) {
cout << current->data << " ";
current = current->next;
}
cout << endl;
}
int main() {
node* head = NULL;
int choice, val;
insertnode(head, 3);
insertnode(head, 5);
insertnode(head, 7);
insertnode(head, 9);
cout << "Original list: ";
display(head);
cout << "Where do you want to insert the node"<<endl;
cout << "1. Insert at Start"<<endl;
cout << "2. Insert at End"<<endl;
cout << "Enter your choice: ";
cin >> choice;
cout << "Enter the value to insert: ";
cin >> val;
if (choice == 1) {
insertAtStart(head, val);
} else if (choice == 2) {
insertAtEnd(head, val);
} else {
cout << "Invalid choice!" << endl;
return 1;
}
cout << "Updated list: ";
display(head);
return 0;
}
