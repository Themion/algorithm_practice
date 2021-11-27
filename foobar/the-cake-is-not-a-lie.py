def solution(s):
    length = len(s)
    
    for size in range(1, length + 1):
        if length % size != 0: continue
        array = []
        idx = 0
        cnt = 0
        
        while (idx < length):
            array.append(s[idx:idx + size])
            idx += size
            
        for text in array:
            if text == array[0]: cnt += 1
            
        if cnt == len(array):
            return cnt

    return 1