// https://codeforces.com/contest/1415/problem/C

// You're creating a game level for some mobile game. The level should contain some number of cells aligned in a row from left to right and numbered with consecutive integers starting from 1, and in each cell you can either put a platform or leave it empty.
// In order to pass a level, a player must throw a ball from the left so that it first lands on a platform in the cell p, then bounces off it, then bounces off a platform in the cell (p+k), then a platform in the cell (p+2k), and so on every k-th platform until it goes farther than the last cell. If any of these cells has no platform, you can't pass the level with these p and k
// You already have some level pattern a1, a2, a3, ..., an, where ai=0 means there is no platform in the cell i, and ai=1 means there is one. You want to modify it so that the level can be passed with given p and k. In x seconds you can add a platform in some empty cell. In y seconds you can remove the first cell completely, reducing the number of cells by one, and renumerating the other cells keeping their order. 
// You can't do any other operation. You can not reduce the number of cells to less than p. What is the minimum number of seconds you need to make this level passable with given p and k?

// Input
// The first line contains the number of test cases t
// (1≤t≤100). Description of test cases follows.
// The first line of each test case contains three integers n, p, and k (1≤p≤n≤105, 1≤k≤n) — the number of cells you have, the first cell that should contain a platform, and the period of ball bouncing required.
// The second line of each test case contains a string a1a2a3…an
// (ai=0 or ai=1) — the initial pattern written without spaces.
// The last line of each test case contains two integers x and y (1≤x,y≤104) — the time required to add a platform and to remove the first cell correspondingly.
// The sum of n over test cases does not exceed 105.

// Output
// For each test case output a single integer — the minimum number of seconds you need to modify the level accordingly.
// It can be shown that it is always possible to make the level passable.

// Example
// Input
// 3
// 10 3 2
// 0101010101
// 2 2
// 5 4 1
// 00000
// 2 10
// 11 2 3
// 10110011000
// 4 3

// Output
// 2
// 4
// 10

// Note

// In the first test case it's best to just remove the first cell, after that all required platforms are in their places: 0101010101. The stroked out digit is removed, the bold ones are where platforms should be located. The time required is y=2
// In the second test case it's best to add a platform to both cells 4 and 5: 00000 → 00011. The time required is x⋅2=4
// In the third test case it's best to to remove the first cell twice and then add a platform to the cell which was initially 10-th: 10110011000 → 10110011010. The time required is y⋅2+x=10.


// Editorial

// Note that instead of deletion of the first cell we can increase the value of p by one, these operations are equivalent. Now let's loop through the possible final values of p, let it be q (p≤q≤n). 
// Then we need to add missing platforms in cells q, (q+k), (q+2k), and so on.
// Let's compute the array ci — the number of cells without a platform among cells i, (i+k), (i+2k), an so on. It can be computed using the method of dynamic programming, going from large i to small: ci=ci+k+(1−ai).
// Now the time required to add the platforms for a given value of q is cq⋅x, while the time needed to increase p to q is (q−p)⋅y. The total time equals cq⋅x+(q−p)⋅y. We only have to choose minimum among all possible values of q.


// #include<iostream>
// using namespace std;

// int main()
// {
//     int t;
//     cin>>t;
//     while(t>0)
//     {
//         long long n,p,k,x,y,i=0,min_time = INT_MAX;
//         cin>>n>>p>>k;
//         long long m;
//         string a;
//         cin>>a;
//         cin>>x>>y;
//         long long q = p;
//         while(q<=n){
//             m=0;
//             for(i=q-1;i<n;i+=k)
//             {
//                 if(a[i]==0)
//                     m++;
//             }
//             m = m*x + (q-p)*y;
//             q++;
//             if(m<min_time)
//                 min_time = m;
//         }
//         cout<<min_time<<"\n";
//         t--;
//     }
//     return 0;
// }

#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
int t;
cin>>t;
for(int i =0;i<t;i++)
{
long long int n,p,k;
cin>>n>>p>>k;
string a;
cin>>a;
long long int x,y;
cin>>x>>y;
long long int s=0,m=10000;
for(long long int j=0;j<n;j++)
{
s=j*y;
if(j+p-1>n)
{
break;
}
if(a[j+p-1]!='1')
{
s+=x;
}
for(long long int b=j+p+k-1;b<n;b+=k)
{
if(a[b]!='1')
{
s+=x;
}
}
if(s<m)
{
m=s;
}
if (s==0)
break;
}
cout<<m<<endl;;
}

 return 0;
}