#include <bits/stdc++.h>

// Considering the maximum number which will be entered will have at max 30 bits in binary representation.
#define MAX_BITS 30

using namespace std;

// A trie structure whose left child refers to 0 and right child refers to 1.
struct trie {
	trie *bits[2];
};

// Inserts the number into the trie following its binary representation.
void insertIntoTrie(int number, trie *root) {
	for(int i = MAX_BITS - 1; i >= 0; i--) {
		// Retrieve the ith bit.
		int bit = (number & (1 << i)) != 0;

		// If the trie doesn't have this bit at the current position, create it.
		if(root -> bits[bit] == NULL) {
			root -> bits[bit] = new trie;
		}

		// Follow down the path of the current bit.
		root = root -> bits[bit];
	}
}

// Finds the maximum XOR for the queried number.
int query(int number, trie *root) {
	// The maximum XOR value for the queried number.
	int xorValue = 0;

	for(int i = MAX_BITS - 1; i >= 0; i--) {
		// Retrieve the ith bit.
		int bit = (number & (1 << i)) != 0;

		// As soon as we get different MSB, it is sure to give the maximum XOR. The following conditions implements this logic.
		if(root -> bits[bit ^ 1] != NULL) {
			// If different bits are available, the xorValue will become (xorValue + 1 * 2^i) which can be written in the form as written below.
			xorValue += (1 << i);
			root = root -> bits[bit ^ 1];
		}
		else {
			root = root -> bits[bit];
		}
	}

	return xorValue;
}

/*
The main logic is, XOR of any subarray from a[i]...a[j] can be represented as (a[1] ^ a[2]...^a[j]) ^ (a[1] ^ a[2]...^a[i - 1]).
Hence we now have to find two numbers in the prefix xor array whose XOR is maximum.
For this, the maximum XOR of the array will be maximum XOR of any element with any available element.
We achieve this with Trie data structure. Follow the code for more understanding.
*/
int main() {
	// Number of elements in the array
	int n;
	cin >> n;

	int a[n + 1], maxXOR = 0;
	a[0] = 0;

	trie *root = new trie;

	insertIntoTrie(0, root);

	for(int i = 1; i <= n; i++) {
		cin >> a[i];

		// Find prefix XOR.
		a[i] ^= a[i - 1];

		// insertIntoTrie this prefix sum value into trie.
		insertIntoTrie(a[i], root);

		// maxXOR will be maximum of current maxXOR and the max XOR of this queried number.
		maxXOR = max(maxXOR, query(a[i], root));
	}

	cout<<maxXOR;
}

/*

Input:                  Output:
6                       13
1 2 4 6 3 8

*/