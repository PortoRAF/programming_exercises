#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPrime (int n)
{
	if (n == 2 || n == 3) {
		return true;
	}
	if (n == 1) {
		return false;
	}
	if (n % 2 == 0) {
		return false;
	}
	if (n % 3 == 0) {
		return false;
	}
	
	int i = 5;
	int j = 2;

	while (i * i <= n) {
		if (n % i == 0) {
			return false;
		}
	
		i += j;
		j = 6 - j;
	}

	return true;
}

int main () 
{
	int t, i, j, temp; //number of test cases
	long m, n; //lower and higher boundaries
	char cases[3];
	char inputs[10][22];
	long m_n[10][2];

	fgets(cases, 3, stdin); //get the number of test cases
	t = strtol(cases, NULL, 10); //convert string to int

	if (t <= 10 && t > 0) { //number of test cases must be higher than 0 and no more than 10

		for (i = 0; i < t; i++) {	
			fgets(inputs[i], 22, stdin); //get boundaries

			char *end; //create pointer to parse string
			m_n[i][0] = strtol(inputs[i], &end, 10); //convert and store lower boundary			
			m_n[i][1] = strtol(end, NULL, 10); //convert and store higher boundary
//			printf("%ld\n%ld\n", m_n[i][0], m_n[i][1]);
			
			for (j = 0; j < 2; j++) {
				if (m_n[i][j] < 1 || m_n[i][j] > 1000000000) {
					return 0;
				}
			}
			if ((m_n[i][1] - m_n[i][0]) > 100000) {
					return 0;
			}
//			printf("%ld\n%ld\n", m_n[i][0], m_n[i][1]);
		}

		for (i = 0; i < t; i++) {
			for (temp = m_n[i][0]; temp <= m_n[i][1]; temp++) {
				if (isPrime(temp)) {
					printf("%d\n", temp);
				}
			}
			printf("\n");
		}
	}

	return 0;
}
