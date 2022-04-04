t = int(input())
while (t > 0):
    t -= 1
    n = int(input())
    a = [int(x) for x in input().split()]

    al = n
    ar = 0
    ans = 1
    for p in range(n):
        for s in range(n - p):
            x = 1
            for i in range(p, n - s):
                x *= a[i]
            if (x > ans):
                ans = x
                al = p
                ar = s
    
    print(al, ar)