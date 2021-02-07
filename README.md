# simple-tree
This is an implementation of a n-ary tree. The tree is simply a list of nodes .  Every node has an id, parent id and a templatized data. Hence the Tree class is implemented as a template class. Every node has a list of children ids.   The implementation allows for quick building of a tree. Searching a node and children should run in o(N). I am still working on an efficient way to print the tree.   There is no recursion involved   This implementation uses STL

The file Tree.h has the main class. The file NetworkCache.cpp uses Tree to suggest creating a simple network cache of nodes. I have used MS Visual Studio only for quick development and testing. It should be possible to use the class on other platforms like Linux as-is or with some minor modification
