class Solution:

    def __init__(self, w: List[int]):
        self.indices = [*range(len(w))]
        s = 0
        for p in w:
            s += p
        self.probs = []
        for p in w:
            self.probs.append(p/s)

    def pickIndex(self) -> int:
        return random.choices(self.indices, self.probs)[0]