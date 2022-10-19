from xml.dom.minicompat import EmptyNodeList


class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        more = True 
        for x in range(0,len(s)):
            if s[x] == '(' or s[x]=='[' or s[x]== '{':
                stack.append(s[x])
            elif len(stack)>0:
                curr = stack.pop()
                if s[x]==')' and curr!='(':
                    more = False
                    break
                elif s[x]==']' and curr!='[':
                    more = False
                    break
                elif s[x]=='}' and curr!='{':
                    more = False
                    break
            else:
                more = False
                break

        if more and len(stack) == 0:
            return True
        else:
            return False