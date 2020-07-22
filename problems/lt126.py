import queue
import itertools

class Solution(object):
    def findLadders(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: List[List[str]]
        """
        parent = {}
        def append_to_parent(p, child):
            if child not in parent:
                parent[child] = [p]
            else:
                parent[child].append(p)

        q = queue.Queue()
        q.put([beginWord])
        no_visit = set(wordList)
        if beginWord in no_visit:
            no_visit.remove(beginWord)

        saw_end = False
        while not q.empty():
            layer = q.get()
            next_layer = set()
            for i in layer:
                for k in range(len(i)):
                    for c in 'abcdefghijklmnopqrstuvwxyz':
                        neww = i[:k]+c+i[k+1:]
                        if neww in no_visit:
                            next_layer.add(neww)
                            append_to_parent(i, neww)
                            if neww == endWord:
                                saw_end = True
            if saw_end:
                break
            if next_layer:
                q.put(next_layer)
            for i in next_layer:
                no_visit.remove(i)

        if not saw_end:
            return []
        def make_path(root):
            if root == beginWord:
                return [[beginWord]]
            pathes = list(itertools.chain(*[make_path(p) for p in parent[root]]))
            for p in pathes:
                p.append(root)
            return pathes
        return make_path(endWord)

print(ret)
