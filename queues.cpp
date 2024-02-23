#include <iostream>
#include <queue>

using namespace std;

void displayQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int choice, num;

    do {
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number to insert: ";
                cin >> num;
                if (q.size() >= 5) {
                    cout << "Queue is full. Deleting the last element." << endl;
                    q.pop();
                }
                q.push(num);
                break;
            case 2:
                if (q.empty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Deleting the first element: " << q.front() << endl;
                    q.pop();
                }
                break;
            case 3:
                cout << "Enter the number to search: ";
                cin >> num;
                {
                    queue<int> temp = q;
                    bool found = false;
                    while (!temp.empty()) {
                        if (temp.front() == num) {
                            found = true;
                            break;
                        }
                        temp.pop();
                    }
                    if (found) {
                        cout << "Number found in the queue." << endl;
                    } else {
                        cout << "Number not found in the queue." << endl;
                    }
                }
                break;
            case 4:
                if (q.empty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue contents: ";
                    displayQueue(q);
                }
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}

