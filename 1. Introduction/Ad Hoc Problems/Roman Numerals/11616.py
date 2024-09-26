import sys
import re

class Converter:
    def __init__(self):
        self.d2r_lookup = [
            ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"],
            ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"],
            ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"],
            ["", "M", "MM", "MMM"],
        ]
        self.r2d_pattern = re.compile("(M{,3})(CD|CM|DC{,3}|C{,3})(XL|XC|LX{,3}|X{,3})(IV|IX|VI{,3}|I{,3})")
        self.r2d_lookup = {
            "I": 1, "II": 2, "III": 3, "IV": 4, "V": 5, "VI": 6, "VII": 7, "VIII": 8, "IX": 9,
            "X": 10, "XX": 20, "XXX": 30, "XL": 40, "L": 50, "LX": 60, "LXX": 70, "LXXX": 80, "XC": 90,
            "C": 100, "CC": 200, "CCC": 300, "CD": 400, "D": 500, "DC": 600, "DCC": 700, "DCCC": 800, "CM": 900,
            "": 0, "M": 1000, "MM": 2000, "MMM": 3000,
        }

    def roman_to_decimal(self, s):
        groups = self.r2d_pattern.match(s).groups()
        print(sum(self.r2d_lookup[value] for value in groups))

    def decimal_to_roman(self, s):
        mapped = [self.d2r_lookup[idx][int(val)] for idx, val in enumerate(reversed(s))]
        print("".join(reversed(mapped)))


conv = Converter()
for line in sys.stdin:
    s = line.strip()
    if s.isnumeric():
        conv.decimal_to_roman(s)
    else:
        conv.roman_to_decimal(s)