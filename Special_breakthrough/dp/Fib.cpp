#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[10001];
int F(int n){
    if(n == 0 || n == 1) return 1;  
    if(dp[n] != -1 ) return dp[n];
    else{
        dp[n] = (F(n-1) + F(n-2)) % 10007;
        return dp[n];
    }
}
int main(){

    memset(dp, -1, sizeof(dp));

    int n ;
    scanf("%d", &n);
    cout << F(n) << endl;
    return 0;
}
