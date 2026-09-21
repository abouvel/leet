from collections import defaultdict
class trie: 
    def __init__(self):
        self.letters = {}
        self.isEnd = False

class WordDictionary:

    def __init__(self):
        self.t = trie()

    def addWord(self, word: str) -> None:
        tCopy = self.t
        for c in word: 
            if c not in tCopy.letters:
                n = trie()
                tCopy.letters[c] = n
            tCopy = tCopy.letters[c]
        tCopy.isEnd = True

        

    def search(self, word: str) -> bool:

        def dfs(idx, node):
            if idx == len(word):
                return node.isEnd
            c = word[idx]
            if c == ".":
                return any(dfs(idx + 1, child) for child in node.letters.values())
            if c not in node.letters:
                return False
            return dfs(idx + 1, node.letters[c])
        return dfs(0, self.t)
        
