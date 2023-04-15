#include<bits/stdc++.h>
using namespace std;

const int maxN = 10000;
int a[maxN];
int dp[maxN], start[maxN];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n; i++ ){
        scanf("%d", &a[i]);
    }
    
    dp[0] = a[0];
    start[0] = 0;
    for(int i = 1; i < n ; i++){
        if(dp[i - 1] >= 0){
            dp[i] = dp[i - 1] + a[i];
            start[i] = start[i-1];
        }else{
            dp[i] = a[i];
            start[i] = i;
        }
    }
    int k = 0;
    for(int i = 1; i < n ;i ++){
        if(dp[i] > dp[k]){
            k = i;
        }
     }
     printf("%d %d %d", dp[k], start[k] + 1, k + 1);
     return 0;
}