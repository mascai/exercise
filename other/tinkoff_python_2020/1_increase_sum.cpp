

def update_levels(levels, cur):
    i = 0
    if cur == 0:
        levels[i].append(0)
        return levels
    while cur > 0:
        levels[i].append(cur % 10)
        i += 1
        cur //= 10
    return levels

n, k = [int(i) for i in (input().split())]

arr = []
levels = []
for i in range(0, 10):
    levels.append([])
arr = [int(i) for i in (input().split())]
for cur in arr:
    levels = update_levels(levels, cur)

for i in range(len(levels)):
    levels[i].sort()

curList = len(levels) - 1
cutPos = 0
res = int(0)
while k > 0 and curList >= 0:
    for cur in levels[curList]:
        if k == 0:
            break
        if cur < 9:
            res = res + int(9 - cur) * int(10**curList)
            k -=1
    curList -= 1

print(res)


