import string
import pprint
class Solution(object):
    def solveSudoku(self, board, level=0):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        print level
        queue = []
        for x, l in enumerate(board):
            for y, s in enumerate(l):
                if board[x][y] == '.':
                    board[x][y] = string.digits[1:]
                elif len(board[x][y]) == 1:
                    queue.append((x, y))
        def remove_and_update(x, y, value):
            if board[x][y] == value:
                raise Exception()
            if len(board[x][y]) != 1:
                n_v = "".join(board[x][y].split(value))
                board[x][y] = n_v
                if len(n_v) == 1:
                    queue.append((x, y))

        while queue:
            x, y = queue.pop()
            value = board[x][y]
            [remove_and_update(i, y, value) for i in range(9) if i != x]
            [remove_and_update(x, j, value) for j in range(9) if j != y]
            start_x = x//3*3
            start_y = y//3*3
            for i in range(start_x, start_x+3):
                for j in range(start_y, start_y+3):
                    if not (i == x and j == y):
                        remove_and_update(i,j, value)
        def rcopy(l):
            new = []
            for i in l:
                new.append(i[:])
            return new
        def itemcopy(a, b):
            for i in range(9):
                for j in range(9):
                    a[i][j] = b[i][j]

        for x, l in enumerate(board):
            for y, s in enumerate(l):
                if len(s) == 2:
                    b1 = rcopy(board)
                    b1[x][y] = s[0]
                    board[x][y] = s[1]
                    try:
                        self.solveSudoku(b1, level+1)
                        itemcopy(board, b1)
                    except Exception:
                        self.solveSudoku(board, level+1)
                    break
        return board

# test = [[".",".",".","8",".","1",".",".","."],
#         [".",".",".",".",".",".","4","3","."],
#         ["5",".",".",".",".",".",".",".","."],
#         [".",".",".",".","7",".","8",".","."],
#         [".",".",".",".",".",".","1",".","."],
#         [".","2",".",".","3",".",".",".","."],
#         ["6",".",".",".",".",".",".","7","5"],
#         [".",".","3","4",".",".","2",".","."],
#         [".",".",".","2",".",".","6",".","."]]
test = [[".",".",".",".","6",".","7",".","."],
        [".",".",".","4","3",".",".",".","."],
        ["8",".","5",".",".",".",".",".","."],
        [".","4",".","1",".",".",".",".","."],
        [".",".",".",".",".",".",".","2","8"],
        [".",".",".",".",".",".",".","5","."],
        ["7","3",".",".",".",".","6",".","."],
        [".",".",".","5",".","2",".",".","."],
        [".",".",".",".",".",".","1",".","."]]
# test = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
# test = [[".",".","9","7","4","8",".",".","."],["7",".",".",".",".",".",".",".","."],[".","2",".","1",".","9",".",".","."],[".",".","7",".",".",".","2","4","."],[".","6","4",".","1",".","5","9","."],[".","9","8",".",".",".","3",".","."],[".",".",".","8",".","3",".","2","."],[".",".",".",".",".",".",".",".","6"],[".",".",".","2","7","5","9",".","."]]
pprint.pprint(Solution().solveSudoku(test))




