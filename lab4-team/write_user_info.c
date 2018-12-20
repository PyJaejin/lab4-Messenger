#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _user_info {
    char id[30];
    char pw[30];
} user_info;

int main(int argc, char **argv) {
    strcpy(user_info.id, argv[1]);
    strcpy(user_info.pw, argv[2]);

    FILE *fp = fopen("user_info.bin", "ab");
    fwrite(&user_info, sizeof(user_info), 1, fp);

    fclose(fp);
}
