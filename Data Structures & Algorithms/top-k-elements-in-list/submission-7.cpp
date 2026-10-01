class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector< pair<int, int> > freq;


        int cnt = 1;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1]){
                freq.push_back({cnt, nums[i-1]});
                cnt = 1;
            }
            else
                cnt++;
        }
        freq.push_back({cnt, nums[n-1]});
        sort(freq.begin(),freq.end());
        reverse(freq.begin(), freq.end());

        vector<int> res;
        for (int i = 0; i < min(k, int(freq.size())); i++)
        {
            res.push_back(freq[i].second);
        }

        return res;
    }
};
