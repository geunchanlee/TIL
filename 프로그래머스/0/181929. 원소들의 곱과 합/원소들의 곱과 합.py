import math

def solution(num_list):
    mul = math.prod(num_list)
    sq = sum(num_list) ** 2
    return 1 if sq > mul else 0