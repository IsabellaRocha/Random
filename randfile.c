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

int main() {
    int arr[10];
    printf("Generating random numbers:\n");
    int idx;
    for(idx = 0; idx < 10, idx++) {
        arr[idx] = randNum();
        printf("\trandom %d: %d\n", idx, arr[idx]);
    }
    
    printf("\nWriting numbers to file...\n\n");
    int fd = open("rand", O_CREAT | ORDWR, 0744); //Set permissions for user to rwx but for group and others to just r
    if (fd == -1) {
        printf("ErrorL %s\n", strerror(errno));
    }
    int n;
    int error = write(fd, &n, 4); //Reads 4 bytes into n
    if (error == -1) {
        printf("ErrorL %s\n", strerror(errno));

    printf("Reading numbers to file...\n\n");

    printf("Verification that written values were the same:\n");
}
