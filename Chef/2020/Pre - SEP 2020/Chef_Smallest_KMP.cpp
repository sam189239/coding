#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        string s, p;
        cin>>s>>p;
        map<char,int> m;
        int i;
        for(i=0;i<str.len(s);i++)
        {
            m[s[i]]++;
        }
        string r = '';
        for(i=0;i<str.len(p);i++)
        {
            m[p[i]]-=1;
        }
        
        t--;
    }
    return 0;
}