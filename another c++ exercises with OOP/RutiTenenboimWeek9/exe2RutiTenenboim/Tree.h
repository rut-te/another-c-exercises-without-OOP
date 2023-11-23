#pragma once
#include <iostream>
#include "QueueVector.h"
using namespace std;

template <class T>
class Tree {

protected:
	class Node {
	public:
		Node* left;
		Node* right;
		Node* parent;
		T value;
		Node(T val) :
			value(val), left(nullptr), right(nullptr) {}
		Node(T val, Node* l, Node* r) :
			value(val), left(l), right(r) {}
	};		//end of Node class
	typename Tree<T>::Node* root;
	void clear(typename Tree<T>::Node* current);
	void preOrder(typename Tree<T>::Node* current) const;
	void inOrder(typename Tree<T>::Node* current) const;
	void postOrder(typename Tree<T>::Node* current) const;
	int height(typename Tree<T>::Node* current) const;
	void reflect(typename Tree<T>::Node* current);

public:
	Tree();
	virtual ~Tree();
	typename Tree<T>::Node* get_root();
	void set_root(typename Tree<T>::Node*);
	bool isEmpty() const;
	void clear();
	void preOrder() const;
	void inOrder() const;
	void postOrder() const;
	virtual void process(T val)const;
	virtual void add(T val) = 0;
	virtual bool search( T val) = 0;
	int height()const;
	void reflect();
	void breadthScan();
	virtual void remove(T val) = 0;

};

//===========================================
//c'tor d'tor
//===========================================
template < class T>
Tree<T>::Tree() {
	root = nullptr;
}

template < class T>
Tree<T>::~Tree() {
	if (root != nullptr)
		clear(root);
}

//===========================================
//          clear::all tree
//===========================================
template<class T>
void Tree<T>::clear() {
	clear(root);
	root = nullptr;
}
//===========================================
//       preOrder :: all tree
//===========================================
template<class T>
void Tree<T>::preOrder()const {
	preOrder(root);
}
//===========================================
//        inOrder:: all tree
//===========================================
template<class T>
void Tree<T>::inOrder()const {
	inOrder(root);
}

//===========================================
//        postOrder :: all tree
//===========================================
template<class T>
void Tree<T>::postOrder()const {
	postOrder(root);
}

//===========================================
//        postOrder :: process
//===========================================
template<class T>
inline void Tree<T>::process(T val) const {
	cout << "val::" << val << endl;
}

//===========================================
//isEmpty:  return true if tree is empty
//          else return false 
//===========================================
template < class T>
bool Tree<T>::isEmpty() const {
	return root == nullptr;
}

//===========================================
//          clear:: clear sepfic Node
// Release memory associated with children
//===========================================
template <class T>
void Tree<T>::clear(typename Tree<T>::Node* current) {
	if (current) {
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}

//===========================================
//preOrder processing of tree rooted at current
// visit Node, left child, right child
//===========================================
template < class T>
void Tree<T>::preOrder(typename Tree<T>::Node* current)const {
	if (current) {
		process(current->value);
		preOrder(current->left);
		preOrder(current->right);
	}
}

//===========================================
//inOrder processing of tree rooted at current
// visit left child, Node, right child
//===========================================
template < class T>
void Tree<T>::inOrder(typename Tree<T>::Node* current)const {
	if (current) {
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

//===========================================
// postOrder processing of tree rooted at current
// visit left child, right child, node
//===========================================
template < class T>
void Tree<T>::postOrder(typename Tree<T>::Node* current)const {
	if (current) {
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}

template<class T>
typename Tree<T>::Node* Tree<T>::get_root() {
	return root;
}

template<class T>
void Tree<T>::set_root(typename Tree<T>::Node* node) {
	root = node;
}

template <class T>
int Tree<T>::height()const
{
	return height(root);
}

template <class T>
int Tree<T>::height(typename Tree<T>::Node* current)const
{
	if (current == nullptr)
		return -1;
	return max(height(current->left), height(current->right)) + 1;
}

template <class T>
void Tree<T>::reflect()
{
	reflect(root);
}



template <class T>
void Tree<T>::reflect(typename Tree<T>::Node* current)
{
	if (current == nullptr)
		return;
	reflect(current->left);
	reflect(current->right);
	typename Tree<T>::Node* temp = current->left;
	current->left = current->right;
	current->right = temp;
}

template<class T>
void Tree<T>::breadthScan()
{
	/*if (isEmpty())return;
	QueueVector<T> temp(100);
	temp.enqueue(this->root->value);
	while (!isEmpty())
	{
		typename Tree<T>::Node* current=this->root;
		current->value = temp.dequeue();
		cout << current->value;
		if (current->left)
		{
			current = current->left;
			temp.enqueue(current->value);
		}
		if (current->right)
		{
			current = current->right;
			temp.enqueue(current->value);
		}
	}*/

	if (isEmpty())return;
	QueueVector<Tree<T>::Node*> tempQueue;
	tempQueue.enqueue(this->root);
	while (!tempQueue.isEmpty())
	{
		typename Tree<T>::Node* current = tempQueue.dequeue();
		cout << current->value << " ";
		if (current->left)
			tempQueue.enqueue(current->left);
		if (current->right)
			tempQueue.enqueue(current->right);
	}
}