dots = 0; line = 2; up = 1
for i in range(int(input())):
    line += up
    up += up
for j in range(line+1):
    dots += j
dots = (dots*2)-line 
print(dots)