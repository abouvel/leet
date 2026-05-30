class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # buy on local min, sell on local max
        if len(prices) <=1:
            return 0
        
        miny = prices[0]
        maxDif = 0
        for item in prices:
            if item < miny:
                miny = item
            else:
                maxDif = max(maxDif, item-miny)
        return maxDif      


        