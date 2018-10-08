//Object Oriented Implementation of hash tables 

#include<bits/stdc++.h>
using namespace std;

class node{
  long long int data;
  node* ptr;
public:
  void setptr(node* p){
    ptr=p;
  }
  void setdata(long long int v){
    data=v;
  }
  node* showptr(){
    return ptr;
  }
  long long int showdata(){
    return data;
  }
  long long int qhf(long long int value,long long int n){
    long long int a=1,b=1,c=1;
    return ((a*value*value+b*value+c)%n);
  }
  void displayhashtable(node* hashtable[],long long int n){
    cout<<"The hashtable is as following: "<<endl;
    for(long long int i=0;i<n;i++){
      cout<<i<<" - ";
      node* end=hashtable[i];
      while(end!=NULL){
        cout<<(*end).showdata()<<" ";
        end=(*end).showptr();
      }
      cout<<endl;
    }
    cout<<endl;
  }
  void insertinhashtable(node* hashtable[],long long int n,long long int key){
    node* newen;
    newen=new node;
    long long int pos=qhf(key,n);
    (*newen).setdata(key);
    node* temp=hashtable[pos];
    (*newen).setptr(temp);
    hashtable[pos]=newen;
  }
  int searchinhashtable(node *hashtable[],long long int n, long long int key){
    int found=0;
    long long int pos=qhf(key,n);
    node* temp=hashtable[pos];
    while(temp!=NULL){
      if((*temp).showdata()==key){
        found=1;
        break;
      }
      temp=(*temp).showptr();
    }
  return found;
  }
};
int main(){
  node callobj;
  long long int n,m;
  cout<<"Give size of hash table : ";
  cin>>n;
  m=(n*n+1);
  m=(long double)m+(long double)m/2;
  long long int alldata[m];
  for(long long int i=0;i<m;i++){
    alldata[i]=rand();
  }
  node* hashtable[n];
  for(long long int i=0;i<n;i++){
    hashtable[i]=NULL;
  }
  long long int pos;
  for(long long int i=0;i<m;i++){
    node* newen;
    newen=new node;
    pos=callobj.qhf(alldata[i],n);
    (*newen).setdata(alldata[i]);
    node* temp=hashtable[pos];
    (*newen).setptr(temp);
    hashtable[pos]=newen;
  }
  callobj.displayhashtable(hashtable,n);
  callobj.insertinhashtable(hashtable,n,35005211);
  callobj.displayhashtable(hashtable,n);
  if(callobj.searchinhashtable(hashtable,n,1967513926))  cout<<"Present"<<endl;
  else cout<<"Not present"<<endl;
  return 0;
}
