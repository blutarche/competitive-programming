import array as arr

def solve(N, A):
    prev = -1
    ans = 0
    for i in range(0, N):
        ansr = 0
        tmp = A[i]
        if tmp > prev:
            prev = tmp
            continue
        a = str(tmp)
        b = str(prev)
        mm = False
        mp = 0
        for j in range(0, len(b)):
            if (j < len(a) and a[j] != b[j]):
                mm = True
                mp = j
                break
        if not mm and len(a) < len(b):
            st = b[len(a):]
            sti = int(st) + 1
            st2 = str(sti)
            if (len(st2) <= len(st)):
                st2 = st2.zfill(len(st) - len(st2))
                for k in range(0, len(st2)):
                    a = a + st2[k]
                    ansr += 1
        while int(a) <= int(b):
            for j in range(0, 10):
                a = a + str(j)
                if (int(a) > int(b)):
                    ansr += 1
                    break
                a = a[0:len(a)-1]
            if (int(a) > int(b)):
                break
            ansr += 1
            a = a + '0'
        # print(ansr)
        ans += ansr
        prev = int(a)
    return ans

# I/O Code
num_cases = int(input())
for case in range(1, num_cases + 1):
    N = int(input())
    A = [int(x) for x in input().split()]
    result = solve(N, A)
    print('Case #{}: {}'.format(case, result))