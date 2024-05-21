#ifndef AVL_TREE_H
#define AVL_TREE_H

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    TreeNode* root;

    // Funciones auxiliares
    int height(TreeNode* node);
    int balanceFactor(TreeNode* node);
    TreeNode* rotateRight(TreeNode* node);
    TreeNode* rotateLeft(TreeNode* node);
    TreeNode* balance(TreeNode* node);
    TreeNode* insertRecursive(TreeNode* node, int value);
    TreeNode* minValueNode(TreeNode* node);
    TreeNode* removeRecursive(TreeNode* node, int value);
    bool searchRecursive(TreeNode* node, int value);
    void displayRecursive(TreeNode* node, int level);

public:
    AVLTree() : root(nullptr) {}

    // Operaciones principales
    void insert(int value);
    bool search(int value);
    void remove(int value);
    void display();
};

#endif // AVL_TREE_H

