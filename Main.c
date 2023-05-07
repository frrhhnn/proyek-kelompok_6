#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include <ctype.h>

typedef struct 
{
    char pertanyaan[500];
    char jawaban[50];
    int level;
} pertanyaan;
        
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
            printf("*****************************\n");
            printf("Selamat anda berhasil login !\n");
            printf("*****************************\n");
        }  else {
                printf("Anda Gagal login !\n");
                printf("Perhatikan kembali username dan passsword yang anda mmasukkan !\n\n");
                return 0;
         }
            int input[0];
            char input1;
            int input2;
            while (1) { 
            printf("                                          ,--,                                                                                                           \n");
            printf("                                       ,---.'|       ,----..                                                ,--.                                         \n");
            printf("                                       |   | :      /   /   /     ,---,           ,---,       ,---,       ,--.'|  ,----..                                \n");
            printf("               ,--.  ,--.  ,--.        :   : |     /   .     :   '  .' /        .'  .' `/  ,`--.' |   ,--,:  : | /   /   /          .--,  .--,  .--,     \n");
            printf("              /  /| /  /| /  /|        |   ' :    .   /   ;.  / /  ;    '.    ,---.'     / |   :  :,`--.'`|  ' :|   :     :         |/  / |/  / |/  /    \n");
            printf("             '  / ''  / ''  / '        ;   ; '   .   ;   /  ` ;:  :       /   |   |  .`/  |:   |  '|   :  :  | |.   |  ;. /         ` /  `` /  `` /  `   \n");
            printf("            /  / //  / //  / /         '   | |__ ;   |  ; / ; |:  |   //   /  :   : |  '  ||   :  |:   |   / | :.   ; /--`           / /  // /  // /  /  \n");
            printf("           /  / ,/  / ,/  / ,          |   | :.'||   :  | ; | '|  :  ' ;.   : |   ' '  ;  :'   '  ;|   : '  '; |;   | ;  __           , /  // /  /, /  / \n");
            printf("           / '/ // '/ // '/ /          :   :    ;.   |  ' ' ' :|  |  ;/  /   /'   | ;  .  ||   |  |'   ' ;.    ;|   : |.' .'          / /` // /` // /` / \n");
            printf("            /  / '/  / '/  / '         |   |  ./ '   ;  / /   |'  :  | /  / ,'|   | :  |  ''   :  ;|   | | /   |.   | '_.' :         ` /  /` /  /` /  /  \n");
            printf("             /  . |/  . |/  . |        ;   : ;    /   /  ',  / |  |  '  '--'  '   : | /  ; |   |  ''   : |  ; .''   ; : /  |        | .  /| .  /| .  /   \n");
            printf("              /__/ /__/. /__/.         |   ,/      ;   :    /  |  :  :        |   | '` ,/  '   :  ||   | '`--'  '   | '/  .'        ./__/ ./__/ ./__/    \n");
            printf("                                       '---'        /    .'    |  | ,'        ;   :  .'    ;   |.' '   : |      |   :    /                               \n");
            printf("                                                     `---`     `--''          |   ,.'      '---'   ;   |.'      |_ _| .'                                 \n");                                                                                                                                            

            printf("\nTekan angka manapun untuk melanjutkan permainan, atau huruf 'n' untuk membatalkan dari permainan : ");
            scanf("%s",&input1);
        
            if (isdigit(input1)) { 
            } else if (input1 == 'n' || input1 == 'N') { // menanyakan apakah pengguna yakin ingin keluar dari permainan
                printf("\nApakah kamu yakin ingin keluar dari permainan? (Y/N) : ");
                scanf("%s", input);
                if (input[0] == 'y' || input[0] == 'Y') {
                    return 0; //keluar dari permainan
                }
            } else {
                return 0;
            }

            pertanyaan pertanyaans[15];
            strcpy(pertanyaans[0].pertanyaan, "Siapa Pemenang piala dunia 2024 ?");
            strcpy(pertanyaans[0].jawaban, "A");
            pertanyaans[0].level = 1;

            strcpy(pertanyaans[1].pertanyaan, "apa ibu kota dari india ?");
            strcpy(pertanyaans[1].jawaban, "B");
            pertanyaans[1].level = 2;

            strcpy(pertanyaans[2].pertanyaan, "Apa yang bisa dilihat sekali dalam satu menit, dua kali dalam satu momen, dan tidak terlihat dalam seribu tahun ?");
            strcpy(pertanyaans[2].jawaban, "D");
            pertanyaans[2].level = 3;

            strcpy(pertanyaans[3].pertanyaan, "Apa nama danau terbesar di dunia ?");
            strcpy(pertanyaans[3].jawaban, "C");
            pertanyaans[3].level = 4;

            strcpy(pertanyaans[4].pertanyaan, "Kota mana yang berjulik 'Crossroads of the pacific' dan 'The Big pineapple' ?");
            strcpy(pertanyaans[4].jawaban, "D");
            pertanyaans[4].level = 5;
    
            printf("********************************************************************************\n");

            printf("*\t #  # # ### ###     # # ### #    #  # # ##   #  # #     # # ###        *\n*\t# # # #  #    #     # # #   #   # # ### # # # # # #     # #  #         *\n*\t# # # #  #   #      ##  ##  #   # # ### ##  # # ##      # #  #         *\n*\t ## # #  #  #       # # #   #   # # # # #   # # # #     # #  #         *\n*\t  # ### ### ###     # # ### ###  #  # # #    #  # #      #  ###        *\n*");
    
            printf("*******************************************************************************\n");

            //inisialisasi variable game
            int level = 1;
            int score = 0;
            int batas_level = 5 ;
            int pertanyaan_saat_ini = 0;
            char jawaban[50];
            int pilihan;
   
            // start game
            printf("\n\t\t    SELAMAT DATANG DI QUIZZ KELOMPOK VI  \n");
            printf("****************************************************************************************\n");
            printf("Kamu akan disediakan 5 pertanyaan dengan tingkat level yang berbeda,\n");
            printf("dengan meningkatnya tingkat kesulitan saat Anda maju.\n");
            printf("****************************************************************************************\n");
            printf("Setiap jawaban yang benar akan memberi Anda poin sesuai dengan tingkat kesulitan soalnya\n");
            printf("****************************************************************************************\n");
            printf("Selamat Bermain!!!!!\n");
            printf("****************************************************************************************\n");

            printf("Masukkan angka 1 untuk masuk ke permainan atau yang lain untuk membatalkan permainan :");
            scanf("%d", &input2);
            printf("********************************************************************************************\n");
            
            if (input2 == 1) {
                printf("\n");
                printf("Permainan dilanjutkan.\n");
                printf("********************************************************************************************\n\n");
            } else {
                printf("\n");
                printf("Permainan Anda dibatalkan....\n");
                printf("********************************************************************************************\n\n");
                return 0;
            }  
            for (int i = 0; i <= batas_level; i++) {
                printf("\nLevel %d: %s\n", level, pertanyaans[pertanyaan_saat_ini].pertanyaan);

            if(level == 1)
            {
                printf("A) Argentina \n");
                printf("B) Prancis \n");
                printf("C) Arab Saudi\n");
                printf("D) Indonesia\n");
                printf("jawaban Anda : ");
            } else if (level == 2)
            {
                printf("A) Mumbai \n");
                printf("B) New Delhi \n");
                printf("C) Maladew \n");
                printf("D) Ankara\n");
                printf("jawaban Anda : ");
            } else if (level == 3)
            {
                printf("A) Huruf O \n");
                printf("B) angka 1\n");
                printf("C) huruf B \n");
                printf("D) Huruf M\n");
                printf("jawaban Anda : ");
            } else if(level == 4)
            {
                printf("A) Danau Toba \n");
                printf("B) Danau Baikal \n");
                printf("C) Danau Kaspia \n");
                printf("D) Danau Victoria\n");
                printf("jawaban Anda : ");
            } else if(level == 5)
            {
                printf("A) Rusia \n");
                printf("B) Indonesia 1 \n");
                printf("C) China \n");
                printf("D) New York\n");
                printf("jawaban Anda : ");
            }

            scanf("%s", jawaban);
            jawaban[0] = toupper(jawaban[0]);

            if (jawaban[0] == 'A' || jawaban[0] == 'B' || jawaban[0] == 'C' || jawaban[0] == 'D') {
            } else {
                printf("Jawaban yang anda masukkan tidak sesuai opsi jawaban.\n");
                printf("********************************************************************************\n");
                printf("Harap memasukkan jawaban sesuai dengan opsi jawaban ('A','B','C','D')\n");
                printf("********************************************************************************\n");
                continue; 
            }
        
            if (strcmp(jawaban, pertanyaans[pertanyaan_saat_ini].jawaban) == 0) {
                printf("Benar <3! kamu mendapatkan $%d nilai.\n", level * 100);
                score += level * 100;
                level++;
                pertanyaan_saat_ini++;
     
                if (pertanyaan_saat_ini == 5){
                    printf("SELAMATT!!!!!! Anda Memenangkan Permainan dan Mendapatkan total $%d!\n", score);
                    printf("********************************************************************************\n");
                    printf("Terima kasih telah bermain. Sampai jumpa lagi!\n");
                    printf("********************************************************************************\n");
                    return 0;
                }
            
                printf("Apakah Anda ingin melanjutkan ke pertanyaan berikutnya? (y/n) : ");
                scanf(" %c", &input1);
                printf("********************************************************************************\n");
                
                if (input1 == 'y') {
                    printf("\n");
                    printf("Baiklah lanjut ke pertanyaan berikutnya..... \n");
                    printf("********************************************************************************\n");
                } else if (input1 == 'n') {
                    printf("\n");
                    printf("Silakan istirahat sebentar dan kembali lagi nanti.\n");
                    printf("********************************************************************************\n");
                    break;   
                } else {
                    printf("MAAF Input yang Anda berikan tidak valid!\n");
                    printf("Harap maukkan 'y' atau 'n' : ");
                    scanf(" %c", &input1);
                    printf("********************************************************************************\n");
                if(input1 == 'y'){
                    printf("\n");
                    printf("Baiklah, berikutnya pertanyaan...\n");
                    printf("********************************************************************************\n");
                } else if (input1 == 'n') {
                    printf("\n");
                    printf("Silakan istirahat sebentar dan kembali lagi nanti.\n");
                    printf("********************************************************************************\n");
                    break;
                } else {
                    printf("\n");
                    printf("Anda salah menginput sebanyak dua kali silahkan coba lagi nanti, terima kasih...\n");
                    printf("********************************************************************************\n");
                    return 0;
                    }
                }   
            } else {
                printf("Maaf, itu tidak benar. Jawaban yang benar adalah %s.\n", pertanyaans[pertanyaan_saat_ini].jawaban);
                printf("********************************************************************************\n");
                printf("Anda mendapatkan total $%d. Semoga lain kali lebih beruntung!\n", score);
                printf("********************************************************************************\n");
                break;
            }
        }
    } 
            
    return 0;
    }
}
