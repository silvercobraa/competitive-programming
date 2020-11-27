import sys

lines = []
grams2cals = [9, 4, 4, 4, 7]
cals2grams = [1/9, 1/4, 1/4, 1/4, 1/7]

for line in sys.stdin:
    l = line.strip()
    if l != '-':
        lines.append(l)
        continue
    if len(lines) == 0:
        break
    cals = [0 for _ in range(5)]
    for food in lines:
        total_grams = 0
        total_percentage = 0
        total_cals = 0
        for i, nutrient in enumerate(food.split()):
            amount = int(nutrient[:-1])
            kind = nutrient[-1]
            if kind == '%':
                total_percentage += amount
            elif kind == 'g':
                total_grams += amount
                total_cals += grams2cals[i] * amount
            elif kind == 'C':
                total_grams += cals2grams[i] * amount
                total_cals += amount
        perc2grams = total_grams / (100 - total_percentage)
        perc2cals = total_cals / (100 - total_percentage)
        for i, nutrient in enumerate(food.split()):
            amount = int(nutrient[:-1])
            kind = nutrient[-1]
            if kind == '%':
                cals[i] += perc2cals * amount
            elif kind == 'g':
                cals[i] += grams2cals[i] * amount
            elif kind == 'C':
                cals[i] += amount
    fat = cals[0]
    total = sum(cals)
    perc = round(100 * fat / total)
    print(perc, '%', sep='')
    lines = []
