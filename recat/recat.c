#include <stdio.h>
#include <stdlib.h>

void reverse(char* buffer, int bufferLen){
    int i;
    for (i = 0; i< bufferLen / 2; i++){
        char temp = buffer[i];
        buffer[i] = buffer[bufferLen - i - 1];
        buffer[bufferLen - i - 1] = temp;
    }
}

int main (int argc, char* argv[]){
    if (argc != 1){

        FILE *fileptr;
        char *buffer;
        long fileLen;

        fileptr = fopen(argv[1], "rb");
        fseek(fileptr, 0, SEEK_END);
        fileLen = ftell(fileptr);
        rewind(fileptr);

        buffer = (char *)malloc(fileLen * sizeof(char));
        fread(buffer, fileLen, 1, fileptr);
        fclose(fileptr);

        reverse(buffer, fileLen);

        printf("%.*s\n", fileLen, buffer);

    }else {
        printf("You need to supply a filename\n");
    }
    exit(0);
}