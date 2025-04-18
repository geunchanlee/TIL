def solution(a, b):
    a, b = str(a), str(b)
    return int(a+b) if int(a+b) >= int(b+a) else int(b+a)