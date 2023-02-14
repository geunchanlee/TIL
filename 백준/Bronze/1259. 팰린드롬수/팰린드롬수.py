while True:
    n = input()
    c = int(len(n))//2
    if n == '0': 
        break
    if len(n) % 2 == 0:    
        if n[0:c] == n[-1:c-1:-1]:
            print('yes')       
        else:
            print('no')
    elif len(n) % 2 == 1:  
        if n[0:c] == n[-1:c:-1]:
            print('yes')       
        else:
            print('no')