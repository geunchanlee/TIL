maxb = 5

class bitskey:
    def __init__(self, x):
        self.x = x

    def get(self):
        return self.x

    def bits(self, k, j):
        return (self.x >> k) & ~(~0 << j)


class node:
    def __init__(self, key):
        self.key = bitskey(key)
        self.left = None
        self.right = None


class Dict:
    itemMin = bitskey(0)

    z = node(itemMin)
    head = node(itemMin)
    head.left = z
    head.right = z

    def search(self, v):
        v = bitskey(v)
        x = self.head.left
        b = maxb
        self.z.key = v
        while v.get() != x.key.get():
            b -= 1
            if v.bits(b, 1):
                x = x.right
            else:
                x = x.left
        if x == self.z:
            return -1
        else:
            return x.key.get()

    def insert(self, v):
        v = bitskey(v)
        b = maxb - 1
        x = self.head.left
        p = self.head

        while x.key.get() != self.z.key.get():
            p = x
            if v.bits(b, 1):
                x = x.right
            else:
                x = x.left
            b -= 1
        x = node(self.itemMin)
        x.key = v
        x.left = self.z
        x.right = self.z
        if v.bits(b + 1, 1):
            p.right = x
        else:
            p.left = x

    def check(self, v):
        v = bitskey(v)
        x = p = self.head.left
        b = maxb
        while v.get() != x.key.get():
            b = b - 1
            p = x
            if v.bits(b, 1):
                x = x.right
            else:
                x = x.left
        print("key: %d, parents: %d" % (x.key.get(), p.key.get()))


N = 7
key = [1, 19, 5, 18, 3, 26, 9]
s_key = [1, 19, 5, 18, 3, 26, 9]
s_key.sort()

d = Dict()
for i in range(N):
    d.insert(key[i])
print(key)
for i in range(N):
    d.check(s_key[i])
