#include <bits/stdc++.h>

using namespace std;

// A trie structure which will store the following alphabets.
struct trie {
	bool isEndOfWord;
	unordered_map<char, trie*> alphabets;

	trie() {
		isEndOfWord = false;
	}
};

void addToTrie(string &s, trie *root) {
	int length = s.length();

	for(int i = 0; i < length; i++) {
		// If the current alphabet is not present in the following path, create it.
		if(root -> alphabets.find(s[i]) == root -> alphabets.end())
			root -> alphabets[s[i]] = new trie;

		root = root -> alphabets[s[i]];
	}

	root -> isEndOfWord = true;
}

void printLongestPrefix(trie *root) {
	// The nodes which have only one child, and are not the end of any word are the common prefix alphabets.
	while(root -> alphabets.size() == 1 && !(root -> isEndOfWord)) {
		cout << (*(root -> alphabets.begin())).first;
		root = (*(root -> alphabets.begin())).second;
	}
}

int main() {
	trie *root = new trie;

	int n;

	cout << "Enter the number of words: ";
	cin >> n;

	cout << "Enter " << n << " words:"<<endl;

	string s;

	while(n--) {
		cin>>s;
		addToTrie(s, root);
	}

	printLongestPrefix(root);
}

/*

Input:          Output:
3               ab
abcd
abc
ab

*/