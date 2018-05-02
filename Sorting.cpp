//Bubble sort Code
//Incresing Order

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int array[100], n, c, d, swap;
 
  printf("Enter number of elements\n");
  scanf("%d", &n);
 
  printf("Enter %d integers\n", n);
 
  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);
 
  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (array[d] > array[d+1]) /* For decreasing order use < */
      {
        swap       = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;
      }
    }
  }
}

//merge sort ascending order

#include<bits/stdc++.h>
using namespace std;

int store[100];
int temp[100];
int n;

void mergesort(int lo,int hi){
    if(lo==hi)return;
    int mid=(lo+hi)/2;
    mergesort(lo,mid);
    mergesort(mid+1,hi);
    int i,j,k;
    for(i=lo,j=mid+1,k=lo;k<=hi;k++){
        if(i==mid+1)temp[k]=store[j++];
        else if(j==hi+1)temp[k]=store[i++];
        else if(store[i]<store[j])temp[k]=store[i++];
        else temp[k]=store[j++];
    }
    for(i=lo;i<=hi;i++){
        store[i]=temp[i];
    }
}

void show(int m)
{
    for(int i=1; i<=m; i++)
    {
        printf("%d ",store[i]);
    }
    printf("\n");
}

int main()
{
    printf("Enter the number of elements to sort:\n");
    scanf("%d",&n);
    printf("Enter the elements to sort:");
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&store[i]);
    }
    mergesort(1,n);
    show(n);

}

//merge sort descending
#include<bits/stdc++.h>
using namespace std;

int store[100];
int temp[100];
int n;

void mergesort(int lo,int hi){
    if(lo==hi)return;
    int mid=(lo+hi)/2;
    mergesort(lo,mid);
    mergesort(mid+1,hi);
    int i,j,k;
    for(i=lo,j=mid+1,k=lo;k<=hi;k++){
        if(i==mid+1)temp[k]=store[j++];
        else if(j==hi+1)temp[k]=store[i++];
        else if(store[i]>store[j])temp[k]=store[i++];
        else temp[k]=store[j++];
    }
    for(i=lo;i<=hi;i++){
        store[i]=temp[i];
    }
}

void show(int m)
{
    for(int i=1; i<=m; i++)
    {
        printf("%d ",store[i]);
    }
    printf("\n");
}

int main()
{
    printf("Enter the number of elements to sort:\n");
    scanf("%d",&n);
    printf("Enter the elements to sort:");
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&store[i]);
    }
    mergesort(1,n);
    show(n);

}

//quick sort ascending 

#include<bits/stdc++.h>

using namespace std;

int ara[100];

void print(int a,int b)
{
    for(int i=a;i<b;i++){
        cout<<ara[i];
    }

}

void q_sort(int lo,int hi)
{
    if(lo>=hi)return;
    int left=lo,right=hi,pivot=lo;
    while(left<right){
        //cout<<pivot<<endl;
        if(pivot==left){
            if(ara[pivot]<ara[right])right--;
            else{
                swap(ara[pivot],ara[right]);
                pivot=right;
            }
        }
        else if(pivot==right){
            if(ara[pivot]>ara[left])left++;
            else{
                swap(ara[pivot],ara[left]);
                pivot=left;
            }
        }
    }
    //print(lo,hi);
    q_sort(lo,pivot-1);
    q_sort(pivot+1,hi);
    return;
}


int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)cin>>ara[i];
    q_sort(0,n-1);
    for(int i=0;i<n;i++)cout<<ara[i]<<" ";


}


//quick sort descending
#include<bits/stdc++.h>

using namespace std;

int ara[100];

void print(int a,int b)
{
    for(int i=a;i<b;i++){
        cout<<ara[i];
    }

}

void q_sort(int lo,int hi)
{
    if(lo>=hi)return;
    int left=lo,right=hi,pivot=lo;
    while(left<right){
        //cout<<pivot<<endl;
        if(pivot==left){
            if(ara[pivot]>ara[right])right--;
            else{
                swap(ara[pivot],ara[right]);
                pivot=right;
            }
        }
        else if(pivot==right){
            if(ara[pivot]<ara[left])left++;
            else{
                swap(ara[pivot],ara[left]);
                pivot=left;
            }
        }
    }
    //print(lo,hi);
    q_sort(lo,pivot-1);
    q_sort(pivot+1,hi);
    return;
}


int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)cin>>ara[i];
    q_sort(0,n-1);
    for(int i=0;i<n;i++)cout<<ara[i]<<" ";


}




