#include <stdio.h> //biblioteca de comunicação com o usúario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca de responsável por cuidar das strings

int registro()     // a funcao responsavel por cadastrar os usuarios no sistema
{
    // inicio criacao de variaveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // final criacao de variaveis/string

    printf("digite o CPF a ser cadastrado:  "); //coletando informacao do usuario
    scanf("%s", cpf);        //%s refere-se a string

    strcpy(arquivo, cpf); // Resposável por copiar os valores das atring

    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); // salva o valor da variavel
    fclose(file); // fecha o arquivo

    file - fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o nome a ser cadastrado:  ");        //coletando informacao do usuario
    scanf("%s",nome);

    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);

    file - fopen(arquivo, "a");
    fprintf(file,",");      //insere uma virgula na separacao de cada informacao inserida pelo usuario
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado:  ");
    scanf("%s",sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);

    file - fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado:  ");
    scanf("%s",cargo);

    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);        //depois de usa - lo e preciso fechar o arquivo com esta funcao

    system("pause");
}

int consulta()
{
    setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado:  ");
    scanf("%s",cpf);         //file scan usada para ler o arquivo

    FILE *file;     //cria o arquivo
    file = fopen(cpf,"r");  // cria o arquivo e o "r" significa ler o arquivo

    if(file == NULL)
    {
        printf("Não foi possivel abrir o arquivo, não localizado!.\n");
    }

    while(fgets(conteudo, 200, file)!= NULL)
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");
}

int deletar()
{
    char cpf[40];

    printf("Difgite o CPF a ser deletado: ");
    scanf("%s",cpf);

    remove(cpf);

    FILE *file;                         //Abrindo o arquivo referente ao cpf e executando o comando "r" para leitura
    file = fopen(cpf,"r");

    if(file == NULL)                   // caso o numero digitado nao seja encontrado no arquivo
    {
        printf("O CPF do usuário não foi encontrado no sistema!.\n ");          //mensagem a ser exibida ao usuario
        system("pause");                                                        //Comando que pausa na tela atual
        return 0;                                                   //Comando que faz o usuario retornar a tela inicial
    }

    fclose(file);                               //Fechar o arquivo depois de verificar a existencia do mesmo

    printf("Deseja deletar este CPF do sistema?/n");        // Confirmando a escolha do usuario sobre deletar ou nao este CPF
    printf("%s",cpf);
    printf("\n Digite (s) para sim ou digite (n) para não! \n\n");  // dando escolhas de confirmacao da acao de exclusao

    getchar();                  //Funcao para capturar a entrada do usuario atraves de caracteres

    char opcao;                 // criando variavel opcao
    opcao = getchar();              //definindo que variavel opcao sera referente ao getchar (caractere que iremos estipular)

    if (opcao== "s" || opcao== "S")           //se o caractere digitado for s minusculo ou S maiusculo
    {
        if (remove(cpf) == 0)           //remove o arquivo cpf e confere se a remocao foi bem sucedida
        {
            printf("Aluno deletado com sucesso!\n");    //caso bem sucedida a exclusao, insere a mensagem para o usuario saber
        }
        system("pause");
    }


    else if(opcao== "n" || opcao== "N")           // se o caractere digitado for n minusculo ou N maiusculo
    {
        printf("Retorne ao menu principal \n");     // essa mensagem sera visualizada pelo usuario
        system("pause");
    }

    else
    {
        printf("Opcao invalida");               //caso o cpf inserido pelo usuario nao constar na base de dados
        system("pause");
    }

}



int main ()
    {
    int opcao=0;// definindo variavéis
    int laco=1;
    
    for(laco=1;laco==1;)
    {
        
        system("cls");
        
        setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
        
        printf("### Cartório da EBAC ###\n\n"); // inicio do menu
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("Opção: ");//fim do menu
        
        scanf("%d",&opcao); //armazenando a escolha do usúario
        
        system("cls");      //responsavel por limpar a tela
        
        switch(opcao) //inicio da seleção do menu
        {
            case 1:
            registro();      // chamada de funcoes, essa ira chamar o registro
            break;
                
            case 2:
            consulta();         // chamada de funcoes, essa ira chamar a consulta
            break;
                
            case 3:
            deletar();      // chamada de funcoes, essa ira chamar o delete de informacao
            break;
            break;

            default:
            printf("Essa opção não está disponivel!\n");     //caso a informacao digitada nao exista o sistema ira retornar com esta mensagem
            system("pause");
            break;

        }
    }    
}
    