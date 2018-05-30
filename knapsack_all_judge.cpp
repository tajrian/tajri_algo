//uva 624

#include<bits/stdc++.h>

using namespace std;







int main()
{

    int n,T,m;

    //scanf("%d",&T);
    while(scanf("%d",&T)!=EOF){

    int amount;
    amount=T;
    scanf("%d",&n);
    //int weight[n+10];
    int price[n+10];
    int dp[n+10][T+10];

    for(int i=0;i<n;i++){
        scanf("%d",&price[i]);
        //amount+=price[i];
    }

    for(int i=0;i<=amount;i++){
        dp[0][i]=0;
    }
    for(int j=0;j<=n;j++){
        dp[j][0]=0;
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=amount;i++){
            if(price[j-1]>i)dp[j][i]=dp[j-1][i];
            else dp[j][i]= max((price[j-1]+dp[j-1][i-price[j-1]]),dp[j-1][i]);
        }
    }
    //printf("sum %d\n",dp[n][amount]);

    stack<int>S;

    int res=dp[n][amount];
    for(int i=n;i>0 && res>0; i--){
        if(res==dp[i-1][T])continue;
        else {
            //printf("%d ",price[i-1]);
            S.push(price[i-1]);
            res= res-price[i-1];
            T=T-price[i-1];
        }
    }
    while(!S.empty()){
        printf("%d ",S.top());
        S.pop();

    }

    printf("sum:%d\n",dp[n][amount]);

    }
    return 0;
}

//uva 10130

#include<bits/stdc++.h>

using namespace std;







int main()
{

    int n,T,m;

    scanf("%d",&T);
    while(T--){

    int amount=0;;
    scanf("%d",&n);
    int weight[n+10];
    int price[n+10];
    int dp[n+10][(n+10)*500];

    for(int i=0;i<n;i++){
        scanf("%d",&price[i]);
        amount+=price[i];
    }

    int sum=amount;
    amount/=2;

    for(int i=0;i<=amount;i++){
        dp[0][i]=0;
    }
    for(int j=0;j<=n;j++){
        dp[j][0]=0;
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=amount;i++){
            if(price[j-1]>i)dp[j][i]=dp[j-1][i];
            else dp[j][i]= max((price[j-1]+dp[j-1][i-price[j-1]]),dp[j-1][i]);
        }
    }
    printf("%d\n",sum-2*dp[n][amount]);
    }
    return 0;
}

//uva 560 

#include<bits/stdc++.h>

using namespace std;





int main()
{

    int n,T,m;

    cin>>T;
    while(T--){
    //int weight[100];
    int price[100];
    int dp[100][100];

    int amount;
    cin>>n;
    int sum=0;;
    for(int i=0;i<n;i++){

       cin>>price[i];
       sum+=price[i];
       weight[i];
    }
    sum=sum/2;
    

    for(int i=0;i<=sum;i++){
        dp[0][i]=0;
    }
    for(int j=0;j<=n;j++){
        dp[j][0]=0;
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=sum;i++){
            if(price[j-1]>i)dp[j][i]=dp[j-1][i];
            else dp[j][i]= max((price[j-1]+dp[j-1][i-weight[j-1]]),dp[j-1][i]);
        }
    }

    for(int i=0;i<m;i++){
        s+=dp[n][ara[i]];
    }

    cout<<s<<endl;
    }
    return 0;
}
