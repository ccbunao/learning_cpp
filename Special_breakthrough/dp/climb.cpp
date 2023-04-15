#include<bits/stdc++.h>
using namespace std;
int climb(int n){
     if (n <= 2)
            return n;
        int num, prio_1 = 2, prio_2 = 1;
        for (int i = 3; i <= n; i++) {
            num = ( prio_1 + prio_2 ) % 10007;
            prio_2 = prio_1 % 10007 ;
            prio_1 = num % 10007;
        }
        return num;
}
int main(){
    int n = 0;
    scanf("%d", &n);
    cout<<climb(n);
}

