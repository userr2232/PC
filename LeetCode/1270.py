class SparseVector:
    def __init__(self, nums: List[int]):
        self.l = []
        c = 0
        for x in nums:
            if x:
                if c:
                    self.l.append(str(c))
                    c = 0
                self.l.append(x)
            else:
                c += 1
        if c:
            self.l.append(str(c))

    def update_val(self, l, i):
        new_value = int(l[i]) - 1
        if new_value == 0:
            i += 1
        else:
            l[i] = str(new_value)
        return i
            
    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec: 'SparseVector') -> int:
        answer = i = j = 0
        while True:
            if i == len(self.l) or j == len(vec.l):
                return answer
            if type(self.l[i]).__name__ == "int" and type(vec.l[j]).__name__ == "int":
                answer += self.l[i] * vec.l[j]
                i += 1
                j += 1
            else:
                if type(self.l[i]).__name__ == "str" and type(vec.l[j]).__name__ == "str":
                    i = self.update_val(self.l, i)
                    j = self.update_val(vec.l, j)
                elif type(self.l[i]).__name__ == "str":
                    j += 1
                    i = self.update_val(self.l, i)
                else:
                    i += 1
                    j = self.update_val(vec.l, j)
            

# Your SparseVector object will be instantiated and called as such:
# v1 = SparseVector(nums1)
# v2 = SparseVector(nums2)
# ans = v1.dotProduct(v2)