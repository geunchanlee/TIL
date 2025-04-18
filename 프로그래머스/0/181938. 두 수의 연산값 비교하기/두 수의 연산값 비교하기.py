def solution(a, b):
    t = int(str(a) + str(b))
    return t if t >= (2*a*b) else (2*a*b)