#include "BSTree.h" 
#include <iostream>
using namespace std;

BSTree::BSTree(){
	root = NULL;
}

BSTree::~BSTree(){

}

bool BSTree::insert(int val){
	if(root == NULL){
		root = new BSTree::Node(val, NULL);
		return true;
	}
	else{
		return insertNode(val, root);
	}
}

bool BSTree::insertNode(int val, BSTree::Node* prev){
	if(prev->data > val){
		if(prev->left == NULL){
			prev->left = new BSTree::Node(val, prev);
			return true;
		}
		else{
			return insertNode(val, prev->left);
		}
	}
	if(prev->data < val){
		if(prev-> right == NULL){
			prev->right = new BSTree::Node(val, prev);
			return true;
		}
		else{
			return insertNode(val, prev->right);
		}
	}
	return false;
}

bool BSTree::empty(){
	if(root == NULL){
		return true;
	}
	return false;
}

bool BSTree::find(int val){
	if(root == NULL){
		return false;
	}
	else{
		return findNode(val, root);
	}
}

bool BSTree::findNode(int val, BSTree::Node* prev){
	if(prev->data > val){
		if(prev->left == NULL){
			return false;
		}
		else{
			return findNode(val, prev->left);
		}
	}
	if(prev->data < val){
		if(prev-> right == NULL){
			return false;
		}
		else{
			return findNode(val, prev->right);
		}
	}
	return true;
}

BSTree::Node* BSTree::get(int val){
	if(find(val)){
		return getNode(val, root);
	}
	return NULL;
}

BSTree::Node* BSTree::getNode(int val, BSTree::Node* prev){
	if(prev->data > val){
		return getNode(val, prev->left);
	}
	if(prev->data < val){
		return getNode(val, prev->right);
	}
	return prev;

}

bool BSTree::remove(int val){
	BSTree::Node* node = get(val);
	if(node != NULL){
		if(node->left == NULL && node->right == NULL){
			removeLeaf(node);
			return true;
		}
		else if(node->left == NULL || node->right == NULL){
			
		}
	}

	return false;

}

void BSTree::removeLeaf(BSTree::Node* node){
	if(node == node->parent->left){
		node->parent->left = NULL;
	}else{
		node->parent->right = NULL;
	}
	delete node;
}

void BSTree::sortedArray(std::vector<int> &list){
	traverse(list, root);
}

void BSTree::traverse(std::vector<int> &list, BSTree::Node* node){
	if(node){
		traverse(list, node->left);
		list.push_back(node->data);
		traverse(list, node->right);
	}
}

