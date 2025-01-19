class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        haystack_length, needle_length = len(haystack), len(needle)
        last_possible_index = haystack_length - needle_length

        for index in range (0, last_possible_index + 1):
            if haystack[index: index + needle_length] == needle:
                return index
        return -1