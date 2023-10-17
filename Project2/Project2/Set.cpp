#include "Set.h"
#include <iostream>

using namespace std;

Set::Set()
{
	head = nullptr;
	m_size = 0;
}

Set::Set(const Set& source)
{
	Node* traverser;
	traverser = source.head;
	//m_size = source.m_size;
	//int counter = 1;

/*	while (traverser != nullptr) {
		Node* newNode;
		newNode = new Node; 
		if (counter == 1) {
			head = newNode;
		}
		newNode->value = traverser->value;
		newNode->next = traverser->next;
		newNode->prev = traverser->prev;
		traverser = traverser->next;
		counter++; //exceptions being thrown for reasons i don't really understand so think of plan b
	} */

	while (traverser != nullptr) {
		insert(traverser->value); //creates new nodes through source's values
		traverser = traverser->next;
	}
}

Set& Set::operator=(const Set& source)
{
	if (this == &source) {
		return *this;
	}

	Node* p;
	p = head;
	while (p != nullptr) { //deletes existing list
		Node* n;
		n = p->next;
		delete p;
		p = n;
	}

	head = nullptr;
	m_size = 0;
	p = source.head;
	while (p != nullptr) {
		insert(p->value); //creates new nodes through source's values
		p = p->next;
	}

	return *this;
}

Set::~Set()
{
	Node* p;
	p = head;

	while (p != nullptr) {
		Node* n;
		n = p->next;
		delete p;
		p = n;
	}
}

bool Set::empty() const
{
	if (head == nullptr) {
		return true;
	}
	return false;
}

int Set::size() const
{
	return m_size;
}

bool Set::insert(const ItemType& value)
{
	Node* p1;
	p1 = head;

	while (p1 != nullptr) { //if head == nullptr(empty), it skips this block. Stops when reaches last item
		if (p1->value == value) {
			return false;
		}
		p1 = p1->next; //will hold the address of the next node/item 
	}

	if (size() == 0) { // (head == nullptr) if empty list, adds to the rear
		Node* p;
		p = new Node;
		p->value = value;
		p->next = head;
		p->prev = head;
		head = p;
		m_size++;
		return true;
	}
	else //if not empty
	{
		//Node* p1;
		p1 = head;
		while (p1->next != nullptr) { //stop if the next node's address is nullptr
			p1 = p1->next; //p holds the address of the next node
		} //p1 stops just before reaching last node

		Node* p2;
		p2 = new Node;
		p2->value = value;
		p1->next = p2; //2nd last node points to last/newest node
		p2->next = nullptr; //last node points to null since it's at the end
		p2->prev = p1; //last node points to 2nd last node
		m_size++;
		return true;
	}
}

bool Set::erase(const ItemType& value)
{
	if (size() == 0) {
		return false; // nothing to erase in an empty list
	}

	if (head->value == value) {//if first item has the value we're looking for
		Node* remover;
		remover = head; //remover points at the first node which we want to delete
		head = remover->next; //head points to new top node
		if (head != nullptr) {//for lists that only have one item
			head->prev = nullptr; //top node should have no prev
		}
		//head->prev = nullptr; //top node should have no prev
		delete remover;
		m_size--;
		return true;
	}

	Node* p1;
	p1 = head;
	while (p1 != nullptr) { //if head == nullptr(empty), it skips this block. Stops when reaches last item
		if (p1->next != nullptr && p1->next->value == value) { //stops just above the node we want to delete
			break;
		}
		p1 = p1->next; //will hold the address of the next node/item 
	}
	if (p1 != nullptr) {
		Node* remover;
		remover = p1->next; //points at the node next to p1 (this node will be deleted)
		p1->next = remover->next; //p1's next will be 1 node down
		if (p1->next != nullptr) { //no need to switch prev pointer if removing last node
			p1->next->prev = p1;
		}
		delete remover;
		m_size--;
		return true;

	}
	return false; //didn't find word
}

bool Set::contains(const ItemType& value) const
{
	Node* p;
	p = head;

	if (size() == 0) {
		return false;
	}

	while (p != nullptr) {
		if (p->value == value) {
			return true;
		}
		p = p->next;
	}
	return false; //word wasn't found
}

bool Set::get(int pos, ItemType& value) const
{
	if (pos >= size() || pos < 0) {
		return false;
	}

	Node* a; //the traversal node
	Node* b; //the comparing node
	int greaterThan = 0; //the number of items b->value is greater than
	a = head;
	b = head;

	while (a != nullptr) {
		if (b->value > a->value) {
			greaterThan++;
			a = a->next;
		}
		else {
			a = a->next;
		}
		if (greaterThan > pos) { //greaterThan should ONLY equal pos
			a = head;
			b = b->next;
			greaterThan = 0;
		}
		if (a == nullptr && greaterThan != pos) { //allows the cycle to continue when end of list is reached
			a = head;
			b = b->next;
			greaterThan = 0;
		}
		else if (a == nullptr && greaterThan == pos) { 
			//allows break if greaterThan threshold reached through last node
			break;
		}
	}

	value = b->value;
	return true;
}

void Set::swap(Set& other)
{
	if (this != &other) {
		Node* tempHead = head; //store's a's head
		int tempSize = m_size; //stores a's size

		head = other.head; //a's list becomes b's list
		m_size = other.m_size; // a's size becomes b's size

		other.head = tempHead; //b's list becomes a's list
		other.m_size = tempSize; // b size becomes a size

	}
}

void unite(const Set& s1, const Set& s2, Set& result)
{
	ItemType x;

	if (&s1 != &result && &s2 != &result) { //will not delete result if s1 or s2 IS result
		int startingSize = result.size();
		for (int i = 0; i < startingSize; i++) { //deletes everything from result
			result.get(0, x);
			result.erase(x);
		}
	}

	for (int k = 0; k < s1.size(); k++) { //inserts elements from s1 into result
		s1.get(k, x);
		result.insert(x);
	}

	for (int j = 0; j < s2.size(); j++) { //inserts elements from s2 into result
		s2.get(j, x);
		result.insert(x);
	}

}

void butNot(const Set& s1, const Set& s2, Set& result)
{
	/*ItemType x;
	if (&s1 != &result && &s2 != &result) { //will not delete result if s1 or s2 IS result
		int startingSize = result.size();
		for (int i = 0; i < startingSize; i++) { //deletes everything from result
			result.get(0, x);
			result.erase(x);
		}
	}

	for (int k = 0; k < s1.size(); k++) { //inserts elements from s1 into result
		s1.get(k, x);
		result.insert(x);
	}

	for (int j = 0; j < s2.size(); j++) { //inserts elements from s2 into result
		s2.get(j, x);
		result.insert(x);
	} */

	unite(s1, s2, result);
	ItemType x;

	//Above was done to get result set for easy sorting

	int startingSize = result.size();
	for (int i = 0; i < startingSize; i++) { //deletes s2 items out of result set, leaving only s1 items
		s2.get(i, x);
		if (result.contains(x)) {
			result.erase(x);
		}
	}

}