/*
Yikai Wang
Period 4 Systems
*/

#include <stdio.h>
#include <stdlib.h>

/* debugging tools */
void displayNum( int n ) {
	printf( "%d\n", n );
}

void displaySeg() {
	printf( "~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
}


/* For first problem: */
char isPrime(int n) { 
/* test for 2 is ommited because the last digit is odd */
  if( n % 3 == 0 ) {
  	return 0;
  }
  
  int i = 5;
  int w = 2;

  while( i * i <= n ) {
  	if( n%i == 0 ) {
  		return 0;
  	}

  	i += w;
  	w = 6 - w;
  }

  return 1;
}

char isPandigital( int n ) {
	int len = 0;
	char digitsUsed[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	while( n != 0 ) {
		int i = n % 10;
		if( i == 0 ) {
			return 0;
		}

		digitsUsed[ i - 1 ] = 1;
		n /= 10;
		len++;
	}

	for(len; len > 0; len--) {
		if( digitsUsed[len-1] == 0 ) { 
			return 0;
		}
	}

	return 1;
}

int pandigitalPrime( int n ) {
	int i;
	for( i = n; i >= 2143; i-=2 ) {
		if( ( isPrime( i ) == 1 ) && (isPandigital( i ) == 1) ) {
			return i;
		}
	}

	return -1;
}

/* For second problem */
int waysTotarget( int target ) {
	int ways = 0;

	int p200, p100, p50, p20, p10, p5, p2, p1;

	for( p200 = target; p200 >= 0; p200 -= 200 ) {
		for ( p100 = p200; p100 >= 0; p100 -= 100 ) {
	    	for ( p50 = p100; p50 >= 0; p50 -= 50 ) {
	        	for ( p20 = p50; p20 >= 0; p20 -= 20 ) {
	            	for ( p10 = p20; p10 >= 0; p10 -= 10 ) {
	                	for ( p5 = p10; p5 >= 0; p5 -= 5 ) {
	                    	for ( p2 = p5; p2 >= 0; p2 -= 2 ) {
	                        	ways++;
	                    	}
	                	}
	            	}
	        	}
	    	}
		}
	}

	return ways;
}


void main() {
	/* Problem 41 */
	int p1 = pandigitalPrime( 7654321 ); /* sum of digits not divisble by 3 */
	printf( "The largest pandigital prime is: %d.\n", p1 ); /* 7652413 */

	/* Problem 31 */
	int p2 = waysTotarget( 200 );
	printf( "Ways to reach £2: %d.\n", p2 ); /* 73682 */
}