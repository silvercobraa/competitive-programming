
def is_leap(n):
	return n % 4 == 0 and (n % 100 != 0 or n % 400 == 0)


first = True
s = input()
try:
	while s != '':
		n = int(s)
		if not first:
			print()
		else:
			first = False
		leap = is_leap(n)
		huluculu = n % 15 == 0
		bulukulu = n % 55 == 0 and leap
		if not leap and not huluculu and not bulukulu:
			print("This is an ordinary year.")
			s = input()
			continue
		if leap:
			print("This is leap year.")
		if huluculu:
			print("This is huluculu festival year.")
		if bulukulu:
			print("This is bulukulu festival year.")
		s = input()
except Exception as e:
	pass
