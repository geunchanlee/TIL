def solution(a, b, c):
    answer = a + b + c
    if a != b != c != a:
        return answer
    answer *= (a**2+b**2+c**2)
    if a == b != c or a != b == c or a == c != b:
        return answer
    answer *= (a**3+b**3+c**3)
    return answer