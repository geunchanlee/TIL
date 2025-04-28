def solution(code):
    mode = False
    ret = ''
    for i in range(len(code)):
        if code[i] == '1':
            mode = not mode
        else:
            if mode == False:
                if i % 2 == 0:
                    ret += code[i]
                else:
                    pass
            if mode == True:
                if i % 2 == 1:
                    ret += code[i]
                else:
                    pass

    return "EMPTY" if ret == '' else ret