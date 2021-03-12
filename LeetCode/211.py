class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.trie = {}
        

    def addWord(self, word: str) -> None:
        current = self.trie
        for c in word:
            if c not in current:
                current[c] = {}
            current = current[c]
        current['$'] = True

    def search(self, word: str) -> bool:
        def dfs_helper(current, word):
            for i, c in enumerate(word):
                if c not in current:
                    if c == '.':
                        for child in current:
                            if child != '$' and dfs_helper(current[child], word[i+1:]):
                                return True
                    return False
                else:
                    current = current[c]
            return '$' in current
        
        return dfs_helper(self.trie, word)