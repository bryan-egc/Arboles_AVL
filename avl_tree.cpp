#include "avl_tree.h"
#include <iostream>
#include <algorithm> // Para std::max

int AVLTree::height(TreeNode* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int AVLTree::balanceFactor(TreeNode* node) {
    if (node == nullptr)
        return 0;
    return height(node->right) - height(node->left);
}

TreeNode* AVLTree::rotateRight(TreeNode* node) {
    TreeNode* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;

    node->height = std::max(height(node->left), height(node->right)) + 1;
    newRoot->height = std::max(height(newRoot->left), height(newRoot->right)) + 1;

    return newRoot;
}

TreeNode* AVLTree::rotateLeft(TreeNode* node) {
    TreeNode* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;

    node->height = std::max(height(node->left), height(node->right)) + 1;
    newRoot->height = std::max(height(newRoot->left), height(newRoot->right)) + 1;

    return newRoot;
}

TreeNode* AVLTree::balance(TreeNode* node) {
    int balance = balanceFactor(node);

    if (balance > 1) {
        if (balanceFactor(node->right) < 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    if (balance < -1) {
        if (balanceFactor(node->left) > 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    return node;
}

TreeNode* AVLTree::insertRecursive(TreeNode* node, int value) {
    if (node == nullptr)
        return new TreeNode(value);

    if (value < node->value)
        node->left = insertRecursive(node->left, value);
    else if (value > node->value)
        node->right = insertRecursive(node->right, value);
    else // Si el valor ya existe, no se hace nada
        return node;

    // Actualizar la altura del nodo actual
    node->height = 1 + std::max(height(node->left), height(node->right));

    // Balancear el árbol
    return balance(node);
}

void AVLTree::insert(int value) {
    root = insertRecursive(root, value);
}

bool AVLTree::searchRecursive(TreeNode* node, int value) {
    if (node == nullptr)
        return false;

    if (value == node->value)
        return true;
    else if (value < node->value)
        return searchRecursive(node->left, value);
    else
        return searchRecursive(node->right, value);
}

bool AVLTree::search(int value) {
    return searchRecursive(root, value);
}

TreeNode* AVLTree::minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

TreeNode* AVLTree::removeRecursive(TreeNode* node, int value) {
    if (node == nullptr)
        return node;

    if (value < node->value)
        node->left = removeRecursive(node->left, value);
    else if (value > node->value)
        node->right = removeRecursive(node->right, value);
    else {
        if (node->left == nullptr || node->right == nullptr) {
            TreeNode* temp = node->left ? node->left : node->right;
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            delete temp;
        } else {
            TreeNode* temp = minValueNode(node->right);
            node->value = temp->value;
            node->right = removeRecursive(node->right, temp->value);
        }
    }

    if (node == nullptr)
        return node;

    node->height = 1 + std::max(height(node->left), height(node->right));
    return balance(node);
}

void AVLTree::remove(int value) {
    root = removeRecursive(root, value);
}

void AVLTree::displayRecursive(TreeNode* node, int level) {
    if (node == nullptr)
        return;

    displayRecursive(node->right, level + 1);
    std::cout << std::endl;

    if (node == root)
        std::cout << "Root -> ";

    for (int i = 0; i < level && node != root; i++)
        std::cout << "        ";

    std::cout << node->value;
    displayRecursive(node->left, level + 1);
}

void AVLTree::display() {
    displayRecursive(root, 0);
    std::cout << std::endl;
}

