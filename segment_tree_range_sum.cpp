#include <bits/stdc++.h>

using namespace std;

void buildTree(int nodeLeft, int nodeRight, int index, int arr[], int segTree[]) {
	// If it's a leaf node, assign the corresponding array value to it.
	if(nodeLeft == nodeRight) {
		segTree[index] = arr[nodeLeft];
		return;
	}

	int mid = (nodeLeft + nodeRight) / 2;

	// Build tree for the first half of the current range.
	buildTree(nodeLeft, mid, 2 * index + 1, arr, segTree);

	// Build tree for the second half of the current range.
	buildTree(mid + 1, nodeRight, 2 * index + 2, arr, segTree);

	// Combine the left and right halves of the current position.
	segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
}

int query(int nodeLeft, int nodeRight, int lowerBound, int upperBound, int index, int segTree[]) {
	// If the queried range is invalid, return 0.
	if(lowerBound > upperBound)
		return 0;

	// If a queried range is found, return ther value.
	if(nodeLeft == lowerBound && nodeRight == upperBound)
		return segTree[index];

	int mid = (nodeLeft + nodeRight) / 2;

	// Query in the left and right halves of the current position and combine the sum.
	return query(nodeLeft, mid, lowerBound, min(mid, upperBound), 2 * index + 1, segTree) + query(mid + 1, nodeRight, max(lowerBound, mid + 1), upperBound, 2 * index + 2, segTree);
}

int main() {
    int n;
    cin >> n;

    int arr[n], segTree[4 * n];

    for(int i = 0; i < n; i++)
    	cin>>arr[i];

    buildTree(0, n - 1, 0, arr, segTree);

    int lowerBound, upperBound;

    cout<<"Enter a range: 1 <= Lower bound <= Upper Bound <= n: ";

    cin >> lowerBound >> upperBound;

    cout << query(0, n - 1, lowerBound - 1, upperBound - 1, 0, segTree);

    return 0;
}

/*

Input:                     Output:
6                          17
1 3 4 2 4 3
1 6

*/
