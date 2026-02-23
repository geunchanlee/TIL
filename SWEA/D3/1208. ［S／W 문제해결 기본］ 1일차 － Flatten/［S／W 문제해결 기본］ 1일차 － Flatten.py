for t in range(1,11):
    dump = int(input())
    boxes = [int(i) for i in input().split()]
    for i in range(dump):
        max_v = max(boxes)
        min_v = min(boxes)
        if max_v - min_v <= 1:
            print(f'#{t} {max_v - min_v}')
            break
        max_idx = boxes.index(max_v)
        min_idx = boxes.index(min_v)
        boxes[max_idx] -= 1
        boxes[min_idx] += 1
    else:
        print(f'#{t} {max(boxes) - min(boxes)}')