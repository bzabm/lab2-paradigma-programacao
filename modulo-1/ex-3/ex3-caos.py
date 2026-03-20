# VERSÃO CAÓTICA
# Neste código implementamos o cálculo da folha de pagamento
# de forma desorganizada, misturando lógica e apresentação

print("\n=== FOLHA DE PAGAMENTO (VERSÃO CAÓTICA) ===\n")

# Funcionário 1
nome = "João Silva"
horas = 160
valor_hora = 25.50
salario_bruto = horas * valor_hora
inss = salario_bruto * 0.11
salario_liquido = salario_bruto - inss
print(f"{nome}: R$ {salario_liquido:.2f}")

# Funcionário 2
nome = "Maria Santos"
horas = 180
valor_hora = 32.00
salario_bruto = horas * valor_hora
inss = salario_bruto * 0.11
salario_liquido = salario_bruto - inss
print(f"{nome}: R$ {salario_liquido:.2f}")

# Funcionário 3
nome = "Carlos Lima"
horas = 140
valor_hora = 28.75
salario_bruto = horas * valor_hora
inss = salario_bruto * 0.11
salario_liquido = salario_bruto - inss
print(f"{nome}: R$ {salario_liquido:.2f}")