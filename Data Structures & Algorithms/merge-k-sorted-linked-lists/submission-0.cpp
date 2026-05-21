/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

const int INF = -1e9;
class Solution {
public:

    int getMinIndex(vector<ListNode*>& lists)
    {
        int sz = lists.size();
        int curMin = -1;
        for (int i = 0; i < sz; i++)
        {
            if (lists[i] == nullptr)
                continue;
            if (curMin == -1)
                curMin = i;
            if (lists[curMin] -> val > lists[i] -> val)
                curMin = i;
        }
        if (curMin != -1 && lists[curMin] == nullptr)
        {
            while (true)
            {

            }
        }
        cout << curMin << endl;
        return curMin;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int sz = lists.size();

        if (sz == 0)
            return nullptr;
        
        int par = getMinIndex(lists);
        if (par == -1)
            return nullptr;

        cout << par << endl;
        ListNode* parPtr = lists[par];
        ListNode* first = parPtr;
        lists[par] = lists[par] -> next;
        while (true)
        {
            // get min
            int cur = getMinIndex(lists);
            if (cur == -1 || lists[cur] == nullptr)
                break;
            parPtr -> next = lists[cur];
            parPtr = lists[cur];
            par = cur;
            lists[cur] = lists[cur] -> next;
            // int par = getMinIndex(lists);
            // lists[par]
        }

        return first;
    }
};
