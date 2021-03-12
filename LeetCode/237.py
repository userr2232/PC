class Solution:
    def decompose(self, num):
        l = []
        num_str = str(num)
        left = 3
        while True:
            if left == 3:
                l.append(num_str[-3:])
            else:
                l.append(num_str[-left:-left + 3])
            if left > len(num_str):
                break
            left += 3
        return l
        
    
    def translate(self, num):
        if num == 0: return [ "" ]
        num_str = str(num)
        n = len(num_str)
        if n == 1:
            return [ self.d[num] ]
        if n == 2:
            if self.d.get(num):
                return [ self.d.get(num) ]
            else:
                r = num % 10
                return self.translate(num - r) + self.translate(r)
        if n == 3:
            return [ self.d[int(num_str[0])], self.d[100] ] + self.translate(int(num_str[1:]))
        if n == 4:
            return [ self.d[int(num_str[0])], self.d[1000] ] + self.translate(int(num_str[1:]))
        if n == 5 or n == 6:
            d = num // 1000
            return self.translate(d) + [ self.d[1000] ] + self.translate(int(num_str[len(str(d)):]))
        if n == 7 or n == 8 or n == 9:
            d = num // 1000000
            return self.translate(d) + [ self.d[1000000] ] + self.translate(int(num_str[len(str(d)):]))
        else:
            d = num // 1000000000
            return self.translate(d) + [ self.d[1000000000] ] + self.translate(int(num_str[len(str(d)):]))
    
    def numberToWords(self, num: int) -> str:
        if num == 0: return "Zero"
        self.d = {
                1: 'One', 2: 'Two', 3: 'Three', 4: 'Four', 5: 'Five',
                6: 'Six', 7: 'Seven', 8: 'Eight', 9: 'Nine', 10: 'Ten',
                11: 'Eleven', 12: 'Twelve', 13: 'Thirteen', 14: 'Fourteen',
                15: 'Fifteen', 16: 'Sixteen', 17: 'Seventeen', 18: 'Eighteen', 19: 'Nineteen',
                20: 'Twenty', 30: 'Thirty', 40: 'Forty', 50: 'Fifty', 60: 'Sixty',
                70: 'Seventy', 80: 'Eighty', 90: 'Ninety', 100: 'Hundred',
                1000: 'Thousand', 1000000: 'Million', 1000000000: 'Billion',
            }
        decomposition = self.decompose(num)
        l = []
        for i, x in enumerate(decomposition):
            l += self.translate(int(x + "000" * i))[::-1]
        k = [x for x in l if x][::-1]
        return ' '.join(k)