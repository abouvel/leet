from collections import deque
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        d = deque()
        v = [0]* len(temperatures)
        for i, val in enumerate(temperatures):
            while d and val > temperatures[d[-1]]:
                ind = d.pop()
                v[ind] = i-ind
            d.append(i)
        return v 