#include <bits/stdc++.h>

int check(char a, string c)
{
    int n = c.length();
    for(int i = 0; i<(n-2); i++)
    {
        if(c[i] == a)
        {
            if(c[i+1]==a)
            {
                if(c[i+2]==a)
                {  
                    return i+1;
                }
            }
        }
    } 
    return -1;
}
string gameWinner(string colors) {
    int n = colors.length(), index;
    string winner = "";
    while(n!=0)
    {
        index = check('w', colors);
        if(index == -1)
            return "bob";
        else {
        colors.erase(index); n--;
        }
        index = check('b', colors);
        if(index == -1)
            return "wendy";
        else {
        colors.erase(index); n--;
        }
    }
    return colors;
}