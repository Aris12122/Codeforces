tst = int(input())
for _ in range(tst):
    n = int(input())
    s = input()
    b = [0 for i in range(n+1)]
    bal = n
    b[0] = bal
    ans = 0
    for i in range(1,n+1):
        if s[i-1] == '+':
            bal += 1
        else:
            bal -= 1
        b[i] = bal
        for j in range(i):
            if b[j] >= b[i] and (b[j] - b[i]) % 3 == 0:
                ans += 1
    print(ans)