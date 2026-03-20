// Neste algoritmo implementamos um sistema hospitalar com struct gigante
// Demonstramos as dificuldades de gerenciar estado em sistemas complexos

#include <stdio.h>
#include <string.h>

// Estrutura que contem todos os dados do sistema hospitalar
typedef struct {
    // Arrays para armazenar dados dos pacientes
    char pacientes[10][50];
    int num_pacientes;
    
    // Arrays para armazenar dados dos medicos
    char medicos[5][50];
    int num_medicos;
    
    // Controle de leitos (0 = livre, 1 = ocupado)
    int leitos_ocupados[20];
    int total_leitos;
    
    // Dados financeiros
    float caixa;
} SistemaHospitalar;

// Procedimento que realiza uma internacao
// Precisa receber a estrutura completa via ponteiro e atualizar multiplos campos
void realizar_internacao(SistemaHospitalar *hospital, char *paciente_nome, char *medico_nome) {
    // Verifica se ha leito disponivel
    int leito_livre = -1;
    for (int i = 0; i < hospital->total_leitos; i++) {
        if (hospital->leitos_ocupados[i] == 0) {
            leito_livre = i;
            break;
        }
    }
    
    // Se nao ha leito, cancela a operacao
    if (leito_livre == -1) {
        printf("   ERRO: Sem leitos disponiveis!\n");
        return;
    }
    
    // Atualiza a lista de pacientes
    strcpy(hospital->pacientes[hospital->num_pacientes], paciente_nome);
    hospital->num_pacientes++;
    
    // Ocupa o leito
    hospital->leitos_ocupados[leito_livre] = 1;
    
    // Atualiza a lista de medicos
    strcpy(hospital->medicos[hospital->num_medicos], medico_nome);
    hospital->num_medicos++;
    
    // Atualiza o caixa
    hospital->caixa += 5000.00;
    
    printf("   Paciente %s internado no leito %d\n", paciente_nome, leito_livre);
}

// Procedimento para exibir o status atual do hospital
void mostrar_status(SistemaHospitalar *hospital) {
    printf("\n=== STATUS DO HOSPITAL ===\n");
    printf("Pacientes internados: %d\n", hospital->num_pacientes);
    printf("Medicos disponiveis: %d\n", hospital->num_medicos);
    
    // Conta leitos ocupados
    int ocupados = 0;
    for (int i = 0; i < hospital->total_leitos; i++) {
        if (hospital->leitos_ocupados[i] == 1) {
            ocupados++;
        }
    }
    printf("Leitos ocupados: %d/%d\n", ocupados, hospital->total_leitos);
    printf("Caixa do hospital: R$ %.2f\n", hospital->caixa);
}

int main() {
    // Inicializa a estrutura do hospital
    SistemaHospitalar hospital = {
        .num_pacientes = 0,
        .num_medicos = 0,
        .total_leitos = 20,
        .caixa = 100000.00
    };
    
    // Inicializa todos os leitos como livres
    for (int i = 0; i < hospital.total_leitos; i++) {
        hospital.leitos_ocupados[i] = 0;
    }
    
    printf("=== SISTEMA HOSPITALAR ===\n");
    mostrar_status(&hospital);
    
    printf("\nRealizando internacoes:\n");
    realizar_internacao(&hospital, "Joao Silva", "Dra. Ana");
    realizar_internacao(&hospital, "Maria Santos", "Dr. Carlos");
    realizar_internacao(&hospital, "Pedro Souza", "Dra. Ana");
    
    mostrar_status(&hospital);
    
    return 0;
}