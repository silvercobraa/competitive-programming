#!/usr/bin/env python
# coding=utf-8
# César Bolívar Severino
# resuelto propio

def read_record():
    line = input().split()
    month = int(line[0])
    depreciation = float(line[1])
    return month, depreciation

def read4():
    line = input().split()
    months = int(line[0])
    down_payment = float(line[1])
    amount_loan = float(line[2])
    dep_records = int(line[3])
    return months, down_payment, amount_loan, dep_records


M, DP, AL, DR = read4()

while M > 0:
    car_value = DP + AL
    debt = AL
    cuota = AL/M # como se dice cuota en inglés?
    dr = {}
    for i in range(DR):
        m, d = read_record()
        dr[m] = d
        # print(m, dr[m])

    m = 1
    prev_d = dr[0]
    car_value *= (1.0 - dr[0])
    # print(car_value)
    while car_value <= debt:
        debt -= cuota
        if m in dr:
            car_value *= (1.0 - dr[m])
            prev_d = dr[m]
        else:
            car_value *= (1.0 - prev_d)

        m += 1
        # print(f'mes: {m}, valor auto: {car_value}, deuda: {debt}')

    if m - 1 == 1:
        print('1 month')
    else:
        print(m - 1, 'months')

    M, DP, AL, DR = read4()
