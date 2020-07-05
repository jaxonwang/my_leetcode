class Solution:

    def minWindow(self, s: str, t: str) -> str:
        i, j=0,0
        occur = {}
        chars = {}
        for c in t:
            if c not in chars:
                chars[c] = 1
            else:
                chars[c] += 1
        def add_to_occur(c):
            if c in occur:
                occur[c] +=1
            else:
                occur[c] = 1
        def rm_from_occur(c):
            if occur[c] == 1:
                del occur[c]
            else:
                occur[c] -= 1

        task = chars.copy()
        while i<len(s):
            if not task:
                break
            if s[i] in chars:
                if s[i] in task:
                    if task[s[i]] > 1:
                        task[s[i]] -= 1
                    else:
                        del task[s[i]]
                add_to_occur(s[i])
            i += 1
        if task:
            return ""
        min_i = i
        min_j = j
        while i < len(s):
            while True:
                if s[j] in chars:
                    if occur[s[j]] == chars[s[j]]:
                        break;
                    else:
                        rm_from_occur(s[j])
                j+=1
            if i-j < min_i - min_j:
                min_i, min_j = i, j
            if s[i] in chars:
                add_to_occur(s[i])
            i += 1
        while j<len(s):
            if s[j] in chars:
                if occur[s[j]] == chars[s[j]]:
                    break;
                else:
                    rm_from_occur(s[j])
            j+=1
        if i-j < min_i - min_j:
            min_i, min_j = i, j
        return s[min_j:min_i]

# print(Solution().minWindow("ADOBECODEBANC", "ABC"))
print(Solution().minWindow("AB", "A"))

