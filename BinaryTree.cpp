#include "BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree(){
  this->root = NULL;
  this->length = 0;
}// BinaryTree

void destroyTree(Node*& node){
  if(node != NULL){
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
  }
}// destroyTree

BinaryTree::~BinaryTree(){
  destroyTree(root);    
}// ~BinaryTree

bool recursiveInsert(Node*& node, ItemType &key){
  if(node == NULL){
    node = new Node;
    node->right = NULL;
    node->left = NULL;
    node->key = key;
    return true;
  }
  else if(key < node->key)
    recursiveInsert(node->left, key);
  else if(key == node->key){                        // if the item is already in the tree
    std::cout << "Item already in tree. \n";
    return false;
  }
  else
    recursiveInsert(node->right, key);
  return true;
}// recursiveInsert

void BinaryTree::insert(ItemType &key){
  if(recursiveInsert(root,key) == true)
    this->length++;
}// insert

void getPredecessor(Node* node, ItemType& data){
  while (node->right != NULL)                        // find the right most node's data from node
    node = node->right;
  data = node->key;
}// getPredecessor

bool recursiveDelete(Node*& node, ItemType &key){
  if(node == NULL){                                  // if item is not in tree, return false
    std::cout << "Item not in tree. \n";
    return false;
  }
  else if(key < node->key){
    if( false == recursiveDelete(node->left, key)){  // if item is not in left sub-tree return false
      return false;
    }
  }
  else if(key > node->key){
    if(false == recursiveDelete(node->right, key)){  // if item is not in right sub-tree return false
      return false;
    }
  }
  else{                                              // if item exist in tree
    ItemType data;
    Node* tempPtr;
    tempPtr = node;
    if(node->left == NULL){                          // if only the right child exist
      node = node->right;
      delete tempPtr;
    }
    else if(node->right == NULL){                    // if only the left child exist
      node = node->left;
      delete tempPtr;
    }
    else{                                            // if two children exist
      getPredecessor(node->left, data);
      node->key = data;
      recursiveDelete(node->left, data);
    }
  }
  return true;
}// recursiveDelete

void BinaryTree::deleteItem(ItemType &key){
  if(recursiveDelete(root, key)){
      length--;
    }
}// deleteItem

void retrieveHelper(Node* node, ItemType& item, bool &found){
  if(node == NULL){                            // if node is not found
    found = false;
  }
  else if(item < node->key){                   // if item is less than current item, search left sub-tree
    retrieveHelper(node->left, item, found);
  }
  else if(item > node->key){                   // if item is greater than current item, serach right sub-tree
    retrieveHelper(node->right, item, found);
  }
  else{                                        // if item is equal
    item = node->key;
    found = true;
  }
}// retrieveHelper

void BinaryTree::retrieve(ItemType &item, bool &found) const{
  retrieveHelper(root, item, found);    
}// retrieve

void printTreePO(Node* node){   // Center, Left, then Right
  if(node != NULL){
    std::cout << " " << node->key.getValue();
    printTreePO(node->left);
    printTreePO(node->right);
  }
}// printTreePO

void BinaryTree::preOrder() const{
  printTreePO(root);
}// preOrder

void printTreeIO(Node* node){    // Left, Center, then Right
  if(node != NULL){
    printTreeIO(node->left);
    std::cout << " " << node->key.getValue();
    printTreeIO(node->right);
  }
}// printTreeIO

void BinaryTree::inOrder() const{
  printTreeIO(root);
}// inOrder

void printTreePTO(Node* node){   // Left, Right, then Center
  if(node != NULL){
    printTreePTO(node->left);
    printTreePTO(node->right);
    std::cout <<  " " << node->key.getValue();
  }
}// printTreePTO

void BinaryTree::postOrder() const{
  printTreePTO(root);
}// postOrder

int BinaryTree::getLength() const{
      return length; 
}// getLength