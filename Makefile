main: main.o ItemType.o BinaryTree.o
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -o main Main.o ItemType.o BinaryTree.o
main.o: Main.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c Main.cpp
ItemType.o: ItemType.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c ItemType.cpp
BinaryTree.o: BinaryTree.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c BinaryTree.cpp
clean:
	rm main Main.o ItemType.o BinaryTree.o