class Solution {
public:
    vector<int> get_prev(vector<int>& heights)
    {
        int n = heights.size();
        vector<int> res(n,0);
        stack<int> st;
        st.push(heights[0]);
        for (int i = 1; i < n; i++)
        {
            int h = heights[i];
            while (!st.empty() && h <= heights[st.top()])
            {
                st.pop();
            }
            if (!st.empty())
                res[i] = st.top();
            else
                res[i] = i;
            st.push(i);
        }

        return res;
    }
    int largestRectangleArea(vector<int>& oldHeights) {
        
        vector<int> heights;
        heights.push_back(0);
        for (auto x: oldHeights)
            heights.push_back(x);
        heights.push_back(0);

        int n = heights.size();
        
        auto left = get_prev(heights);
        reverse(heights.begin(), heights.end());
        auto right = get_prev(heights);

        reverse(heights.begin(), heights.end());
        reverse(right.begin(), right.end());

        for (int i = 0; i < n; i++)
        {
            right[i] = n - right[i] - 1;
        }

        for (int i = 0; i < n; i++)
        {
            left[i]++;
            right[i]--;
            cout << i << " -> " << left[i] << " " << right[i] << endl;
        }
        
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            long long cur = (right[i] - left[i] + 1) * heights[i];
            cout << i << " ->> " << cur << endl;
            res = max(res, cur);
        }

        return res;
    }
};
