#not allowed to convert string with a built-in library

class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        char_delta = 48
        num1_length, num2_length = len(num1), len(num2)

        #get num1 as decimal 
        dec_num1 = 0
        pow_num = num1_length - 1
        for i in range(0, num1_length):
            dec_num1 += (ord(num1[i]) - char_delta) * (10**pow_num)
            pow_num -= 1

        #get num2 as decimal 
        dec_num2 = 0
        pow_num = num2_length - 1
        for i in range(0, num2_length):
            dec_num2 += (ord(num2[i]) - char_delta) * (10**pow_num)
            pow_num -= 1

        return str(dec_num1 * dec_num2)