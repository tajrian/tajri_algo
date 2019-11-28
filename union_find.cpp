
#include <iostream>

using namespace std;

int p[10];
int rank_[10];

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

int main()
{
    int i;
    for(i=1;i<=5;i++){
        create_set(i);
    }
    
    merge_set(1,2);
    merge_set(4,5);
    merge_set(1,5);
    printf("%d",find_root(1));

    return 0;
}
