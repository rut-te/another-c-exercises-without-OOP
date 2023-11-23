#pragma once
#include "Tree.h"
#include <iostream>
using namespace std;

template<class T>
class SearchTree : public Tree<T>
{
public:
	void add(T value);
	bool search(T val)
	{
		return search(this->root, val);
	}

	void remove(T val) {
		typename Tree<T>::Node* p = search(this->root, val);
		if(p)
			remove(p);
	}
	T successor(T val)
	{
		typename Tree<T>::Node* p = search(this->root, val);
		if (!p)
			throw "no successor";
		else
			return this->successor(p)->value;
	}
	typename Tree<T>::Node* minimum(typename Tree<T>::Node*);
	void deleteDuplicates() {
		deleteDuplicates(this->root);
	}

private:
	void add(typename Tree<T>::Node* current, T val);
	typename Tree<T>::Node* search(typename Tree<T>::Node* current, T val);
	void remove(typename Tree<T>::Node* current);
	typename Tree<T>::Node* successor(typename Tree<T>::Node*);
	void deleteDuplicates(typename Tree<T>::Node*);
};


template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{
	if (current->value < val) { // Add to right subtree
		if (!current->right)
		{
			current->right = new class Tree<T>::Node(val);
			current->right->parent = current;
			if (current->parent)
				return;
		}
		else
			add(current->right, val);
	}
	else { // Add to left subtree
		if (!current->left)
		{
			current->left = new class Tree<T>::Node(val);
			current->left->parent = current;
			return;
		}
		else
			add(current->left, val);
	}
}

template <class T>
void SearchTree<T>::add(T val)
{
	// Add value to binary search tree
	if (!this->root)
	{
		this->root = new class Tree<T>::Node(val);
		return;
	}
	add(this->root, val);
}
template <class T>
typename Tree<T>::Node* SearchTree<T>::search(typename Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return nullptr; // not found
	if (current->value == val)
		return current;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}

template<class T>
void SearchTree<T>::remove(typename Tree<T>::Node* current)
{
	if (!current->right && !current->left)
	{
		if (current->parent->right == current)
			current->parent->right = nullptr;
		else
			current->parent->left = nullptr;
		delete current;
		return;
	}
	else {
		if (!current->right)
		{
			if (current->parent->right == current) {
				current->parent->right = current->left;
				current->left->parent = current->parent;
			}
			else
			{
				current->parent->left = current->left;
				current->left->parent = current->parent;
			}
			delete current;
			return;
		}
		else {
			if (!current->left)
			{
				if (current->parent->right == current) {
					current->parent->right = current->right;
					current->right->parent = current->parent;
				}
				else
				{
					current->parent->left = current->right;
					current->right->parent = current->parent;
				}
				delete current;
				return;
			}
		}
	}
	typename Tree<T>::Node* successor = this->successor(current);
	current->value = successor->value;
	this->remove(successor);
}

template<class T>
typename Tree<T>::Node* SearchTree<T>::successor(typename Tree<T>::Node* p)
{
	if (p->right != nullptr)
		return minimum(p->right);
	typename Tree<T>::Node* p1 = p->parent;
	while (p1 != nullptr && p == p1->right)
	{
		p = p1;
		p1 = p->parent;
	}
	if (p1 == nullptr)
		throw "no successor";
	else
		return p1;
}

template<class T>
inline typename Tree<T>::Node* SearchTree<T>::minimum(typename Tree<T>::Node* p)
{
	if (p->left == nullptr)
		return p;
	minimum(p->left);
}

template<class T>
inline void SearchTree<T>::deleteDuplicates(typename Tree<T>::Node* current)
{
	if (this->isEmpty())return;
	if (current->right == nullptr && current->left == nullptr)
		return;
	if (current->left)
	{
		typename Tree<T>::Node* p = current->left;
		typename Tree<T>::Node* temp = nullptr;
		while (p)
		{
			p = search(p, current->value);
			if (p) {
				temp = p->left;
				remove(p);
				p = temp;
			}
		}
	}
	if (current->left)deleteDuplicates(current->left);
	if (current->right)deleteDuplicates(current->right);
}