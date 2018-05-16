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
	printf("[-] %s\n[Usage] %s <Chunk_Size Ex. 512> <Device Ex. /dev/sdb>\n",err,prog);
	exit(0);
}

int main(int argc, char** argv)
{
	int devFD;
	int infoi = 1073741824; // 1GB
	ssize_t tempbuff, totalbytes = 0;
	if (argc < 2)
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
			printf("[INFO] Bytes Out: %ld -> Device: %s\n",totalbytes,argv[2]);
	} while (tempbuff == chunksize);
	printf("[+] Clearing Write Cache..\n");
	close(devFD);
	printf("[+] Total Bytes Out: %ld\n",totalbytes);
	free(bytes);
	return 0;
}
