from string import ascii_lowercase

def is_pangram(sentence):
	sentence = sentence.lower()
	for letter in ascii_lowercase:
		if sentence.count(letter) == 0:
			return False

	return True
