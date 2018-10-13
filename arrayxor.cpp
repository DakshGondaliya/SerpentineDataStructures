#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void rotate_bits(int n, int k)
{

int n1 = n; 
int n2 = n;
k = k%16;
        n1 = ((((1<<k)-1)&n1)<<(16-k)) + (n1>>k);
        n2 = (((((1<<k)-1)<<(16-k))&n2)>>(16-k))+(n2<<k);
   cout<<n2<<"\n"<<n1<<"\n";
}


int main() {
	//code
	
	int n;
	cin>>n;
	while(n--)
	{
	   int num,k;
	   cin>>num>>k;
	   rotate_bits(num,k);
	    
	    
	}
	
	return 0;
}
