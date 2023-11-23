//Ruti Tenenboim 214360778
//sadna in c++
//week 8 exe 2
//מימוש תור ע"י מחסנית ומחסנית עזר
#pragma once
// ------------------------------------------------
 // class List
 // arbitrary size Lists
 // permits insertion and removal
 // only from the front of the List
 //------------------------------------------------
class List
{
protected:
	//--------------------------------------------
	// inner class link
	// a single element for the linked List
   //--------------------------------------------
	class Link {
	public:
		// constructor
		Link(int linkValue, Link* nextPtr);
		Link(const Link&);
		// data areas
		int value;
		Link* next;
	}; //end of class Link
public:
	// constructors
	List();
	List(const List&);
	~List();
	// operations
	void add(int value);
	int firstElement() const;
	bool search(const int& value) const;
	bool isEmpty() const;
	void removeFirst();
	void clear();
protected:
	// data field
	Link* head;
};
