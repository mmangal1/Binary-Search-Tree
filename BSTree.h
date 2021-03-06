#ifndef BSTREE_H 
#define BSTREE_H

#include <cstdlib>
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
		BSTree::Node* findMaxInMinTree(Node* node);
		BSTree::Node* findMinInMaxTree(Node* node);
		bool insertNode(int val, Node* prev);
		bool findNode(int val, Node* prev);
		void removeLeaf(Node* node);
		void shortCircuit(Node* node);
		void promotion(Node* node);
		void inOrder(std::vector<int> &new_list, Node* node);
		void preOrder(Node* node);
		void postOrder(Node* node);
		Node* root;

	public:
		BSTree();
		BSTree(const BSTree &old_tree);
		~BSTree();
		bool empty();
		bool insert(int val);
		bool find(int val);
		bool remove(int val);
		void sortedArray(std::vector<int> &list);
};
#endif
