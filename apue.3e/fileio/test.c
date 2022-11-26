#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int val;
    if (argc != 2) {
        err_quit("usage: pff <descriptor>");
    }
    // get file flag
    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0) {
        err_sys("err: fcntl for file descriptor: %d", atoi(argv[1]));
    }

    // print access mode
    switch (val & O_ACCMODE) {
        case O_RDONLY:
            printf("read only\n");
            break;
        case O_WRONLY:
            printf("write only\n");
            break;
        case O_RDWR:
            printf("read & write\n");
            break;
        default:
            err_dump("unknown access mode");
    }
    // print others file flags
    if (val & O_APPEND)
        printf("Append...\n");

    if (val & O_NONBLOCK)
        printf("NonBlocking...\n");

    if (val & O_SYNC)
        printf("sychronous writes\n");
}
