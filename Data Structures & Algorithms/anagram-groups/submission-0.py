class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        sorted_strs = []
        for s in strs:
            new_s = "".join(sorted(s))
            sorted_strs.append(new_s)

        seen = set()
        sz = len(strs)

        res = []
        for ind, s in enumerate(sorted_strs):
            if ind in seen:
                continue
                
            sub_list = [ind]
            for j in range(ind + 1, sz):
                if s == sorted_strs[j]:
                    sub_list.append(j)
                    seen.add(j)
            res.append(sub_list)
        
        for sub in res:
            for i in range(len(sub)):
                sub[i] = strs[sub[i]]
        return res
