#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000;
int a[maxn], dp[maxn], pre[maxn];
int n;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    memset(pre, -1, sizeof(pre));

    int k, maxlen = 0;
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i;j++){
            if(a[j] <= a[i] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }
        }
        if(dp[i] > maxlen){
            maxlen = dp[i];
            k = i;
        }
        maxlen = max(maxlen, dp[i]);
    }

    vector<int> maxlenque;
    while(k != -1){
        maxlenque.push_back(a[k]);
        k = pre[k];
    }
    reverse(maxlenque.begin(), maxlenque.end());
    printf("%d\n", maxlen);
    for(int i = 0; i<maxlenque.size(); i++){
        printf("%d", maxlenque[i]);
        if(i < (int)maxlenque.size() - 1){
            printf(" ");
        }
    }
    return 0;
}