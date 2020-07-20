class Solution(object):


    def solve(self, candidates, start, target):

        if target < 0:
            return []

        if start >= len(candidates):
            return []

        if target in self.tb[start]:
            return self.tb[start][target]

        ret0 = []
        if target == candidates[start]:
            ret0 = [[candidates[start]]]
        else:
            tmp = self.solve(candidates, start, target - candidates[start])
            ret0 = [[candidates[start]] + i for i in tmp]

        ret1 = self.solve(candidates, start + 1, target)

        ret = ret0 + ret1
        self.tb[start][target] = ret

        return ret


    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """

        self.tb= []
        for i in range(len(candidates)):
            self.tb.append({})

        return self.solve(candidates, 0, target)

print(Solution().combinationSum([2,3,5],8))
