#include<bits/stdc++.h>

using namespace std;

int ara[100];
int price[100];


int knapsack(int w,int index)
{
    if(index==0)return 0;
    if(w==0)return 0;
    if(ara[index-1]>w)return knapsack(w,index-1);
    else return max((price[index-1]+knapsack(w-ara[index-1],index-1)),knapsack(w,index-1));



}

int main()
{
    int n;
    int amount;
    cin>>amount;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ara[i];
        cin>>price[i];
    }
    int ans=knapsack(amount,n);
    cout<<ans<<endl;
}

