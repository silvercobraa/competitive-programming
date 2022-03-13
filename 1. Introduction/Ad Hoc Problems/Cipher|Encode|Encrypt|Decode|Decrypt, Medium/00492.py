import sys

def is_letter(c):
	return c in 'qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM'

def is_vowel(c):
	return c in 'aeiouAEIOU'

for line in sys.stdin:
	is_first_letter = True
	# states
	INITIAL, STARTS_WITH_VOWEL, STARTS_WITH_CONSONANT = 0, 1, 2
	state = INITIAL
	consonant = None
	for c in line:
		if state == INITIAL:
			if is_vowel(c):
				print(c, end='')
				state = STARTS_WITH_VOWEL
			elif is_letter(c):
				consonant = c
				state = STARTS_WITH_CONSONANT
			else:
				print(c, end='')
		elif state == STARTS_WITH_VOWEL:
			if is_letter(c):
				print(c, end='')
			else:
				print('ay', c, sep='', end='')
				state = INITIAL
		elif state == STARTS_WITH_CONSONANT:
			if is_letter(c):
				print(c, end='')
			else:
				print(consonant, 'ay', c, sep='', end='')
				state = INITIAL
