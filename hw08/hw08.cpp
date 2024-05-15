#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    Node* left;
    Node* right;
    Node(int id) : id(id), left(nullptr), right(nullptr) {}
};

Node* root = nullptr;

Node* insertNode(Node* node, int id) {
    if (node == nullptr) {
        return new Node(id);
    }
    if (id < node->id) {
        node->left = insertNode(node->left, id);
    } else if (id > node->id) {
        node->right = insertNode(node->right, id);
    }
    return node;
}

bool searchNode(Node* node, int id) {
    if (node == nullptr) {
        return false;
    }
    if (id == node->id) {
        return true;
    }
    return id < node->id ? searchNode(node->left, id) : searchNode(node->right, id);
}

// node -> left -> right
void preorder(Node* node) {
    if (node != nullptr) {
        cout << node->id << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

// left -> node -> right
void inorder(Node* node) {
    if (node != nullptr) {
        inorder(node->left);
        cout << node->id << " ";
        inorder(node->right);
    }
}

// left -> right -> node
void postorder(Node* node) {
    if (node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        cout << node->id << " ";
    }
}

void insert(int id) {
    if (searchNode(root, id) == true) {
        cout << id << " already exists in the library.\n";
    } else {
        root = insertNode(root, id);
    }
}

void check(int id) {
    if (searchNode(root, id) == true) {
        cout << id << " exists in the library.\n";
    } else {
        cout << id << " does not exist in the library.\n";
    }
}

void show() {
    cout << "Preorder: ";
    preorder(root);
    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << "\n";
}

void end() {
    show();
}

int main() {
    string command;

    while (cin >> command, command != "end") {
        if (command == "insert") {
            int id;
            cin >> id;
            insert(id);
        } else if (command == "check") {
            int id;
            cin >> id;
            check(id);
        } else if (command == "show") {
            show();
        }
    }

    end();

    return 0;
}
