class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:

        diff = len(s2) - len(s1)
        s1 = "".join(sorted(s1))
        l1 = len(s1)
        if diff < 0:
            return False

        for i in range(diff + 1):
            subs = s2[i:i + l1]
            
            subs = "".join(sorted(subs))
            print(subs)
            if subs == s1:
                return True
        return False