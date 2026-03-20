# Esse algoritmo utiliza recursividade para encontrar uma pasta/arquivo e retornar seu caminho


# Exemplo de pasta de arquivos
arquivos_alinhados = {
    "documentos": {
        "trabalho.txt": "arquivo",
        "faculdade": {
            "tcc.docx": "arquivo",
            "pesquisa.pdf": "arquivo"
        }
    },
    "download": {
        "foto1.png": "arquivo",
      
    }
}

# Função que procura o arquivo dentro das pastas e retorna o caminho onde ele está
def buscar_arquivo(pasta, nome_arquivo, caminho=""):

    # For que percorre todo conteúdo da pasta
    for nome, conteudo in pasta.items():

        # Monta o caminho da pasta ou arquivo
        caminho_atual = f"{caminho}/{nome}"

        # Caso base - um if para verificar se o item é o arquivo que entamos pesquisando
        if nome == nome_arquivo and conteudo == "arquivo":
            return caminho_atual

        # Recursão - se o arquivo for uma subpasta, a função é chamada novamente para continuar a busca
        if isinstance(conteudo, dict):
            resultado = buscar_arquivo(conteudo, nome_arquivo, caminho_atual)

            if resultado:
                return resultado

    return None


# Nome do arquivo que desejamos buscar
arquivo = "arquivo.docx"

# Chamada da função e armazenamento do resultado na variável resultado
resultado = buscar_arquivo(arquivos_alinhados, arquivo)

# Um pequeno if/else apenas para verificar se o arquivo foi encontrado ou não
if resultado:
    print("Arquivo encontrado em:", resultado)
else:
    print("Arquivo não encontrado")