// Neste algoritmo simulamos um sistema de controle de altitude de um avião
// Demonstramos a diferença entre função pura e procedimento com efeito colateral

#include <stdio.h>

// Função que calcula nova altitude sem alterar o estado original
// Recebe o valor atual e a variação, retorna o novo valor calculado
int calcular_nova_altitude(int altitude_atual, int variacao) {
    int nova_altitude = altitude_atual + variacao;
    
    // Validação para não ultrapassar limites de segurança
    if (nova_altitude < 0) {
        nova_altitude = 0;
    }
    if (nova_altitude > 30000) {
        nova_altitude = 30000;
    }
    
    return nova_altitude;
}

// Procedimento que altera altitude via efeito colateral
// Recebe ponteiro para a variável original e modifica diretamente
void alterar_altitude(int *ponteiro_altitude, int variacao) {
    // Modifica diretamente o valor original na memória
    *ponteiro_altitude = *ponteiro_altitude + variacao;
    
    // Aplica as mesmas validações de segurança
    if (*ponteiro_altitude < 0) {
        *ponteiro_altitude = 0;
    }
    if (*ponteiro_altitude > 30000) {
        *ponteiro_altitude = 30000;
    }
}

int main() {
    // Variável de estado local no main
    int altitude = 10000;
    
    printf("\n=== SISTEMA DE CONTROLE DE ALTITUDE ===\n\n");
    printf("Altitude inicial: %d pés\n\n", altitude);
    
    // Demonstração da função pura (sem alterar estado)
    printf("1. Usando FUNCAO (calcula sem alterar):\n");
    int nova_altitude = calcular_nova_altitude(altitude, 2000);
    printf("   Nova altitude calculada: %d\n", nova_altitude);
    printf("   Altitude original: %d (permaneceu inalterada)\n\n", altitude);
    
    // Demonstração do procedimento com efeito colateral
    printf("2. Usando PROCEDIMENTO (altera diretamente):\n");
    alterar_altitude(&altitude, 2000);
    printf("   Altitude apos procedimento: %d (foi alterada)\n", altitude);
    
    return 0;
}