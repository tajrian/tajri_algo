/*
check if a given number is a power of 2 

(x-1) will have all the bits same as x, except for the rightmost 1 in x 
and all the bits to the right of the rightmost 1.

4=100
3=011

8=1000
7=0111

10=1010
9 =1001

binary representation of (x-1) can be obtained by simply flipping 
all the bits to the right of rightmost 1 in x and also including the rightmost 1. 
So a number is power of 2 if it is nonzero(obviously) and the bitwise operation of n and n-1 must be zero.
*/

bool power_of2(int n){
    if(n && !(n & (n-1)))return true;
    return false;
}


/*
Count the number of ones in the binary representation of the given number.

given:10
  1010
& 1001
-----
  1000
& 0111 
------
  0000
two two iterations , 2 ones in binary representation of 10
*/

int how_many1(int n){
    int cnt=0;
    if (n){
        while(n){
            n=n&(n-1);
            cnt++;
        }
    }
    return cnt;
}

/*
if ith bit is ON or OFF(1 or 0)

check if ith(i=2) bit of 10 is ON(indexing starts from 0)
1010
0100 -> 1<<i
----
0000 ->off

*/


bool if_1(int n,int i){
     if(n && (n & (1<<i)))return true;
     return false;
}


//finding all combinations of a given set

/* the main idea behind this is to find all combination of bit from 1 till 2^N
here we can find all binary combinarion using bit multiplication techniques like

1 & 1<<0 = 1 ->0th character
1 & 1<<1 = 0 
....
10 & 1<<0= 0 
10 & 10<<1 = 1 ->1th character
....
11 & 1<<0 = ->0th character
11 & 1<<1 = ->1th character
....
100 & 1<<0 = 0
100 & 1<<1 = 0
100 & 1<<2 = 1 ->2nd character
....
101 & 1<<0 = 1 ->0th character
101 & 1<<1 = 0
101 & 1<<2 = 1 ->2nd character
......
......
*/

void allsubsets(char c[],int N){
    int i,j;
    for(i=1;i<(1<<N);i++){
        for(j=0;j<(1<<N);j++){
            if(i & (1<<j)){
                cout<<c[j]<<" ";
            }
        }
        cout<<endl;
    }
}

//How many bits in a number
unsigned countBits(unsigned int number) 
{       
      // log function in base 2  
      // take only integer part 
      return (int)log2(number)+1; 
} 

//largest power of 2 less or equal to N

int lagrest_pow_of2(int n){
    n=n| n>>1;
    n=n| n>>2;
    n=n| n>>4;
    n=n| n>>8;
    
    return (n+1)>>1;
}

/*this solution can also be done by finding the number of bit in the given number using i=(int)log2(number)+1 
and 2^i-1 would be the largest power of 2 less or equal to the number
*/
