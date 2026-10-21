#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree() {
    int value;
    cin >> value;

    if (value == -1) return nullptr;

    TreeNode* current = new TreeNode(value);

    cout << "Left child of " << value << ": ";
    current->left = buildTree();

    cout << "Right child of " << value << ": ";
    current->right = buildTree();

    return current;
}

void displayPreOrder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    displayPreOrder(root->left);
    displayPreOrder(root->right);
}

void displayInOrder(TreeNode* root) {
    if (!root) return;
    displayInOrder(root->left);
    cout << root->val << " ";
    displayInOrder(root->right);
}

void displayPostOrder(TreeNode* root) {
    if (!root) return;
    displayPostOrder(root->left);
    displayPostOrder(root->right);
    cout << root->val << " ";
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    cout << "Enter the root value:\n";
    TreeNode* root = buildTree();

    cout << "\nPre-order:  "; displayPreOrder(root);  cout << '\n';
    cout << "In-order:   "; displayInOrder(root);   cout << '\n';
    cout << "Post-order: "; displayPostOrder(root); cout << '\n';

    freeTree(root);
    return 0;
}
