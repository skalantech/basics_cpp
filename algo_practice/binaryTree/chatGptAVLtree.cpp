#include <iostream>

class Node {
public:
  int key, height;
  Node *left, *right;
  
  Node(int key) {
    this->key = key;
    this->height = 1;
    this->left = this->right = NULL;
  }
};

int height(Node *node) {
  if (!node) return 0;
  return node->height;
}

int balanceFactor(Node *node) {
  if (!node) return 0;
  return height(node->left) - height(node->right);
}

Node* rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;
  
  x->right = y;
  y->left = T2;
  
  y->height = std::max(height(y->left), height(y->right)) + 1;
  x->height = std::max(height(x->left), height(x->right)) + 1;
  
  return x;
}

Node* leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;
  
  y->left = x;
  x->right = T2;
  
  x->height = std::max(height(x->left), height(x->right)) + 1;
  y->height = std::max(height(y->left), height(y->right)) + 1;
  
  return y;
}

Node* insert(Node *node, int key) {
  if (!node) return new Node(key);
  
  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);
  else
    return node;
  
  node->height = 1 + std::max(height(node->left), height(node->right));
  
  int balance = balanceFactor(node);
  
  // Left Left Case
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);
  
  // Right Right Case
  if (balance < -1 && key > node->right->key)
    return leftRotate(node);
  
  // Left Right Case
  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }
  
  // Right Left Case
  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }
  
  return node;
}

void preOrder(Node *root) {
  if (!root) return;
 
