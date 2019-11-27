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

