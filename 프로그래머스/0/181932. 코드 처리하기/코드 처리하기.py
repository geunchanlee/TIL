def solution(code):
    mode = False
    ret = ''
    for i in range(len(code)):
        if code[i] == '1':
            mode = not mode
            continue
        if mode == False and not i % 2:
            if i % 2 == 0:
                ret += code[i]
        elif mode == True and i % 2:
            ret += code[i]

    return ret if ret else "EMPTY"