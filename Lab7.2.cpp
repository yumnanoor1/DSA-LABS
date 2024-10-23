#include <iostream>

using namespace std;

struct Node {
    string data;   // Item name
    Node* next;   
};


class GroceryList {
private:
    Node* top; // Pointer to the top of the stack

public:

    GroceryList() {
        top = nullptr;
    }

    // Function to add an item (push into stack)
    void addItem(string item) {
        Node* newNode = new Node(); 
        newNode->data = item;      
        newNode->next = top;    
        top = newNode;            
        cout << item << " added to the grocery list.\n";
    }
    void removeItem() {
        if (top == nullptr) {
            cout << "The grocery list is empty, nothing to remove.\n";
            return;
        }

              string removedItem = top->data;
        Node* temp = top;   
        top = top->next;   
        delete temp;        
        cout << removedItem << " removed from the grocery list.\n";
    }

        void displayList() {
        if (top == nullptr) {
            cout << "The grocery list is empty.\n";
            return;
        }

        Node* current = top;
        cout << "Grocery list items:\n";
        while (current != nullptr) {
            cout << "- " << current->data << endl;
            current = current->next;
        }
    }

      ~GroceryList() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    GroceryList list;

    int choice;
    string item;

    do {
        cout << "\nGrocery List Menu:\n";
        cout << "1. Add an item\n";
        cout << "2. Remove the last added item\n";
        cout << "3. View all items\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character after the number input

        switch (choice) {
            case 1:
                cout << "Enter the item to add: ";
                getline(cin, item);
                list.addItem(item);
                break;
            case 2:
                list.removeItem();
                break;
            case 3:
                list.displayList();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

