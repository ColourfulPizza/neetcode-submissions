#include <cstring>

const int MAXN = 1e5 + 10;
class Solution {
public:

    int bit[MAXN];

    void update(int i, int val) {
        for (; i < MAXN; i += i & (-i))
            bit[i] = max(bit[i], val);
    }

    int query(int i) {
        int res = 0;
        for (; i > 0; i -= i & (-i))
            res = max(res, bit[i]);
        return res;
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector< pair<int,int> > env;
        memset(bit, 0, sizeof(bit));
        int n = envelopes.size();
        for (auto t: envelopes)
        {
            pair<int,int> x = {t[0], t[1]};
            env.push_back(x);
        }

        sort(env.begin(), env.end());

        for (int i = 0; i < n; i++)
            cout << env[i].first << " : " << env[i].second << endl;
        
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int x = env[i].first;
            vector<pair<int,int>> st;
            while ((i < n) && (env[i].first == x))
            {
                int y = env[i].second;
                int l = query(y - 1) + 1;
                ans = max(ans, l);
                st.push_back({y,l});
                i++;
            }
            
            while (!st.empty())
            {
                auto x = st.back();
                st.pop_back();
                update(x.first,x.second);
            }
            i--;
        }

        return ans;
    }
};





