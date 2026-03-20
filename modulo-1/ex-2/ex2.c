// Neste algoritmo demonstramos a diferença entre passagem por valor
// e passagem por referência em C, utilizando um saldo bancário

#include <stdio.h>

// funcao que tenta alterar o saldo por valor
// Recebe uma CÓPIA do valor original
void tentar_alterar_por_valor(int saldo) {
    // Modifica apenas a cópia local
    saldo = 5000;
    printf("   Dentro da funcao (valor): saldo = %d\n", saldo);
}

// funcao que altera o saldo por referência
// Recebe o ENDEREÇO da variável original
void alterar_por_referencia(int *ponteiro_saldo) {
    // Modifica diretamente o valor original através do ponteiro
    *ponteiro_saldo = 5000;
    printf("   Dentro da funcao (referência): saldo = %d\n", *ponteiro_saldo);
}

int main() {
    // Variável de estado criada no escopo do main
    int saldo_bancario = 1000;
    
    printf("\n=== DEMONSTRACAO DE PASSAGEM DE PARAMETROS ===\n\n");
    printf("Saldo inicial: %d\n\n", saldo_bancario);
    
    // Teste com passagem por valor
    printf("1. Chamando funcao com PASSAGEM POR VALOR:\n");
    tentar_alterar_por_valor(saldo_bancario);
    printf("   Após a funcao: saldo = %d (nao alterado!)\n\n", saldo_bancario);
    
    // Teste com passagem por referência
    printf("2. Chamando funcao com PASSAGEM POR REFERENCIA:\n");
    alterar_por_referencia(&saldo_bancario);
    printf("   Apos a funcao: saldo = %d (alterado com sucesso!)\n\n", saldo_bancario);
    
    return 0;
}