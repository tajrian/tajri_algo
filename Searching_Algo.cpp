// Binary Search

vector<int>ara;//search space

int bsearch(int target)
{
    int lo=0,high=ara.size()-1;
    while(lo<=high){
        mid=lo+((high-lo)/2);
        if(target==ara[mid])return ara[mid];
        else if(target<ara[mid])high=mid-1;
        else low=mid+1;
    }
}
// recursive binary serach:

#include<bits/stdc++.h>
using namespace std;

int n,t;

int b_search(int lo,int high,int ara[]){
    if(lo>high)return -1;
    int mid=lo+((high-lo)/2);
    if(t==ara[mid])return mid;
    else if(t<ara[mid]) return b_search(lo,mid-1,ara);
    else if(t>ara[mid]) return b_search(mid+1,high,ara);
}

int main()
{
   cin>>n;
   int ara[n];
   for(int i=0;i<n;i++){
        cin>>ara[i];
   }
   int r,e;
   cin>>r;
   while(r--){
       cin>>t;
       e=b_search(0,n-1,ara);
       if(e==-1)cout<<"not found"<<endl;
       else cout<<e<<endl;
   }
}

//------------------------------------

//binnary search function of non increasing array with no multiple occurances 

int b_search(int lo,int high,int ara[]){
    if(lo>high)return -1;
    int mid=lo+((high-lo)/2);
    if(t==ara[mid])return mid;
    else if(t<ara[mid]) return b_search(lo,mid-1,ara);
    else if(t>ara[mid]) return b_search(mid+1,high,ara);
}


