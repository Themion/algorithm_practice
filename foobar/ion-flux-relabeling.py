def solution(h, q):
    global tree
    global idx_map
    global num

    tree = [0 for _ in range(2 ** h)]
    idx_map = [0 for _ in range(2 ** h)]
    num = 1
    ret = []

    search(1)
    tree[0] = -1

    for i in q:
        ret.append(tree[(int)(idx_map[i] / 2)])

    return ret

# idx번째 원소를 후위 순회
def search(idx):
    global tree
    global num

    if idx < len(tree):
        search(2 * idx)
        search(2 * idx + 1)

        tree[idx] = num
        idx_map[num] = idx
        num += 1