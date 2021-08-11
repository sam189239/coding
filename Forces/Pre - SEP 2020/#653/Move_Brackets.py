t = int(input())
while t>0:
    n = int(input())
    s = input()
    i = 0
    j=0
    k=0
    while j<n:
        if s[j] == '(':
            i+=1
        else:
            i-=1
        if i<0:
            s = s[:j-1]+s[j+1:]
            s = s+')'
            k+=1
            j-=1
        j+=1
    t-=1
    print(k)