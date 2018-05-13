from string import ascii_letters

def is_isogram(string):
	string = string.lower()
	for letter in string:
		if letter in ascii_letters:
			if string.count(letter)	> 1:
				return False

	return True
