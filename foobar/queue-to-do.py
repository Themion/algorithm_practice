def xor_1_to_n(n):
    if n < 0: return 0
    return {0: n, 1: 1, 2: n + 1, 3: 0}[n % 4]

def solution(start, length):
    ans = 0
    add = length

    while add > 0:
        ans = ans ^ xor_1_to_n(start + add - 1) ^ xor_1_to_n(start - 1)
        start += length
        add -= 1


    return ans