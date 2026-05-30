from collections import defaultdict
import heapq
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # pairs of values and frequency in the priority queue
    
        m = defaultdict(int)
        for i in nums: 
            m[i]+=1
        
        vec = [(-v,k)  for (k,v) in m.items()]
        heapq.heapify(vec)
        f = []
        for i in range(k):
            f.append(heapq.heappop(vec)[1])
        return f