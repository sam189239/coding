t = int(input())
while t>0:
    s = input()
    p = input()
    i = 0
    d = dict()
    for i in range(len(s)):
        if s[i] not in d.keys():
            d[s[i]] = 0
        d[s[i]]+=1
    r = list()
    for i in range(len(p)):
        if p[i] in d.keys():
            d[p[i]] -= 1

    for i in sorted(d.keys()):
        for j in range(d[i]):
            r += i
    r+=[p]
    r.sort()    
    r = "".join(str(item)for item in r)
    print(r)
    t-=1