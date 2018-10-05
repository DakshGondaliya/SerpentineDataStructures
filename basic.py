import math
def maxSubarrayXOR(arr,n): 
  
    ans = -2147483648
    for i in range(n): 
        curr_xor = 0 
        for j in range(i,n): 
            curr_xor = curr_xor ^ int(arr[j]) 
            ans = max(ans, curr_xor) 
    return ans 
 
n = raw_input("Enter length of array")
arr = raw_input("Array elements with space")
arr = arr.split(" ")
print 'Maximum subarray XOR is '
print maxSubarrayXOR(arr,int(n))