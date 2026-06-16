from collections import deque
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        self.m = [[] for _ in range(n)]

        for f,s in edges:
            self.m[f].append(s)
            self.m[s].append(f)
        
        
        st = deque()
        st.append((0,-1))
        s= set()
        while len(st) >0:
            cur,prev = st[0]
            st.popleft()
            
            s.add(cur)
            for v in self.m[cur]:
                if v!=prev and v not in s:
                    print(v,cur,prev)
                    st.append((v,cur))
                    s.add(v)
                elif v!=prev and v in s:
                    return False
        print(len(s))
        return len(s) == n

       





        