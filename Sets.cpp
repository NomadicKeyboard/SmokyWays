#include <iostream>
#include <set>
#include <vector>

void insertSets(std::set<int>& A, std::vector<int>& B) {
    std::set<int> unionSet, intersectionSet;
    std::cout << "Inserted sets for B: ";
    for (int i = 0; i < B.size(); i++) {
        A.insert(B[i]);
        std::cout << B[i] << " ";
        unionSet.insert(B[i]);
        if (A.find(B[i]) != A.end()) {
            intersectionSet.insert(B[i]);
        }
    }
    std::cout << std::endl;
    std::cout << "Union of sets A and B = {";
    for (auto it = unionSet.begin(); it != unionSet.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << "}" << std::endl;
    std::cout << "Intersection of the sets A and B = {";
    for (auto it = intersectionSet.begin(); it != intersectionSet.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << "}" << std::endl;
    std::cout << "Number of sets in the Union: " << unionSet.size() << std::endl;
    std::cout << "Number of sets in the Intersection: " << intersectionSet.size() << std::endl;
}

int main() {
    std::set<int> A = {1, 3, 4, 6, 7, 9};
    std::cout << "Given Sets A = {";
    for (auto it = A.begin(); it != A.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << "}" << std::endl;

    int n;
    while (true) {
        std::cout << "How many numbers of sets you want to insert: ";
        std::cin >> n;
        if (n > 0) {
            break;
        }
        std::cout << "Invalid input. Please enter a positive integer." << std::endl;
    }

    std::vector<int> B(n);
    for (int i = 0; i < n; i++) {
        std::cout << "Insert a number for sets B: ";
        std::cin >> B[i];
    }

    insertSets(A, B);

    while (true) {
        char choice;
        std::cout << "Do you want to try again? (y/n): ";
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            A.clear();
            std::cout << "Given Sets A = {";
            for (auto it = A.begin(); it != A.end(); it++) {
                std::cout << *it << ", ";
            }
            std::cout << "}" << std::endl;
            std::cin.ignore();
            main();
        }
        else if (choice == 'n' || choice == 'N') {
            break;
        }
        else {
            std::cout << "Invalid choice. Please enter 'y' or 'n'." << std::endl;
        }
    }

    return 0;
}
