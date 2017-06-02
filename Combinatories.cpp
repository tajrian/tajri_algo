/*

Combinatories:
Your task is to compute in how many ways they can pick a pair of astronauts belonging to different countries. 
--------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------

We need to find the distinct sets (i.e. if x and y are from same country, they belong to same set) to get the answer. Let's say set A has a elements,set B has b elements.

Answer = a x b. [Because actual formula is to select one from set A and another one from set B = aC1 x bC1 = a x b]

Similarly, let's calculate answer for 4 sets - A,B,C,D with a,b,c,d elements respectively.

Lets say somehow I find set A has a elements.

Answer = 0 (Since I don't have another country to pair with)

Now, I find set B with b elements.

Answer = axb; .................................................(1)

Then, I find set C with c elements.

Answer = (axb) + (axc) + (bxc) [because we can select a pair from A and B, or A and C or B and C]

But this can be written as

Answer = (axb) + (a+b)xc ......................................(2)

Now I find set D with d elements, and I've examined all people.

Answer = (axb) + (axc) + (axd) + (bxc) + (bxd) + (cxd)

Or

Answer = (axb) x (a+b)xc + (a+b+c)xd ..........................(3)

Do you see the pattern? That means when we find a new set, the new answer is the old answer + the sum of old values x new value.
*/


//problem link: https://www.hackerrank.com/challenges/journey-to-the-moon

#include<bits/stdc++.h>
using namespace std;

long long nodes,ans,sum;

vector<int>re[100000];
bool visited[100005];

void DFS(int n){
    nodes++;
    visited[n]=true;
    for(int i=0;i<re[n].size();i++){
        if(!visited[re[n][i]])DFS(re[n][i]);
    }
}

int main()
{
    long long n,m,n1,n2,i;
    scanf("%lld %lld",&n,&m);
    while(m--){
        scanf("%lld %lld",&n1,&n2);
        re[n1].push_back(n2);
        re[n2].push_back(n1);
    }
    ans=0;
    sum=0;
    for(i=0;i<n;i++){
        if(!visited[i]){
            //printf("i: %lld\n",i);
            nodes=0;
            DFS(i);
            //printf("%lld has elemnt: %lld\n",i,nodes);
            ans+=(sum*nodes);
            sum+=nodes;
        }
    }
    printf("%lld\n",ans);
    return 0;
}


------------------------------------------------------------------------------
------------------------------------------------------------------------------

