#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEST_CASES 3
#define MAX_INPUT_LEN 5
#define MAX_X_LEN 512

char *getInput (int str_len)
{
	char *str = malloc(sizeof(str) * str_len);
//	str = strInput;
	int c = EOF;
	unsigned int i = 0;

	while ((c = getchar()) != '\n' && c != EOF) {
		str[i++] = (char)c;
	}

//	str[i] = '\0';

	return str;
}

int validate_S_C (int S, int C)
{
	if ((S < 1 || S >= 100) || (C < 1 || C >= 100)) {
		return 0;
	}
	if (S + C > 100) {
		return 0;
	}
	return 1;
}

int table (void)
{
//	char T_in[MAX_TEST_CASES+1];
//	getInput(T_in, MAX_TEST_CASES+1);
	char *T_in = malloc(sizeof(T_in) * MAX_TEST_CASES);
	T_in = getInput(MAX_TEST_CASES+1);	

	int T = strtol(T_in, NULL, 10);

	if (T <=0 || T > 500) {
		return 0;
	}

//	char params[MAX_INPUT_LEN+1];
//	char X_params[99999999];
	char *params = malloc(sizeof(params) * MAX_INPUT_LEN);
	char *X_params = malloc(sizeof(X_params) * MAX_X_LEN);

	int i, j;
	int S[T];
	int C[T];
//	int (*X)[T] = malloc(sizeof(int[300][T]));
	int X[T][100];

	for (i = 0; i < T; i++) {
		char *end;
//		getInput(params, MAX_INPUT_LEN+1);
		params = getInput(MAX_INPUT_LEN+1);
		S[i] = strtol(params, &end, 10);
		C[i] = strtol(end, NULL, 10);
		if (!validate_S_C(S[i], C[i])) {
//			break;
			return 0;
		}

//		getInput(X_params, 300);		
		X_params = getInput(300);
		char *begin = X_params;
		end = NULL;
		for (j = 0; j < S[i]; j++) {
			X[i][j] = strtol(begin, &end, 10);
			begin = end;
		}
	}
	
	for (i = 0; i < T; i++) {
		int diffTable[S[i]][S[i]+C[i]];
		for (j = 0; j < S[i]; j++) {
			int n;
			for (n = 0; n < S[i]; n++) {
				if (j == 0) {
					diffTable[j][n] = X[i][n];
				} else {
					diffTable[j][n] = diffTable[j-1][n+1] - diffTable[j-1][n];
				}
			}
		}
/*
		printf("\n");
		int v, w;
		for (v = 0; v < S[i]; v++) {
			for (w = 0; w < S[i]+C[i]; w++) {
				printf("%d   ", diffTable[v][w]);
			}
			printf("\n");
		}
*/		
		int row = sizeof(diffTable) / sizeof(diffTable[0]);
		int col = sizeof(diffTable[0]) / sizeof(diffTable[0][0]);		
		int k;
		int L = 0;
		for (j = row; j > 0; j--)  {
			for (k = 1+L; k <= C[i]+L; k++) {
				if (j == row) {
					diffTable[j-1][k] = diffTable[j-1][k-1];
				} else {
					diffTable[j-1][k] = diffTable[j][k-1] + diffTable[j-1][k-1];
				}
			}
			L++;
		}
/*
		for (j = row; j > 0; j--)  {
			for (k = 1; k < col; k++) {
				if (j == row) {
					diffTable[j-1][k] = diffTable[j-1][k-1];
				} else {
					diffTable[j-1][k] = diffTable[j][k-1] + diffTable[j-1][k-1];
				}
			}
		}
*/
/*
		printf("\n");
		for (v = 0; v < S[i]; v++) {
			for (w = 0; w < S[i]+C[i]; w++) {
				printf("%d   ", diffTable[v][w]);
			}
			printf("\n");
		}
*/
//		char output[300] = "";
//		char str[12];
		for (j = S[i]; j < col; j++) {
			printf("%d ", diffTable[0][j]);
//			sprintf(str, "%d ", diffTable[0][j]);
//			strcat (output, str);
		}
		puts("");
//		printf("%s\n", output); 
	}

	free(params);
	free(X_params);

	return 0;
}
