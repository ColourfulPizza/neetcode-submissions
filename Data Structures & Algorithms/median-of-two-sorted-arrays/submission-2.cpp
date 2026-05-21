class Solution {
public:

    double findIndex(vector<int>& n1, vector<int>& n2, int wantedIndex)
    {
        if (n1.empty()) return n2[wantedIndex];
        if (n2.empty()) return n1[wantedIndex];
        int l = 0;
        int r = n1.size();
        while (r - l > 1)
        {
            int m1 = (r + l)/2;
            int m2 = wantedIndex - m1;
            if (m2 < 0 || n2[m2] < n1[m1])
                r = m1;
            else
                l = m1;
        }
        int m2 = wantedIndex - l;
        if (m2 >= 0 && m2 < n2.size() && n1[l] <= n2[m2] && ( m2 == 0 || n1[l] >= n2[m2 - 1]))
        {
            return n1[l];
        }
        if (m2 == n2.size() && n1[l] >= n2[m2 - 1])
        {
            return n1[l];
        }
        return findIndex(n2,n1,wantedIndex);
    }
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
        int total = (n1.size() + n2.size());
        if (total & (1 << 0))
        {
            int ind = total/2;
            return findIndex(n1,n2,ind);
        }
        int ind = total/2;
        return (findIndex(n1,n2,ind - 1) + findIndex(n1,n2,ind))/2.0;
    }
};
