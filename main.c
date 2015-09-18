// gcc -o main.exe main_002.c -lpthread -lcurses

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <ncurses.h>

#define uchar unsigned char

#define NUM_THREADS     5

uchar memory[ 4096 ];

void *thFunz0(void *thParam) {
	uchar *mem;
	mem = (uchar *)thParam;
   
	while (1) {
		mem[0] = getch();
		printf("%c",mem[0]);
	}
	
	pthread_exit(NULL);
}


int main( int argc, uchar *argv[] ) {
	int rc;

	pthread_t th_0;
	
	rc = pthread_create(&th_0, NULL, thFunz0, (void *)memory);
	
	while (1) {
		// printf( "memory: %08X ", memory );
		// for ( rc=0; rc<8; rc ++ ) {
			// printf( "%02X ",memory[rc] );
		// }
		// printf( "\r" );
	}
	
	pthread_exit(NULL);

	return 0;
}