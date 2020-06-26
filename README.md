# Red_Black_Tree Properties

1. Every node is either red or black.
2. Root is black
3. Every leaf (NULL) is black.
4. If a node is red, then both its children are black.
5. Every simple path from a node to a descendant leaf contains the same number of black nodes i.e. it maintains equal black height on every path.

In this project, basic operations on Red-Black Tree like insertion, deletion, searching etc. are performed.
Run the makefile.
Perform the given operations by selecting a particular option.

In Red-Black Tree insertion, we come across a problem of red-red parent-child relationship. In order to fix the issue, we need to perform some rotation &/or recoloring operations. Similarly, for delete operation, we have to fix double black issue while deleting a black node.
In this project, recursive approach is used to fix the above issues.
Finding a given node, finding minimum & maximum node operations are exactly similar to that in case of a BST.
Output is printed in inorder manner. Any other way can also be used.

Red-Black Tree with n keys has the height: h <= 2 * log(n + 1)
There is the assurance that its height remains as O(log n) after any sequence of deletions and insertions. So time complexity is fixed as it makes itself evenly distributed.
