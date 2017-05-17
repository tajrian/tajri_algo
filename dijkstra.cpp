#include<bits/stdc++.h>
using namespace std;

struct data{
    int v,cost;
    friend bool operator < (data a,data b)
    {
        return a.cost>b.cost;
    }
};

vector<data>edges[100];
int cost[100];

void djk(int n)
{
    priority_queue<data>Q;
    Q.push({n, 0});
    cost[n]=0;
    while(!Q.empty())
    {
        data t=Q.top();
        Q.pop();
        for(int i=0;i<edges[t.v].size();i++){
            int x=edges[t.v][i].v;
            if(cost[x]>cost[t.v]+edges[t.v][i].cost){
               cost[x]=cost[t.v]+edges[t.v][i].cost;
               Q.push({x,cost[x]});
            }
        }
    }
}

int main()
{
    int n,e,i,n1,n2,n3;  //n are nodes,e denoting edges.
    scanf("%d %d",&n,&e);
    for(i=1;i<=n;i++){
        cost[i]=1000000000;
    }
    while(e--){
        scanf("%d %d %d",&n1,&n2,&n3);
        edges[n1].push_back({n2,n3});
        edges[n2].push_back({n1,n3});
    }
    
    scanf("%d %d",&n1,&n2);
    djk(n1);
    printf("%d\n",cost[n2]);

}
