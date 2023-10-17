/*#include <iostream>
#include <assert.h>
#include "Set.h"

using namespace std;

//MY MAIN, THE MAIN THAT I MADE

int main()
{
	Set test;
/*	//tests insert
	test.insert("Walt");
	test.insert("Skyler");
	test.insert("Jr");
	test.insert("Walt");
	assert(test.size() == 3);
	//tests erase
	test.erase("Skyler");
	assert(!test.erase("Sklyer") && test.size() == 2);
	//tests contains
	assert(test.contains("Walt") && !test.contains("Skyler"));

	//tests erase
	Set test2;
	assert(!test2.erase("Hi"));
	test2.insert("Gus");
	test2.insert("Mike");
	test2.insert("Carlos");
	test2.insert("Eladio");
	test2.insert("Hector");
	test2.erase("Gus");
	assert(test2.size() == 4);
	test2.erase("Hector");
	assert(test2.size() == 3 && !test2.erase("Holly"));
	test2.erase("Carlos");
	assert(test2.size() == 2);
	//tests contains
	assert(test2.contains("Mike") && !test2.contains("Gus"));


	Set sss;  // ItemType is std::string
	sss.insert("ccc");
	sss.insert("aaa");
	sss.insert("bbb");
	ItemType xx = "xxx";
	assert(!sss.get(3, xx) && xx == "xxx");  // x is unchanged
	assert(sss.get(1, xx) && xx == "bbb");

	//tests swap
	Set ss1;
	ss1.insert("laobing");
	Set ssa;
	ssa.insert("matzo");
	ssa.insert("pita");
	ss1.swap(ssa);
	assert(ss1.size() == 2 && ss1.contains("matzo") && ss1.contains("pita") &&
		ssa.size() == 1 && ssa.contains("laobing")); */

	//tests copy constructor
/*	Set ss;
	ss.insert("lavash");
	ss.insert("roti");
	ss.insert("chapati");
	ss.insert("injera");
	ss.insert("roti");
	ss.insert("matzo");
	ss.insert("injera");
	assert(ss.size() == 5);  // duplicate "roti" and "injera" were not added
	string x;
	ss.get(0, x);
	assert(x == "chapati");  // "chapati" is greater than exactly 0 items in ss
	ss.get(4, x);
	assert(x == "roti");  // "roti" is greater than exactly 4 items in ss
	ss.get(2, x);
	assert(x == "lavash");  // "lavash" is greater than exactly 2 items in ss
	ss.get(3, x);
	assert(x == "matzo");
	ss.get(1, x);
	assert(x == "injera");
	assert(!ss.get(5, x));

	Set ss2(ss);
	assert(ss2.size() == 5);
	string x2;
	ss2.get(0, x2);
	assert(x2 == "chapati");  // "chapati" is greater than exactly 0 items in ss
	ss2.get(4, x2);
	assert(x2 == "roti");  // "roti" is greater than exactly 4 items in ss
	ss2.get(2, x2);
	assert(x2 == "lavash");  // "lavash" is greater than exactly 2 items in ss
	ss2.get(3, x2);
	assert(x2 == "matzo");
	ss2.get(1, x2);
	assert(x2 == "injera");
	assert(!ss2.get(5, x2)); */
	
	//tests assignment operator
/*	Set ss;
	ss.insert("lavash");
	ss.insert("roti");
	ss.insert("chapati");
	ss.insert("injera");
	ss.insert("roti");
	ss.insert("matzo");
	ss.insert("injera");
	assert(ss.size() == 5);  // duplicate "roti" and "injera" were not added
	string x;
	ss.get(0, x);
	assert(x == "chapati");  // "chapati" is greater than exactly 0 items in ss
	ss.get(4, x);
	assert(x == "roti");  // "roti" is greater than exactly 4 items in ss
	ss.get(2, x);
	assert(x == "lavash");  // "lavash" is greater than exactly 2 items in ss
	ss.get(3, x);
	assert(x == "matzo");
	ss.get(1, x);
	assert(x == "injera");
	assert(!ss.get(5, x));

	Set ss2;
	ss2.insert("blah");
	assert(ss2.size() == 1);
	ss2 = ss;

	assert(ss2.size() == 5);
	string x2;
	ss2.get(0, x2);
	assert(x2 == "chapati");  // "chapati" is greater than exactly 0 items in ss
	ss2.get(4, x2);
	assert(x2 == "roti");  // "roti" is greater than exactly 4 items in ss
	ss2.get(2, x2);
	assert(x2 == "lavash");  // "lavash" is greater than exactly 2 items in ss
	ss2.get(3, x2);
	assert(x2 == "matzo");
	ss2.get(1, x2);
	assert(x2 == "injera");
	assert(!ss2.get(5, x2)); */

//tests unite
/*Set a;
a.insert("2");
a.insert("8");
a.insert("3");
a.insert("9");
a.insert("5");

Set b;
b.insert("6");
b.insert("3");
b.insert("8");
b.insert("5");
b.insert("10");

Set c;
c.insert("blah1");
c.insert("blah2");
c.insert("blah3");
assert(c.size() == 3);

unite(a, b, c);
assert(c.size() == 7);
assert(c.contains("2") && c.contains("8") && c.contains("3") && c.contains("9") && 
	c.contains("5") && c.contains("6") && c.contains("10") && !c.contains("blah1"));

unite(a, b, b);
assert(b.size() == 7);
assert(b.contains("2") && b.contains("8") && b.contains("3") && b.contains("9") &&
	b.contains("5") && b.contains("6") && b.contains("10")); 

Set d;
Set e;
Set f = b;
assert(f.size() == 7);
unite(d, f, d);
assert(d.size() == 7); */

//tests erasing everything in a linked list
/*Set a;
a.insert("hi");
a.insert("bye");
a.erase("hi");
a.erase("bye");

//tests butNot
Set a;
a.insert("2");
a.insert("8");
a.insert("3");
a.insert("9");
a.insert("5");

Set b;
b.insert("6");
b.insert("3");
b.insert("8");
b.insert("5");
b.insert("10");

Set c;
c.insert("blah1");
c.insert("blah2");
c.insert("blah3");
assert(c.size() == 3);

butNot(a, b, c);
assert(c.size() == 2);
assert(c.contains("2") && c.contains("9") && !c.contains("blah3"));
butNot(b, a, c);
assert(c.size() == 2);
assert(c.contains("6") && c.contains("10") && !c.contains("9"));
butNot(a, b, a);
assert(a.size() == 2);
assert(a.contains("2") && a.contains("9") && !a.contains("3"));

/*Set a;
Set b(a);

	cerr << "Passed all Tests" << endl;
} */