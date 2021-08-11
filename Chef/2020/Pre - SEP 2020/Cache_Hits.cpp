#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n,b,m,i,c=-1;
        cin>>n>>b>>m;
        int A[m];
        for(i=0;i<m;i++)
            cin>>A[i];
        i=0;int n_old = 1,n_new;
        int k=0;
        for(i=0;i<m;i++)
        {

            if(A[i]/b !=c)
            {
                c = A[i]/b;
                k++;
            }
        }
        
        cout<<k<<"\n";
        t--;
    }
    return 0;
}