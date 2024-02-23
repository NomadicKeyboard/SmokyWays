#include <iostream>

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void search(int value) {
        Node* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->data == value) {
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (found) {
            std::cout << "Value " << value << " found in the linked list." << std::endl;
        } else {
            std::cout << "Value " << value << " not found in the linked list." << std::endl;
        }
    }

    void deleteNode(int value) {
        Node* temp = head;
        Node* prev = nullptr;
        bool found = false;

        while (temp != nullptr) {
            if (temp->data == value) {
                found = true;
                break;
            }
            prev = temp;
            temp = temp->next;
        }

        fouif (nd) {
            if (prev == nullptr) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            std::cout << "Node with value " << value << " deleted from the linked list." << std::endl;
        } else {
            std::cout << "Node with value " << value << " not found in the linked list." << std::endl;
        }
    }
};

int main() {
    LinkedList list;

    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.insert(20);
    list.insert(25);

    list.display();

    list.search(15);
    list.search(30);

    list.deleteNode(10);
    list.deleteNode(30);

    list.display();

    return 0;
}