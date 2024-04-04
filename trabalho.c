#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_USERS 10
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PASSWORD_LENGTH 20

//grupo: Pedro Augusto, Adriel Silva, Cleyton Melo


typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char senha[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int userCount = 0;

//globais
char name[MAX_NAME_LENGTH];
char email[MAX_EMAIL_LENGTH];
char senha[MAX_PASSWORD_LENGTH];

//função para adicionar usuarios
void addUser () {

    if (userCount < MAX_USERS) {
        strcpy(users[userCount].name, name);
        strcpy(users[userCount].email, email);
        strcpy(users[userCount].senha, senha);
        userCount++;
        printf("Usuario cadastrado com sucesso!\n");
    } 
    if (userCount >= MAX_USERS) {
        printf("Limite de usuarios atingido.\n");
    }
};

//vizualiza users
void viewUsers() {
    printf("Lista de usuarios:\n");
    for (int i = 0; i < userCount; i++) {
        printf("Nome: %s, Email: %s, Senha: %s\n", users[i].name, users[i].email, users[i].senha);
    }
}

//gera senha aleatoria baseada na array
void generateRandomPassword() {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
    srand(time(NULL));
    for (int i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        senha[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    //marca o final da arrey
    senha[MAX_PASSWORD_LENGTH] = '\0';
}

//edita
void editUser(char *email) {
    int found = 0;
    int opt;
    for (int i = 0; i < userCount; i++) {
        //strcmp compara duas strings
        if (strcmp(users[i].email, email) == 0) {
            printf("digite o novo nome para %s: ", email);
            scanf("%s", users[i].name);

            //editar senha
            printf("\nEditar nova senha? 1 - Sim, 2 - Nao: \n");
            scanf("%d", &opt);
            if(opt == 1){
                generateRandomPassword();
                strcpy(users[i].senha, senha);
            }

            printf("user editado com sucesso\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("usuario nao encontrado!\n");
    }
}


int main()  {
    int option;
    
    do
    {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Cadastrar user\n");
        printf("2 - Visualizar usuario\n");
        printf("3 - editar user\n");
        printf("4 - sair\n");
        scanf("%d", &option);

        switch (option) {

        case 1:
            printf("\nDigite o nome do usuario: ");
            scanf("%s", name);
            printf("Digite o email do usuario: ");
            scanf("%s", email);
            generateRandomPassword();
            addUser();
            
            break;

        case 2:
            viewUsers();

            break;

        case 3:
            printf("\nDigite o email do usuário que deseja editar: ");
            scanf("%s", email);
            editUser(email);

            break;
        
        case 4:
            printf("\ntchau!\n");

            break;

        default:
            printf("\nOpcao invalida. Tente de novo.\n");
        
        }

    } while (option != 4);
    

    return 0;
}