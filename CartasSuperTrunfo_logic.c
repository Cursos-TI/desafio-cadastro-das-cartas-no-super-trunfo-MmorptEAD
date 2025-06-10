#include <stdio.h>
#include <stdlib.h> // Para system("cls") ou system("clear")
#include <string.h> // Necessário para strcpy
#include <locale.h> // Para acentuação em português

// REQUISITO: Estrutura para organizar os dados de cada carta
typedef struct {
    char nomeCidade[50];
    char codigo[4];
    unsigned long int populacao;
    float area;
    double pib; // Usar double para maior precisão com valores grandes
    int pontosTuristicos;
    float densidade;
    double pibPerCapita;
} Carta;

// Protótipos das funções auxiliares
void exibirMenuAtributos(int atributo_a_ignorar);
const char* obterNomeAtributo(int escolha);
double obterValorAtributo(Carta c, int escolha);
void limparTela();

int main() {
    // REQUISITO: Usabilidade - Configura o programa para exibir acentos
    setlocale(LC_ALL, "Portuguese");

    // --- CARTA 1: SÃO PAULO ---
    Carta carta1;
    strcpy(carta1.nomeCidade, "São Paulo");
    strcpy(carta1.codigo, "A01");
    carta1.populacao = 12325000;
    carta1.area = 1521.11;
    carta1.pib = 700000000000.00;
    carta1.pontosTuristicos = 50;
    carta1.densidade = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    // --- CARTA 2: RIO DE JANEIRO ---
    Carta carta2;
    strcpy(carta2.nomeCidade, "Rio de Janeiro");
    strcpy(carta2.codigo, "B02");
    carta2.populacao = 6748000;
    carta2.area = 1182.30;
    carta2.pib = 400000000000.00;
    carta2.pontosTuristicos = 30;
    carta2.densidade = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    int escolha1 = 0, escolha2 = 0;

    // --- ESCOLHA DO PRIMEIRO ATRIBUTO ---
    while (escolha1 < 1 || escolha1 > 6) {
        limparTela();
        printf("=======================================\n");
        printf("    JOGO SUPER TRUNFO - CIDADES\n");
        printf("=======================================\n\n");
        printf("Jogador, escolha o PRIMEIRO atributo para a comparação:\n\n");
        
        // REQUISITO: Menu Dinâmico - Chamada para exibir todas as opções (0 = ignorar nada)
        exibirMenuAtributos(0); 
        
        printf("\nSua escolha: ");
        scanf("%d", &escolha1);

        // REQUISITO: Confiabilidade - Trata entrada inválida
        if (escolha1 < 1 || escolha1 > 6) {
            printf("\nOpção inválida! Pressione Enter para tentar novamente.");
            while(getchar() != '\n'); // Limpa o buffer de entrada
            getchar();
        }
    }

    // --- ESCOLHA DO SEGUNDO ATRIBUTO ---
    while (escolha2 < 1 || escolha2 > 6 || escolha2 == escolha1) {
        limparTela();
        printf("=======================================\n");
        printf("    JOGO SUPER TRUNFO - CIDADES\n");
        printf("=======================================\n\n");
        printf("Você escolheu '%s'. Agora, escolha o SEGUNDO atributo:\n\n", obterNomeAtributo(escolha1));
        
        // REQUISITO: Menu Dinâmico - Exibe o menu ignorando a primeira escolha
        exibirMenuAtributos(escolha1);

        printf("\nSua escolha: ");
        scanf("%d", &escolha2);

        // REQUISITO: Confiabilidade e Lógica - Garante que o atributo é válido e não repetido
        if (escolha2 == escolha1) {
            printf("\nVocê não pode escolher o mesmo atributo duas vezes! Pressione Enter.");
            while(getchar() != '\n');
            getchar();
        } else if (escolha2 < 1 || escolha2 > 6) {
            printf("\nOpção inválida! Pressione Enter para tentar novamente.");
            while(getchar() != '\n');
            getchar();
        }
    }

    // --- OBTENÇÃO DOS VALORES E CÁLCULO DA SOMA ---
    // REQUISITO: Comparação com Múltiplos Atributos
    double valor1_c1 = obterValorAtributo(carta1, escolha1);
    double valor1_c2 = obterValorAtributo(carta2, escolha1);

    double valor2_c1 = obterValorAtributo(carta1, escolha2);
    double valor2_c2 = obterValorAtributo(carta2, escolha2);

    // REQUISITO: Soma dos Atributos
    double soma_c1 = valor1_c1 + valor2_c1;
    double soma_c2 = valor1_c2 + valor2_c2;


    // --- EXIBIÇÃO CLARA DO RESULTADO ---
    limparTela();
    printf("=======================================\n");
    printf("        RESULTADO DA RODADA\n");
    printf("=======================================\n\n");
    printf("-> Cartas: %s vs %s\n", carta1.nomeCidade, carta2.nomeCidade);
    printf("-> Atributos: %s e %s\n\n", obterNomeAtributo(escolha1), obterNomeAtributo(escolha2));

    printf("----------------------------------------------------------\n");
    printf(" ATRIBUTO             | %-16s | %-16s\n", carta1.nomeCidade, carta2.nomeCidade);
    printf("----------------------------------------------------------\n");
    // Usamos %.2f para formatar os valores para 2 casas decimais, melhorando a leitura
    printf(" %-20s | %-16.2f | %-16.2f\n", obterNomeAtributo(escolha1), valor1_c1, valor1_c2);
    printf(" %-20s | %-16.2f | %-16.2f\n", obterNomeAtributo(escolha2), valor2_c1, valor2_c2);
    printf("----------------------------------------------------------\n");
    printf(" SOMA TOTAL           | %-16.2f | %-16.2f\n", soma_c1, soma_c2);
    printf("----------------------------------------------------------\n\n");
    
    // REQUISITO: Lógica de vitória e Tratamento de Empates
    if (soma_c1 > soma_c2) {
        printf("🎉 VENCEDOR: %s! 🎉\n", carta1.nomeCidade);
    } else if (soma_c2 > soma_c1) {
        printf("🎉 VENCEDOR: %s! 🎉\n", carta2.nomeCidade);
    } else {
        printf("⚖️ RESULTADO: Empate! ⚖️\n");
    }
    printf("\nFim de jogo!\n");

    return 0;
}

/**
 * @brief Exibe o menu de atributos, pulando um item específico.
 * @param atributo_a_ignorar O número do atributo (1-6) a não ser exibido. Se for 0, exibe todos.
 */
void exibirMenuAtributos(int atributo_a_ignorar) {
    // REQUISITO: Manutenibilidade - Nomes de variáveis descritivos
    const char* nomes[] = {
        "População", "Área (km²)", "PIB (em R$)", 
        "Pontos Turísticos", "Densidade Populacional", "PIB per Capita (R$)"
    };
    
    // REQUISITO: Menus Dinâmicos - Lógica para pular opção já escolhida
    for (int i = 0; i < 6; i++) {
        if ((i + 1) == atributo_a_ignorar) {
            continue; // Pula para a próxima iteração do loop, ignorando o atributo
        }
        printf("   %d. %s\n", i + 1, nomes[i]);
    }
}

/**
 * @brief Obtém o nome de um atributo com base na escolha numérica.
 * @param escolha O número (1-6) escolhido pelo usuário.
 * @return Uma string constante com o nome do atributo.
 */
const char* obterNomeAtributo(int escolha) {
    // REQUISITO: Menus Dinâmicos com switch
    switch (escolha) {
        case 1: return "População";
        case 2: return "Área (km²)";
        case 3: return "PIB (em R$)";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Pop.";
        case 6: return "PIB per Capita";
        default: return "Inválido"; // REQUISITO: Confiabilidade - default para tratar erro
    }
}

/**
 * @brief Obtém o valor de um atributo de uma carta específica.
 * @param c A carta da qual se quer o valor.
 * @param escolha O número do atributo desejado.
 * @return O valor do atributo como um double para consistência nos cálculos.
 */
double obterValorAtributo(Carta c, int escolha) {
    // A exceção da Densidade (menor vence) não é aplicada aqui,
    // pois a regra final é a SOMA dos valores brutos.
    switch (escolha) {
        case 1: return (double)c.populacao;
        case 2: return (double)c.area;
        case 3: return c.pib;
        case 4: return (double)c.pontosTuristicos;
        case 5: return (double)c.densidade;
        case 6: return c.pibPerCapita;
        default: return 0;
    }
}

/**
 * @brief Limpa o console de forma portável (Windows e Unix-like).
 */
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}