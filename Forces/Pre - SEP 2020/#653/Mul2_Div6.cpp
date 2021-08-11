#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n,i=0,j=0,k=-1;
        cin>>n;
        if(n==1)
        {
            k=0;
        }
        while(n%6==0)
        {
            i++;
            n=n/6;
        }
        while(n%3==0)
        {
            j++;
            n=n/3;
        }
        if(n==1 && (i!=0 || j!=0))
            k=i+2*j;
        t--;
        cout<<k<<"\n";
    }
    return 0;
}