#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int divide(int a, int b){
        // 被除数为最小值的
        if(a == INT_MIN){
            if(b == 1){
                return INT_MIN;
            }
            if(b == -1){
                return INT_MAX;
            }
        }
        // 除数为最小值
        if(b == INT_MIN){
            return a == INT_MIN ? 1 : 0;
        }
        // 被除数为0
        if(a == 0){
            return 0;
        }
        // 一般情况下，使用二分查找
        bool rev = false;
        if( a > 0 ){
            a = -a;
            rev = !rev;
        }
        if( b > 0 ){
            b = -b;
            rev = !rev;
        }

        // 快速乘
        auto quickAdd = [](int y, int z, int x){
            // x 、y是负数，z是整数
            // 需要判断 z*y>=x是否成立
            int result = 0 , add = y;
            while(z){
                if(z & 1){
                    // 需要保证result + add >= x;
                    if (result < x - add ){
                        return false;
                    }
                    result += add;
                }
                if(z != 1){
                    // 需要保证 add + add >= x;
                    if(add < x - add){
                        return false;
                    }
                    add += add;
                }
                // 不用除法
                z >>= 1;
            }
            return true;
        };

        int left = 1, right = INT_MAX, ans = 0;
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            bool check = quickAdd(b, mid, a);
            if(check){
                ans = mid;
                if(mid == INT_MAX){
                    break;
                }
                left = mid + 1;
            }else{
                right = mid -1;
            }
        }
        return rev ? -ans : ans;
    }
};