#include <stdio.h>

void printPrimfaktorzerlegung(int n);
int isFactorOf(int factor, int of);
int isPrim(int n);

int main(int argc, char* argv[])
{
	int n;

	printf("### PRIMFAKTORZERLEGUNG ###\n");
	printf("Gib eine Zahl ein:\n");
	scanf(" %d", &n);
	printPrimfaktorzerlegung(n);
}

void printPrimfaktorzerlegung(int n) {
	for(int i = 2; i <= n; i++) {
		// wir teilen uns die Logik auf in 2 Funktionen
		// wenn i ein Faktor von n ist
		// und
		// wenn i eine Primzahl ist
		if(isFactorOf(i, n) && isPrim(i)) {
			printf("%d\t", i);
			printPrimfaktorzerlegung(n / i);
			break;
		}
	}
}

int isFactorOf(int factor, int checkAgainst) {
	return checkAgainst % factor == 0;
}

int isPrim(int n) {
	int isPrim = 1;
	if( n < 2 ) {
		isPrim = 0;
	}
	for(int i = n - 1; i > 1; i--) {
		if(isFactorOf(i, n)) {
			isPrim = 0;
		}
	}
	return isPrim;
}
