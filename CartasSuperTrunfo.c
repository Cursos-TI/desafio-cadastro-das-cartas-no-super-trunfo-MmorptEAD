#include   <stdio.h>

int main() {
    // Carta 1
    char estado1 [] = "A";
    char cod1 [] = "A01";
    char nome_cidade1 [50] = "São Paulo";
    unsigned long int populacao1 = 12325000;
    float area1 = 1521.11;
    float pib1 = 700000000000.00;
    int ponto_turistico1 = 50;
    //parte 2
    float densidade_populacional1 = (populacao1 / area1);
    float pib_per_capita1 = (pib1 / populacao1);
    //parte 3
    float DP_PIBPC1 =(densidade_populacional1 / pib_per_capita1);
    float SUPERTRUNFO1 = (populacao1 + area1 + pib1 + ponto_turistico1 + pib_per_capita1 - densidade_populacional1);
    

    float resultado1, resultado2;
    resultado1 = (populacao1 + area1 + pib1 + ponto_turistico1 + pib_per_capita1 + SUPERTRUNFO1);

    // Carta 2
    char estado2 [] = "B";
    char cod2 [] = "B02";
    char nome_cidade2 [50] = "Rio de Janeiro";
    unsigned long int populacao2 = 6748000;
    float area2 = 1182.30;
    float pib2 = 400000000000.00;
    int ponto_turistico2 = 30;
    //parte 2
    float densidade_populacional2 = (populacao2 / area2);
    float pib_per_capita2 = (pib2 / populacao2);
    //parte 3
    float DP_PIBPC2 =(densidade_populacional2 / pib_per_capita2);
    float SUPERTRUNFO2 = (populacao2 + area2 + pib2 + ponto_turistico2 + pib_per_capita2 - densidade_populacional2);
    resultado2 = (populacao2 + area2 + pib2 + ponto_turistico2 + pib_per_capita2 + SUPERTRUNFO2);

    long int result_pop = (populacao1 > populacao2);
    long int result_area = (area1 > area2);
    long int result_pib = (pib1 > pib2);
    long int result_ponto_turistico = (ponto_turistico1 > ponto_turistico2);
    long int result_densidade_populacional = (densidade_populacional1 > densidade_populacional2);
    long int result_pib_per_capita = (pib_per_capita1 > pib_per_capita2);
    long int result_supertrunfo = (SUPERTRUNFO1 > SUPERTRUNFO2);

    // Comparação entre as cartas

    
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
    //parte 3
    printf("Densidade populacional / PIB per capita: %.2f\n", DP_PIBPC1);
    printf("SUPERTRUNFO: %.2f\n", SUPERTRUNFO1);
    


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
    //parte 3
    printf("Densidade populacional / PIB per capita: %.2f\n", DP_PIBPC2);
    printf("SUPERTRUNFO: %.2f\n", SUPERTRUNFO2);

    printf("\n");

    printf("***Resultado da comparação:***\n");
    
    printf("População carta: %d venceu\n", result_pop);
    printf("Área carta: %d venceu\n", result_area);
    printf("PIB carta: %d venceu\n", result_pib);
    printf("Pontos turísticos carta: %d venceu \n", result_ponto_turistico);
    printf("Densidade populacional carta: %d venceu \n", result_densidade_populacional);
    printf("PIB per capita carta: %d venceu \n", result_pib_per_capita);
    printf("Supertrunfo carta: %d venceu \n", result_supertrunfo);

    printf("\n");
    printf("Resultado final:\n");
    if (resultado1 > resultado2) {
        printf("A carta 1 venceu!\n");
    } else if (resultado1 < resultado2) {
        printf("A carta 2 venceu!\n");
    } else {
        printf("As cartas são iguais!\n");
    }



    return 0;
}