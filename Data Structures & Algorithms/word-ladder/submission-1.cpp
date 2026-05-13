class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        int beginId = -1;
        bool add = true;
        bool foundEnd = false;
        int endId = -1;
        for (int i = 0; i < wordList.size(); i++)
        {
            string s = wordList[i];
            if (s == beginWord)
            {
                add = false;
                beginId = i;
            }
            if (s == endWord){
                foundEnd = true;
                endId = i;
            }
        }

        if (!foundEnd)
        {
            return 0;
        }

        if (add)
        {
            beginId = wordList.size();
            wordList.push_back(beginWord);
        }
        int n = wordList.size();
        int len = wordList[0].size();
        vector<vector<int>> edges(n, vector<int>(n,0));
        for (int i = 0; i < n; i++)
            for (int j = i+1;j < n; j++)
            {
                int diff = 0;
                for (int k = 0; k < len; k++)
                    if (wordList[i][k] != wordList[j][k])
                        diff++;
                if (diff == 1){
                    edges[i][j] = edges[j][i] = 1;
                    cout << i << "-" << j << endl;
                }
            }
        
        queue<int> q;
        q.push(beginId);
        vector<bool> seen(n,false);
        vector<int> dist(n,-1);
        dist[beginId] = 0;
        seen[beginId] = true;
        while (!q.empty())
        {
            int first = q.front(); q.pop();
            for (int v = 0; v < n; v++)
            {
                if (seen[v]) continue;
                if (edges[first][v] != 1)   continue;
                seen[v] = true;
                q.push(v);
                dist[v] = dist[first] + 1;
            }
        }
        cout << endId << endl;
        return dist[endId] + 1;
    }
};
