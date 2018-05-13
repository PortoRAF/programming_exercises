def verify(isbn):
	isbn = isbn.replace("-", "")

	if len(isbn) is not 10:
		return False

	total = 0
	index = 0
	
	for element, multiplier in zip(isbn, range(10,0,-1)):
		if element is "X" and multiplier is 1:
			element = 10

		try:
			element = int(element)
		except:
			return False

		total += element * multiplier

	if total % 11 == 0:
		return True

	return False


