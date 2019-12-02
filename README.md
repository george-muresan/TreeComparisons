# TreeComparisons
Program designed to compare three commonly used Trees in computer science: BST, AVL, and Splay Trees.

Using a simple input txt file, there were steps calculated for each tree to see how long it takes to sort the tree given the input. 

AVL and Splay trees both used a balancing method for when a node is removed, there is a particular order in which the tree “balances” out in order to correctly have the nodes in place. This balancing method, allowed for a more optimized method of traversing a tree in order to insert, search, or remove. Rotating methods as well, were able to complete this task and made sure that no dangling pointers would form, as well as keep the nodes in their correct order. BST did not have this balancing nor the rotation methods which led it to have a very poor efficiency. 

These were the results: 
Splay: 408
AVL: 678
BST: 862
This data shows that the Splay tree was more than twice as efficient as the BST tree, because it took less than half of the steps required in order to achieve the same tasks. 
