#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_PALAVRA 30
#define MAX_TENTATIVAS 6
#define MAX_LETRAS_USADAS 26

#define COR_VERDE  "\033[1;32m"
#define COR_VERMELHA "\033[1;31m"
#define COR_RESET  "\033[0m"

void limpar_terminal() {
    printf("\033[H\033[J");
}

int letra_ja_usada(char letra, char usadas[], size_t usadas_len) {
    for (size_t i = 0; i < usadas_len; i++) {
        if (usadas[i] == letra) return 1;
    }
    return 0;
}

void mostrar_estado(char exibicao[], char usadas[], int tentativas) {
    printf("Palavra: %s\n", exibicao);
    printf("Tentativas restantes: %d\n", tentativas);
    printf("Letras usadas: ");
    for (size_t i = 0; i < strlen(usadas); i++) {
        printf("%c d", usadas[i]);
    }
    printf("\n\n");
}

int main() {
    char palavra[TAM_PALAVRA];
    char exibicao[TAM_PALAVRA];
    char letrasUsadas[MAX_LETRAS_USADAS + 1] = {0};
    int tentativas = MAX_TENTATIVAS;
    int acertos = 0;
    size_t letras_usadas_count = 0;

    limpar_terminal();
    printf("Digite a palavra a ser adivinhada: ");
    scanf("%s", palavra);
    limpar_terminal();

    size_t len_palavra = strlen(palavra);

    for (size_t i = 0; i < len_palavra; i++) {
        exibicao[i] = '_';
    }
    exibicao[len_palavra] = '\0';

    while (tentativas > 0) {
        mostrar_estado(exibicao, letrasUsadas, tentativas);

        char letra;
        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        // Verifica se letra já foi usada
        if (letra_ja_usada(letra, letrasUsadas, letras_usadas_count)) {
            printf("Letra já usada. Tente outra.\n");
            continue;
        }

        if (letras_usadas_count < MAX_LETRAS_USADAS) {
            letrasUsadas[letras_usadas_count++] = letra;
            letrasUsadas[letras_usadas_count] = '\0';
        }

        int acertou = 0;
        for (size_t i = 0; i < len_palavra; i++) {
            if (palavra[i] == letra && exibicao[i] == '_') {
                exibicao[i] = letra;
                acertos++;
                acertou = 1;
            }
        }

        if (!acertou) {
            tentativas--;
            printf("Letra errada!\n");
        } else {
            printf("Boa!\n");
        }

        if (strcmp(palavra, exibicao) == 0) {
            printf(COR_VERDE "\n[V] Parabéns! Você adivinhou a palavra: %s\n" COR_RESET, palavra);
            break;
        }
    }

    if (tentativas == 0) {
        printf(COR_VERMELHA "\n[X] Você perdeu! A palavra era: %s\n" COR_RESET, palavra);
    }

    return 0;
}
