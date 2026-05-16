using pii = pair<int, int>;

const int alph = 64;

class Solution {
public:

    bool hasEnough(vector<int>& f, vector<int>& s) // f has enough for s
    {
        for (int i = 0; i < alph; i++)
            if (f[i] < s[i])
                return 0;
        return 1;
    }

    void copy(vector<int>& from, vector<int>& to)
    {
        for (int i =0; i < alph; i++)
            to[i] = from[i];
    }

    vector<int> diff(vector<int>& l, vector<int>& r)
    {
        vector<int> ans(alph,0);
        for (int i = 0; i < alph; i++)
            ans[i] = r[i] - l[i];
        return ans;
    }

    string minWindow(string s, string t) {
        
        cout << " reached here " << endl;
        s = '0' + s;
        cout << " reached here " << endl;
        int n = s.length();
        vector<vector<int>> cnt(n, vector<int>(alph,0));
        vector<int> tCount(alph,0);
        for (int i = 0; i < t.length(); i++)
        {
            int chr = t[i] - 'A';
            tCount[chr]++;
        }
        
        for (int i = 1; i < n ; i++)
        {
            int chr = s[i] - 'A';
            copy(cnt[i-1], cnt[i]);
            cnt[i][chr]++;
        }
        int l = 0, r = 1;
        
        vector<pii> subStrs;

        // (l,r]
        while (l <= r && r < n)
        {
            if (l == r){
                r++;
                continue;
            }
            auto d = diff(cnt[l], cnt[r]);
            if (hasEnough(d, tCount))
            {
                subStrs.push_back({l,r});
                l++;
            }
            else {
                r++;
            }
        }

        int minDiff = 100000;
        int ml = 0, mr = 0;
        for (auto [l, r]: subStrs)
        {
            cout << l << " : " << r << endl;
            int len = r - l;
            if (len < minDiff)
            {
                minDiff = len;
                ml = l;
                mr = r;
            }
        }

        string ans = s.substr(ml + 1, mr - ml);
        return ans;
    }
};
