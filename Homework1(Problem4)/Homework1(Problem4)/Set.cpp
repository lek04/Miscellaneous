#include <iostream>
#include <string>
#include <assert.h>
#include "Set.h"

using namespace std;

Set::Set()
{
    m_size = 0;
    //arr[m_size];
}

bool Set::empty() const
{
    if (size() == 0) {
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
    if (size() >= DEFAULT_MAX_ITEMS) { //if set is at capacity
        return false;
    }
    for (int k = 0; k < size(); k++) {
        if (arr[k] == value) { // if the set already contained the word in value var
            return false;
        }
    }
    m_size++; //adding a space for the new word
    arr[size()-1] = value;
    return true;
}

bool Set::erase(const ItemType& value)
{
    // Remove the value from the set if it is present.  Return true if the
    // value was removed; otherwise, leave the set unchanged and
    // return false.
    for (int k = 0; k < size(); k++) {
        if (value == arr[k]) { //if word was found
            for (int j = k + 1; j < size(); j++) { //shifts array to the left starting from where value is found
                arr[j - 1] = arr[j]; //replaces the word in the array that is the same as value with element ahead
            }
            m_size--; 
            return true;
        }
    }
    return false;
}

bool Set::contains(const ItemType& value) const
{
    // Return true if the value is in the set, otherwise false.
    for (int k = 0; k < size(); k++) {
        if (value == arr[k]) {
            return true;
        }
    }
    return false;
}

bool Set::get(int i, ItemType& value) const
{
    // If 0 <= i < size(), copy into value the item in the set that is
    // strictly greater than exactly i items in the set and return true.
    // Otherwise, leave value unchanged and return false.
    if (i >= size() || i < 0) {
        return false;
    }

    int comparedWord = 0;
    int greaterThan = 0;
    int k;

    for (k = 0; k < size(); k++) {
        if (arr[comparedWord] > arr[k]) { //first, is arr[0] == arr[0]?
            greaterThan++;
        }
        if (greaterThan > i) //when the word that is being compared is greater than too many words
        {
            k = -1;
            comparedWord++;
            greaterThan = 0;
        }
        if (k == (size() - 1) && greaterThan != i) { //allows the scanning of all words 
            k = -1;
            comparedWord++;
            greaterThan = 0;
        }
    }

    value = arr[comparedWord];
    return true;
}

void Set::swap(Set& other)
{
    // Exchange the contents of this set with the other one.
    if (this != &other) {
        Set temp = other; // other = b, temp is now b

        other.m_size = m_size; //b_size = a_size
        m_size = temp.m_size; //a_size = b_size

        for (int k = 0; k < other.m_size; k++) {
            other.arr[k] = arr[k]; //b_arr is now a_arr
        }

        for (int j = 0; j < m_size; j++) {
            arr[j] = temp.arr[j]; //a_arr is now b_arr
        }

    }
}