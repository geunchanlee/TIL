while True:
    try:
        d = {'e':'i','i':'e','E':'I','I':'E'}
        print(''.join([d[w] if w in d else w for w in list(input())]))
    except EOFError:
        break