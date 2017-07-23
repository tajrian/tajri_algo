// Base conversation: Decimal from Any other base:
//-------------
//==============


#include<bits/stdc++.h>
using namespace std;

int power(int n,int m)
{
    int ans=1;
    for(int i=1;i<=m;i++){
       ans*=n;
    }
    return ans;
}

int main()
{
    int num,base,i=0,x,ans=0;
    scanf("%d %d",&num,&base);// given number and its base
    while(num){
        x=num%10;
        num/=10;
        ans+=x*power(base,i);
        i++;
    }
    printf("%d",ans);
}

//Base conversation: Decimal to any other base
//----------------------
//======================

int main()
{
    int num,base,i=0,x,ans=0;
    scanf("%d %d",&num,&base);
    string s;
    while(num){
        s.insert(s.begin(),'0'+num%base); // insert works as pushing element to a stack for a string.
        num/=base;
    }
    cout<<s<<endl;
}

//perfect squres within given range

int countOddSquares(int n, int m)
{
   return (int)pow(m,0.5) - (int)pow(n-1,0.5); // nlower bound ,m upper bound 
}

//-----------------------------

//bigmod

ll bigmod(ll a, ll b, ll md)
{

    ll r = 1;
    while(b)
    {

        if(b&1) r = (r * a%md)%md;
        a = (a%md * a%md)%md;
        b = b/2;

    }
    return r;

}

//-----------------------------------
