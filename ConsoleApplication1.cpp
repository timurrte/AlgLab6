#include <iostream>
#include <Windows.h>

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    }
    else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

// функція копіювання лівих піддерев
void copyLeftNodes(Node* sourceTree, Node*& targetTree) {
    if (sourceTree == NULL) {
        return;
    }
    if (sourceTree->left != NULL) {
        targetTree = insert(targetTree, sourceTree->left->data);
    }
    copyLeftNodes(sourceTree->left, targetTree);
    copyLeftNodes(sourceTree->right, targetTree);
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}


void printBT(const std::string& prefix, const Node* node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;

        std::cout << (isLeft ? "|--" : "L__");

        // print the value of the node
        std::cout << node->data << std::endl;

        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "|   " : "    "), node->left, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

void printBT(const Node* node)
{
    printBT("", node, false);
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Node* sourceTree = NULL;
    sourceTree = insert(sourceTree, 50);
    insert(sourceTree, 30);
    insert(sourceTree, 20);
    insert(sourceTree, 40);
    insert(sourceTree, 70);
    insert(sourceTree, 60);
    insert(sourceTree, 80);
    insert(sourceTree, 11);
    insert(sourceTree, 17);
    insert(sourceTree, 45);
    insert(sourceTree, 9);

    Node* targetTree = NULL;
    copyLeftNodes(sourceTree, targetTree);

    std::cout << "Inorder traversal of the source tree is: ";
    inorder(sourceTree);
    std::cout << "\n";

    std::cout << "Inorder traversal of the target tree is: ";
    inorder(targetTree);
    std::cout << "\n";

    printBT(sourceTree);

    return 0;
}
