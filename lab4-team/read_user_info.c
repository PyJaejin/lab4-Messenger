#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _user_info {
    char id[30];
    char pw[30];
} user_info;

int main() {
    FILE *fp = fopen("user_info.bin", "rb");
    while(!feof(fp)) {
        if(0 == (fread(&user_info, sizeof(user_info), 1, fp))) break;
        printf("ID : %s\nPW : %s\n", user_info.id, user_info.pw);
    }
    fclose(fp);
}
