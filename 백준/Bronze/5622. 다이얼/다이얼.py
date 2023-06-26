dial = [
    [],
    [],
    [],
    ["A", "B", "C"],
    ["D", "E", "F"],
    ["G", "H", "I"],
    ["J", "K", "L"],
    ["M", "N", "O"],
    ["P", "Q", "R", "S"],
    ["T", "U", "V"],
    ["W", "X", "Y", "Z"],
]
w = input()
time = 0
for i in range(len(w)):
    for j in dial:
        for k in range(len(j)):
            if j[k] == w[i]:
                time += dial.index(j)
print(time)