//Longest Common subsequence  

#include<bits/stdc++.h>
#include<algorithm>

#define diag 1
#define up 2
#define left 3

using namespace std;

int main()
{
    string str,str2;
    cin>>str;
    cin>>str2;
    int i,j,len1,len2;
    len1= str.size();
    len2= str2.size();

    int mat[len1+1][len2+1];
    for(i=0;i<=len1;i++){
        mat[i][0]=0;
    }
    for(j=0;j<=len2;j++){
        mat[0][j]=0;
    }
    for(i=1;i<=len1;i++){
        for(j=1;j<=len2;j++){
            if(str[i-1]==str2[j-1]){
                mat[i][j] = mat[i-1][j-1]+1;
            }
            else{
                mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }
    string st="";
    while(i>0  && j>0){
        if(str[i-1] == str2[j-1] ){
            st+= str[i-1];
            i--;
            j--;
        }
        else if(mat[i-1][j]>=mat[i][j-1]){
            i--;
        }
        else
        {
            j--;
        }
    }

    reverse(st.begin(),st.end());
    cout<<st<<endl;

    cout<<"LCS length "<<mat[len1][len2]<<endl;
    return 0;
}

//matrix chain multiplication 

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

int ara[100];

int store[100][100];
int visited[100][100];



int mcm(int lo,int hi){
    if(lo>=hi)return 0;
    if(visited[lo][hi]==1)return store[lo][hi];
    int q=1<<30;
    for(int i=lo;i<hi;i++){
        int t=mcm(lo,i)+mcm(i+1,hi)+(ara[lo-1]*ara[i]*ara[hi]);
        //cout<<t<<endl;
        q=min(q,t);
    }
    visited[lo][hi]=1;
    store[lo][hi]=q;
    return store[lo][hi];

}


int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ara[i-1]>>ara[i];
    }

    int z=mcm(1,n);
    cout<<z<<endl;
    return 0;

}

//rod cutting 
#include<bits/stdc++.h>

using namespace std;

int memo[100],path[100],ara[100];

void print_path(int n){
    cout<<"cut piece are :";
    while(n>0){
        cout<<path[n]<<" ";
        n=n-path[n];
    }
    cout<<endl;
}


int main()
{
    int n,i,j,ans,q;
    cin>>n;
    for(i=1; i<=n; i++)cin>>ara[i];
    memo[0]=0;
    for(i=1; i<=n; i++)
    {
        q=-9999999;
        for(j=1; j<=i; j++)
        {
            if(q<ara[j]+memo[i-j])
            {
                q=ara[j]+memo[i-j];
                path[i]=j;
            }
        }
        memo[i]=q;
    }
    cout<<"maximum profit "<<memo[n]<<endl;
    print_path(n);

}



