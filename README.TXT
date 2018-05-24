# PPDS
A tool to overwrite devices with trash data on Linux

# Compile
$ cd PPDS/
$ make

# Execute
$ ./PPDS
[-] Insufficient args
[Usage] ./PPDS <Chunk_Size Ex. 512> <Device Ex. /dev/sdb>

# Example output of erasing my 8GB USB drive

[ra_horakhty][Dev][PPDS]
-> sudo ./PPDS 512 /dev/sdb
[sudo] password for ra_horakhty: 
[INFO] Bytes Out: 1073741824 -> Device: /dev/sdb
[INFO] Bytes Out: 2147483648 -> Device: /dev/sdb
[INFO] Bytes Out: 3221225472 -> Device: /dev/sdb
[INFO] Bytes Out: 4294967296 -> Device: /dev/sdb
[INFO] Bytes Out: 5368709120 -> Device: /dev/sdb
[INFO] Bytes Out: 6442450944 -> Device: /dev/sdb
[INFO] Bytes Out: 7516192768 -> Device: /dev/sdb
[+] Finishing up. This could take a while..
[+] Total Bytes Out: 8006926335
