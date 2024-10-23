#include <iostream>
using namespace std;
class node{
public:
int data;
node* next;
node* prev;
node (int val) {
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
void deleteFromStart(node* &head) {
if (head == NULL) {
cout << "List is empty. No node to delete." << endl;
return;
}
node* temp = head;
head = head->next;
if (head != NULL) {
head->prev = NULL;
}
delete temp;
}
void deleteFromEnd(node* &head) {
if (head == NULL) {
cout << "List is empty. No node to delete." << endl;
return;
}
if (head->next == NULL) {
delete head;
head = NULL;
return;
}
node* current = head;
while (current->next != NULL) {
current = current->next;
}
current->prev->next = NULL;
delete current;
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
insertnode(head, 3);
insertnode(head, 5);
insertnode(head, 7);
insertnode(head, 9);
cout << "Original list: ";
display(head);
int choice;
cout << "Enter 1 to delete from start, or 2 to delete from end: ";
cin >> choice;
if (choice == 1) {
deleteFromStart(head);
cout << "List after deleting from start: ";
}
else if (choice == 2) {
deleteFromEnd(head);
cout << "List after deleting from end: ";
}
else {
cout << "Invalid choice!" << endl;
}
display(head);
return 0;
}

