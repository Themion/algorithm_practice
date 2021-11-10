def coord(pos):
    return (int(pos / 8), int(pos % 8))

def is_valid(y, x):
    return y >= 0 and y < 8 and x >= 0 and x < 8

def solution(src, dest):
    board = [[-1 for _ in range(8)] for _ in range(8)]
    add = [ (-2, -1), 
            (-1, -2), 
            (1, -2), 
            (2, -1), 
            (2, 1), 
            (1, 2), 
            (-1, 2), 
            (-2, 1)]

    q = [coord(src)]
    dest = coord(dest)
    move = 1

    board[q[0][0]][q[0][1]] = 0

    while board[dest[0]][dest[1]] == -1:
        length = len(q)
        
        for _ in range(length):
            pos = q.pop(0)

            for a in add:
                pos_ = (pos[0] + a[0], pos[1] + a[1])
                if is_valid(pos_[0], pos_[1]) and board[pos_[0]][pos_[1]] == -1:
                    board[pos_[0]][pos_[1]] = move
                    q.append(pos_)

        move += 1

    return board[dest[0]][dest[1]]