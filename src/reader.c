#include <stdlib.h>
#include <stdio.h>
#include "reader.h"
#include "common.h"

void read_metadata(char* PATH) {

    //File Handling
    FILE *fp = fopen(PATH, "r");
    if (fp == NULL) {
        perror("fopen");
        return ;
    }

    //Skip 10 bytes of Header
    fseek(fp, 10, SEEK_SET);

    //Read 4 bytes of tag
    char tag[5];
    fread(tag, 4, 1, fp);
    tag[4]='\0';
    printf("Tag : %s\n", tag);

    //Read 4 bytes of size
    int be_size, le_size;
    fread(&be_size, 4, 1, fp); //Size is in Big Endian Format
    le_size = to_le(be_size);
    printf("Size : %d\n", le_size);

    //Skip 2 bytes of flag + 1 byte of frame data
    fseek(fp, 3, SEEK_CUR);
    char *buf = malloc((le_size-1) * sizeof(char));
    fread(buf, le_size-1, 1, fp);
    buf[le_size-1]='\0';
    printf("Tile/Song Name: %s\n", buf);

    //Read 4 bytes of tag
    fread(tag, 4, 1, fp);
    tag[4]='\0';
    printf("Tag : %s\n", tag);

    //Read 4 bytes of size
    fread(&be_size, 4, 1, fp); //Size is in Big Endian Format
    le_size = to_le(be_size);
    printf("Size : %d\n", le_size);

    //Skip 2 bytes of flag + 1 byte of frame data
    fseek(fp, 3, SEEK_CUR);
    fread(buf, le_size-1, 1, fp);
    buf[le_size-1]='\0';
    printf("Artist Name: %s\n", buf);

    //Read 4 bytes of tag
    fread(tag, 4, 1, fp);
    tag[4]='\0';
    printf("Tag : %s\n", tag);

    //Read 4 bytes of size
    fread(&be_size, 4, 1, fp); //Size is in Big Endian Format
    le_size = to_le(be_size);
    printf("Size : %d\n", le_size);

    //Skip 2 bytes of flag + 1 byte of frame data
    fseek(fp, 3, SEEK_CUR);
    fread(buf, le_size-1, 1, fp);
    buf[le_size-1]='\0';
    printf("Album Name: %s\n", buf);

    //Read 4 bytes of tag
    fread(tag, 4, 1, fp);
    tag[4]='\0';
    printf("Tag : %s\n", tag);

    //Read 4 bytes of size
    fread(&be_size, 4, 1, fp); //Size is in Big Endian Format
    le_size = to_le(be_size);
    printf("Size : %d\n", le_size);

    //Skip 2 bytes of flag + 1 byte of frame data
    fseek(fp, 3, SEEK_CUR);
    fread(buf, le_size-1, 1, fp);
    buf[le_size-1]='\0';
    printf("Year: %s\n", buf);

    //Read 4 bytes of tag
    fread(tag, 4, 1, fp);
    tag[4]='\0';
    printf("Tag : %s\n", tag);

    //Read 4 bytes of size
    fread(&be_size, 4, 1, fp); //Size is in Big Endian Format
    le_size = to_le(be_size);
    printf("Size : %d\n", le_size);

    //Skip 2 bytes of flag + 1 byte of frame data
    fseek(fp, 3, SEEK_CUR);
    fread(buf, le_size-1, 1, fp);
    buf[le_size-1]='\0';
    printf("Content Type: %s\n", buf);

    //Read 4 bytes of tag
    fread(tag, 4, 1, fp);
    tag[4]='\0';
    printf("Tag : %s\n", tag);

    //Read 4 bytes of size
    fread(&be_size, 4, 1, fp); //Size is in Big Endian Format
    le_size = to_le(be_size);
    printf("Size : %d\n", le_size);

    //Skip 2 bytes of flag + 1 byte of frame data
    fseek(fp, 3, SEEK_CUR);
    fread(buf, le_size-1, 1, fp);
    buf[le_size-1]='\0';
    printf("Composer: %s\n", buf);
}


