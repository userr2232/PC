class Solution:
    def valid(self, row, col):
        return 0 <= row < self.n and 0 <= col < self.n
    
    def DFS(self, r, c):
        if not self.valid(r, c) or not self.grid[r][c]: return
        self.ccs[(r, c)] = self.cc_num
        if not self.sizes.get(self.cc_num):
            self.sizes[self.cc_num] = 1
        else:
            self.sizes[self.cc_num] += 1
        self.max_size = max(self.max_size, self.sizes[self.cc_num])
        for i in range(4):
            new_r, new_c = r + self.drow[i], c + self.dcol[i]
            if self.valid(new_r, new_c) and self.grid[new_r][new_c]:
                if (new_r, new_c) not in self.visited:
                    self.visited.add((new_r, new_c))
                    self.DFS(new_r, new_c)
    
    def largestIsland(self, grid: List[List[int]]) -> int:
        self.drow = [0, 0, 1, -1]
        self.dcol = [-1, 1, 0, 0]
        self.cc_num = 1
        self.ccs = dict()
        self.visited = set()
        self.sizes = dict()
        self.max_size = 0
        self.n = len(grid)
        self.grid = grid
        # find all conected components
        for r in range(self.n):
            for c in range(self.n):
                if self.grid[r][c]:
                    if (r, c) not in self.visited:
                        self.visited.add((r, c))
                        self.DFS(r, c)
                        self.cc_num += 1
        for r in range(self.n):
            for c in range(self.n):
                if not grid[r][c]:
                    new_size = 1
                    ccs = set()
                    for i in range(4):
                        new_r, new_c = r + self.drow[i], c + self.dcol[i]
                        if self.valid(new_r, new_c):
                            if grid[new_r][new_c]:
                                cc = self.ccs.get((new_r, new_c))
                                if cc and cc not in ccs:
                                    new_size += self.sizes[cc]
                                    ccs.add(cc)
                                else:
                                    pass
                            else:
                                pass
                        else:
                            pass
                    self.max_size = max(new_size, self.max_size)
                else:
                    pass
        return self.max_size