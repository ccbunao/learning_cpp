#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int maxn = 10000;
char a[maxn],b[maxn];
int dp[maxn][maxn];
int main(){
    int n;
    gets(a + 1);
    gets(b + 1);

    int lena = strlen(a+1);
    int lenb = strlen(b+1);
    for(int i = 0 ;i <= lena ; i++){
        dp[i][0] = 0;
    }
    for(int j = 0; j <= lenb; j++){
        dp[0][j] = 0;
    }

    for(int i = 1; i <= lena; i++){
        for(int j = 1 ;j <= lenb; j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    printf("%d", dp[lena][lenb]);
    return 0;
}



