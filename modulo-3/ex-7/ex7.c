// Esse algoritmo utiliza de recursividade para realizar uma contagem regressiva, removemos o caso base para provocar um stack overflow 


#include <stdio.h>

// Protótipo da função recursiva
void contagem_regressiva(int numero);

// Função principal
int main(void){

    // Aqui é chamada a função recursiva iniciando a contagem
    contagem_regressiva(20);

    // Se o programa terminar corretamente, retorna 0
    return 0;
}

// Função recursiva onde ocorre a contagem regressiva
void contagem_regressiva(int numero){

    // Exibe o número atual da contagem
    printf("%d\n", numero);

    // Caso base - verifica se o número é menor que 1 para interromper a recursão
    //if (numero < 1){
        //return;
    //}

    // A função chama a si mesma com o número decrementado
    contagem_regressiva(numero - 1);
}