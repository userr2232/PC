class Solution:
    def __init__(self):
        self.prev_read = []
    
    def read(self, buf: List[str], n: int) -> int:
        chars_current_read = 0
        buf_idx = 0
        while n >= 0:
            n_prev_read = len(self.prev_read)
            if n_prev_read:
                if n > n_prev_read:
                    chars_current_read += n_prev_read
                    buf[buf_idx:buf_idx+n_prev_read] = self.prev_read
                    self.prev_read = []
                    buf_idx += n_prev_read
                    n -= n_prev_read
                elif n == n_prev_read:
                    chars_current_read += n_prev_read
                    buf[buf_idx:buf_idx+n_prev_read] = self.prev_read
                    self.prev_read = []
                    return chars_current_read
                else:
                    # n < n_prev_read
                    chars_current_read += n
                    buf[buf_idx:buf_idx+n] = self.prev_read[:n]
                    self.prev_read = self.prev_read[n:]
                    return chars_current_read
            else:
                self.prev_read = [None]*4
                n_read = read4(self.prev_read)
                self.prev_read = self.prev_read[:n_read]
                if n_read == 0:
                    break
            
        return chars_current_read
            