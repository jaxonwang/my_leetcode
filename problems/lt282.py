import itertools
import pprint

import re

class Solution(object):
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """

        al = []

        def good(s):
            for i, v in enumerate(s):
                if not v.isdigit():
                    continue
                if i < len(s) -1 and v == '0' and s[i+1].isdigit():
                    return False
            return True
        for i in range(4 ** (len(num) - 1)):
            tmp = i
            l = [num[0]]
            flag = 0;
            fail = 0
            for j in num[1:]:
                if tmp % 4 == 0:
                    l.append("+")
                if tmp % 4 == 1:
                    l.append("-")
                if tmp % 4 == 2:
                    l.append("*")
                l.append(j)
                tmp //= 4
            exp = "".join(l)
            if not good(exp):
                continue
            if eval(exp) == target:
                al.append(exp)
        return al

class Solution1:

    def addOperators(self, num, target):
        res, self.target = [], target
        for i in range(1,len(num)+1):
            if i == 1 or (i > 1 and num[0] != "0"): # prevent "00*" as a number
                self.dfs(num[i:], num[:i], int(num[:i]), int(num[:i]), res) # this step put first number in the string
        return res

    def dfs(self, num, temp, cur, last, res):
        if not num:
            if cur == self.target:
                res.append(temp)
            return
        for i in range(1, len(num)+1):
            val = num[:i]
            if i == 1 or (i > 1 and num[0] != "0"): # prevent "00*" as a number
                self.dfs(num[i:], temp + "+" + val, cur+int(val), int(val), res)
                self.dfs(num[i:], temp + "-" + val, cur-int(val), -int(val), res)
                self.dfs(num[i:], temp + "*" + val, cur-last+last*int(val), last*int(val), res)

ret1 = Solution1().addOperators("123456789", 45)
print(ret1)


