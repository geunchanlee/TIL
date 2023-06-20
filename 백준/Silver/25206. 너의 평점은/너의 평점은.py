import sys

C = 0  # 이수한 학점
G = 0  # 과목 평점 * 학점
score = {
    "A+": 4.5,
    "A0": 4.0,
    "B+": 3.5,
    "B0": 3.0,
    "C+": 2.5,
    "C0": 2.0,
    "D+": 1.5,
    "D0": 1.0,
    "F": 0.0
}
for i in range(20):
    name, credit, grade = sys.stdin.readline().split()
    credit = float(credit)
    if grade != "P":
        C += credit
        G += score[grade] * credit
print(G/C)
