#include <stdio.h> //biblioteca de comunicacao com usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //funcão responsável por cadastrar usuarios no sistema.
{
	//inicio criacão de variáveis/string
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final criacão de variáveis/string
    printf("Digite o CPF a ser cadastrado: "); //coletando informacão do usuário
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //responsavel por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo,"w"); // cria o arquivo e o "w" criar uma nova e já escrever. 
    fprintf(file,cpf); //salvo o valor da variavel
    fclose(file); //fecha o arquivo
 
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado:");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado:");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado:");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
   
    
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado:");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file== NULL)
    {
    	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo,200, file) != NULL)
	{
		printf("\nEssas são as informacões do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	system("pause");
}

int deletar()
{
    setlocale(LC_ALL,"Portuguese");
    
	char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado:");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file== NULL)
    {
    	printf("Não foi possível localizar o usuário!\n");
    	system("pause");
    	
	}
	
}

int main()
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
   {
	
	  system("cls");
	  
	  setlocale(LC_ALL,"Portuguese");
	
	  printf("### Cartorio da EBAC ###\n\n");
	  printf("escolha a opcao desejada do menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n\n"); 
	  printf("Opcao:"); //fim do menu

      scanf("%d", &opcao);  //armazenando a escolha do usuário
    
      system("cls"); //responsavel por limpar a tela
      
      
      switch(opcao)
      {
      	case 1:
      		registro(); //chamada de funcões
    	    break;
    	    
        case 2:
        	consulta();
    	break;
    	
    	case 3:
    		consulta();
         	break;
     	
     	     	
     	default:
     		printf("Essa opcao não está disponível!\n");
    	system("pause");
    	break;
    	//fim da selecão
	  }
    
      
	}

}
