#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int singleNumber(vector<int>& nums){
        unordered_map<int, int> count;
        for(int i : nums){
            count[i]++;
        }
        for(auto [k , v] : count){
            if( v == 1) return k;
        }
        return -1;
    }
};