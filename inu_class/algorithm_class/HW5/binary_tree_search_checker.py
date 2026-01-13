class node:
    def __init__(self, key=None, left=None, right=None):
        self.key = key
        self.left = left
        self.right = right


class Dict:
    x = p = node

    z = node(key=0, left=0, right=0)
    z.left = z
    z.right = z
    head = node(key=0, left=0, right=z)

    def search(self, search_key):
        x = self.head.right
        while x != self.z:
            if x.key == search_key:
                return x.key
            if x.key > search_key:
                x = x.left
            else:
                x = x.right
        return -1

    def insert(self, v):
        x = p = self.head
        while x != self.z:
            p = x
            if x.key == v:
                return
            if x.key > v:
                x = x.left
            else:
                x = x.right
        x = node(key=v, left=self.z, right=self.z)
        if p.key > v:
            p.left = x
        else:
            p.right = x

    def check(self, search_key):
        x = p = self.head.right
        while x != self.z:
            if x.key == search_key:
                print("key : ", x.key, ", parents : ", p.key)
            p = x
            if x.key > search_key:
                x = x.left
            else:
                x = x.right


N = 8
key = [2, 1, 7, 8, 6, 3, 5, 4]
s_key = list(range(1, N + 1))
print("키 리스트: ", key)
d = Dict()
for i in range(N):
    d.insert(key[i])
for i in range(N):
    d.check(s_key[i])
