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
		if(node == root){
			promotion(root);
			return true;
		}else{
			if(node->left == NULL && node->right == NULL){
				removeLeaf(node);
				return true;
			}
			else if(node->left == NULL || node->right == NULL){
				shortCircuit(node);
				return true;
			}else{
				promotion(node);
				return true;
			}
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

void BSTree::shortCircuit(BSTree::Node* node){
	if(node == node->parent->left){
		if(node->left != NULL){
			node->left->parent = node->parent;
			node->parent->left = node->left;
		}else{
			node->right->parent = node->parent;
			node->parent->left = node->right;
		}
	}else{
		if(node->left != NULL){
			node->left->parent = node->parent;
			node->parent->right = node->left;
		}
		else{
			node->right->parent = node->parent;
			node->parent->right = node->right;
		}
	}
	delete node;
}

void BSTree::promotion(BSTree::Node* node){
	Node* promote;
	if(node->left != NULL){
		promote = findMaxInMinTree(node);
		node->data = promote->data;
		if(promote->left == NULL){
			removeLeaf(promote);
		}else{
			shortCircuit(promote);
		}
	}else if(node->right != NULL){
		promote = findMinInMaxTree(node);
		node->data = promote->data;
		if(promote->right == NULL){
			removeLeaf(promote);
		}else{
			shortCircuit(promote);
		}
	}else{
		delete node;
		root = NULL;
	}
}

BSTree::Node* BSTree::findMaxInMinTree(BSTree::Node* node){
	Node* retVal = node->left;
	while(retVal->right != NULL){
		retVal = retVal->right;
	}
	return retVal;
}

BSTree::Node* BSTree::findMinInMaxTree(BSTree::Node* node){
	Node* retVal = node->right;
	while(retVal->left != NULL){
		retVal = retVal->left;
	}
	return retVal;
}

void BSTree::sortedArray(std::vector<int> &list){
	traverse(list, root);
}

void BSTree::traverse(std::vector<int> &list, BSTree::Node* node){
	if(node){
		traverse(list, node->left);
		list.push_back(node->data);
		cout << node->data << " " ;
		traverse(list, node->right);
	}
}

