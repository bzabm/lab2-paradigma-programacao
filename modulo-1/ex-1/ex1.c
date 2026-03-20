// Neste algoritmo calculamos o 40º termo da sequência de Fibonacci
// usando duas abordagens: iterativa e recursiva

#include <stdio.h>

// Função recursiva para cálculo de Fibonacci
// Cada chamada gera duas novas chamadas, criando muitos stack frames
long long fibonacci_recursivo(int n) {
    // Caso base: Fibonacci(0) = 0, Fibonacci(1) = 1
    if (n <= 1) {
        return n;
    }
    // Passo recursivo: fib(n) = fib(n-1) + fib(n-2)
    return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
}

// Função iterativa para cálculo de Fibonacci
// Utiliza apenas um loop e três variáveis, sem alocar múltiplos stack frames
long long fibonacci_iterativo(int n) {
    // Casos base
    if (n <= 1) {
        return n;
    }
    
    // Variáveis para armazenar os dois últimos valores
    long long anterior = 0;   // fib(0)
    long long atual = 1;      // fib(1)
    long long proximo;
    
    // Loop calculando do 2º até o n-ésimo termo
    for (int i = 2; i <= n; i++) {
        proximo = anterior + atual;  // Calcula próximo termo
        anterior = atual;            // Desloca os valores
        atual = proximo;
    }
    
    return atual;
}

int main() {
    int n = 40;
    
    printf("=== CALCULO DO %d TERMO DE FIBONACCI ===\n\n", n);
    
    // Executa e exibe resultado da versão iterativa
    printf("\nVersao Iterativa: %I64d\n", fibonacci_iterativo(n));
    
    // Executa e exibe resultado da versão recursiva
    printf("\nVersao Recursiva: %I64d\n\n", fibonacci_recursivo(n));
    
    return 0;
}