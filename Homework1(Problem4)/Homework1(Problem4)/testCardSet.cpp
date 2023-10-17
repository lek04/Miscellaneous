#include <iostream>
#include <assert.h>
#include "CardSet.h"

using namespace std;

int main()
{
	CardSet a;
	assert(a.add(1));
	assert(a.add(2));
	assert(a.add(3));
	assert(!a.add(2));
	assert(a.size() == 3);
	a.print();
}