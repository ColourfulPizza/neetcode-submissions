class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        m--;n--;

        if (n < m) swap(m,n);

        cout << n << " :" << m << endl;
        vector<bool> div(m, false);
        div[1] = true;
        div[0] = true;
        for (int i = m+n; i > n; i--)
        {
            ans *= i;
            for (int j = 2; j <= m; j++)
                if (!div[j] && (ans % j == 0)){
                    ans /= j;
                    div[j] = true;
                }
        }


        return ans;
    }
};
