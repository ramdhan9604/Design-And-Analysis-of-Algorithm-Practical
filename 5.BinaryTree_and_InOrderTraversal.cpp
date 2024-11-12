#include <iostream>
using namespace std;

// Node structure representing each element in the binary search tree
struct Node {
    int data;           // Data held by the node
    Node* left = nullptr;  // Pointer to the left child
    Node* right = nullptr; // Pointer to the right child

    // Constructor to initialize a new node with given data
    Node(int data) : data(data) {}
};

// Function to insert a new node with given data into the binary search tree
Node* insertNode(Node* root, int data) {
    // If tree is empty, create a new node and return it as the root
    if (!root) {
        return new Node(data);
    }
    // If data is smaller, insert it in the left subtree
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } 
    // If data is greater, insert it in the right subtree
    else {
        root->right = insertNode(root->right, data);
    }
    return root;  // Return the (unchanged) root pointer
}

// Function to perform in-order traversal of the binary search tree
void inOrderTraversal(Node* root) {
    if (root) {  // If the node is not null
        inOrderTraversal(root->left);        // Traverse left subtree
        cout << root->data << " ";           // Print current node data
        inOrderTraversal(root->right);       // Traverse right subtree
    }
}

int main() {
    int arr[] = {23, 15, 7, 18, 50, 34, 42, 70, 11, 2, 20, 30, 25, 47, 60}; // Array of elements to insert
    Node* root = nullptr; // Initialize root as nullptr for an empty tree

    // Insert each element in the array into the binary search tree
    for (int num : arr) {
        root = insertNode(root, num);
    }

    // Perform in-order traversal to print elements in sorted order
    cout << "In-order traversal of the binary tree: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}

// ***********************************OUTPUT*******************************
//   In-order traversal of the binary tree: 2 7 11 15 18 20 23 25 30 34 42 47 50 60 70 
