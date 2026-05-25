class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<bool> reach(n);

        int mx = 0;
        reach[0] = 1;
        for (int i = 0; i < n; i++)
        {
            if (!reach[i]) continue;
            for (int j = mx - i + 1; j <= nums[i] && i + j < n; j++)
            {
                reach[i + j] = 1;
            }
            mx = max(mx, i + nums[i]);
        }

        return reach[n - 1];
    }
};
