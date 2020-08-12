import queue

class Node:
    def __init__(self):
        self.next_nodes = {}
        self.is_term = False
        self.fail = None

    def __str__(self):
        return str(id(self))+" next: " + ",".join(self.next_nodes.keys()) + " " + str(self.is_term) + " " + str(id(self.fail))

def build_tire(dictionary):
    node_start = Node()

    for s in dictionary:
        n = node_start
        for c in s:
            if c not in n.next_nodes:
                n.next_nodes[c] = Node()
            n = n.next_nodes[c]
        n.is_term = True

    q = queue.Queue()
    q.put(node_start)
    while not q.empty():
        n = q.get()
        for _next in n.next_nodes:
            fail_n = n.fail
            while fail_n and _next not in fail_n.next_nodes:
                fail_n = fail_n.fail
            if not fail_n:
                n.next_nodes[_next].fail = node_start
            else:
                n.next_nodes[_next].fail = fail_n.next_nodes[_next]
            q.put(n.next_nodes[_next])
    return node_start

def next_state(c, state):
    tmp = state
    while tmp:
        if c in tmp.next_nodes:
            return tmp.next_nodes[c]
        tmp = tmp.fail
    return tmp

def match(string, dictionary):
    start = build_tire(dictionary)
    match_pos = []
    s = start
    for i, c in enumerate(string):
        s = next_state(c, s) or  start
        if s.is_term:
            match_pos.append(i)

    return match_pos

string = "abcdefghijk"
dictionary = ["abc", "cde", "hi", "ghijk"]
ret = match(string, dictionary)
print(ret)

