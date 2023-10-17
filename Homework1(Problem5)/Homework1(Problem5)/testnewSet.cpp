#include "newSet.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int main()
{
    //tests get and insert and size
 /*   Set ss;
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

    //tests swap
    Set ss1;
    ss1.insert("laobing");
    Set ss2;
    ss2.insert("matzo");
    ss2.insert("pita");
    ss1.swap(ss2);
    assert(ss1.size() == 2 && ss1.contains("matzo") && ss1.contains("pita") &&
        ss2.size() == 1 && ss2.contains("laobing"));

    //tests empty string
    Set sss;
    sss.insert("dosa");
    assert(!sss.contains(""));
    sss.insert("tortilla");
    sss.insert("");
    sss.insert("focaccia");
    assert(sss.contains(""));
    sss.erase("dosa");
    assert(sss.size() == 3 && sss.contains("focaccia") && sss.contains("tortilla") &&
        sss.contains(""));
    string v;
    assert(sss.get(1, v) && v == "focaccia");
    assert(sss.get(0, v) && v == "");

    //tests general
    Set s;
    assert(s.empty());
    ItemType xx = "arepa";
    assert(!s.get(42, xx) && xx == "arepa"); // x unchanged by get failure
    s.insert("chapati");
    assert(s.size() == 1);
    assert(s.get(0, xx) && xx == "chapati");
    cerr << "Passed all tests" << endl; */

    //Tests dynamic allocation
    Set a(1000);   // a can hold at most 1000 distinct items
    Set b(5);      // b can hold at most 5 distinct items
    Set c;         // c can hold at most DEFAULT_MAX_ITEMS distinct items
    ItemType v[6] = { "I","Really","Do","Hope","This","Works" };

    // No failures inserting 5 distinct items into b
    for (int k = 0; k < 5; k++) {
        assert(b.insert(v[k]));
    }

    // Failure if we try to insert a sixth distinct item into b
    assert(!b.insert(v[5]));

    // When two Sets' contents are swapped, their capacities are swapped
    // as well:
    a.swap(b);
    assert(!a.insert(v[5]) && b.insert(v[5]));

    assert(c.insert("Test"));
    assert(c.insert("Hi"));
    assert(b.insert("Hello"));
    b = c; //b should have 160 size and c should have 160
    assert(b.size() == 2 && c.size() == 2);
    assert(b.contains("Test"));
    assert(!b.contains("Hello"));

    Set ss;  // ItemType is std::string
    ss.insert("ccc");
    ss.insert("aaa");
    ss.insert("bbb");
    ItemType x = "xxx";
    assert(!ss.get(3, x) && x == "xxx");  // x is unchanged
    assert(ss.get(1, x) && x == "bbb");

    cerr << "Passed all tests" << endl;

    //tests the typeAlias
 /*   Set s;
    assert(s.empty());
    ItemType x = 9876543;
    assert(!s.get(42, x) && x == 9876543); // x unchanged by get failure
    s.insert(123456789);
    assert(s.size() == 1);
    assert(s.get(0, x) && x == 123456789);
    cerr << "Passed all tests" << endl; */

    //tests cardset
 /*   CardSet a;
    assert(a.add(1));
    assert(a.add(2));
    assert(a.add(3));
    assert(!a.add(2));
    assert(a.size() == 3);
    a.print(); */


}