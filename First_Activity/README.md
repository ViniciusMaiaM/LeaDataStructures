# Readme

Neste repositório podem ser encontrados os algorítmos de ordenação requeridos pela atividade avaliativa da primeira unidade da disciplina de Estrutura de Dados. Neste arquivo você encontra instruções sobre como compilar e executar os programas.

## Executando os algoritmos

1. Entre no diretório referente ao arquivo que você quer executar
``` cd First_Activity/fontes/quick ```

2. Compile o código com os seguintes comandos
``` gcc -c -Wall arquivo.c ```

3. Gere o executavel
``` gcc -o executal arquivo.o ```

4. Agora execute o arquivo passando um tamanho para o vetor como parametro de sua execução
``` ./arquivo 100 ```

## Utilizando o iterate

O script iterate foi disponibilizado pelo professor da disciplina e que auxilia na execução do código repetidas vezes, salvando seu tempo de execução em arquivos .txt

1. Ainda no diretório usando anteriormente execute o seguinte comando em seu terminal linux
```../iterate.sh execução tamanho_inicial_n aumento_n tamanho_final_n "nome_do_programa" nome_txt```

2. Sugestão de execução
```../iterate.sh 50 100 100 900 "./quick" quick```
