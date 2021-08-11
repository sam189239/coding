#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n;
        cin>>n;
        char a[n];
        int j = 0,c=0;
        for(j=0;j<n;j++)
        {
            cin>>a[j];
        }
        for(j=0;j<n-6;j++)
        {
            if((a[j] == 'a')&&(a[j+1] == 'b')&&(a[j+2] == 'a')&&(a[j+3] == 'c')&&(a[j+4] == 'a')&&(a[j+5] == 'b')&&(a[j+6] == 'a'))
                c++;
        }
        for(j=0;j<n-6;j++)
        {
            if((c == 0) && (a[j] == 'a' || a[j] == '?')&&(a[j+1] == 'b' || a[j+1] == '?')&&(a[j+2] == 'a' || a[j+2] == '?')&&(a[j+3] == 'c' || a[j+3] == '?')&&(a[j+4] == 'a' || a[j+4] == '?')&&(a[j+5] == 'b' || a[j+5] == '?')&&(a[j+6] == 'a' || a[j+6] == '?'))
            {
                c++;
                a[j] = 'a';
                a[j+1] = 'b';
                a[j+2] = 'a';
                a[j+3] = 'c';
                a[j+4] = 'a';
                a[j+5] = 'b';
                a[j+6] = 'a';
            }
            
        }
        for(j=0;j<n-6;j++)
        {
            if(a[j] == '?')
                a[j] = 'd';
        }
        if(c==0 || c>1)
            cout<<"No";
        else
        {
            cout<<"Yes\n";
            for(j=0;j<n;j++)
                cout<<a[j];
        }
        cout<<"\n";    
        t--;
    }
    return 0;
}