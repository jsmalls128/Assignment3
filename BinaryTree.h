#include <cstdlib>
#include "ItemType.h"

struct Node {
  ItemType key;
  Node* left;
  Node* right;
};

class BinaryTree{
  
  Node* root;
  int length;
  
  public:
    BinaryTree();
    ~BinaryTree();
    void insert(ItemType &key);
    void deleteItem(ItemType &key);
    void retrieve(ItemType &item, bool &found) const;
    void preOrder() const;
    void inOrder() const;
    void postOrder() const;
    int getLength() const;
};