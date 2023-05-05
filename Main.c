#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct registration
{
    char nama[20];
    char pekerjaan[20];
    char username[20];
    char password[20];
} regis;


int main(int manyArgc, char *argc[])
{
    if(manyArgc == 1){
        regis reg;
        printf("\n");
        printf("*************************************************************\n");
        printf("*****\t\tWellcome to our game quizz\t\t*****\n");
        printf("Silahkan registrasi terlebih dahulu sebelum memulai game quiz <3\n");
        printf("Nama\t\t: "); gets(reg.nama);
        printf("Pekerjaan\t: "); gets(reg.pekerjaan);
        printf("\n");
        printf("\tLets create your account <3\n");
        printf("Username\t: "); gets(reg.username);
        printf("Password\t: "); gets(reg.password);
        printf("\nCreate account success !\n");
        printf("Lets lgoin and enjoy the game <3 !\n");
        printf("Note cara login : ./FileProgramUtama Username Password (harap perhatikan huruf besar dan kecil ya <3!)\n\n");
        
        FILE *fpw = fopen("database/login.bin", "wb");

        char insl[3] = "#";
        strcat(reg.username, insl);
        strcat(reg.username, reg.password);

        fwrite(reg.username, sizeof(char), sizeof(reg.username)/sizeof(char), fpw);

        fclose(fpw);
    }

    if(manyArgc == 2){
        printf("\nFail to login !\n");
        printf("Anda belum memasukkan password !\n");
        printf("Note cara login : ./FileProgramUtama Username Password (harap perhatikan huruf besar dan kecil ya <3!)\n\n");
    }

    if(manyArgc == 3)
    return 0;
}
