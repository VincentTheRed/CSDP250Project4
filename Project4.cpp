/***********************************************
 * Name: [Vincent Bardinelli]
 * Date: [November 6, 2023]
 * Class: [CSDP 250 Fall 2023]
 * Program Description: This program creates a binary search tree (BST),
 * prompts the user for the number of elements, ensures the number is between
 * 35 and 99, generates random natural numbers within this range, inserts
 * them into the BST, and performs pre-order, in-order, and post-order
 * traversals to display the numbers in different orders.
 ***********************************************/

#include <iostream>
#include <limits>
#include <ctime>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* leftNext;
    Node* rightNext;

    //Constructor to initialize a node
    Node(int val) : data(val), leftNext(nullptr), rightNext(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    //Recursively delete all nodes in the tree
    void deleteTree(Node* node) {
        if (node) {
            deleteTree(node->leftNext); //Delete left subtree
            deleteTree(node->rightNext); //Delete right subtree
            delete node; //Delete the node itself
        }
    }

    //Private method to insert a new node
    void insertNode(Node*& node, int value) {
        if (!node) {
            node = new Node(value);
        } else if (value < node->data) {
            insertNode(node->leftNext, value);
        } else {
            insertNode(node->rightNext, value);
        }
    }

    //Display tree in pre-order traversal
    void displayPreOrder(Node* node) const {
        if (node) {
            cout << node->data << " ";
            displayPreOrder(node->leftNext);
            displayPreOrder(node->rightNext);
        }
    }

    //Display tree in in-order traversal
    void displayInOrder(Node* node) const {
        if (node) {
            displayInOrder(node->leftNext);
            cout << node->data << " ";
            displayInOrder(node->rightNext);
        }
    }

    //Display tree in post-order traversal
    void displayPostOrder(Node* node) const {
        if (node) {
            displayPostOrder(node->leftNext);
            displayPostOrder(node->rightNext);
            cout << node->data << " ";
        }
    }

public:
    //Constructor initializes the tree
    BinarySearchTree() : root(nullptr) {}

    //Insert a value into the tree
    void insert(int value) {
        insertNode(root, value);
    }

    //Public method to display tree in pre-order
    void displayPreOrder() const {
        cout << "Pre-order traversal: ";
        displayPreOrder(root);
        cout << "\n";
    }

    //Public method to display tree in in-order
    void displayInOrder() const {
        cout << "In-order traversal: ";
        displayInOrder(root);
        cout << "\n";
    }

    //Public method to display tree in post-order
    void displayPostOrder() const {
        cout << "Post-order traversal: ";
        displayPostOrder(root);
        cout << "\n";
    }

    //Destructor deletes all nodes to prevent memory leaks
    ~BinarySearchTree() {
        deleteTree(root); //Start deletion from the root
        root = nullptr; //Prevent dangling pointer by setting root to nullptr
    }
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); //Seed for random number generation
    BinarySearchTree bst; //Create a Binary Search Tree object
    vector<int> numbers; //Vector to store the original numbers
    int totalNumbers;

    //Input validation loop
    do {
        cout << "Enter the total numbers (35-99): ";
        cin >> totalNumbers;
        if (cin.fail() || totalNumbers < 35 || totalNumbers >= 100) {
            cout << "Invalid input. Please enter a number between 35 and 99.\n";
            cin.clear(); //Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignore the rest of the input
        }
    } while (totalNumbers < 35 || totalNumbers >= 100);

    //Insert random numbers into the tree and store them in the vector
    for (int i = 0; i < totalNumbers; ++i) {
        int number = rand() % 100; //Generate a random number
        numbers.push_back(number); //Add to the vector
        bst.insert(number); //Insert into the tree
    }

    //Display the original numbers
    cout << "Original numbers: ";
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << "\n";

    //Display the numbers in different tree traversal orders
    bst.displayPreOrder(); //Show the pre-order traversal
    bst.displayInOrder(); //Show the in-order traversal
    bst.displayPostOrder(); //Show the post-order traversal

    return 0; //End of the program
}

