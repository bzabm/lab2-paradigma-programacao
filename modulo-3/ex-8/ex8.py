# Nesse algoritmo utilizamos uma corrotina (permite pausar e retomar a execução) para simular uma linha de montagem


# Função geradora que simula uma linha de montagem usando corrotina
def linha_montagem():

    # Variável que representa a peça atual
    peca = 1

    # Loop infinito simulando produção contínua
    while True:

        # Mensagem indicando qual peça está sendo processada
        print("Processando peça", peca)

        # O yield pausa a função, salva o estado e retorna um valor
        # Quando next() for chamado novamente, a execução continua daqui
        yield f"Peça {peca} concluída"

        # Incrementa para a próxima peça
        peca += 1


# Criação da corrotina
fabrica = linha_montagem()

# Chamando o gerador para processar algumas peças
print(next(fabrica))
print(next(fabrica))
print(next(fabrica))
print(next(fabrica))