#include<bits/stdc++.h>
using namespace std;
int dp[10001] = {0}, a[10000] = {0};
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0 ;i < n; i++){
        scanf("%d", &a[i]);
    }
    
    dp[0] = a[0];
    int m = -1;
    for(int i = 0 ;i < n ;i++){
        dp[i] = max(a[i],dp[i-1]+a[i]);
        m = m > dp[i] ? m :dp[i];
    }
    printf("%d", m);
    return 0;
}