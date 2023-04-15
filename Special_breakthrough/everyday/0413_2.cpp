#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int nums[n][2] = {0};
    int maxx = INT_MAX, minx = INT_MIN;
    for(int i = 0 ;i < n; i++){
        cin>>nums[i][0]>>nums[i][1];
        maxx = min(nums[i][0] / nums[i][1], maxx);
        minx = max(nums[i][0] / (nums[i][1] + 1) + 1, minx);
    }
    cout<< maxx <<' ' << minx<< endl;
    


    return 0;
}