class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        self.d = defaultdict(list)
        
        def string_to_tuple(string):
            tup = ()
            for i in range(len(string) - 1):
                d = ord(string[i]) - ord(string[i+1])
                if d < 0:
                    d += 26
                tup = tup + (d,)
            return tup
        
        for string in strings:
            self.d[string_to_tuple(string)].append(string)
            
        return [strs for tup, strs in self.d.items()]