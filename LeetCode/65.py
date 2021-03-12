class Solution(object):    
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        def is_digit(d):
            return '0' <= d <= '9'
        
        def state_9(s):
            if not s:
                return state_7()
            if is_digit(s[0]):
                return state_9(s[1:])
            if s[0] == 'e' or s[0] == 'E':
                return state_4(s[1:])
            else:
                return state_8()
        
        def state_8():
            return False
        
        def state_7():
            return True
        
        def state_11(s):
            if not s:
                return state_8()
            if is_digit(s[0]):
                return state_5(s[1:])
        
        def state_6(s):
            if not s:
                return state_7()
            if is_digit(s[0]):
                return state_6(s[1:])
            if s[0] == 'e' or s[0] == 'E':
                return state_4(s[1:])
            else:
                return state_8()
        
        def state_5(s):
            if not s:
                return state_7()
            if is_digit(s[0]):
                return state_5(s[1:])
            else:
                return state_8()
        
        def state_4(s):
            if not s:
                return state_8()
            if s[0] == '+' or s[0] == '-':
                return state_11(s[1:])
            if is_digit(s[0]):
                return state_5(s[1:])
            else:
                return state_8()
        
        def state_3(s):
            if not s:
                return state_8()
            if is_digit(s[0]):
                return state_6(s[1:])
            else:
                return state_8()
        
        def state_2(s):
            if not s:
                return state_7()
            if is_digit(s[0]):
                return state_2(s[1:])
            if s[0] == 'e' or s[0] == 'E':
                return state_4(s[1:])
            if s[0] == '.':
                return state_9(s[1:])
            else:
                return state_8()
        
        def state_1(s):
            if not s:
                return state_8()
            if s[0] == '.':
                return state_3(s[1:])
            if is_digit(s[0]):
                return state_2(s[1:])
            else:
                return state_8()
        
        def state_0(s):
            if not s:
                return state_8()
            elif s[0] == "+" or s[0] == "-":
                return state_1(s[1:])
            else:
                return state_1(s)
            
        return state_0(s)