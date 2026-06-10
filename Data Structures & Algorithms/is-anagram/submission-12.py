class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        letters = [0] * 26
        for i in range(0, len(s), 1):
            letters[ord(s[i]) - ord('a')] += 1
            letters[ord(t[i]) - ord('a')] -= 1

        for i in letters:
            if i != 0:
                return False
        
        return True