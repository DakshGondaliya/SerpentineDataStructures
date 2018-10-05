#include<iostream>
using namespace std;
int main(){
int n;
cout<<"enter size of array";
cin>>n;
int a[n];
//input array elements
cout<<"enter elements os array";
for(int i=0;i<n;i++)
    cin>>a[i];

int ans = 0 ;   // Initialize result
    // Pick starting points of subarrays
    for (int i=0; i<n; i++)
    {
        int curr_xor = 0; // to store xor of current subarray
        // Pick ending points of subarrays starting with i
        for (int j=i; j<n; j++)
        {
            curr_xor = curr_xor ^ a[j];
            ans = max(ans, curr_xor);
        }
    }
cout<<ans;
return 0;
}


Output:
enter size of array4
enter elements os array1
2
3
4
7
