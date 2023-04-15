# Y式DP分析法

![image-20230412222359277](D:\zwc\c++\Brush_Algorithm\Special_breakthrough\dp\img\1.png)







# 动态规划

动态规划是将一个 复杂问题分解成若干子问题，通过综合子问题的最优解得到原问题的最优解。动态规划会将每个求解过的子问题的捷记录下来，这样当下一次碰到同样的子问题时，既可以直接使用之前记录的结果，而不是重复计算。

## 递归计算

斐波那契数列的求解。

```cpp
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[10001];
int F(int n){
    if(n == 0 || n == 1) return 1;  
    if(dp[n] != -1 ) return dp[n];
    else{
        dp[n] = F(n-1) + F(n-2);
        return dp[n];
    }
}
int main(){

    memset(dp, -1, sizeof(dp));

    int n = 5;
    cout << F(n) << endl;
    return 0;
}
```

## 递推算法

使用递推算法的计算方式是自底向上，从边界开始，不断向上解决问题，直接解决了目标问题。

```c++
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1000;
int dp[maxn][maxn], f[maxn][maxn];
int main(){
    int n ;
    scanf("%d",&n);
    for(int i = 1;i <= n; i++){
        for(int j = 1 ; j <= i; j++){
            scanf("%d", &f[i][j]);
        }
    }
    //边界
    for(int j = 1; j<= n; j++){
        dp[n][j] = f[n][j]; 
    }

    // 从n-1层不断往上计算
    for(int i = n-1 ; i >= 1; i--){
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + f[i][j];
        }
    }

    printf("%d\n", dp[1][1]);
    return 0;
}
```

- 分治与动态规划

  分治和动归都是将问题分解为子问题不重叠，因此分治法解决的问题不拥有重叠子问题，而动态规划解决的问题拥有重叠子问题。

- 贪心与动态规划

  贪心和动归都要求原问题必须拥有最优子结构。二者的的区别在，贪心法采用的计算方式类似于上面介绍的自顶向上，但是并不等待子问题求解完毕后再选择使用哪一个，而是通过一种策略直接选择一个子问题解决，没被选择的子问题就不求解，直接抛弃。

## 最大连续子序和



```c++
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
```

状态的无后效性：当前状态记录了历史信息，一旦当前状态确定，就不会再改变，且未来的决策只能在已有的一个或若干状态的基础上机型，历史信息只能通过已有的状态去影响未来的决策。



## 最大连续子序和优化



```c++
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10000;
int a[MAXN];
int dp[MAXN], start[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    dp[0] = a[0];
    start[0] = 0;
    for (int i = 1; i < n; i++) {
        if (dp[i - 1] >= 0) {
            dp[i] = dp[i - 1] + a[i];
            start[i] = start[i - 1];
        } else {
            dp[i] = a[i];
            start[i] = i;
        }
    }
    int k = 0;
    for (int i = 1; i < n; i++) {
        if (dp[i] > dp[k]) {
            k = i;
        }
    }
    printf("%d %d %d", dp[k], start[k] + 1, k + 1);
    return 0;
}
```

## 最长不下降子序列



```c
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100;
int a[MAXN];
int dp[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] <= a[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    printf("%d", maxLen);
    return 0;
}
```

## 最长上升子序列的最优方案

```cpp
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
```

## 最长公共子序列



```c++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 1;
int dp[MAXN][MAXN];

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    printf("%d", dp[s1.length()][s2.length()]);
    return 0;
}
```



# 1359. 租用游艇

## 题目描述

长江游艇俱乐部在长江上设置了 $n$ 个游艇出租站 $1,2,\cdots,n$。游客可在这些游艇出租站租用游艇，并在下游的任何一个游艇出租站归还游艇。游艇出租站 $i$ 到游艇出租站 $j$ 之间的租金为 $r(i,j)$（$1\le i\lt j\le n$）。试设计一个算法，计算出从游艇出租站 $1$ 到游艇出租站 $n$ 所需的最少租金。

## 输入格式

第一行中有一个正整数 $n$，表示有 $n$ 个游艇出租站。接下来的 $n-1$ 行是一个半矩阵 $r(i,j)$（$1\le i<j\le n$）。

## 输出格式

输出计算出的从游艇出租站 $1$ 到游艇出租站 $n$ 所需的最少租金。

## 样例 #1

### 样例输入 #1

```
3
5 15
7
```

### 样例输出 #1

```
12
```

## 提示

$n\le 200$，保证计算过程中任何时刻数值都不超过 $10^6$。

## code

```c++
#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
int a[201][201],i,j,n,dp[201];
int main(){
    cin>>n;
    for(i = 1 ; i < n ;i++){
        for(j = i + 1 ; j <= n; j++){
            cin>>a[i][j];
        }
        dp[i] = INT_MAX;
    }

    for(i = n-1; i>=1; i--){
        for(j = i+1; j <= n; j++){
            dp[i] = min(dp[i], a[i][j]+dp[j]);
        }
    }
    cout<<dp[1];
    return 0;
}
```

# 1060.[NOIP2006 普及组] 开心的金明

## 题目描述

金明今天很开心，家里购置的新房就要领钥匙了，新房里有一间他自己专用的很宽敞的房间。更让他高兴的是，妈妈昨天对他说：“你的房间需要购买哪些物品，怎么布置，你说了算，只要不超过$N$元钱就行”。今天一早金明就开始做预算，但是他想买的东西太多了，肯定会超过妈妈限定的$N$元。于是，他把每件物品规定了一个重要度，分为$5$等：用整数$1-5$表示，第$5$等最重要。他还从因特网上查到了每件物品的价格（都是整数元）。他希望在不超过$N$元（可以等于$N$元）的前提下，使每件物品的价格与重要度的乘积的总和最大。

设第$j$件物品的价格为$v[j]$，重要度为$w[j]$，共选中了$k$件物品，编号依次为$j_1,j_2,…,j_k$，则所求的总和为：

$v[j_1] \times w[j_1]+v[j_2] \times w[j_2]+ …+v[j_k] \times w[j_k]$。

请你帮助金明设计一个满足要求的购物单。

## 输入格式

第一行，为$2$个正整数，用一个空格隔开：$n,m$（其中$N(<30000)$表示总钱数，$m(<25)$为希望购买物品的个数。）

从第$2$行到第$m+1$行，第$j$行给出了编号为$j-1$的物品的基本数据，每行有$2$个非负整数$ v p$（其中$v$表示该物品的价格$(v \le 10000)$，$p$表示该物品的重要度($1-5$)

## 输出格式

$1$个正整数，为不超过总钱数的物品的价格与重要度乘积的总和的最大值$(<100000000)$。

## 样例 #1

### 样例输入 #1

```
1000 5
800 2
400 5
300 5
400 3
200 2
```

### 样例输出 #1

```
3900
```

## 提示

NOIP 2006 普及组 第二题