#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void registro_num();
void probabilidade();
void mostrar_jogos();

int main(void){
    verificacao();
    int escolha, parar = 1;
    while(parar == 1){
        printf("------------------------------------------\n");
        printf("               LOTOFACIL\n");
        printf("------------------------------------------\n");
        printf("1 - Registrar jogo\n2 - Ver Probabilidade\n3 - Ver ultimos jogos lancados\n4 - Sair do programa\n------------------------------------------\nESCOLHA: ");
        scanf("%d", &escolha);
        if(escolha == 4){
            printf("------------------------------------------\n");
            printf("           Programa Fechado!\n");
            printf("------------------------------------------\n");
            parar = 0;
        }
        else if(escolha == 1){
            system("cls");
            printf("------------------------------------------\n");
            printf("                REGISTRO\n");
            printf("------------------------------------------\n");
            registro_num();
            system("cls");

        }
        else if(escolha == 2){
            system("cls");
            printf("------------------------------------------\n");
            printf("              PROBABILIDADE\n");
            printf("------------------------------------------\n");
            probabilidade();
            system("cls");
        }
        else if(escolha == 3){
            system("cls");
            printf("------------------------------------------\n");
            printf("              JOGOS LANCADOS\n");
            printf("------------------------------------------\n");
            mostrar_jogos();
            system("cls");
        }


    }
    return 0;
}
void registro_num(){
    FILE *ptr_arq; //abrindo arquivo
    ptr_arq = fopen("jogos.txt", "a+");
    if(ptr_arq == NULL){
        printf("Erro ao abrir o arquivo!!!\n");
        exit(-1);
    }
    else{
        printf("Arquivos dos jogos aberto com sucesso!!!\n");

    }
    FILE *ptr_arquivo;//probabilidade
    ptr_arquivo = fopen("dados.txt", "a+");

    if(ptr_arquivo == NULL){
        printf("Erro ao abrir o arquivo!!!\n");
        exit(-1);
    }
    else{
        printf("Arquivo dos dados aberto com sucesso!!!\n");
    }

    //pegar numero de jogos
    int num_jogos;
    fscanf(ptr_arquivo,"%d", &num_jogos);
    fseek(ptr_arquivo, 1, SEEK_CUR);

    //pegar dados da probabilidade
    int um, dois, tres, quatro, cinco, seis, sete, oito, nove, dez,
    onze, doze, treze, quartoze, quinze, dezeseis, dezesete, dezoito, dezenove,
    vinte, vinte_um, vinte_dois, vinte_tres, vinte_quatro, vinte_cinco;

    fscanf(ptr_arquivo, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", &um, &dois, &tres, &quatro, &cinco, &seis, &sete, &oito, &nove, &dez, //escreve
           &onze, &doze, &treze, &quartoze, &quinze, &dezeseis, &dezesete, &dezoito, &dezenove, &vinte, &vinte_um, &vinte_dois, &vinte_tres, &vinte_quatro, &vinte_cinco);

    int num[15];
    printf("------------------------------------------\n");
    int rep;
    for(int i = 0;i < 15;i++){ // registro dos numeros
            printf("%d = ", i+1);
            scanf("%d", &rep);


                for(int z = 0;z < i;z++){

                    if(rep == 0){
                        printf("------------------------------------------\n");
                        printf("ERROR: Numero invalido!\n");
                        printf("------------------------------------------\n");
                        printf("%d = ", i + 1);
                        scanf("%d", &rep);
                        z = -1;
                    }
                    if(rep == num[z]){
                        printf("------------------------------------------\n");
                        printf("ERROR: Esse numero ja foi cadastrado nesse jogo!\n");
                        printf("------------------------------------------\n");
                        printf("%d = ", i + 1);
                        scanf("%d", &rep);
                        z = -1;
                    }
                    if(rep > 25){
                            printf("------------------------------------------\n");
                            printf("ERROR: Esse numero e maior que 25!\n");
                            printf("------------------------------------------\n");
                            printf("%d = ", i + 1);
                            scanf("%d", &rep);
                            z = -1;
                        }

                }
              num[i] = rep;
              if(rep == 1){
                    um++;
                }
                else if(rep == 2){
                    dois++;
                }
                else if(rep == 3){
                    tres++;
                }
                else if(rep == 4){
                    quatro++;
                }
                else if(rep == 5){
                    cinco++;
                }
                else if(rep == 6){
                    seis++;
                }
                else if(rep == 7){
                    sete++;
                }
                else if(rep == 8){
                    oito++;
                }
                else if(rep == 9){
                    nove++;
                }
                else if(rep == 10){
                    dez++;
                }
                else if(rep == 11){
                    onze++;
                }
                else if(rep == 12){
                    doze++;
                }
                else if(rep == 13){
                    treze++;
                }
                else if(rep == 14){
                    quartoze++;
                }
                else if(rep == 15){
                    quinze++;
                }
                else if(rep == 16){
                    dezeseis++;
                }
                else if(rep == 17){
                    dezesete++;
                }
                else if(rep == 18){
                    dezoito++;
                }
                else if(rep == 19){
                    dezenove++;
                }
                else if(rep == 20){
                    vinte++;
                }
                else if(rep == 21){
                    vinte_um++;
                }
                else if(rep == 22){
                    vinte_dois++;
                }
                else if(rep == 23){
                    vinte_tres++;
                }
                else if(rep == 24){
                    vinte_quatro++;
                }
                else if(rep == 25){
                    vinte_cinco++;
                }

    }
        for(int j = 0;j < 15;j++){
            if(j < 14){
                fprintf(ptr_arq,"%d ", num[j]);
            }
           else{
                fprintf(ptr_arq,"%d\n", num[j]);
            }
        }

        //atualizo a lista de probabilidade, tanto numeros de vezes quanto quantidade de jogos
        num_jogos++;
        ptr_arquivo = fopen("dados.txt", "w+");
        fprintf(ptr_arquivo,"%d\n", num_jogos);
        fprintf(ptr_arquivo,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", um, dois, tres, quatro, cinco, seis, sete, oito, nove, dez, //escreve
       onze, doze, treze, quartoze, quinze, dezeseis, dezesete, dezoito, dezenove, vinte, vinte_um, vinte_dois, vinte_tres, vinte_quatro, vinte_cinco);


        //fecho arquivos
        fclose(ptr_arq);
        fclose(ptr_arquivo);
    }
void probabilidade(){
    FILE *ptr_arquivo;//probabilidade
    ptr_arquivo = fopen("dados.txt", "a+");

    if(ptr_arquivo == NULL){
        printf("Erro ao abrir o arquivo!!!\n");
        printf("------------------------------------------\n");
        exit(-1);
    }
    else{
        printf("Arquivo dos dados aberto com sucesso!!!\n");
        printf("------------------------------------------\n");
    }

    int num_jogos; // pega quantidade de jogos
    fscanf(ptr_arquivo,"%d", &num_jogos);
    fseek(ptr_arquivo, 1, SEEK_CUR);

    printf("Quantidade de jogos: %d\n", num_jogos);
    printf("------------------------------------------\n");

    int um, dois, tres, quatro, cinco, seis, sete, oito, nove, dez,
        onze, doze, treze, quartoze, quinze, dezeseis, dezesete, dezoito, dezenove,
        vinte, vinte_um, vinte_dois, vinte_tres, vinte_quatro, vinte_cinco;


    fscanf(ptr_arquivo, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", &um, &dois, &tres, &quatro, &cinco, &seis, &sete, &oito, &nove, &dez, //escreve
           &onze, &doze, &treze, &quartoze, &quinze, &dezeseis, &dezesete, &dezoito, &dezenove, &vinte, &vinte_um, &vinte_dois, &vinte_tres, &vinte_quatro, &vinte_cinco);

    int numeros[25] = {um,dois, tres, quatro, cinco, seis, sete, oito, nove, dez,
       onze, doze, treze, quartoze, quinze, dezeseis, dezesete, dezoito, dezenove, vinte, vinte_um, vinte_dois, vinte_tres, vinte_quatro, vinte_cinco};
       float prob;

       for(int i = 0; i < 25;i++){
            prob = (float)numeros[i];
             if(i % 3 == 0){
                printf("\n");
            }
            printf("%d = %.1f\t",i + 1,(100 / num_jogos) * prob);


       }
    int continuar = 0;
    while(continuar == 0){
        printf("\n------------------------------------------\n");
        printf("1 - Ir para Menu\n2 - Fechar programa\n");
        printf("------------------------------------------\n");
        printf("ESCOLHA: ");
        scanf("%d", &continuar);
        if(continuar == 1){
            break;
        }
        else if(continuar == 2){
            printf("\n------------------------------------------\n");
            printf("           Programa Fechado!\n");
            printf("------------------------------------------\n");
            exit(-1);
        }
    }

    fclose(ptr_arquivo);
}
void mostrar_jogos(){
  FILE *ptr_arquivo;//probabilidade
    ptr_arquivo = fopen("dados.txt", "a+");

    if(ptr_arquivo == NULL){
        printf("Erro ao abrir o arquivo!!!\n");
        printf("------------------------------------------\n");
        exit(-1);
    }
    else{
        printf("Arquivo dos dados aberto com sucesso!!!\n");

    }
    FILE *ptr_arq;//probabilidade
    ptr_arq = fopen("jogos.txt", "a+");

    if(ptr_arquivo == NULL){
        printf("Erro ao abrir o arquivo!!!\n");
        printf("------------------------------------------\n");
        exit(-1);
    }
    else{
        printf("Arquivo dos jogos aberto com sucesso!!!\n");
        printf("------------------------------------------\n");
    }

    int num_jogos; // pega quantidade de jogos
    fscanf(ptr_arquivo,"%d", &num_jogos);
    fseek(ptr_arquivo, 1, SEEK_CUR);

    printf("Quantidade de jogos: %d\n", num_jogos);
    printf("------------------------------------------\n");

    int quant;//numero para mostrar na tela
    int quantidade;//quantidade de jogos
    printf("Quantos jogos: ");
    scanf("%d", &quantidade);

    if(quantidade > num_jogos){
        printf("------------------------------------------\n");
        printf("Error: Quantidade superior a quantidade de jogos!\n");
        printf("Retornando ao MENU\n");
        sleep(5);
        return;
    }

    printf("------------------------------------------\n");

    int pulo = num_jogos - quantidade;

      for(int j = 0;j < pulo;j++){
             for(int j = 0;j < 15;j++){
                fscanf(ptr_arq,"%d",&quant);
                fseek(ptr_arq, 1, SEEK_CUR);
        }
      }
    for(int i = 0;i < quantidade;i++){

        for(int j = 0;j < 15;j++){
            fscanf(ptr_arq,"%d",&quant);
            printf("%d ", quant);
            fseek(ptr_arq, 1, SEEK_CUR);
        }
        printf("\n");
    }
    printf("------------------------------------------\n");
    int continuar = 0;
    while(continuar == 0){
        printf("\n------------------------------------------\n");
        printf("1 - Ir para Menu\n2 - Fechar programa\n");
        printf("------------------------------------------\n");
        printf("ESCOLHA: ");
        scanf("%d", &continuar);
        if(continuar == 1){
            break;
        }
        else if(continuar == 2){
            printf("\n------------------------------------------\n");
            printf("           Programa Fechado!\n");
            printf("------------------------------------------\n");
            exit(-1);
        }
    }
    fclose(ptr_arq);
    fclose(ptr_arquivo);
}

void verificacao(){
    FILE *ptr_arq;
    if(ptr_arq = fopen("dados.txt", "r") == NULL){
        printf("------------------------------------------\n");
        printf("\t\tArquivo sendo criado\n");
        printf("------------------------------------------\n");


        ptr_arq = fopen("dados.txt", "a+");
        if(ptr_arq == NULL){
            printf("Erro ao criar o arquivo!!!\n");
            printf("------------------------------------------\n");
            printf("\tPrograma sendo fechado!!!\n");
            printf("------------------------------------------\n");
            exit(-1);
        }
        printf("Arquivo criado com sucesso!\n");
        fprintf(ptr_arq,"0\n"); //criando arquivo necessario
        fprintf(ptr_arq,"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n");
    }
    fclose(ptr_arq);
}
