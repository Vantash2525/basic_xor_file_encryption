#include <stdio.h>
#include <string.h>

void encrypt(const char *path, const char *key) {
    FILE *fp = fopen(path, "r+b"); 
    if (fp == NULL) {
        perror("Error opening file"
        return;
    }

    int key_len = strlen(key);
    int ch;
    int i = 0;

    while ((ch = fgetc(fp)) != EOF) {
        
        ch ^= key[i % key_len];

       
        fseek(fp, -1, SEEK_CUR);
        fputc(ch, fp);
        fflush(fp); 

        i++;
    }

    fclose(fp);
    printf("Done.\n");
}

int main() {
    char path[260];
    char key[100];

    printf("Enter file path: ");
    scanf("%s", path);
    printf("Enter key: ");
    scanf("%s", key);

    encrypt(path, key);

    return 0;
}
