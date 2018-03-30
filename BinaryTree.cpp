#include "BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree(){
  this->root = NULL;
  this->length = 0;
}
void destroyTree(Node*& node){
  if(node != NULL){
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
  }
}
BinaryTree::~BinaryTree(){
  destroyTree(root);    
}
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
  else if(key == node->key){
    std::cout << "Item already in tree. \n";
    return false;
  }
  else
    recursiveInsert(node->right, key);
  return true;
}
void BinaryTree::insert(ItemType &key){
  if(recursiveInsert(root,key) == true)
    this->length++;
}
void getPredecessor(Node* node, ItemType& data){
  while (node->right != NULL)
    node = node->right;
  data = node->key;
}
bool recursiveDelete(Node*& node, ItemType &key){
  if(node == NULL){
    std::cout << "Item not in tree. \n";
    return false;
  }
  else if(key < node->key){
    if( false == recursiveDelete(node->left, key)){
      return false;
    }
  }
  else if(key > node->key){
    if(false == recursiveDelete(node->right, key)){
      return false;
    }
  }
  else{
    ItemType data;
    Node* tempPtr;
    tempPtr = node;
    if(node->left == NULL){
      node = node->right;
      delete tempPtr;
    }
    else if(node->right == NULL){
      node = node->left;
      delete tempPtr;
    }
    else{
      getPredecessor(node->left, data);
      node->key = data;
      recursiveDelete(node->left, data);
    }
  }
  return true;
}
void BinaryTree::deleteItem(ItemType &key){
  if(recursiveDelete(root, key)){
      length--;
    }
}
void retrieveHelper(Node* node, ItemType& item, bool &found){
  if(node == NULL){
    found = false;
  }
  else if(item < node->key){
    retrieveHelper(node->left, item, found);
  }
  else if(item > node->key){
    retrieveHelper(node->right, item, found);
  }
  else{
    item = node->key;
    found = true;
  }
}
void BinaryTree::retrieve(ItemType &item, bool &found) const{
  retrieveHelper(root, item, found);    
}
void printTreePO(Node* node){
  if(node != NULL){
    std::cout << " " << node->key.getValue();
    printTreePO(node->left);
    printTreePO(node->right);
  }
}
void BinaryTree::preOrder() const{
  printTreePO(root);
}
void printTreeIO(Node* node){
  if(node != NULL){
    printTreeIO(node->left);
    std::cout << " " << node->key.getValue();
    printTreeIO(node->right);
  }
}
void BinaryTree::inOrder() const{
  printTreeIO(root);
}
void printTreePTO(Node* node){
  if(node != NULL){
    printTreePTO(node->left);
    printTreePTO(node->right);
    std::cout <<  " " << node->key.getValue();
  }
}
void BinaryTree::postOrder() const{
  printTreePTO(root);
}
int BinaryTree::getLength() const{
      return length; 
}