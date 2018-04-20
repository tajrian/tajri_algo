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

//finding the first occurance using b_search

int result=-1 ,t;

void bs_f(int lo,int hi,int ara[])
 {
    if(lo>hi)return;
    int mid=lo+((hi-lo)/2);
    if(t==ara[mid]){
       result=mid;
       bs_f(lo,mid-1,ara);
    }
    else if(t<ara[mid])bs_f(lo,mid-1,ara);
    else if(t>ara[mid])bs_f(mid+1,hi,ara);
 }


//finding the last occurance using b_search 

int result=-1 ,t;
void bs_f(int lo,int hi,int ara[])
 {
    if(lo>hi)return;
    int mid=lo+((hi-lo)/2);
    if(t==ara[mid]){
       result=mid;
       bs_f(mid+1,hi,ara);
    }
    else if(t<ara[mid])bs_f(lo,mid-1,ara);
    else if(t>ara[mid])bs_f(mid+1,hi,ara);
 }


//finding first occurance using b_serach in non incrasing array

int result=-1,t;

 void bs_f(int lo,int hi,int ara[]){
     if(lo>hi)return;
     int mid=lo+((hi-lo)/2);
     if(t==ara[mid]){
        result=mid;
        bs_f(lo,mid-1,ara);
     }
     else if(t>ara[mid])bs_f(lo,mid-1,ara);
     else if(t<ara[mid])bs_f(mid+1,hi,ara);
 }


int main()
{

    int n;
    while(cin>>n){
        int ara[n];
        for(int i=0;i<n;i++)cin>>ara[i];
        scanf("%d",&t);
        bs_f(0,n-1,ara);
        cout<<"first occurance at "<<result+1<<endl;
    }
    return 0;

}


//finding values less than x using b_search in non increasing array 
int v=-1;
int bs_bound(int lo,int hi,int ara[]){
    if(t>ara[lo]){
        v=1; // v=1 hole songkhar cheye choto songkhar index return korbe
        return lo;
    }
    if(t<ara[hi]){
        v=2; // v=2 hole songkhar cheye immiditae boro songkhar index return korbe 
        return hi;
    }
    int mid=lo+((hi-lo)/2);
    if(ara[mid]>t){
        bs_bound(mid+1,hi,ara);
    }
    else if(ara[mid]<t){
        bs_bound(lo,mid-1,ara);
    }

}











   

