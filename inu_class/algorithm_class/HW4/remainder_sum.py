# 나머지 합
# 힌트: 누적 합 구간에서 나머지가 같은것 끼리 빼면 나머지가 0이다
import sys

N, M = map(int, sys.stdin.readline().split())
numList = [int(_) for _ in sys.stdin.readline().split()]
remainderCnt = [0 for _ in range(M)]  # 누적 합의 나머지 리스트

sum = 0  # 누적 합
answer = 0  # 정답 저장 변수

for i in range(N):
    sum += numList[i]  # 누적 합 구하기
    remainderCnt[sum % M] += 1  # 누적 합에서 얻은 나머지를 나머지 리스트에 나머지 값 수 더함

answer += remainderCnt[0]  # remainderCnt[0]은 나머지가 이미 0인 구간 합의 수
for i in remainderCnt:
    if i == 0:
        continue

    answer += i * (i - 1) // 2  # i개중 2개를 뽑는 조합

print(answer)
