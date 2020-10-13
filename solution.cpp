#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <limits>
#include <utility> // pair
#include <tuple>
#include <algorithm>

/*
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.


*/

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        printf("input:\n");
        for (int i = 0 ; i < nums.size(); i++)
            printf("%d\t", nums[i]);
        printf("\n");

        int *dp = new int[nums.size()];
        dp[0] = nums[0];
        // if there are only two rooms, choose one
        dp[1] = std::max(nums[0],nums[1]);

        for(int i = 2; i < nums.size(); i++){
            printf("max((%d + %d), %d)\n",dp[i-2], nums[i], dp[i-1]);
            dp[i] = std::max(dp[i-2] + nums[i], dp[i-1]);
            printf("dp[%d]:%d\n", i, dp[i]);
        }
        return dp[nums.size()-1];
    }

};


int main(int argc, char *argv[]) {
    Solution *s = new Solution();
    std::vector<int> nums{ 1,2,5,6,3,10,1,2,1,1 };
    printf("output:%d\n", s -> rob(nums));
}
