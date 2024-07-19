#include <stdio.h>
#include <string.h>

#define TAMANHO_ALFABETO 256 // Tamanho do alfabeto (ASCII)

int maximo(int a, int b) {
    return (a > b) ? a : b;
}


void preprocessarCaractereRuim(char *padrao, int tamPadrao, int tabelaCaractereRuim[TAMANHO_ALFABETO]) {
    int i;

    // Inicializa todas as ocorrências como -1
    for (i = 0; i < TAMANHO_ALFABETO; i++) {
        tabelaCaractereRuim[i] = -1;
    }

    // Preenche a última ocorrência de um caractere
    for (i = 0; i < tamPadrao; i++) {
        tabelaCaractereRuim[(int) padrao[i]] = i;
    }
}

// Função para realizar a busca utilizando o algoritmo Boyer-Moore
void buscaBoyerMoore(char *texto, char *padrao) {
    int tamTexto = strlen(texto);
    int tamPadrao = strlen(padrao);

    int tabelaCaractereRuim[TAMANHO_ALFABETO];

    // Preprocessa a regra de caractere ruim
    preprocessarCaractereRuim(padrao, tamPadrao, tabelaCaractereRuim);

    int deslocamento = 0; // Deslocamento da posição da string principal

    while (deslocamento <= (tamTexto - tamPadrao)) {
        int j = tamPadrao - 1;

        // Continua reduzindo j enquanto os caracteres de padrao e texto coincidem
        while (j >= 0 && padrao[j] == texto[deslocamento + j]) {
            j--;
        }

        // Se o padrão estiver presente na string principal no deslocamento atual
        if (j < 0) {
            printf("Padrão encontrado na posição %d\n", deslocamento);

            // Move o padrão de modo que o próximo caractere no texto se alinhe
            // com a última ocorrência do mesmo no padrão
            deslocamento += (deslocamento + tamPadrao < tamTexto) ? tamPadrao - tabelaCaractereRuim[texto[deslocamento + tamPadrao]] : 1;
        } else {
            // Move o padrão de modo que o caractere ruim no texto se alinhe
            // com a última ocorrência do mesmo no padrão
            deslocamento += maximo(1, j - tabelaCaractereRuim[texto[deslocamento + j]]);
        }
    }
}

int main() {
    char texto[] = "abacaabadcabacabaabb";
    char padrao[] = "bad";

    buscaBoyerMoore(texto, padrao);

    return 0;
}
