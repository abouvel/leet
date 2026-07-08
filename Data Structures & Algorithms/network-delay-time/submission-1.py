import heapq
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        v = [[] for _ in range(n+1)]
        minHeap = [(0, k)]

        dist = [float("inf")] *(n+1)
        dist[k] = 0
        for s,f,w in times:
            v[s].append((f,w))

        minDist = float("inf")
        while minHeap:

            curDist, node = heapq.heappop(minHeap)
            if curDist > dist[node]:
                continue

            for n, w in v[node]:
                newDist = curDist + w
            
                if newDist < dist[n]:
                    dist[n] = newDist
                    heapq.heappush(minHeap, (newDist,n))
        ans = max(dist[1::])
        return ans if ans != float("inf") else -1

                
        



        