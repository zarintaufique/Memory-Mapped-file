#include <sys/mman.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <pthread.h>

void *change(void* buff){
	char *buf = (char*)buff;
	int size = strlen(buf);
	size = size / 2;
	int i = 0;
	for(;i < size;i++){
		//converting to upper case
		if(buf[i] >=97 && buf[i] <= 122){
			buf[i] = buf[i] - 32;
		}
		//converting to lower case
		else if (buf[i] >=65 && buf[i] <= 90){
			buf[i] = buf[i] + 32;
		}
		//squaring numbers
		else if (buf[i] >=48 && buf[i] <= 57){
			buf[i] = buf[i] * buf[i];	
		}
		//special charachters
		else {
			buf[i] = ' ';
		}
		printf("%c\n", buf[i]);
	}
	pthread_exit(0);
}
