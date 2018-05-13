def to_rna(dna_strand):
	rna_strand = ""
	for element in dna_strand:
		if element is 'G':
			rna_strand += 'C'
		elif element is 'C': 
			rna_strand += 'G'
		elif element is 'T':
			rna_strand += 'A'
		elif element is 'A':
			rna_strand += 'U'
		else:
			raise Exception('Not a valid input')
	
	return rna_strand
