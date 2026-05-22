#include <cstring>

class Solution {
public:

    int trie[3000][26]{};
    bool terminal[3000]{};
    int cntID = 0;
    void insert(string s)
    {
        int terminalID = 0;
        for (char c: s)
        {
            int k = c - 'a';
            if (!trie[terminalID][k])
                trie[terminalID][k] = cntID++;
            terminalID = trie[terminalID][k];
        }

        terminal[terminalID] = true;

    }
    int minExtraChar(string s, vector<string>& dictionary) {
        cntID = 1;
        memset(trie, 0, sizeof(trie));
        memset(terminal, 0, sizeof(terminal));

        for (string s: dictionary)
        {
            insert(s);
        }

        int sz = s.size();
        vector<int> dp(sz + 1, 0);
        for (int i = sz - 1; i >= 0; i--){
            cout << " starting " << i << endl;
            dp[i] = dp[i + 1] + 1;
            int node = 0; // current root
            for (int j = i; j < sz; j++)
            {
                int c = s[j] - 'a';
                if (!trie[node][c]) break;
                node = trie[node][c];
                if (terminal[node])
                    dp[i] = min(dp[i], dp[j+1]);
            }

            cout << dp[i] << endl;
        }

        return dp[0];
    }
};