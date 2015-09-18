#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//	gcc -o main.exe main.c -lpthead

#define uchar unsigned char

#define NUM_THREADS     5

uchar memory[ 4096 ];

void *thFunz0(void *thParam) {
	char *mem;
	mem = (char *)thParam;
   
	while (1) {
		mem[0]++;
		if ( mem[0] == 255 ) mem[0] = 0;
	}
	
	pthread_exit(NULL);
}

void *thFunz1(void *thParam) {
	char *mem;
	mem = (char *)thParam;
   
	while (1) {
		mem[1]++;
		if ( mem[1] == 255 ) mem[1] = 0;
	}
	
	pthread_exit(NULL);
}

void *thFunz2(void *thParam) {
	char *mem;
	mem = (char *)thParam;
   
	while (1) {
		if ( mem[0] > mem[1] ) {
			mem[2] = 255;
		} else {
			mem[2] = 0;
		}
	}
	
	pthread_exit(NULL);
}

void *thFunz3(void *thParam) {
	char *mem;
	mem = (char *)thParam;
   
	while (1) {
		if ( mem[0] > mem[1] ) {
			mem[3] = 255;
		} else {
			mem[3] = 0;
		}
	}
	
	pthread_exit(NULL);
}

void *thFunz4(void *thParam) {
	char *mem;
	mem = (char *)thParam;
   
	while (1) {
		if ( mem[2] != mem[3] ) {
			mem[4] = 255;
		} else {
			mem[4] = 0;
		}
	}
	
	pthread_exit(NULL);
}

int main( int argc, char *argv[] ) {
	int rc;

	pthread_t th_0;
	pthread_t th_1;
	pthread_t th_2;
	pthread_t th_3;
	pthread_t th_4;
	
	rc = pthread_create(&th_0, NULL, thFunz0, (void *)memory);
	rc = pthread_create(&th_1, NULL, thFunz1, (void *)memory);
	rc = pthread_create(&th_2, NULL, thFunz2, (void *)memory);
	rc = pthread_create(&th_3, NULL, thFunz3, (void *)memory);
	rc = pthread_create(&th_4, NULL, thFunz4, (void *)memory);
		
	while (1) {
		printf( "memory: %08X ", memory );
		for ( rc=0; rc<8; rc ++ ) {
			printf( "%02X ",memory[rc] );
		}
		printf( "\r" );
	}
	
	pthread_exit(NULL);

	return 0;
}