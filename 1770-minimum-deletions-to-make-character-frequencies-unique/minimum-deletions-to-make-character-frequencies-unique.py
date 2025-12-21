
class Solution:
    def minDeletions(self, s: str) -> int:
        freq= Counter(s)
        used=set()
        d=0
        for f in freq.values():
            while f>0 and f in used:
                f-=1
                d+=1
            if f>0:
                used.add(f)
        
        return d