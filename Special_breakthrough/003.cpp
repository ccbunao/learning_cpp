#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int countOnes(int x){
        int ones;
        while(x > 0){
            x &= (x-1);
            ones++;
        }
        return ones;
    }
    vector<int> countBits(int n){
        vector<int> bits( n + 1);
        for(int i = 0; i<=n;i++){
            bits[i] = countOnes(i);
        }
        return bits;
    }
};