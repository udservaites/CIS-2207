/*
Binary tree is a non-linear linked list in which each node may point to 0, 1, or two other nodes. 

Each node can have 0, 1, or 2 childrem

Tree pointer: like head pointer. Points to first node in binary tree

Root node: Node at the top of the tree.

Leaf node: A node with no children

Parent node: The node one up.

Subtree: Portion of tree from a node down to the leaves.

Primary use of binary tree is to do searches. A binary search tree cannot have things added
to it after it is initilized. 

A node in a binary tree is similar to one in a linked list except it has two pointers. 

How to insert a node into a binary search tree:
1. If tree is empty, insert new node as the root node.
2. 
3.
4.

Traversing a tree:
1. Inorder (Sorted):
*left then the item then the right
a)Traverse left subtree of node
b)Process data in node
c)Traverse right subtree of node
2. Preorder
*data item, left subtree, right subtree
a)Process data in node
b)Travese left subtree of node
c)Travers right subtree of node
3. Postorder
*process left, process right, then the item. 


Deleting a node from a Binary tree:
If the node isn't there: don't worry about it, throw an exception, etc.
If the node is a leaf, make a temp pointer, point the temp pointer to it, delete the temp pointer. The pointer that was
pointing to it, change to null. 
If the node has a child: Change the pointer pointing to the one to be removed to its child. Make temp pointer
and delete node. 
If the node has two children: Do a binary search to find the node to be deleted. Set a temp pointer to the node.
Promote the root and have it point to the next node to the right on the tree. Find the leftmost child that has a pointer that is null
of teh node to be promoted. Point the leaf to the first subtree on the left. Delete the temp node. 
But now the tree is unbalanced. An unbalanced tree loses efficeny of searching. Now it is a linked list. 

The value in your node has to have some concept of order. 

When coding, pick one side or another to protote. Do not go back and forth.





*/