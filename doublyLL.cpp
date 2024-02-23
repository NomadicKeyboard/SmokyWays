#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Class for Doubly Linked List operations
class DoublyLinkedList {
private:
    Node* head;

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the beginning of the list
    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        }

        head = newNode;
    }

    // Function to delete a node from the list
    void remove(int value) {
        Node* current = head;

        while (current != nullptr) {
            if (current->data == value) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }

                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }

                delete current;
                break;
            }

            current = current->next;
        }
    }

    // Function to search for a node in the list
    bool search(int value) {
        Node* current = head;

        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }

            current = current->next;
        }

        return false;
    }

    // Function to traverse and print the list
    void traverse() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    int choice, value;
    char tryAgain;

    do {
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Traverse" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                list.insert(value);
                break;
            case 2:
                cout << "Enter the value to delete: ";
                cin >> value;
                list.remove(value);
                break;
            case 3:
                cout << "Enter the value to search: ";
                cin >> value;
                if (list.search(value)) {
                    cout << "Value found in the list." << endl;
                } else {
                    cout << "Value not found in the list." << endl;
                }
                break;
            case 4:
                cout << "List: ";
                list.traverse();
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }

        cout << "Do you want to try again? (y/n): ";
        cin >> tryAgain;
    } while (tryAgain == 'y' || tryAgain == 'Y');

    return 0;
}