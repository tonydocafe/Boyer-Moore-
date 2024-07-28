#include <stdio.h>
#include <string.h>

#define TAMANHO_ALFABETO 256
#define TAMANHO_MAXIMO 1024

// Função para criar a tabela de mau-caractere
void preprocessamentoMauCaractere(const char *padrao, int m, int mauCaractere[]) {
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        mauCaractere[i] = m; // Inicializa todos os saltos com o comprimento do padrão
    }
    for (int i = 0; i < m - 1; i++) {
        mauCaractere[(unsigned char)padrao[i]] = m - i - 1; // Calcula a distância para cada caractere no padrão
    }
}

// Função para criar a tabela de sufixo bom
void preprocessamentoSufixoBom(const char *padrao, int m, int sufixoBom[]) {
    int i = m, j = m + 1;
    int borda[m + 1];
    borda[i] = j;
    
    while (i > 0) {
        while (j <= m && padrao[i - 1] != padrao[j - 1]) {
            if (sufixoBom[j] == 0) {
                sufixoBom[j] = j - i;
            }
            j = borda[j];
        }
        i--;
        j--;
        borda[i] = j;
    }
    
    j = borda[0];
    for (i = 0; i <= m; i++) {
        if (sufixoBom[i] == 0) {
            sufixoBom[i] = j;
        }
        if (i == j) {
            j = borda[j];
        }
    }
}

// Função para realizar a busca usando o algoritmo BM
int boyerMoore(const char *texto, const char *padrao) {
    int n = strlen(texto); // Comprimento do texto
    int m = strlen(padrao); // Comprimento do padrão

    if (m > n) {
        return -1; // O padrão é maior que o texto, então não pode haver correspondência
    }

    int mauCaractere[TAMANHO_ALFABETO];
    int sufixoBom[m + 1];

    // Inicializa a tabela de sufixo bom com zeros
    memset(sufixoBom, 0, sizeof(int) * (m + 1));

    preprocessamentoMauCaractere(padrao, m, mauCaractere); // Preprocessa a tabela de mau-caractere
    preprocessamentoSufixoBom(padrao, m, sufixoBom); // Preprocessa a tabela de sufixo bom

    int s = 0; // Índice para percorrer o texto
    while (s <= (n - m)) {
        int j = m - 1; // Começa a comparação pelo final do padrão

        while (j >= 0 && padrao[j] == texto[s + j]) {
            j--;
        }

        if (j < 0) {
            return s; // Encontrou uma correspondência
        } else {
            s += (mauCaractere[(unsigned char)texto[s + j]] > sufixoBom[j + 1]) ? mauCaractere[(unsigned char)texto[s + j]] : sufixoBom[j + 1];
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

    int resultado = boyerMoore(texto, padrao);

    if (resultado != -1) {
        printf("Padrão encontrado na posição: %d\n", resultado);
    } else {
        printf("Padrão não encontrado\n");
    }

    return 0;
}
