#!/usr/bin/python3
# this is a algorithm computes number of way to cover a m_len * n_len rectangle
# by arbitrary smaller rectagle

m_len = 4
n_len = 3
valid = []
for i in range(m_len * n_len):
    valid.append([1])
    if i % n_len != 0:
        valid[i].append(2)
    if i >= n_len:
        valid[i].append(3)
    if i >= n_len and i % n_len != 0:
        valid[i].append(4)


def visual_print(arr):
    p_matrix = []
    for i in range(m_len * 2 + 1):
        p_matrix.append([0]*(2*n_len +1))

    for i, v in enumerate(arr):
        x , y = i // n_len * 2+ 1, i % n_len * 2+ 1
        p_matrix[x - 1][y] = 1 - (v - 1) // 2
        p_matrix[x][y - 1] = 1 - (v - 1) % 2
        p_matrix[x + 1][y] = 1
        p_matrix[x][y + 1] = 1

    for i in range(2 * m_len + 1):
        for j in range(2 * n_len + 1):
            if i % 2 == 0 and j % 2 == 0:
                p_matrix[i][j] = "+"
            elif i % 2 == 0 and j % 2 == 1:
                p_matrix[i][j] = "-" if p_matrix[i][j] else " "
            elif i % 2 == 1 and j % 2 == 0:
                p_matrix[i][j] = "|" if p_matrix[i][j] else " "
            else:
                p_matrix[i][j] = " "

    for i in range(2 * m_len + 1):
        for j in range(2 * n_len + 1):
            if j %2 == 1:
                print(p_matrix[i][j]*3, end="")
            print(p_matrix[i][j], end="")
        print()

def leagal(pos, left, up, value):
    if value == 1 and  up in [2, 4] and left in [3 ,4]:
        return False;
    if value == 2 and left in [4 ,3]:
        return False;
    if value == 3 and  up in [4, 2]:
        return False;
    if value == 4:
        if up == 4 and left ==4:
            return True
        elif up == 2 and pos < n_len * 2 and left != 1 and left!=2:
            return True
        elif left ==3 and (pos-1) % n_len == 0 and up != 3 and up!= 1:
            return True
        return False
    return True

def dfs(pos, arr):
    if pos == m_len * n_len:
        # visual_print(arr)
        return 1
    count = 0
    for i in range(1, 5):
        if i not in valid[pos]:
            continue
        if pos >= n_len and pos % n_len != 0:
            left = arr[pos - 1]
            up = arr[pos - n_len]
            if not leagal(pos, left ,up, i):
                continue
        newarr = arr[:]
        newarr[pos] = i
        count += dfs(pos + 1, newarr)
    return count

arr = [0] * m_len * n_len
arr[0] = 1
print(dfs(1, arr))

def print_arr(arr):
    for i in range(m_len):
        for j in range(n_len) :
            print(arr[i*n_len+j], end=" ")
        print()
    print()

