//Ruti Tenenboim 214360778
//sadna in c++
//week 6 exe 2
//������� ������ ����� �� ����� ������, ������ ����� ������� ����� 
#include "RoundList.h"

ostream& operator<<(ostream& os, const RoundList& rl)//������� �����
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

void RoundList::addToEnd(int val)//����� ����
{
    if (!isEmpty())
    {
        //����� ����� ���� ����� ����� ��� ������
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

int RoundList::search(int n)//����� ����� ����� ����� ������
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

void RoundList::add(int val)//����� ������
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

int RoundList::firstElement() const//����� ���� ����� ������
{
    return head->next->value;
}

bool RoundList::search(const int& value) const//����� �� ��� ���� ������
{
    List::Link* p = head;
    do {
        if (p->value == value)
            return true;
        p = p->next;
    } while (p != head);
    return false;
}

void RoundList::removeFirst()//����� ����� ������
{
    if (!isEmpty())
    {
        List::Link* p = head->next;
        head->next = p->next;
        p->next = nullptr;
        delete p;
    }
}

void RoundList::clear()//����� ������
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

RoundList& RoundList::operator=(const RoundList& rl)//������� ����
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


