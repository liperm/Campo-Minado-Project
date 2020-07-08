//Alunos: Felipe Ribeiro Machado, Vitor da Hora, Lucas Nathaniel.
#include <iostream>
#include<locale.h>
#include <stdlib.h>
#include <time.h>
#define TamLinha 3
#define TamColuna 3
#define Nbomba 2
using namespace std;

int main()
{
    setlocale(LC_ALL, "Poertuguese");
    srand((unsigned)time(NULL) );

    int linha, coluna, i, x, y;
    //MatA= matriz que ficará escondida e recebendo os valores
    //MatB= matriz que aparecerá para o usuário.

    int MatA[TamLinha][TamColuna]={0};
    int MatB[TamLinha][TamColuna]={0};

    //Criação da MatB:
    for (x=0; x<TamLinha; x++){
        for (y=0; y<TamColuna; y++){
            MatB[x][y]=99;//indica que a posição ainda não foi jogada
        }
    }

    //SOMENTE PARA TESTE. SERÁ APAGADO AO FIM DO TRABALHO.
    /*for (x=0; x<TamLinha; x++){
        for (y=0; y<TamColuna; y++){
            cout<<MatB[x][y]<<"\t";
        }cout<<endl;
    }*/

    //Criando a MatA:
   for(i=0; i<Nbomba; i++){
        do{
            linha=rand()%TamLinha;
            coluna=rand()%TamColuna;// do-while para gerar uma posição válida de bomba
        } while(MatA[linha][coluna]==100);
            MatA[linha][coluna]=100;//Bomba=100
                for (int i=-1; i<2; i++){//laços para selecionar as posições ao redor da bomba
                    for(int j=-1; j<2; j++){
                        if(linha+i>=0 and coluna+j>=0 and linha+i<TamLinha and coluna+j<TamColuna){//verificação para as posições que não existem
                            if(MatA[linha+i][coluna+j]!=100){//verificação para distinguir se for uma bomba
                                MatA[linha+i][coluna+j]=MatA[linha+i][coluna+j]+1;
                            }
                        }
                    }
                }
            }

    //SOMENTE PARA TESTE
    /*cout<<endl;
    for(linha=0; linha<TamLinha; linha++){
        for(coluna=0; coluna<TamColuna; coluna++){
            cout<<MatA[linha][coluna]<<"\t";
        }cout<<endl;
    }
    cout<<"\n";*/


        int jogadasMaximas=(TamLinha*TamColuna)-Nbomba;//Número de jogadas máximas possíveis
        int jogadas=0, linhaJogada, colunaJogada;

    //INÍCIO DO GAME:
    cout<<"As posições jogáveis são representadas pelo número 99\n";
    do{
        for(x=0; x<TamLinha; x++){
            for(y=0; y<TamColuna; y++){
                cout<<MatB[x][y]<<"\t";
            }cout<<endl;
        }//Mostra o mapa de jogo

            cout<<"Linha: ";
            cin>> linhaJogada;
            cout<<"Coluna: ";
            cin>> colunaJogada;//Pede a coordenada pro jogador

            //Verificaçes da coordenada:
            //Caso tenha bomba:
            if(MatA[linhaJogada][colunaJogada]==100){
                cout<<"Você Perdeu!\n";
            }
            //Caso a coordenada seja inválida:
            else if(linhaJogada>TamLinha or colunaJogada>TamColuna or linhaJogada<0 or colunaJogada<0){
                cout<<"Os valores de linha deve estar entre 0 e "<<TamLinha-1<<" e o valor da coluna deve estar entre 0 e "<<TamColuna-1<<"\n";
            }
            //Caso a coordenada ja tenha sido jogada:
            else if (MatB[linhaJogada][colunaJogada]!=99){
                cout<<"Essa coordenada já foi jogada!\n";
            }
            //se a coordenada for válida:
            else{
                jogadas++;
                cout<<"Jogadas: "<<jogadas<<"\n\n";
                if(jogadas==jogadasMaximas){
                    cout<<"Você Venceu!\n";
                }
            }
            MatB[linhaJogada][colunaJogada]=MatA[linhaJogada][colunaJogada];//Atribui o valor da matriz que contem os valores na mtriz de mapa de jogo

    }while(MatA[linhaJogada][colunaJogada]!=100 and jogadas!=jogadasMaximas);// fim de jogo se acertar a bomba ou se vencer o jogo
    //Quando o jogo terminar, aparecerá o mapa completo do jogo e o número de jogadas realizadas
    cout<<"Jogadas: "<<jogadas<<endl;;
    for(linha=0; linha<TamLinha; linha++){
        for (coluna=0; coluna<TamColuna; coluna++){
            cout<<MatA[linha][coluna]<<"\t";
        }cout<<endl;
    }
    return 0;
}
