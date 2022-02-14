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
int main() {
		char filename[10]="file.txt";
		int fd = open(filename,  O_RDWR);

		if (fd == -1) {
   		 printf("File could not open!\n");
  		 return 1;
 		}
 		
 		fseek(fd, 0L, SEEK_END);
		int sz = ftell(fd);
	
		pthread_t thread[2];
 		char *map= (char*) mmap(NULL, sz, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
 		 if (map == MAP_FAILED) {
 			  printf("File could not be memory mapped!\n");
  			  return 1;
		 } 
		
		pthread_create(&thread[0], NULL, &change, map);
		pthread_create(&thread[1], NULL, &change, map + 50);
		
		pthread_join(thread[0], NULL);
		pthread_join(thread[1], NULL);

		munmap(map, 100);
		close(fd);
	return 0;
}
