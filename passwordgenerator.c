#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SENHA 20

void gerarSenha(char senha[], int tamanho) {
    const char caracteres[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
    int numCaracteres = sizeof(caracteres) - 1;

    srand(time(NULL));

    for (int i = 0; i < tamanho; i++) {
        int indice = rand() % numCaracteres;
        senha[i] = caracteres[indice];
    }

    senha[tamanho] = '\0';
}

int main() {
    int tamanhoSenha;
    char senha[MAX_SENHA + 1];

    printf("Programa Gerador de Senhas\n");
    printf("-------------------------\n");

    printf("Digite o tamanho da senha desejada: ");
    scanf("%d", &tamanhoSenha);

    if (tamanhoSenha > 0 && tamanhoSenha <= MAX_SENHA) {
        gerarSenha(senha, tamanhoSenha);
        printf("Senha gerada: %s\n", senha);
    } else {
        printf("Tamanho de senha inválido!\n");
    }

    return 0;
}
