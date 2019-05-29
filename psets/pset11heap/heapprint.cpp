/**
 
 /*
 Include the following line at the top of your every file with your name signed.
 On my honour, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: Jeon, Yeo Hun
 *
 
 
* File: heapprint.cpp
*	converts a heap data structure in an array into a complete
*	binary tree and invokes treeprint() in treeprint.cpp
*
* @Author	Youngsup Kim, idebtor@gmail.com
* 05/05/2016	Creation
* 05/05/2019	Simplified using std::queue
*
* Algorithm to build a binary tree(BT) from a complete binary tree(CBT).
* 0. If the CBT size is zero, return a nullptr.
* 1. initialize the tree (BT) with the first key from CBT
* 2. queue the tree root node.
* 3. Loop until the queue is empty
*    Get a next key from the CBT
*    Get the front node in the queue.
*    If the left child of this front node doesn¡¯t exist,
*        set the left child as the new node.
*	 else if the right child of this front node doesn¡¯t exist,
*        set the right child as the new node.
* 4. If the front node has both the left child and right child,
*        dequeue() it.
* 5. enqueue() the new node.
*/

#include <iostream>
#include <cassert>
#include <queue>
#include <cmath>
#include "heap.h"
#include "treenode.h"

void treeprint(tree t);

void heapprint(heap p) {
	DPRINT(std::cout << ">heapprint\n";);
    std::queue <tree> q;
    if (empty(p)) return;
    
    int index=1;
    
    tree root = new TreeNode(p->nodes[index]);
    q.push(root);
    while(index < p->N){
        tree newNode = new TreeNode(p->nodes[++index]);
        tree queNode = q.front();
        if (queNode->left == nullptr){
            queNode->left = newNode;
        }
        else if (queNode->right == nullptr){
            queNode->right = newNode;
        }
        if (queNode->left != nullptr && queNode->right != nullptr){
            q.pop();
        }
        q.push(newNode);
    }
    treeprint(root);
    
    
	// treeprint(root);

	// treeprint_levelorder(root);  // may use this instead of heapprint_levelorder()
	DPRINT(std::cout << "<heapprint\n";);
}

void heapprint_levelorder(heap p) {
	DPRINT(std::cout << ">heapprint_levelorder\n";);
	if (empty(p)) return;
	int N = size(p);                   // number of nodes, N is the last index
	int max_level = height(N);         // total number of levels, starting at 1
	int i = 1;
	while (i <= N) {
		for (int level = 0; level < max_level; level++) {
			int n = (int)pow(2, level);            // n is max nodes per level
			for (int k = 0; k < n && i <= N; k++)   // disply one level
				std::cout << p->nodes[i++] << " ";
			std::cout << std::endl;
		}
	}
	DPRINT(std::cout << "<heapprint_levelorder\n";);
}
