// stonehail.c
// returns all hailstone sequences of a certain size

#include <stdio.h>
#include <stdlib.h>

// prints a hailstone sequence starting with n
void hail(long n) {
	printf("%ld ", n);
	if ( n == 1 ) {
		printf("\n");
		return;
	}
	else if ( n % 2 == 0 ) {
		n /= 2;
		hail(n);
	}
	else {
		n *= 3;
		++n;
		hail(n);
	}
	return;
}

// finds all initial values for sequences of a certain size, and passes them to hail.
int stone(long s) {
	// d is elements in stones array, d-1 is last element index
	int d = 1;
	long *stones = malloc(sizeof *stones);
	if(!stones) return 1;
	stones[0] = 1;
	for (int stop = d; s > 1; --s) {
		for (int j = 0; j < stop; ++j) {
			if ( stones[j] == 4 );
			else if ( stones[j] % 6 == 4) {
				++d;
				stones = realloc(stones, d * sizeof *stones);
				if(!stones) return 1;
				stones[(d-1)] = (stones[j] - 1) / 3;
			}
			stones[j] *= 2;
		}
		stop = d;
	}
	for (j = 0; j < d; ++j) hail(stones[j]);
	return 0;
}

// program takes one argument, which is passed to stone.
int main(int argc, char **argv) {
	if ( argc == 2 ) {
		return stone(strtol(argv[1],NULL,0));
	}
	else return 1;
}
