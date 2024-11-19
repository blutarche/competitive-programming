# inn = '''10 7 4
# 4 3
# 5 3
# 5 5
# 4 3
# 4 5
# 3 5
# 4 5
# 4 4
# 3 5
# 4 5'''

npk = input()
[n,p,k] = npk.split(" ")
# inputlines = inn.split("\n")
# [n, p, k]  = inputlines[0].split(" ")
orders = []
n = int(n)
p = int(p)
k = int(k)
for x in range(n):
    ab = input()
    [a,b] = ab.split(" ")
    # [a,b] = inputlines[x+1].split(" ")
    orders.append([int(a), int(b), x+1])
    
# print(n,p,k)
# print(orders)

orders.sort(key=lambda x: (-x[0], -x[1]))
# print(orders)

ans = []
minimum = -1
g = [False]*n
for i in range(n):
    # print("ans", ans)
    if len(ans) == p:
        break
    if i<k:
        ans.append(orders[i][2])
        g[i] = True
        if minimum==-1 or orders[i][1] < minimum:
            minimum=orders[i][1]
        continue
    # print("min", minimum)
    if orders[i][1] < minimum:
        ans.append(orders[i][2])
        g[i] = True
    # print("ans", ans)

if len(ans) < p:
    for i in range(n):
        if not g[i]:
            g[i] = True
            ans.append(orders[i][2])
    # print("ans", ans)

# print("final ans", ans)
print(' '.join(str(x) for x in ans))
