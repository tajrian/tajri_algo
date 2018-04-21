
// hackerearth 
/*
https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/the-old-monk/
*/

#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include <iomanip>
using namespace std;

long long  result=-1,t,v=-1;

void bs_f(long long  lo,long long  hi,long long  ara[])
{
    if(lo>hi)return;
    long long  mid=lo+((hi-lo)/2);
    if(t==ara[mid])
    {
        result=mid;
        bs_f(lo,mid-1,ara);
    }
    else if(t>ara[mid])bs_f(lo,mid-1,ara);
    else if(t<ara[mid])bs_f(mid+1,hi,ara);
}

long long  bs_bound(long long  lo,long long  hi,long long  ara[])
{
    if(t>ara[lo])
    {
        v=1; // v=1 hole songkhar cheye choto songkhar index return korbe
        return lo;
    }
    if(t<ara[hi])
    {
        v=2; // v=2 hole songkhar cheye immiditae boro songkhar index return korbe
        return hi;
    }
    long long  mid=lo+((hi-lo)/2);
    if(ara[mid]>t)
    {
        bs_bound(mid+1,hi,ara);
    }
    else if(ara[mid]<t)
    {
        bs_bound(lo,mid-1,ara);
    }

}



int main()
{
    long long  q,n,z,ans,fans;
    cin>>q;
    while(q--)
    {
        cin>>n;
        ans,fans=0;
        long long  ara1[n];
        long long  ara2[n];
        for(long long  i=0; i<n; i++)cin>>ara1[i];
        for(long long  i=0; i<n; i++)cin>>ara2[i];
        for(long long  i=0; i<n; i++)
        {
            ans=0;
            z=-1;
            t=ara2[i];
            if(t>ara1[0])z=0;
            else if(t<ara1[n-1])z=n;
            else
            {
                result=-1;
                bs_f(0,n-1,ara1);
                if(result!=-1)
                {
                    //cout<<"Number found at "<<result+1<<endl;
                    z=result;
                }
                else
                {
                    v=-1;
                    z=bs_bound(0,n-1,ara1);
                    if(v==2)z=z+1;
                }
            }
            if(i>=z)ans=i-z;
            else ans=0;
            fans=max(ans,fans);

        }
        cout<<fans<<endl;
    }
    return 0;

}
