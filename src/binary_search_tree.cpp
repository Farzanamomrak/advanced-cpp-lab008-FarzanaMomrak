#include "project/binary_search_tree.h"

#include <algorithm>
#include <stdexcept>

BinarySearchTree::BinarySearchTree() : root_(nullptr), size_(0) {}

BinarySearchTree::~BinarySearchTree() {
    deleteSubtree(root_);
}

void BinarySearchTree::deleteSubtree(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    // delete children before their parents
    deleteSubtree(node->left);
    deleteSubtree(node->right);
    delete node;
}

bool BinarySearchTree::insert(int value) {
    // to prevent duplicate values
    if (search(value)) {
        return false;
    }
    root_ = insertRecursive(root_, value);
    ++size_;
    return true;
}

bool BinarySearchTree::remove(int value) {
    //if value is not present, do not change the size
    if (!search(value)) {
        return false;
    }
    root_ = removeRecursive(root_, value);
    --size_;
    return true;
}

bool BinarySearchTree::search(int value) const {
    return searchRecursive(root_, value);
}

bool BinarySearchTree::contains(int value) const {
    return search(value);
}

bool BinarySearchTree::empty() const noexcept {
    return size_ == 0;
}

std::size_t BinarySearchTree::size() const noexcept {
    return size_;
}

int BinarySearchTree::height() const {
    return heightRecursive(root_);
}

std::vector<int> BinarySearchTree::inorderTraversal() const {
    std::vector<int> result;
    inorderRecursive(root_, result);
    return result;
}

std::vector<int> BinarySearchTree::preorderTraversal() const {
    std::vector<int> result;
    preorderRecursive(root_, result);
    return result;
}

std::vector<int> BinarySearchTree::postorderTraversal() const {
    std::vector<int> result;
    postorderRecursive(root_, result);
    return result;
}

int BinarySearchTree::minimum() const {
    if (empty()) {
        throw std::logic_error("BST is empty");
    }
    return minimumRecursive(root_);
}

int BinarySearchTree::maximum() const {
    if (empty()) {
        throw std::logic_error("BST is empty");
    }
    return maximumRecursive(root_);
}

TreeNode* BinarySearchTree::insertRecursive(TreeNode* node, int value) {
    // new node when reaching a null position
    if (node == nullptr) {
        return new TreeNode(value);
    }
    // smaller value to the left, larger value to the right
    if (value < node->value) {
        node->left = insertRecursive(node->left, value);
    } else if (value > node->value) {
        node->right = insertRecursive(node->right, value);
    }
    return node;
}

TreeNode* BinarySearchTree::removeRecursive(TreeNode* node, int value) {
    if (node == nullptr) {
        return nullptr;
    }
    if (value < node->value) {
        node->left = removeRecursive(node->left, value);
    } else if (value > node->value) {
        node->right = removeRecursive(node->right, value);
    } else {
        // case 1: node with no child
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        } 
        // case 2: node with only one right child
        if (node->left == nullptr) {
            TreeNode* child = node->right;
            delete node;
            return child;
        } 
        // case 3: node with only one left child
        if (node->right == nullptr) {
            TreeNode* child = node->left;
            delete node;
            return child;
        }
        // case 4: node with two children
        TreeNode* temp = node->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        node->value = temp->value;
        node->right = removeRecursive(node->right, temp->value);
    }
    return node;
}

bool BinarySearchTree::searchRecursive(const TreeNode* node, int value) const {
    if (node == nullptr) {
        return false;
    }
    if (value == node->value) {
        return true;
    }
    if (value < node->value) {
        return searchRecursive(node->left, value);
    }
    return searchRecursive(node->right, value);
}

void BinarySearchTree::inorderRecursive(const TreeNode* node, std::vector<int>& result) const {
    if (node == nullptr) {
        return;
    }
    inorderRecursive(node->left, result);
    result.push_back(node->value);
    inorderRecursive(node->right, result);
}

void BinarySearchTree::preorderRecursive(const TreeNode* node, std::vector<int>& result) const {
    if (node == nullptr) {
        return;
    }
    result.push_back(node->value);
    preorderRecursive(node->left, result);
    preorderRecursive(node->right, result);
}

void BinarySearchTree::postorderRecursive(const TreeNode* node, std::vector<int>& result) const {
    if (node == nullptr) {
        return;
    }
    postorderRecursive(node->left, result);
    postorderRecursive(node->right, result);
    result.push_back(node->value);
}

int BinarySearchTree::heightRecursive(const TreeNode* node) const {
    // an empty tree has height 0
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = heightRecursive(node->left);
    int rightHeight = heightRecursive(node->right);
    return 1 + std::max(leftHeight, rightHeight);
}

int BinarySearchTree::minimumRecursive(const TreeNode* node) const {
    // minimum value in a BST is the leftmost node
    while (node->left != nullptr) {
        node = node->left;
    }
    return node->value;
}

int BinarySearchTree::maximumRecursive(const TreeNode* node) const {
    // maximum value in a BST is the rightmost node
    while (node->right != nullptr) {
        node = node->right;
    }
    return node->value;
}
