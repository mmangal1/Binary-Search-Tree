#ifndef BSTREE_H 
#define BSTREE_H

#include <cstdlib>
#include <algorithm>
#include <vector>

class BSTree{
	private:
		class Node{
			public:
				int data;
				Node* left;
				Node* right;
				Node* parent;
				Node(int value, Node* prev){
					data = value;
					left = NULL;
					right = NULL;
					parent = prev;
				}
		};
		BSTree::Node* get(int val);
		BSTree::Node* getNode(int val, Node* prev);
		Node* root;

	public:
		BSTree();
		~BSTree();
		bool empty();
		bool insert(int val);
		bool insertNode(int val, Node* prev);
		bool find(int val);
		bool findNode(int val, Node* prev);
		bool remove(int val);
		void removeLeaf(Node* node);
		void sortedArray(std::vector<int> &list);
		void traverse(std::vector<int> &list, Node* node);
};
#endif
