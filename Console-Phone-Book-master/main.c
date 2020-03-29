
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
//Using a constant for an array has problems with older compilers,
//so defining a global constant with #define is the only solution.
#define TOTAL_OPTIONS 5

struct record
{
    /* data */
    char name[50];
    unsigned long long number;
    unsigned long long alternate_number;
    char email[50];
    char address[300];
}contact_list;

FILE *fp,*ft;

void clear(){
    // printf("\e[1;1H\e[2J"); //Regex to clear the screen almost instantly!
    system("cls"); // For Windows only. "clear" for Linux and macOS.
}

void startOptions(){
    unsigned int option;
    char options[TOTAL_OPTIONS][100] = {
        "Show all records",
        "Insert a new record",
        "Delete a record",
        "Find a specific record",
        "Exit"
    };

    printf("Choose one of the following options:\n\n");
    for(int i = 1; i <= TOTAL_OPTIONS; i++){
        printf("%d. %s\n", i, options[i - 1]);
    }

    printf("\nOption number: ");
    int intSuccess = scanf("%d", &option);//Return 1 if 1 integer successfully read. If anything else, then it won't provide 1

    if(intSuccess == 1 && option < TOTAL_OPTIONS && option > 0){
        switch(option){
            case 1:
                list_contacts();
                break;
            case 2:
                add_contact();
                break;
            default:
                clear();
                startOptions();
                break;
        }
    }
    else{
        clear();
        startOptions();
    }

}

void add_contact(){
    system("cls");
    fp=fopen("contacts","ab+");

        fflush(stdin);
        printf("Input name:");
        scanf("%s",&contact_list.name);

        fflush(stdin);
        printf("Input number:");
        scanf("%llu",&contact_list.number);

        fflush(stdin);
        printf("Input email:");
        scanf("%s",&contact_list.email);

        fflush(stdin);
        printf("Input address:");
        scanf("%s]",&contact_list.address);

        fwrite(&contact_list,sizeof(contact_list),1,fp);

        fclose(fp);

}

void list_contacts(){
    int id_num=1;
    fp=fopen("contacts","rb");
            printf("records:\n");
    while(fread(&contact_list,sizeof(contact_list),1,fp)==1){
        printf("%d.%s   %s   %s   %llu\n",id_num++,contact_list.name,contact_list.email,contact_list.address,contact_list.number);
    }
    fclose(fp);
}

int main(){

    printf("\n\tPhone Book in C - B2 1911089 1911093 1911109\n");
    startOptions();

    // struct record records[500];
    // records[0].number = 0123456789;
    // printf("%llu \n", records[0].number);

    getch();
    return 0;
}
