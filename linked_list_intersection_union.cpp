#include <bits/stdc++.h>

using namespace std;

struct node {
	int number;
	node *next;

	node() {
		number = INT_MAX;
		next = NULL;
	}
};

void printUnion(node *firstList, node *secondList, unordered_set<int> &secondListLookup) {
	cout << "Union of both lists is: "<<endl;

	while(firstList -> number != INT_MAX) {
		// If the current number is not present in the second list, print it. Else it will anyways, be printed by the second list.
		if(secondListLookup.find(firstList -> number) == secondListLookup.end())
			cout << firstList -> number << ' ';

		firstList = firstList -> next;
	}

	while(secondList -> number != INT_MAX) {
		cout<< secondList -> number << ' ';
		secondList = secondList -> next;
	}

	cout<<endl;
}

void printIntersection(node *firstList, unordered_set<int> &secondListLookup) {
	cout << "Intersection of both lists is: "<<endl;

	while(firstList -> number != INT_MAX) {
		// If the current number is present in the second list, print it.
		if(secondListLookup.find(firstList -> number) != secondListLookup.end())
			cout << firstList -> number << ' ';

		firstList = firstList -> next;
	}

	cout<<endl;
}

int main() {

	// firstList is the HEAD to the first list. Same for secondList.
    node *firstList = new node, *secondList = new node;

    // iteratorFirst iterates over the first list to take inputs. Same for iteratorSecond.
    node *iteratorFirst = firstList, *iteratorSecond = secondList;

    cout << "Enter the number of elements in the first linked list: ";
    int n;
    cin >> n;

    cout << "Enter the elements: ";

    for(int i = 1; i <= n; i++) {
    	int x;
    	cin >> x;

    	iteratorFirst -> number = x;
    	iteratorFirst -> next = new node;
    	iteratorFirst = iteratorFirst -> next;
    }

    cout << "Enter the number of elements in the second linked list: ";
    int m;
    cin >> m;

    // An unordered_set to lookup the numbers in second list while printing intersection and union. It provides O(1) lookup. See its implementation for usage.
    unordered_set<int> secondListLookup;

    cout << "Enter the elements: ";

    for(int i = 1; i <= m; i++) {
    	int x;
    	cin >> x;

    	iteratorSecond -> number = x;
    	iteratorSecond -> next = new node;
    	iteratorSecond = iteratorSecond -> next;

    	secondListLookup.insert(x);
    }

    printUnion(firstList, secondList, secondListLookup);
    printIntersection(firstList, secondListLookup);

    return 0;
}

/*

Input:                 Output:
6                      Union of both lists is:
1 2 3 4 5 6            2 3 4 5 1 6 8 8
4                      Intersection of both lists is:
1 6 8 8                1 6 

*/