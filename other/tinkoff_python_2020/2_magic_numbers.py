

def digits(n):
    if n == 0:
        return 1
    res = 0
    while n > 0:
        res += 1
        n //= 10
    return res

def get_start(n):
    res = 1
    for i in range(n - 1):
        res = res * 10 + 1
    return res


l, r = [int(i) for i in input().split()]
res = 0

if l < 10:
    res += min(9, r) - l + 1

mind = max(digits(l), 2)
maxd = digits(r)

for i in range(mind, maxd + 1):
    start = get_start(i)
    if start > r:
        break
    for mul in range(1, 10):
        cur = start * mul
        if cur > r:
            break
        if cur >= l:
            res += 1
print(res)
