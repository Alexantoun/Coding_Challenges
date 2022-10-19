class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        score = 0
        strLength = len(s)
        startIndex = 0
        sbstring = set()
        while startIndex < strLength:
            sbstring.clear()
            currentIndex = startIndex
            currentScore = 0
            while currentIndex < strLength and not s[currentIndex] in sbstring:
                currentScore += 1
                sbstring.add(s[currentIndex])
                currentIndex += 1
            if score < currentScore:
                score = currentScore
            startIndex += 1   
            
        return score
            
            
        