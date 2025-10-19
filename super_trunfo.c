#include <stdio.h>

int main() {
    /* === Variáveis da Carta 1 === */
    unsigned long int populacao1;
    char estado1;
    char codigo1[4];
    char nomeCidade1[100];
    float area1;
    float pib_bilhoes1;
    int pontosTuristicos1;
    double densidade1;       
    double pibPerCapita1;
    float superPoder1;        

    /* === Variáveis da Carta 2 === */
    unsigned long int populacao2;
    char estado2;
    char codigo2[4];
    char nomeCidade2[100];
    float area2;
    float pib_bilhoes2;
    int pontosTuristicos2;
    double densidade2;
    double pibPerCapita2;
    float superPoder2;

    /* === Entrada da Carta 1 === */
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Informe o estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Informe o codigo da carta (ex: A01): ");
    scanf("%3s", codigo1);

    printf("Informe o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade1);

    printf("Informe a populacao (numero inteiro nao-negativo): ");
    scanf("%lu", &populacao1);

    printf("Informe a area (em km²): ");
    scanf("%f", &area1);

    printf("Informe o PIB (em bilhoes de reais): ");
    scanf("%f", &pib_bilhoes1);

    printf("Informe o número de pontos turisticos: ");
    scanf("%d", &pontosTuristicos1);

    /* === Cálculos Carta 1 === */
    densidade1 = (area1 > 0.0f) ? ((double)populacao1 / (double)area1) : 0.0;
    // PIB per capita: convertendo PIB (bilhões) para reais antes de dividir
    pibPerCapita1 = (populacao1 > 0) ? (((double)pib_bilhoes1 * 1e9) / (double)populacao1) : 0.0;

    /* === Entrada da Carta 2 === */
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Informe o estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Informe o codigo da carta (ex: A01): ");
    scanf("%3s", codigo2);

    printf("Informe o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("Informe a populaçao (numero inteiro nao-negativo): ");
    scanf("%lu", &populacao2);

    printf("Informe a area (em km2): ");
    scanf("%f", &area2);

    printf("Informe o PIB (em bilhoes de reais): ");
    scanf("%f", &pib_bilhoes2);

    printf("Informe o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);

    /* === Cálculos Carta 2 === */
    densidade2 = (area2 > 0.0f) ? ((double)populacao2 / (double)area2) : 0.0;
    pibPerCapita2 = (populacao2 > 0) ? (((double)pib_bilhoes2 * 1e9) / (double)populacao2) : 0.0;

    double pib_reais1 = (double)pib_bilhoes1 * 1e9;
    double pib_reais2 = (double)pib_bilhoes2 * 1e9;

    double inversoDensidade1 = (densidade1 > 0.0) ? (1.0 / densidade1) : 0.0;
    double inversoDensidade2 = (densidade2 > 0.0) ? (1.0 / densidade2) : 0.0;

    double sp1_double = (double)populacao1
                      + (double)area1
                      + pib_reais1
                      + (double)pontosTuristicos1
                      + pibPerCapita1
                      + inversoDensidade1;

    double sp2_double = (double)populacao2
                      + (double)area2
                      + pib_reais2
                      + (double)pontosTuristicos2
                      + pibPerCapita2
                      + inversoDensidade2;

    superPoder1 = (float)sp1_double;
    superPoder2 = (float)sp2_double;

    printf("\n\n=== Carta 1 ===\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Populaçao: %lu\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib_bilhoes1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", (double)superPoder1);

    printf("\n=== Carta 2 ===\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populaçao: %lu\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib_bilhoes2);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", (double)superPoder2);

    int cmpPopulacao       = (populacao1 > populacao2) ? 1 : 0;
    int cmpArea            = (area1 > area2) ? 1 : 0;
    int cmpPIB             = (pib_reais1 > pib_reais2) ? 1 : 0;
    int cmpPontosTuristicos= (pontosTuristicos1 > pontosTuristicos2) ? 1 : 0;
    int cmpDensidade       = (densidade1 < densidade2) ? 1 : 0;
    int cmpPIBperCapita    = (pibPerCapita1 > pibPerCapita2) ? 1 : 0; 
    int cmpSuperPoder      = (superPoder1 > superPoder2) ? 1 : 0;     
    

    printf("\n\n=== Comparaçao de Cartas ===\n\n");
    printf("Populaçao: Carta 1 venceu (%d)\n", cmpPopulacao);
    printf("Area: Carta 1 venceu (%d)\n", cmpArea);
    printf("PIB: Carta 1 venceu (%d)\n", cmpPIB);
    printf("Pontos Turisticos: Carta 1 venceu (%d)\n", cmpPontosTuristicos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", cmpDensidade);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", cmpPIBperCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", cmpSuperPoder);

    return 0;
}
