#include "BinaryTree.h"
#include <fstream>

using namespace std;

int main(int argc, char * argv[]){
  // Command prompt
  cout << "Commands - insert (i), delete (d), retrieve (r), length (l), in-order (n), pre-order (p), post-order(o), getSameLevelNonsiblings (c), quit (q)" << endl;
    char input;
    int numbers;
    bool cont = true;
    ifstream inFile;
    inFile.open(argv[1]);       // attempt to open file
    if(!inFile){
      cout << "Unable to open file";
      return EXIT_FAILURE;
    }
    BinaryTree startList = BinaryTree();
    while(inFile >> numbers){                    // Insert all numbers in file into a Binary Tree
      ItemType data;
      data.initialize(numbers);
      startList.insert(data); 
    }
    do {
      cout << "Enter a command: ";
      std::cin >> input;
      if(input == 'i'){                                   // Insert value
        cout << "Item to insert: ";
        std::cin >> numbers ;
        ItemType data;
        data.initialize(numbers);
        startList.insert(data);
        cout << "In-Order:";
        startList.inOrder();
        cout << "\n";
      }
      else if(input == 'd'){                              // Delete value
        cout << "Item to delete: ";
        std::cin >> numbers ;
        ItemType data;
        data.initialize(numbers);
        startList.deleteItem(data);
        cout << "In-Order:";
        startList.inOrder();
        cout << "\n";
      }
      else if(input  == 'n'){                             // In-Order Print
        cout << "In-Order:";
        startList.inOrder();
        cout << "\n";
      }
      else if(input  == 'o'){                             // Post-Order Print
        cout << "Post-Order:";
        startList.postOrder();
        cout << "\n";
      }
      else if(input  == 'p'){                             // Pre-Order Print
        cout << "Pre-Order:";
        startList.preOrder();
        cout << "\n";
      }
      else if(input  == 'l'){                             // Print length
        cout << "List length: " << startList.getLength() << endl;
      }
      else if(input == 'r'){                              // Retrieve Item
        bool found = false;
        cout << "Item to be retrieved: ";
        std::cin >> numbers;
        ItemType data;
        data.initialize(numbers);
        startList.retrieve(data,found);
        if(found)
          std::cout << "Item found in tree.\n";
        else
          std::cout << "Item not in tree.\n";
      }
      else if(input == 'q'){                              // Quit program
        cout << "Quitting program..." << endl;
        return EXIT_SUCCESS;
      }
      else if(input != 'q'){                              // Other input
        cout << "Command not recognized. Try again" << endl;
      }
    }
    while(cont);                                     
  
  return EXIT_SUCCESS;    
} // main