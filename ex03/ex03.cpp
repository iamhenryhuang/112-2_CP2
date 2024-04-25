#include <iostream>

struct Node {
    int value;
    Node *nextPtr;

    // Constructor to initialize node with a value and optional next pointer
    Node(int val = 0, Node* ptr = nullptr) : value(val), nextPtr(ptr) {}
};

void create2DArray(Node **&arr, int m, int n) {
    arr = new Node*[m];  // Allocate an array of Node pointers, each will point to a linked list
    for (int i = 0; i < m; i++) {
        Node *current = nullptr, *previous = nullptr;
        for (int j = 0; j < n; j++) {
            current = new Node(n);  // Create a new node initialized with value n
            if (j == 0) {
                arr[i] = current;  // Point the array at the first node in this row
            } else {
                previous->nextPtr = current;  // Link the previous node to the current node
            }
            previous = current;  // Move previous to current
        }
        if (current) {
            current->nextPtr = nullptr;  // Last node's nextPtr should be nullptr
        }
    }
}

void free2DArray(Node **arr, int m) {
    for (int i = 0; i < m; i++) {
        Node *current = arr[i];
        while (current != nullptr) {
            Node *temp = current;
            current = current->nextPtr;
            delete temp;  // Free each node
        }
    }
    delete[] arr;  // Free the array of pointers
}

int main() {
    Node **myArray = nullptr;
    int m, n;  // n is now used as both the row length and initial value
    std::cin >> m >> n;

    create2DArray(myArray, m, n);

    for (int i = 0; i < m; i++) {
        Node *current = myArray[i];
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->nextPtr;
        }
        std::cout << std::endl;
    }

    free2DArray(myArray, m);
    return 0;
}
