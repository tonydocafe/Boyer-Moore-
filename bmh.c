#include <stdio.h>
#include <string.h>

#define TAMANHO_ALFABETO 256
#define TAMANHO_MAXIMO 1024

// Função para criar a tabela de saltos
void preprocessamentoDeslocamentoMauCaractere(const char *padrao, int m, int deslocamentoMauCaractere[]) {
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        deslocamentoMauCaractere[i] = m; // Inicializa todos os saltos com o comprimento do padrão
    }
    for (int i = 0; i < m - 1; i++) {
        deslocamentoMauCaractere[(unsigned char)padrao[i]] = m - i - 1; // Calcula a distância para cada caractere no padrão
    }
}

// Função para realizar a busca usando o algoritmo BMH
int boyerMooreHorspool(const char *texto, const char *padrao) {
    int n = strlen(texto); // Comprimento do texto
    int m = strlen(padrao); // Comprimento do padrão

    if (m > n) {
        return -1; // O padrão é maior que o texto, então não pode haver correspondência
    }

    int deslocamentoMauCaractere[TAMANHO_ALFABETO];
    preprocessamentoDeslocamentoMauCaractere(padrao, m, deslocamentoMauCaractere); // Preprocessa a tabela de saltos

    int s = 0; // Índice para percorrer o texto
    while (s <= (n - m)) {
        int j = m - 1; // Começa a comparação pelo final do padrão

        while (j >= 0 && padrao[j] == texto[s + j]) {
            j--;
        }

        if (j < 0) {
            return s; // Encontrou uma correspondência
        } else {
            s += deslocamentoMauCaractere[(unsigned char)texto[s + m - 1]]; // Usa a tabela de saltos para avançar
        }
    }

    return -1; // Não encontrou correspondência
}

int main() {
    char texto[TAMANHO_MAXIMO];
    char padrao[TAMANHO_MAXIMO];

    printf("Digite o texto:\n");
    fgets(texto, TAMANHO_MAXIMO, stdin);
    texto[strcspn(texto, "\n")] = '\0'; // Remove o caractere de nova linha, se houver

    printf("Digite o padrão:\n");
    fgets(padrao, TAMANHO_MAXIMO, stdin);
    padrao[strcspn(padrao, "\n")] = '\0'; // Remove o caractere de nova linha, se houver

    int resultado = boyerMooreHorspool(texto, padrao);

    if (resultado != -1) {
        printf("Padrão encontrado na posição: %d\n", resultado);
    } else {
        printf("Padrão não encontrado\n");
    }

    return 0;
}
