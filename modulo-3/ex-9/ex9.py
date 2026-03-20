# Neste algoritmo simulamos um gerador de registros de logs produzidos sob demanda

# Importamos a biblioteca time para criar um delay entre os registros
import time

# Função geradora responsável por produzir os registros de log
def gerador_logs():

    # Inicializa o contador de registros
    contador = 1

    # Loop infinito simulando geração contínua de logs
    while True:

        # Cria a mensagem do registro atual
        log = f"Registro de log número {contador}"

        # yield gera um registro por vez e pausa a execução da função
        yield log

        # Incrementa o contador
        contador += 1

        # Delay de 1 segundo entre os registros
        time.sleep(1)


# Criação do gerador
logs = gerador_logs()

# Loop que solicita 10 registros ao gerador
for _ in range(10):
    registro = next(logs)
    print(registro)