//Dp problem 1:
//problem link: 
//https://csacademy.com/contest/round-31/task/recursive-string/discussion/

my solutio: 
#include<bits/stdc++.h>
using namespace std;

long long memo[40];

string solve(int n,int k)
{
    if(memo[n]<k)return "-1";
    if(n==0)return "a";
    if(n==1)return "b";
    if(n==2)return "c";

    for(int i=1;i<=3;i++){
        if(k>memo[n-i]){
            k-=memo[n-i];
        }
        else{
            return solve(n-i,k);
        }
    }
}

int main()
{
    memo[0]=1;
    memo[1]=1;
    memo[2]=1;
    int n,k;
    cin>>n>>k;
    for(int i=3;i<=n;i++){
        memo[i]=memo[i-1]+memo[i-2]+memo[i-3];
    }
    cout<< solve(n,k) << endl;
}


//problem 2:
//link: https://www.devskill.com/CodingProblems/ViewProblem/342

//not my solution

#include <bits/stdc++.h>
using namespace std;

int n;
int avail[] = {0, 1, 2, 3, 4};

int solve (int cur, int digit)
{
    if (digit == n) return 1;
    if (cur > 4 || cur < 0) return 0;

    int sol = 0;
    if (digit == 0) sol += solve(cur+1, digit);
    sol += solve(cur+2, digit+1);
    sol += solve(cur-2, digit+1);

    return sol;
}

int main()
{

    while (scanf("%d", &n) == 1)
        printf("%d\n", solve(0, 0)/2);
    return 0;
}


