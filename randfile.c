#include "randfile.h"

int randNum() {
    int fd = open("/dev/random", O_RDONLY);
    if (fd == -1) {
        printf("Error %s\n", strerror(errno));
    }
    int n;
    int error = read(fd, &n, 4); //Reads 4 bytes into n
    if (error == -1) {
        printf("Error %s\n", strerror(errno));
    }
    return n;
}

int main() {
    int arr[10];
    printf("Generating random numbers:\n");
    int idx;
    for(idx = 0; idx < 10; idx++) {
        arr[idx] = randNum();
        printf("\trandom %d: %d\n", idx, arr[idx]);
    }

    printf("\nWriting numbers to file...\n\n");
    int fd = open("rand", O_CREAT | O_RDWR, 0744); //Set permissions for user to rwx but for group and others to just r
    if (fd == -1) {
        printf("Error %s\n", strerror(errno));
    }
    int error = write(fd, arr, 40); //Reads 4 bytes into n
    if (error == -1) {
        printf("Error %s\n", strerror(errno));
    }
    close(fd);

    printf("Reading numbers to file...\n\n");
    int arr2[10];
    int file = open("rand", O_RDONLY);
    if (file == -1) {
        printf("Error %s\n", strerror(errno));
    }
    int err = read(file, arr2, 40);
    if (err == -1) {
        printf("Error %s\n", strerror(errno));
    }
    close(file);

    printf("Verification that written values were the same:\n");
    int i;
    for(i = 0; i < 10; i++) {
        printf("\trandom %d: %d\n", i, arr2[i]);
    }
    return 0;
}
