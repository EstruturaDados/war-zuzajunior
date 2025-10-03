// --- Constantes Globais ---
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERRITORIOS 5
#define TAM_NOME 30
#define TAM_COR 20

// Estrutura de Dados
typedef struct {
    char nome[TAM_NOME];
    char cor[TAM_COR];
    int tropas;
} Territorio;

// --- Função Principal (main) ---
int main() {
    Territorio territorios[MAX_TERRITORIOS];
    int qtd = 0; // Quantidade de territórios cadastrados
    int opcao;

    do {
        printf("\n==== JOGO WAR ====\n");
        printf("1 - Cadastrar Territorio\n");
        printf("2 - Listar Territorios\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar buffer da Entrada

        switch (opcao) {
            case 1:
                if (qtd < MAX_TERRITORIOS) {
                    printf("\n--- Cadastro do Territorio %d ---\n", qtd + 1);

                    printf("Nome do territorio: ");
                    fgets(territorios[qtd].nome, TAM_NOME, stdin);
                    territorios[qtd].nome[strcspn(territorios[qtd].nome, "\n")] = '\0'; // remove \n

                    printf("Cor do territorio: ");
                    fgets(territorios[qtd].cor, TAM_COR, stdin);
                    territorios[qtd].cor[strcspn(territorios[qtd].cor, "\n")] = '\0';

                    printf("Quantidade de tropas: ");
                    scanf("%d", &territorios[qtd].tropas);
                    getchar(); // limpar buffer

                    qtd++;
                    printf("Territorio cadastrado com sucesso!\n");
                } else {
                    printf("\nLimite de %d territorios atingido!\n", MAX_TERRITORIOS);
                }
                break;

            case 2:
                printf("\n--- Lista de Territorios ---\n");
                if (qtd == 0) {
                    printf("Nenhum territorio cadastrado ainda.\n");
                } else {
                    for (int i = 0; i < qtd; i++) {
                        printf("Territorio %d:\n", i + 1);
                        printf("Nome: %s\n", territorios[i].nome);
                        printf("Cor: %s\n", territorios[i].cor);
                        printf("Tropas: %d\n\n", territorios[i].tropas);
                    }
                }
                break;

            case 3:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 3);

    return 0;
}




