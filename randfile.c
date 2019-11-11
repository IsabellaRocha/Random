#include "randfile.h"

int randNum() {
    int fd = open("/dev/random", O_RDONLY);
    if (fd == -1) {
        printf("ErrorL %s\n", strerror(errno));
    }
    int n;
    int error = read(fd, &n, 4); //Reads 4 bytes into n
    if (error == -1) {
        printf("ErrorL %s\n", strerror(errno));
    }
    return n;
}
