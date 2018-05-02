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

