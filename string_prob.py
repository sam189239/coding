def flow(a,b):
    ans=0
    for i in range(len(a)):
        ans+=(a[i]!=b[i])
    return ans

def fun(A,B,C):

    memor={}  
    def rev(i,j):
        if (i-1,j+1) in memor:
            ans=memor[(i-1,j+1)]-(A[i-1]!=B[j+1])-(B[i-1]!=A[j+1])
        elif (i+1,j-1) in memor:
            ans=memor[(i+1,j-1)]+(A[i]!=B[j])+(B[i]!=A[j])
        else:
            ans=flow(A[i:j+1],B[i:j+1][-1::-1])
        memor[(i,j)]=ans
        return ans



    
    memo={}  
    def forw(i,j):
        if (i,j+1) in memo:
            ans=memo[(i,j+1)]-(A[j+1]!=B[j+1])
        elif (i+1,j) in memo:
            ans=memo[(i+1,j)]+(A[i]!=B[i])
        elif (i-1,j) in memo:
            ans=memo[(i-1,j)]-(A[i-1]!=B[i-1])
        elif (i,j-1) in memo:
            ans=memo[(i,j-1)]+(A[j]!=B[j])
        else:
            ans=flow(A[i:j+1],B[i:j+1])
        memo[(i,j)]=ans
        return ans

    ans={}
    for i in range(0,len(A)):
        for j in range(i,len(A)):
            k=(forw(i,j)-rev(i,j))
            ans[k]=(i,j)
    res=max(ans)
    if res>C:
        return True,res,ans[res]
    return False,0,(0,0)

class Solution:
    # @param A : string
    # @param B : string
    # @param C : integer
    # @return an integer
    def solve(self, A, B, C):
        p,q,r=fun(A,B,C)
        if p:
            ans=flow(A,B)
            res=ans+C-q
        else:
            res=flow(A,B)
        return res