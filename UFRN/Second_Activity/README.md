Readme

Nesta seção do repositório podem ser encontrados os algorítmos de de ávores binárias e tabela de dispersão referentes a atividade avaliativa da segunda unidade da disciplina de estrutura de dados. Neste arquivo você encontra instruções sobre como compilar e executar os programas.
Executando os algoritmos

    Entre no diretório referente ao arquivo que você quer executar cd Second_Activity/fontes/binary

    Compile o código com os seguintes comandos gcc -c -Wall arquivo.c

    Gere o executavel gcc -o executal arquivo.o

    Agora execute o arquivo passando um tamanho para o vetor como parametro de sua execução ./arquivo 100

Utilizando o iterate

O script iterate foi disponibilizado pelo professor da disciplina e que auxilia na execução do código repetidas vezes, salvando seu tempo de execução em arquivos .txt

    Ainda no diretório usando anteriormente execute o seguinte comando em seu terminal linux ../iterate.sh execução tamanho_inicial_n aumento_n tamanho_final_n "nome_do_programa" nome_txt

    Sugestão de execução ../iterate.sh 50 100 100 900 "./quick" quick
