#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

// Estrutura da carta
typedef struct {
    char nome[50];
    float populacao;
    float area;
    float pib;
    float densidade;
} Pais;

// Retorna o valor do atributo escolhido
float obterValor(Pais p, int atributo) {
    switch (atributo) {
        case 1: return p.populacao;
        case 2: return p.area;
        case 3: return p.pib;
        case 4: return p.densidade;
        default: return 0;
    }
}

// Retorna o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Densidade Demográfica";
        default: return "Inválido";
    }
}

// Exibe menu dinâmico
void mostrarMenu(int atributoBloqueado) {
    if (atributoBloqueado != 1) printf("1 - População\n");
    if (atributoBloqueado != 2) printf("2 - Área\n");
    if (atributoBloqueado != 3) printf("3 - PIB\n");
    if (atributoBloqueado != 4) printf("4 - Densidade Demográfica\n");
}

int main()
{ SetConsoleOutputCP(CP_UTF8);
    Pais pais1 = {"Brasil", 213.3, 8515.8, 1600.0, 25.0};
    Pais pais2 = {"Canadá", 38.0, 9984.7, 2100.0, 4.0};

    int attr1 = 0, attr2 = 0;

    printf("=== SUPER TRUNFO - COMPARAÇÃO AVANÇADA ===\n\n");
    printf("Carta 1: %s\n", pais1.nome);
    printf("Carta 2: %s\n\n", pais2.nome);

    // Escolha do primeiro atributo
    do {
        printf("Escolha o PRIMEIRO atributo:\n");
        mostrarMenu(0);
        scanf("%d", &attr1);
    } while (attr1 < 1 || attr1 > 4);

    // Escolha do segundo atributo (dinâmico)
    do {
        printf("\nEscolha o SEGUNDO atributo:\n");
        mostrarMenu(attr1);
        scanf("%d", &attr2);
    } while (attr2 < 1 || attr2 > 4 || attr2 == attr1);

    // Valores dos atributos
    float v1a = obterValor(pais1, attr1);
    float v2a = obterValor(pais2, attr1);
    float v1b = obterValor(pais1, attr2);
    float v2b = obterValor(pais2, attr2);

    // Soma (regra da densidade: menor vence, então inverte)
    float soma1 = (attr1 == 4 ? -v1a : v1a) + (attr2 == 4 ? -v1b : v1b);
    float soma2 = (attr1 == 4 ? -v2a : v2a) + (attr2 == 4 ? -v2b : v2b);

    // Resultado
    printf("\n=== RESULTADO ===\n\n");

    printf("%s vs %s\n\n", pais1.nome, pais2.nome);

    printf("Atributo 1: %s\n", nomeAtributo(attr1));
    printf("%s: %.2f | %s: %.2f\n\n", pais1.nome, v1a, pais2.nome, v2a);

    printf("Atributo 2: %s\n", nomeAtributo(attr2));
    printf("%s: %.2f | %s: %.2f\n\n", pais1.nome, v1b, pais2.nome, v2b);

    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", pais1.nome, soma1);
    printf("%s: %.2f\n\n", pais2.nome, soma2);

    printf("Vencedor: ");
    if (soma1 > soma2)
        printf("%s\n", pais1.nome);
    else if (soma2 > soma1)
        printf("%s\n", pais2.nome);
    else
        printf("Empate!\n");

    return 0;
}