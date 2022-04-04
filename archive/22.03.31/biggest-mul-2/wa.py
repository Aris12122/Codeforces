tst = int(input())
for _ in range(tst):
    n = int(input())
    a = list(map(int, input().split()))
    all_z = [-1]
    for i in range(n):
        if a[i] == 0:
            all_z.append(i)
    all_z.append(n)
    best_prod = 0
    x = n
    y = 0
    for c in range(0, len(all_z) - 1):
        l = all_z[c]
        r = all_z[c + 1]
        cnt = 0
        sgn = 0
        fi_neg = -1
        last_neg = -1
        for i in range(l + 1, r):
            if a[i] < 0:
                sgn ^= 1
                last_neg = i
                if fi_neg == -1:
                    fi_neg = i
            if a[i] == -2 or a[i] == 2:
                cnt += 1
        cur_val = 0
        cur_x = 0
        cur_y = 0
        if sgn == 1:
            cur_val = cnt
            for t in range(l + 1, fi_neg + 1):
                if a[t] == 2 or a[t] == -2:
                    cur_val -= 1
            cur_x = fi_neg + 1
            cur_y = n - r
            if best_prod < cur_val:
                best_prod = cur_val
                x = cur_x
                y = cur_y
            cur_val = cnt
            for t in range(last_neg, r):
                if a[t] == 2 or a[t] == -2:
                    cur_val -= 1
            cur_x = l + 1
            cur_y = n - last_neg - 1
            if best_prod < cur_val:
                best_prod = cur_val
                x = cur_x
                y = cur_y
        else:
            cur_val = cnt
            cur_x = l + 1
            cur_y = n - r
            if best_prod < cur_val:
                best_prod = cur_val
                x = cur_x
                y = cur_y
    print(x, y)