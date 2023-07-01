class Solution:
    def solve(self,cookies,pos,l):
        if pos==self.n:
            
            m=max(l)
            if self.finalans>m:
                self.finalans=m
            return
        
        for i in range(self.k):
            l2=l.copy()
            
            l2[i]=l2[i]+cookies[pos]
            if l2[i]>self.finalans:   # skipping all cases which have values greater than self.finalans (if we remove this line and next line we'll get TLE)
                continue
            
            
            self.solve(cookies,pos+1,l2)
        
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        self.n=len(cookies)
        self.k=k
        l=[0 for i in range(k)]
        
        self.finalans=float("inf")
        self.solve(cookies,0,l)
            
        return self.finalans