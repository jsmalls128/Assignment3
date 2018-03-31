#include <cstdlib>
#include "ItemType.h"

struct Node {
  ItemType key;         // Generic datatype for node
  Node* left;           // Node pointer to left child
  Node* right;          // Node pointer to right child
};

class BinaryTree{
  
  Node* root;            // Node pointer to root of tree
  int length;            // The amount of nodes in tree
  
  public:
    BinaryTree();                                        // BinaryTree constructor
    ~BinaryTree();                                       // BinaryTree destructor
    void insert(ItemType &key);                          // Inserts Item into tree
    void deleteItem(ItemType &key);                      // Removes Item from tree
    void retrieve(ItemType &item, bool &found) const;    // Checks if Item is in tree
    void preOrder() const;                               // Prints tree in pre-order
    void inOrder() const;                                // Prints tree in in-order
    void postOrder() const;                              // Prints tree in post-order
    int getLength() const;                               // Returns length variable
};