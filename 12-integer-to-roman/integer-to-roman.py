class Solution:
    def intToRoman(self, num: int) -> str:

        roman_map = {1: 'I', 4: 'IV', 5: 'V', 9: 'IX', 10: 'X', 40: 'XL', 50: 'L', 90: 'XC', 100: 'C', 400: 'CD', 500: 'D', 900: 'CM', 1000: 'M'}
        roman_num = ''
        for value, numeral in sorted(roman_map.items(), reverse=True):
            while num >= value:
                roman_num += numeral
                num -= value
        return roman_num