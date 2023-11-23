//Ruti Tenenboim 214360778
//sadna in c++
//week 6 exe 2
//התוכנית מגדירה מחלקה של רשימה מעגלית, המחלקה יורשת מהמחלקה רשימה 
#include "RoundList.h"

ostream& operator<<(ostream& os, const RoundList& rl)//אופרטור הדפסה
{
    if (!rl.isEmpty())
    {
        List::Link* p = rl.head;
        for (; p->next != rl.head;p=p->next)
        {
            os << p->next->value << " ";
        }
        os << rl.head->value;
    }
    return os;
}

RoundList::RoundList()//constructor
{
    List();
}

RoundList::RoundList(const RoundList& rl)//copy constructor
{
    if (rl.head==nullptr)
    {
        List(rl);
    }
    else
    {
        head = new List::Link(rl.head->value, rl.head->next);
        List::Link* p1 = rl.head;
        List::Link* p2 = head;
        do {
            p2->next= new List::Link(p2->value, p2->next);
            p1 = p1->next;
            p2 = p2->next;

        } while (p2 != rl.head);
        
    }
    
}

RoundList::~RoundList()//destuctor
{
    clear();
}

void RoundList::addToEnd(int val)//הוספה לסוף
{
    if (!isEmpty())
    {
        //הוספה האיבר החדש לאיבר שאחרי ראש הרשימה
        List::Link* p1 = head;
        List::Link* p2 = new List::Link(val, head->next);
        head= p2;
        p1->next = p2;
    }
    else {
        head = new List::Link(val, head);
        head->next = head;
    }
}

int RoundList::search(int n)//החזרת האיבר במקום שנשלח כפרמטר
{
    if (!isEmpty())
    {
        List::Link* p = head->next;
        for (int i = 0; i < n; i++)
        {
               p = p->next;
        }

        return p->value;
    }
    return -1;
}

void RoundList::add(int val)//הוספה להתחלה
{
    if (head == nullptr)
    {
        head= new List::Link(val, head);
        head->next = head;
    }
    else
    {
        List::Link* p = new List::Link(val, head->next);
        head->next = p;
    }
}

int RoundList::firstElement() const//בדיקה מיהו האיבר הראשון
{
    return head->next->value;
}

bool RoundList::search(const int& value) const//בדיקה אם ערך קיים ברשימה
{
    List::Link* p = head;
    do {
        if (p->value == value)
            return true;
        p = p->next;
    } while (p != head);
    return false;
}

void RoundList::removeFirst()//מחיקת האיבר הראשון
{
    if (!isEmpty())
    {
        List::Link* p = head->next;
        head->next = p->next;
        p->next = nullptr;
        delete p;
    }
}

void RoundList::clear()//ניקוי הרשימה
{
    if (!isEmpty())
    {
        List::Link* p1 = head->next;
        do
        {
            List::Link* p2 = head->next;
            p1 = p1->next;
            head->next = p2->next;
            p2 = nullptr;
            delete p2;


        } while (p1 != head);

        //head->next = nullptr;
        head = nullptr;
        delete head;
    }
    
}

RoundList& RoundList::operator=(const RoundList& rl)//אופרטור השמה
{
    if (rl.head == nullptr)
    {
        head = nullptr;
    }
    else
    {
        head = new List::Link(rl.head->value, rl.head->next);
        List::Link* p1 = rl.head;
        List::Link* p2 = head;
        do {
            p2->next = new List::Link(p2->value, p2->next);
            p1 = p1->next;
            p2 = p2->next;

        } while (p2 != rl.head);

    }
    return *this;
}


