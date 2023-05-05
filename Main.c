#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include <ctype.h>

typedef struct {
    char pertanyaan[500];
    char jawaban[50];
    int level;
} pertanyaan;

int main() {

   int input[0];
   while (1) {                                                                                                                                             

    printf("\nTekan angka manapun untuk melanjutkan permainan, atau huruf 'n' untuk membatalkan dari permainan: \n");
        scanf("%s", input);
        if (isdigit(input[0])) { 
        } else if (input[0] == 'n' || input[0] == 'N') { // menanyakan apakah pengguna yakin ingin keluar dari permainan
            printf("\nApakah kamu yakin ingin keluar dari permainan? (Y/N): ");
            scanf("%s", input);
            if (input[0] == 'y' || input[0] == 'Y') {
                return 0; // keluar dari permainan
            }
        } else {
            return 0;
        }

    pertanyaan pertanyaans[15];
    strcpy(pertanyaans[0].pertanyaan, "Siapa Pemenang piala dunia 2024?");
    strcpy(pertanyaans[0].jawaban, "A");
    pertanyaans[0].level = 1;

    strcpy(pertanyaans[1].pertanyaan, "apa ibu kota dari india?");
    strcpy(pertanyaans[1].jawaban, "B");
    pertanyaans[1].level = 2;

    strcpy(pertanyaans[2].pertanyaan, "Apa yang bisa dilihat sekali dalam satu menit, dua kali dalam satu momen, dan tidak terlihat dalam seribu tahun?");
    strcpy(pertanyaans[2].jawaban, "D");
    pertanyaans[2].level = 3;

    strcpy(pertanyaans[3].pertanyaan, "Apa nama danau terbesar di dunia?");
    strcpy(pertanyaans[3].jawaban, "C");
    pertanyaans[3].level = 4;

    strcpy(pertanyaans[4].pertanyaan, "Kota mana yang berjulik 'Crossroads of the pacific' dan 'The Big pineapple'?");
    strcpy(pertanyaans[4].jawaban, "D");
    pertanyaans[4].level = 5;
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
        {
        regis reg;

        char usernameInput[10], passwordInput[10];
        strcpy(usernameInput, argc[1]);
        strcpy(passwordInput, argc[2]);
        
        FILE *fpr = fopen("database/login.bin", "rb");

        fread(reg.username, sizeof(char), sizeof(reg.username)/sizeof(char), fpr);

        fclose(fpr);

        char *string[3];
        char username[20], password[20];
        int ctrl = 0;

        string[0] = strtok(reg.username, "#");
        while (string[ctrl++] != NULL){
            string[ctrl] = strtok(NULL, "#");
        }

        strcpy(username, string[0]);
        strcpy(password, string[1]);

        if( (strcmp(usernameInput, username) == 0 ) && (strcmp(passwordInput, password) == 0)) {
            printf("Selamat anda berhasil login !\n");
        } 
        else{
            printf("Anda Gagal login !\n");
    }
    }
    return 0;
}
