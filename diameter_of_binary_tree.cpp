#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

typedef struct Btree
{
    int data;
    struct Btree *left;
    struct Btree *right;
} Btree;

Btree *putValue(Btree *root, int data)
{
    Btree *nn = new Btree();
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    if (root == NULL)
        return nn;

    queue<Btree *> q;
    q.push(root);
    while (!q.empty())
    {
        Btree *node = q.front();
        q.pop();
        if (node->left)
            q.push(node->left);
        else
        {
            node->left = nn;
            return root;
        }
        if (node->right)
            q.push(node->right);
        else
        {
            node->right = nn;
            return root;
        }
    }
}


static int maxi = 0;

int maximum(int a, int b)
{
    return a > b ? a : b;
}

int daimeter(Btree *root)
{
    if (root == NULL)
        return 0;
    int lside = daimeter(root->left);
    int rside = daimeter(root->right);
    // cout << lside << " " << rside << endl;
    if (maxi < 1 + lside + rside)
        maxi = 1 + lside + rside;
    return 1 + maximum(lside, rside);
}
int main()
{
    Btree *root = NULL;
    root = putValue(root, 1);
    root = putValue(root, 2);
    root = putValue(root, 3);
    root = putValue(root, 4);
    root = putValue(root, 5);
    root = putValue(root, 6);
    root = putValue(root, 7);
    root = putValue(root, 8);
    root = putValue(root, 9);
    root = putValue(root, 10);
    root = putValue(root, 11);
    root = putValue(root, 12);
    root = putValue(root, 13);
    root = putValue(root, 14);
    root = putValue(root, 15);
    root = putValue(root, 16);
    root = putValue(root, 17);
    root = putValue(root, 18);
    root = putValue(root, 19);
    root = putValue(root, 20);
    root = putValue(root, 21);
    daimeter(root);
    printf("%d", maxi);
    return 0;
}