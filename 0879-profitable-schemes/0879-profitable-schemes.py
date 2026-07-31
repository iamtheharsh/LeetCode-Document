class Solution:
    mod = 10**9 + 7
    def solve(self, i,cp,left):
        if i== len(self.group):
             return cp>=self.mp
        
        if (i,cp,left) in self.dp:
            return self.dp[(i,cp,left)]


        ans = 0
        cp = min(cp,self.mp)
        ans = self.solve(i+1,cp,left)
        take = 0
        if self.group[i]<=left :
            ans  += self.solve(i+1,min(self.mp , cp + self.profit[i]),left-self.group[i])

        self.dp[(i,cp,left)] = ans
        
        return (ans)%self.mod


    def profitableSchemes(self, n: int, minProfit: int, group: List[int], profit: List[int]) -> int:
        self.n = n
        self.mp = minProfit
        self.group = group
        self.profit = profit
        self.dp = {}
        return self.solve( 0,0,n)

        