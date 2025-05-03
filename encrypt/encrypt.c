#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void encrypt(char *path,char *key){

FILE *fp;
FILE *ofp;
char data;
char encrypted_data;
unsigned char output_data;
int key_len=strlen(key);

fp = fopen(path,"rb");
fseek(fp,0,SEEK_END);
long file_size = ftell(fp);
rewind(fp);

char *buffer = malloc(file_size);
fread(buffer,1,file_size,fp);
int keylen=strlen(key);
for(long i=0;i<file_size;i++){
	buffer[i]=buffer[i]^key[i%keylen];
}
fclose(fp);
ofp=fopen(path,"wb");
fwrite(buffer,1,file_size,ofp);

free(buffer);
fclose(ofp);
}


int main(){
	char path[100];
	char key[20];
	printf("enter a file path:");
	scanf("%s",path);
	printf("enter password");
	scanf("%s",key);
	encrypt(path,key);
	return 0;
}
