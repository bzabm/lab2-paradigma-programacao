# VERSÃO REFATORADA
# Neste código refatoramos a folha de pagamento aplicando alta coesão
# Separamos a função pura para cálculo e o procedimento para impressão

# Função pura para cálculo do salário
# Recebe os dados de entrada e retorna o resultado sem efeitos colaterais
def calcular_salario(horas, valor_hora):
    salario_bruto = horas * valor_hora
    inss = salario_bruto * 0.11
    salario_liquido = salario_bruto - inss
    return salario_liquido

# Procedimento para impressão do resultado
# Responsável apenas por exibir as informações
def imprimir_holerite(nome, salario):
    print(f"{nome}: R$ {salario:.2f}")

# Programa principal com os dados dos funcionários
print("\n=== FOLHA DE PAGAMENTO (VERSÃO REFATORADA) ===\n")

# Lista de funcionários com seus respectivos dados
funcionarios = [
    ("João Silva", 160, 25.50),
    ("Maria Santos", 180, 32.00),
    ("Carlos Lima", 140, 28.75)
]

# Processa cada funcionário utilizando as funções separadas
for nome, horas, valor in funcionarios:
    salario = calcular_salario(horas, valor)
    imprimir_holerite(nome, salario)