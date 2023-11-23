//Ruti Tenenboim 214360778
//sadna in c++
//week 6 exe 2
//התוכנית מגדירה מחלקה של רשימה מעגלית, המחלקה יורשת מהמחלקה רשימה 
#include "List.h"
//השתמשתי במחלקה של רשימה שהגדרתי בתרגיל בית 5
List::Link::Link(int val, Link* nxt) : value(val), next(nxt)
{}

List::Link::Link(const Link& source) : value(source.value), next(source.next)
{}

List::List() : head(nullptr)
{

}

List::List(const List& l)
{
	Link* src, * trg;
	if (l.head == nullptr)
		head = nullptr;
	else
	{
		head = new Link((l.head)->value, nullptr);
		src = l.head;
		trg = head;
		while (src->next != nullptr)
		{
			trg->next = new Link((src->next)->value, nullptr);
			src = src->next;
			trg = trg->next;
		}
	}
}


List::~List()
{
	clear();
}


void List::clear()//ניקוי הרשימה
{
	// empty all elements from the List
	Link* theNext = nullptr;
	for (Link* p = head; p != nullptr; p = theNext)
	{
		// delete the element pointed to by p
		theNext = p->next;
		p->next = nullptr;
		delete p;
	}
	// mark that the List contains no elements
	head = nullptr;
}

List& List::operator=(const List& l)//אופרטור השמה
{
	if (l.isEmpty())
		head->next = nullptr;
	else
	{
		head = new Link((l.head)->value, nullptr);
		Link* q = head;
		Link* p = l.head;
		while (p->next)
		{
			q->next = new Link((p->next)->value, nullptr);
			p = p->next;
			q = q->next;
		}
	}
	return *this;
}

void List::insert(int key)//הוספת איבר
{
	if (isEmpty())
		head->value = key;
	else
	{
		Link* p = head;
		while (p->next)
		{
			if (head->value <= key)
			{
				add(key);
				return;
			}
			else
			{
				if (p->next->value <= key)
				{
					Link* n = new Link(key, p->next);
					p->next = n;
					return;
				}
				p = p->next;
			}
		}
		Link* n = new Link(key, nullptr);
		p->next = n;

	}
}

void List::remove(int key)//מחיקת איבר
{

	Link* p = head;
	if (head->value == key)
	{
		head = head->next;
	}
	else
	{
		while (p->next)
		{
			if (p->next->value == key)
			{
				Link* h = p->next;
				p->next = h->next;
				return;
			}
			p = p->next;
		}
		throw "value not found";
	}

}

bool List::isEmpty() const//בדיקה אם הרשימה ריקה
{
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null
	return head == nullptr;
}

void List::add(int val)//הוספה להתחלה
{
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (head == nullptr)
		throw "failed in memory allocation";
}

int List::firstElement() const//בדיקה מיהו האיבר הראשון
{
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}

bool  List::search(const int& val) const//בדיקה אם ערך קיים ברשימה
{
	// loop to test each element
	for (Link* p = head; p != nullptr; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}


void List::removeFirst()//מחיקת האיבר הראשון
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = nullptr;
	// recover memory used by the first element
	delete p;
}

ostream& operator<<(ostream& os, const List& l)//אופרטור הדפסה
{
	List::Link* p = l.head;
	while (p)
	{
		os << p->value << " ";
		p = p->next;
	}
	os << endl;
	return os;
}

istream& operator>>(istream& is, List& l)//אופרטור הכנסה
{
	int key, prev;

	is >> key;
	l.add(key);
	prev = key;
	is >> key;
	while (prev > key)
	{
		l.insert(key);
		prev = key;
		is >> key;
	}


	return is;
}
