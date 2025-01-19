class Solution {
public:
    int strStr(string haystack, string needle) {
        const int haystackLength = haystack.size();
        const int needleLength = needle.size();

        for(int i = 0; i <= haystackLength - needleLength; ++i)
        {
            if(haystack.substr(i, needleLength) == needle)
                return i;
        }
        return -1;
    }
};
