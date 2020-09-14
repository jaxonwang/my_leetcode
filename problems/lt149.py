from typing import List

def isline(x1,y1,x2,y2,x3,y3):
    return (y1 - y2)*(y3-y2) == (x3-x2)*(x1-x2)

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        if len(points) <= 1:
            return len(points)

        points.sort(key=lambda x:x[0])
        # print(points)

        lineset = []
        for i, currentpoint in enumerate(points):
            candidate = set( (points[i][0], points[i][1]) for i in range(i))
            newlineset = []
            for k in range(i):
                pointk = points[k]
                if (pointk[0], pointk[1]) not in candidate:
                    continue
                connectexisting = False
                for s in lineset[k]:
                    otherp = None
                    for pointins in s: # find a point is not k
                        if pointins[0]== pointk[0] and pointins[1] == pointk[1]:
                            continue
                        otherp = pointins
                        break
                    if isline(otherp[0], otherp[1], pointk[0], pointk[1], currentpoint[0], currentpoint[1]):
                        connectexisting = True
                        for p_ in s: # remove all connecting lines
                            candidate.remove(p_)
                        s.add((currentpoint[0], currentpoint[1]))
                        newlineset.append(s)
                        break
                if not connectexisting:
                    newlineset.append(set([tuple(pointk), tuple(currentpoint)]))
            # print(newlineset)
            lineset.append(newlineset)

        maxlength = 0
        for ls in lineset:
            for s in ls:
                maxlength = max(maxlength, len(s))
        return maxlength



data = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]

ret = Solution().maxPoints(data)

print(ret)

