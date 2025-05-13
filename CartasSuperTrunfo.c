#include   <stdio.h>

int main() {
    // Carta 1
    char estado1 [] = "A";
    char cod1 [] = "A01";
    char nome_cidade1 [50] = "São Paulo";
    int populacao1 = 12325000;
    float area1 = 1521.11;
    float pib1 = 700000000000.00;
    int ponto_turistico1 = 50;
    //parte 2
    float densidade_populacional1 = (populacao1 / area1);
    float pib_per_capita1 = (pib1 / populacao1);

    // Carta 2
    char estado2 [] = "B";
    char cod2 [] = "B02";
    char nome_cidade2 [50] = "Rio de Janeiro";
    int populacao2 = 6748000;
    float area2 = 1182.30;
    float pib2 = 400000000000.00;
    int ponto_turistico2 = 30;
    //parte 2
    float densidade_populacional2 = (populacao2 / area2);
    float pib_per_capita2 = (pib2 / populacao2);

    // Impressão carta 1

    printf("Carta 1:\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", cod1);
    printf("Nome da Cidade: %s\n", nome_cidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Pontos turísticos: %d\n", ponto_turistico1);
    //parte 2
    printf("Densidade populacional: %.2f hab/km²\n", densidade_populacional1);
    printf("PIB per capita: R$ %.2f \n", pib_per_capita1);


    printf("\n");

    // Impressão carta 2

    printf("Carta 2:\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", cod2);
    printf("Nome da Cidade: %s\n", nome_cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos turísticos: %d\n", ponto_turistico2);
    //parte 2
    printf("Densidade populacional: %.2f hab/km²\n", densidade_populacional2);
    printf("PIB per capita: R$ %.2f\n", pib_per_capita2);


    printf("\n");

    return 0;
}