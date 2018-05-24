/*
 * ==============================================\
 * [+] PPDS ~ Pink_P4nther's Device Shredder     |
 * ==============================================|
 * [+] PPDS overwrites a device of your choice   |
 * ==============================================/
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

void pperror(const char* err, char* prog)
{
	printf("[-] %s\n[Usage] %s <Buffer write size in bytes Ex. 1048576 (1MB)> <Device Ex. /dev/sdb>\n",err,prog);
	exit(1);
}

int main(int argc, char** argv)
{
	if (geteuid() != 0)
		pperror("Must be root",argv[0]);
	
	int devFD;
	int infoi = 1073741824; /* 1GB */
	ssize_t tempbuff, totalbytes = 0;
	
	if (argc < 3)
		pperror("Insufficient args",argv[0]);
	
	devFD = open(argv[2],O_WRONLY);
	int chunksize = atoi(argv[1]);
	
	if (devFD < 0)
		pperror("Can't open device for writing.",argv[0]);

	char* bytes = calloc(1,chunksize);
 
	do
	{
		tempbuff = write(devFD, bytes, chunksize);
		totalbytes += tempbuff;
	
		if (totalbytes%infoi == 0)
			printf("[INFO] Bytes Written: %ld -> Device: %s\n",totalbytes,argv[2]);
	
	} while (tempbuff == chunksize);

	printf("[INFO] Finishing up. This could take a while..\n");
	close(devFD);
	printf("[INFO] Device overwritten: %s\n",argv[2]);
	printf("[INFO] Total bytes written: %ld\n",totalbytes);
	free(bytes);
	return 0;
}
