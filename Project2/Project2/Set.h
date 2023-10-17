#ifndef SET_H
#define SET_H

#include <iostream>
#include <string>
#include "OurType.h" //this is the tester smallberg gave

//using ItemType = std::string; //orginal itemtype
using ItemType = int; //testing itemtype

class Set
{
public:
    Set();
    Set(const Set& source);
    Set& operator=(const Set& source);
    ~Set();
    bool empty() const;
    int size() const;
    bool insert(const ItemType& value);
    bool erase(const ItemType& value);
    bool contains(const ItemType& value) const;
    bool get(int pos, ItemType& value) const;
    void swap(Set& other);

private:
    struct Node
    {
        ItemType value;
        Node* next;
        Node* prev;
    };
    Node* head;
    int m_size;
};

void unite(const Set& s1, const Set& s2, Set& result);
void butNot(const Set& s1, const Set& s2, Set& result);

#endif//SET_H