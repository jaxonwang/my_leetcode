from typing import List

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:

        first = newInterval[0]
        second = newInterval[1]

        overlaps = []
        nooverlaps = []

        for i in intervals:
            if i[0] >= first and i[0] <= second or i[1] >= first and i[1] <= second:
                overlaps.append(i)
            elif i[0] < first and i[1] > second:
                overlaps.append(i)
            else:
                nooverlaps.append(i)

        # print(overlaps)
        # print(nooverlaps)
        overlaps.append(newInterval)
        minleft = 10e7
        maxright = 0
        for i in overlaps:
            if i[0] < minleft:
                minleft = i[0]
            if i[1] > maxright:
                maxright = i[1]

        nooverlaps.append([minleft, maxright])

        nooverlaps.sort(key=lambda x:x[0])

        return nooverlaps

data = [[[1,5]], [2,3]]
ret=Solution().insert(*data)
print(ret)





