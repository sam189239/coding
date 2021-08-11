#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int** rotate(int **a, int n){
    
    return 0;
}

void print_matrix(int a[][3], int n){
    int i = n;
    i--;n--;
    while(i>0){
        while(n>0){
            cout<<a[i][n]<<"\t";
            n--;
        }
        i--;
        cout<<"\n";
    }
}

int main(){
    cout<<"Hello World";
    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    print_matrix(a,3);
    return 0;
}