#include <stdio.h>


struct date{
    int dia, mes, any;
};

struct file{
    char name[50];
    char lastname1[50];
    char lastname2[50];
    char address[50];
    int phone;
    struct date birth;
};

int main(void){
    int option;
    char fileName[100];

    printf("Welcome to Personal Agenda!\n");
    printf("Do you want to work with an existing agenda or create a new one?\n");
    printf("1. New Agenda\n2. Existing Agenda\nOption: ");
    scanf("%i", &option);

    if(option == 1){
        printf("Enter the name of the new agenda: ");
        scanf("%s", fileName);
        save(fileName);
    }else if(option == 2){
        printf("Enter the file name of the existing agenda: ");
        scanf("%s", fileName);
        printf("What do you want to do with this agenda?\n");
        printf("1. Read records\n2. Insert new records\nOption: ");
        scanf("%i", &option);

        if(option == 1){
            read(fileName);
        }else if(option == 2){
            save(fileName);
            read(fileName);
        }
    }
    return 0;
}

void save(char *fileName){
    FILE *file;
    struct file person;

    file = fopen(fileName, "a");
    if(file == NULL){

    printf("Error opening file.\n");
    }

    int numRegistries;
    printf("\n How many records do you want to enter? ");
    scanf("%i",&numRegistries);
    for(int i=0;i<numRegistries;i++){
        printf("\nEnter the details of the person %d:\n", i + 1);
        printf("Name: ");
        scanf("%s %s %s", person.name, person.lastname1, person.lastname2);
        printf("Address: ");
        scanf("%s", person.address);
        printf("Phone: ");
        scanf("%lld", &person.phone);
        printf("Date of birth (day month year): ");
        scanf("%d %d %d", &person.birth.day,
              &person.birth.month, &person.birth.year);

        fprintf(file, "%s %s %s %s %i %i %i %i\n",
                person.name, person.surname1, person.surname2,
                person.address, person.telephone,
                person.birth.day, person.birth.month,
                person.birth.year);
    }

    fclose(file);
}
    }
}
