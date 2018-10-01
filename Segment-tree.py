def build(node,start,end):
    if start==end:
        tree[node]=a[start]
    else:
        mid=(start+end)//2
        build(2*node,start,mid)
        build(2*node+1,mid+1,end)
        tree[node]=tree[2*node]+tree[2*node+1]

def update(node,start,end,index,val):
    if start==end:
        a[index]=val
        tree[node] = val
    else:
        mid=(start+end)//2
        if start<=index and index<=mid:
            update(2*node, start, mid, index, val)
        else:
            update(2*node+1, mid+1, end, index, val)
        tree[node] = tree[2*node] + tree[2*node+1]
           

def query(node,start,end,l,r):
    if r<start or l>end:
        return 0
    if l<=start and r>=end:
        return tree[node]
    mid=(start+end)//2
    p1=query(2*node,start,mid,l,r)
    p2=query(2*node+1,mid+1,end,l,r)
    return p1+p2




n=5 #no.of elements in the array
a=[1,2,3,4,5] #the array elements
a.insert(0,0) #adding a 0 at the starting of the array which will help in offsetting the array indices to 1-based indexing 
tree=[0]*(4*(n+1)) #initialize the tree 
#the "build(int,int,int)" function is used to build the segment tree 
build(1,1,n)
print ("Sum before updating :" + str(query(1,1,n,1,3)))
#Update the tree using "update(int,int,int,int,int)" function in order to update the element at 3rd(1-based indexing) index with 6
update(1,1,n,3,6)
#Updated array a=[1,2,6,4,5]
#Displaying the Query using query(int,int,int,int,int)" function to find the sum of the subarray a[1....3]
print ("Sum after updating :" + str(query(1,1,n,1,3)))

