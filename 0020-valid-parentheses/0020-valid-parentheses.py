class Solution:
    # my solution:
    # def isValid(self, s: str) -> bool:
    #     if (len(s))%2 != 0:return False
    #     stk = deque()
    #     closed = [')', ']', '}']
    #     mp = {
    #         '(': ')', 
    #         '[': ']',
    #         '{': '}',
    #     }
    #     for ch in s:
    #         if ch in closed:
    #             if len(stk)>0:
    #                 x = stk[-1]
    #                 stk.pop()
    #                 if mp[x] != ch:
    #                     return False
    #             else:
    #                 #no open brackets in stk and closing bracket came
    #                 return False
    #         else:
    #             stk.append(ch)
    #     if len(stk) != 0: 
    #         return False #open brackets remaining
    #     return True

    # cleaner:
    def isValid(self, s: str) -> bool:
        stack = []
        mapping = {')': '(', ']': '[', '}': '{'}
        for char in s:
            if char in mapping:
                if not stack or stack.pop() != mapping[char]:
                    return False
            else:
                stack.append(char)
        return not stack