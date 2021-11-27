def solution(M, F):
    M = int(M)
    F = int(F)

    global step
    step = 0

    if gcd(M, F) == 1: return str(step - 1)
    else: return 'impossible'

def gcd(a, b):
    global step
    if a < b : return gcd(b, a)
    elif b == 0: return a
    else: 
        step += int(a / b)
        return gcd(a % b, b)