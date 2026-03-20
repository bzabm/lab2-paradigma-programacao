# Neste algoritmo demonstramos o perigo do call-by-sharing em Python
# Simulamos um estoque de loja que é modificado dentro de uma função

# Função que aplica desconto aos itens do estoque
# Recebe a lista e modifica seus elementos diretamente
def aplicar_desconto(estoque, percentual):
    # Percorre todos os itens do estoque
    for i in range(len(estoque)):
        # Calcula o valor do desconto
        desconto = estoque[i] * (percentual / 100)
        # Modifica o elemento da lista original
        estoque[i] = estoque[i] - desconto
        print(f"   Item {i}: novo valor = R$ {estoque[i]:.2f}")

# Lista representando o estoque da loja
# Listas em Python são objetos MUTÁVEIS
estoque_original = [100.00, 250.00, 75.50, 120.00, 300.00]

print("=== SIMULADOR DE ESTOQUE COM DESCONTO ===\n")

print("Estoque original:")
for i, preco in enumerate(estoque_original):
    print(f"   Item {i}: R$ {preco:.2f}")

print("\nAplicando desconto de 10%...")
aplicar_desconto(estoque_original, 10)

print("\nEstoque após a função:")
for i, preco in enumerate(estoque_original):
    print(f"   Item {i}: R$ {preco:.2f}")

print("\nO estoque original foi modificado porque:")
print("- Python usa passagem por referência de objeto (call-by-sharing)")
print("- Listas são objetos mutáveis")
print("- A função recebeu uma referência para a mesma lista")
print("- Modificações nos elementos afetam o objeto original")