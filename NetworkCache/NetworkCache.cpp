// NetworkCache.cpp : Defines the entry point for the console application.
//

#include "Tree.h"
#include <string>
int main()
{
	Tree<string> myTree;
	unsigned int parent = myTree.AddNode("Bob");
	if (parent)
	{
		myTree.AddChild(parent, "Jim");
		myTree.AddChild(parent, "Mary");
		myTree.AddChild(parent, "George");
	}

	myTree.PrintTree();
	cout << "Press any key to quit\n";
	char ch;
	cin >> ch;
	cout << ch;
    return 0;
}

