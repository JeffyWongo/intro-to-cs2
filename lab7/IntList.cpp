#include "IntList.h"

IntList::IntList()
{
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList()
{
    while (head != nullptr)
    {
        IntNode* next = head->next;
        delete head;
        head = next;
    }
    head = nullptr;
    tail = nullptr;
}

void IntList::push_front(int value)
{
    IntNode* temp = new IntNode(value);
    temp->next = this->head;
    this->head = temp;
    if (this->tail == nullptr)
    {
        this->tail = this->head;
    }
}

void IntList::pop_front()
{
    if(head == nullptr)
    {
        tail = nullptr;
        return;
    }
    IntNode *tempNode = head;
    head = head->next;
    delete tempNode;
}

bool IntList::empty() const
{
    if(head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

const int& IntList::front() const
{
    return head->value;
}

const int& IntList::back() const
{
    IntNode* currNode = head;
    while(currNode->next != nullptr)
    {
        currNode = currNode->next;
    }
    return currNode->value;
}

ostream& operator<<(ostream &out, const IntList &list) 
{   
    IntNode* currNode = list.head;
    while(currNode != nullptr)
    {
        if(currNode->next == list.tail->next)
        {
            out << currNode->value;
            currNode = currNode->next;
        }
        else
        {
            out << currNode->value << " ";
            currNode = currNode->next;
        }
    }
    return out;
}

IntList::IntList(const IntList &cpy)
{
    if(cpy.empty())
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = nullptr;
        tail = nullptr;
        IntNode* currNode = cpy.head;
        tail = currNode;
        while(currNode != nullptr)
        {
            push_back(currNode->value);
            currNode = currNode->next;
        }
    }
}

IntList& IntList::operator=(const IntList &rhs)
{
    if(rhs.empty())
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        if(this != &rhs)
        {
            clear();
            IntNode* currNode = rhs.head;
            while(currNode != nullptr)
            {
                push_back(currNode->value);
                currNode = currNode->next;
            }
        }
    }
    return *this;
}

void IntList::push_back(int value)
{
    IntNode* tempNode = new IntNode(value);
    if(head == nullptr)
    {
        head = tempNode;
        tail = tempNode;
        return;
    }
    tail->next = tempNode;
    tail = tempNode;
}

void IntList::clear()
{
    while(!empty())
        {
            pop_front();
        }
    head = nullptr;
    tail = nullptr;
}

void IntList::selection_sort()
{
    IntNode* currNode = head;
    IntNode* i = head;
    IntNode* min = head;
    int tempVal;
    if(head == nullptr)
    {
        return;
    }
    while(i != nullptr)
    {
        while(currNode != nullptr)
        {
            if(currNode->value < min->value)
            {
                min = currNode;
            }
            currNode = currNode->next;
        }
        tempVal = min->value;
        min->value = i->value;
        i->value = tempVal;
        i = i->next;
        min = i;
        currNode = i;
    }
}

void IntList::insert_ordered(int value)
{
    if(head == nullptr)
    {
        push_front(value);
    }
    else if(value <= head->value)
    {
        push_front(value);
    }
    else if(value >= tail->value)
    {
        push_back(value);
    }
    else
    {
        IntNode* currNode = head;
        while(currNode->next != nullptr)
        {
            if(value < currNode->next->value)
            {
                IntNode* temp = new IntNode(value);
                temp->next = currNode->next;
                currNode->next = temp;
                return;
            }
            currNode = currNode->next;
        }
    }
}

void IntList::remove_duplicates()
{
    if(head == nullptr)
    {
        return;
    }
    IntNode* i = head;
    while(i->next != nullptr)
    {
        IntNode* p = i;
        IntNode* currNode = p->next;
        while(currNode != nullptr)
        {
            if(currNode->value == i->value)
            {
                p->next = p->next->next;
                if(currNode == tail)
                {
                    tail = p;
                }
                delete currNode;
            }
            else
            {
                p = p->next;
            }
            currNode = p->next;
        }
        if(i == tail)
        {
            return;
        }
        i = i->next;
    }
}
