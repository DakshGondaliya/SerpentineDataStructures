#include<bits/stdc++.h>
using namespace std;
int maxsubxor(int a[],int n)
{
	int ans=INT_MIN;
	for(int i=0;i<n;i++)
	{
		int cur_xor=0;
		for(int j=i;j<n;j++)
		{
			cur_xor^=a[j];
			ans=max(ans,cur_xor);
		}	
	}
	return ans;
}
int main()
{
	int arr[]={8,1,2,12};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"Max subarray XOR is "<<maxsubxor(arr,n);
	return 0;	
}

/*
Output: Max subarray XOR is 15
*/
