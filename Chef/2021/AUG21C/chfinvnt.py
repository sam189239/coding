T = int(input())
for _ in range(T):
    n, p, k = map(int, input().split())
    ans = 0
    
    a = p%k - 1
    b = ((n-1)//k)*k
    b = n - 1 - b
    
    if (a>b):
        ans += (b+1)*((n-1)//k + 1) +(a-b)*((n-1)//k)
    else:
        ans += ((n-1)//k + 1)*(a+1)
        
    for i in range(a+1, n, k):
        ans += 1
        if (i==p):
            print(ans)
            break