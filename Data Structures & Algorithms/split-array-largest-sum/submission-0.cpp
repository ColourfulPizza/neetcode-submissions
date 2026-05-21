class Solution {
public:
    bool solve(vector<int>& nums, int mx, int k)
    {
        int cnt = 1;

        int curSum = 0;
        for (auto n: nums)
        {
            if (n > mx)
                return false;
            if (curSum + n > mx)
            {
                curSum = 0;
                cnt++;
            }
            curSum += n;
        }

        return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        long long totalSum = 0;
        for (auto n: nums)
            totalSum += n;

        int l = -1, r = totalSum;


        while (r - l > 1)
        {
            int m = (l+r)/2;
            bool a = solve(nums, m, k);
            if (a)
            {
                r = m;
            } else
            {
                l = m;
            }
        }


        return r;
    }
};