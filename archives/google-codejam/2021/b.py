from math import gcd
from functools import reduce # Python version 3.x
from fractions import Fraction

def lcm(denominators):
    return reduce(lambda a,b: a*b // gcd(a,b), denominators)


def solve(N, Q):
    F = [1] * Q
    T = [1] * Q
    for n in range(0, N):
        ar = input().split()
        sq = str(ar[0])
        sc = int(ar[1])
        for i in range(0, len(sq)):
            if sq[i] == 'T':
                T[i] *= sc
                F[i] *= Q - sc
            else:
                F[i] *= sc
                T[i] *= Q - sc
    print(T)
    print(F)
    ans = ""
    z = [0] * Q
    w = [0] * Q
    for q in range(0, Q):
        if (F[q] >= T[q]):
            ans = ans + 'F'
            z[q] = F[q]
            w[q] = Q**N
        else:
            ans = ans + 'T'
            z[q] = T[q]
            w[q] = Q**N
    lc = lcm(w)
    zz = 0
    ww = lc
    for q in range(0, Q):
        zz = zz + (z[q] * (lc / w[q]))
    gc =gcd(int(zz), int(ww))
    # print(lc, gc)
    return ans, int(zz/gc), int(ww/gc)

# I/O Code
num_cases = int(input())
for case in range(1, num_cases + 1):
    N, Q = map(int, input().split())
    y, z, w = solve(N, Q)
    print('Case #{}: {} {}/{}'.format(case, y, z, w))