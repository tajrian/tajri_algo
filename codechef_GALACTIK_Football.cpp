#include <iostream>

using namespace std;

int p[100005];
int rank_[100005];
bool vis[100005];
int cost[100005];


void create_set(int x){
    p[x]=x;
    rank_[x]=0;
}

int find_root(int x){
    if(p[x]!=x)p[x]=find_root(p[x]);
    return p[x];
}

void merge_set(int x,int y){
    int root_x = find_root(x);
    int root_y = find_root(y);
    if(rank_[root_x]>rank_[root_y])p[root_y]=root_x;
    else p[root_x]=root_y;
    if(rank_[root_x]==rank_[root_y])rank_[root_y]=rank_[root_y]+1;
}

void find_root2(int x){
    int root = find_root(x);
    if((cost[x]>=0 && cost[root]>cost[x]) || (cost[root]<0 && cost[x]>=0)){
        cost[root]=cost[x];
    }
}

int main()
{
    int n,m,a,b;
    cin>>n>>m;
    int i;
    for(i=1;i<=n;i++){
        create_set(i);
        vis[i]= false;
    }
    for(i=1;i<=m;i++){
        cin>>a>>b;
        merge_set(a,b);
    }
    
    for(i=1;i<=n;i++)cin>>cost[i];
    
    for(i=1;i<=n;i++){
        find_root2(i);
    }
    
    int j=1,cnt=0,min = 100005,sum=0;
    
    for(i=1;i<=n;i++){
        int root= find_root(i);
        if(vis[root]==false){
            //cout<<"root"<<cost[root]<<endl;
            if(cost[root]<0){
                j=0;
            }
            vis[root]=true;
            sum+=cost[root];
            cnt++;
            if(min>cost[root])min = cost[root];
            
        }
    }
    
    if(cnt!=1){
        if(j==0)cout<<"-1"<<endl;
        else cout<<sum+((cnt-2)*min)<<endl;
        
    }
    else cout<<"0"<<endl;
    
    
    return 0;
}


/*
Input 1
6 6
1 2
2 3
1 3
4 5
5 6
4 6
1
3
5
2
4
6

Output 1
3


Input 2
3 1
2 3
1
-1
-1

*/
