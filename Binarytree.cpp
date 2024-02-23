#include <iostream>
using namespace std;

// Structure for a node in the BST
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory allocation failed!" << endl;
        return nullptr;
    }
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to insert a value into the BST
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Function to search for a value in the BST
Node* searchNode(Node* root, int value) {
    if (root == nullptr || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return searchNode(root->left, value);
    }
    return searchNode(root->right, value);
}

// Function to find the minimum value in the BST
Node* findMin(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to find the maximum value in the BST
Node* findMax(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}

// Function to delete a value from the BST
Node* deleteNode(Node* root, int value) {
    if (root == nullptr) {
        return root;
    }
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform inorder traversal of the BST
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Function to perform preorder traversal of the BST
void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    Node* root = nullptr;
    int choice, value;
    char repeat;

    do {
        cout << "1. Insert a value" << endl;
        cout << "2. Search for a value" << endl;
        cout << "3. Delete a value" << endl;
        cout << "4. View inorder traversal" << endl;
        cout << "5. View preorder traversal" << endl;
        cout << "6. Find the root" << endl;
        cout << "7. Find the lowest value" << endl;
        cout << "8. Find the largest value" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                root = insertNode(root, value);
                break;
            case 2:
                cout << "Enter the value to search: ";
                cin >> value;
                if (searchNode(root, value) != nullptr) {
                    cout << "Value found in the BST!" << endl;
                } else {
                    cout << "Value not found in the BST!" << endl;
                }
                break;
            case 3:
                cout << "Enter the value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;
            case 4:
                cout << "Inorder traversal: ";
                inorderTraversal(root);
                cout << endl;
                break;
            case 5:
                cout << "Preorder traversal: ";
                preorderTraversal(root);
                cout << endl;
                break;
            case 6:
                cout << "Root of the BST: " << root->data << endl;
                break;
            case 7:
                cout << "Lowest value in the BST: " << findMin(root)->data << endl;
                break;
            case 8:
                cout << "Largest value in the BST: " << findMax(root)->data << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
