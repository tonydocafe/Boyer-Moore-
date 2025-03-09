# Familia Boyer Moore

# Algoritmos de Busca de Padrão: Boyer-Moore (BM) e Boyer-Moore-Horspool (BMH)

Este repositório contém dois algoritmos de busca de padrão eficientes para encontrar substrings dentro de um texto: **Boyer-Moore (BM)** e **Boyer-Moore-Horspool (BMH)**.

## Descrição dos Algoritmos

### Boyer-Moore (BM)
O algoritmo Boyer-Moore é um dos mais eficientes para busca de padrão em textos longos. Ele utiliza duas heurísticas principais:
- **Heurística do Mau-Caractere**: Permite saltar vários caracteres quando ocorre um mismatch.
- **Heurística do Sufixo Bom**: Usa informações sobre o sufixo do padrão para realizar saltos maiores.

Este algoritmo é implementado no primeiro script e é indicado para cenários onde se busca maior eficiência em textos grandes.

### Boyer-Moore-Horspool (BMH)
O algoritmo Boyer-Moore-Horspool é uma versão simplificada do BM, utilizando apenas a heurística do **Mau-Caractere**. Ele é mais fácil de implementar e geralmente tem um desempenho competitivo em textos comuns, apesar de não ser tão eficiente quanto o BM em alguns casos específicos.

Este algoritmo está implementado no segundo script.

## Estrutura dos Arquivos
- **bm.c**: Implementação do algoritmo Boyer-Moore (BM).
- **bmh.c**: Implementação do algoritmo Boyer-Moore-Horspool (BMH).

## Como Compilar e Executar

Para compilar ambos os scripts, utilize o compilador **GCC**:

```sh
# Compilar o Boyer-Moore
gcc -o bm bm.c

# Compilar o Boyer-Moore-Horspool
gcc -o bmh bmh.c
```

Para executar:

```sh
# Executar Boyer-Moore
./bm

# Executar Boyer-Moore-Horspool
./bmh
```

## Entrada e Saída
Ambos os programas solicitam:
1. Um **texto** onde a busca será realizada.
2. Um **padrão** a ser buscado dentro do texto.

Exemplo de entrada:
```
Digite o texto:
Este é um exemplo de busca
Digite o padrão:
busca
```
Saída esperada:
```
Padrão encontrado na posição: 17
```
Se o padrão não for encontrado, o programa retorna:
```
Padrão não encontrado
```

## Referências
- Boyer, R. S., & Moore, J. S. (1977). "A Fast String Searching Algorithm".
- Horspool, R. N. (1980). "Practical fast searching in strings".

Este repositório serve para estudos e comparação entre os dois algoritmos de busca de padrão. Sinta-se livre para modificá-los e explorar diferentes cenários!

