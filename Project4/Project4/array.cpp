#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int appendToAll(string a[], int n, string value) {
	if (n < 0) {
		return -1;
	}
	if (n == 0) {
		return n;
	}
	for (int k = 0; k != n; k++) {
		a[k] += value;
	}
	return n;
}

int lookup(const string a[], int n, string target) {
	if (n < 0) {
		return -1;
	}
	if (n == 0) {
		return -1;
	}
	int k;
	for (k = 0; k != n; k++) {
		if (a[k] == target) {
			break;
		}
		if (k == n - 1) {
			return -1;
		}
	}
	return k;
}

int positionOfMax(const string a[], int n) {
	if (n < 0) {
		return -1;
	}
	if (n == 0) {
		return -1;
	}
	int k;
	string max = a[0];
	int maxpos = 0;
	for (k = 0; k != n; k++) {
		if (k != n - 1) {
			if (a[k + 1] > max) { //if element is higher than current max
				max = a[k + 1]; //set max to that element
				maxpos = k + 1; //set max pos to that element's position
			}
		}
		else {
			break;
		}
	}
	return maxpos;
}

int rotateLeft(string a[], int n, int pos) {
	if (n < 0 || pos < 0 || pos > n) {
		return -1;
	}
	if (n == 0) {
		return -1;
	}
	for (int k = 0; k != n; k++) {
		if (a[k] == a[pos]) {
			string tempstring = a[pos]; //copies the element at pos/k
			for (int j = pos + 1; j != n; j++) {
				a[j - 1] = a[j]; // repeatedly set the elements at and before position pos to the element ahead of it 
			}
			a[n - 1] = tempstring; //set the last element to the element at pos
		}
	}
	return pos;
}

int countRuns(const string a[], int n) {
	if (n < 0) {
		return -1;
	}
	if (n == 0) {
		return 0;
	}
	int counter = 1; //the first element will always be counted
	for (int k = 0; k != n - 1; k++) {
		if (a[k] != a[k + 1]) { //if the element at k is not the same as the element in front of it
			counter++;
		}
	}
	return counter;
}

int flip(string a[], int n) {
	if (n < 0) {
		return -1;
	}
	if (n == 0) {
		return n;
	}
	for (int k = 0; k != n / 2; k++) { //will allow the array to be flipped until it reaches the middle
		string temp = a[k]; //copy the beginning element
		a[k] = a[n - 1 - k]; //first element becomes the last element
		a[n - 1 - k] = temp; //last element becomes the first element/
	}
	return n;
}

int differ(const string a1[], int n1, const string a2[], int n2) {
	if (n1 < 0 || n2 < 0) {
		return -1;
	}
	if (n1 <= n2) {
		for (int k = 0; k != n1; k++) {
			if (a1[k] != a2[k]) {
				return k;
			}
		}
		return n1;
	}
	else if (n2 <= n1) {
		for (int k = 0; k != n2; k++) {
			if (a1[k] != a2[k]) {
				return k;
			}
		}
		return n2;
	}
	return -1;
}

int subsequence(const string a1[], int n1, const string a2[], int n2) {
	if (n2 > n1) {
		return -1;
	}
	if (n2 == 0) {
		return n2;
	}
	int counter = 0;
	int k = 0;
	for (int j = 0; j != n1; j++) {
		if (a2[k] == a1[j]) {
			counter++;
			k++;
		}
		else { //if the elements are not in order of the sequence, reset it
			counter = 0;
			k = 0;
		}
		if (counter == n2) { //if counter matches number of elements in the subsequence array
			return j - (n2 - 1); //return it's starting position in the sequence array
		}
		if (a1[j] == a1[n1 - 1]) { //if goes through the array without finding a matching subsequence
			return -1;
		}
	}
	return -1;
}

int lookupAny(const string a1[], int n1, const string a2[], int n2) {
	if (n1 < 0 || n2 < 0) {
		return -1;
	}
	for (int k = 0; k != n1; k++) {
		for (int j = 0; j != n2; j++) {
			if (a2[j] == a1[k]) {
				return k;
			}
		}
	}
	return -1;
}

int split(string a[], int n, string splitter) {
	string b[50];
	int count = 0;
	if (n < 0) {
		return -1;
	}
	if (n == 0) {
		return -1;
	}
	for (int i = 0; i != n; i++) {
		if (a[i] < splitter) {
			b[count] = a[i];
			count++; //so that the function could add to b2 in the correct element positions
		}
	}
	for (int i = 0; i != n; i++) {
		if (a[i] == splitter) {
			b[count] = a[i];
			count++;
		}
	}
	for (int i = 0; i != n; i++) {
		if (a[i] > splitter) {
			b[count] = a[i];
			count++;
		}
	}
	for (int k = 0; k != n; k++) {
		if (b[k] >= splitter) {
			return k;
		}
	}
	return n;
}

int main() {

}