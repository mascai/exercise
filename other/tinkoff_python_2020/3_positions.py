
n = int(input())
arr = [int(i) for i in (input().split())]

cnt = [] # list of pairs (val, id)
for i in range(len(arr)):
    cnt.append((arr[i], i + 1))

cnt.sort(reverse=True)
bad_even = None
cnt_bad_even = 0
cnt_bad_odd = 0
bad_odd = None

for i in range(len(cnt)):
    val = cnt[i][0]
    curid = cnt[i][1]
    if val % 2 != curid % 2:
        if val % 2 == 1:
            cnt_bad_odd += 1
            if cnt_bad_odd == 1:
                bad_odd = curid
        else:
            cnt_bad_even += 1
            if cnt_bad_even == 1:
                bad_even = curid

if cnt_bad_even == 0 or cnt_bad_odd == 0 or cnt_bad_even > 1 or cnt_bad_odd > 1:
    print(-1, -1)
else:
    print(min(bad_even, bad_odd), max(bad_even, bad_odd))



