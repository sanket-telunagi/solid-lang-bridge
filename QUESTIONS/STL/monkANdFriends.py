t = int(input())
while (t > 0) :
    n,m = map(int,input().split(" "))
    l = []
    for i in range(n+m):
        l.append(int(input()))
    for i in l[n::]:
        if i in l[::n] :
            print("YES")
        else:
            print("NO")

