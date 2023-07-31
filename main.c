#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define TAM 9
#include <locale.h>
/// Alunos: Daiene dos Santos Costas e Maria Luisa De Castro Ferreira
// Jogo resta 1

// função que que comborta a exibição do tabuleiro
void tabuleiro1(int tabuleiro[TAM][TAM],int mc,int ml)
{
    int i, j  ;
    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            if  (ml==i && mc==j)
            {
                if (tabuleiro[i][j] != 1)
                {
                    printf("( )");
                }
                else
                {
                    printf("(%i)", tabuleiro[i][j]);
                }
            }
            else
            {
                if (tabuleiro[i][j] != 1)
                {
                    printf("   ");
                }
                else
                {
                    printf(" %i ", tabuleiro[i][j]);
                }
            }
        }
        printf("\n");
    }

}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    /// essas são para a movimentação na matriz
    int i, j,ml ,mc , teclas, control,controc,pecalinha,pecacoluna,  ;
    int cont=0, contpeca; /// essas são as variaveis ultilizadas na finalização do jogo

    int tabuleiro[TAM][TAM] =
    {
        {2,2, 2, 2, 2, 2, 2, 2,2},
        {2,2, 2, 1, 1, 1, 2, 2,2},
        {2,2, 2, 1, 1, 1, 2, 2,2},
        {2,1, 1, 1, 1, 1, 1, 1,2},
        {2,1, 1, 1, 0, 1, 1, 1,2},
        {2,1, 1, 1, 1, 1, 1, 1,2},
        {2,2, 2, 1, 1, 1, 2, 2,2},
        {2,2, 2, 1, 1, 1, 2, 2,2},
        {2,2, 2, 2, 2, 2, 2, 2,2},
    };

    ml = mc = 4;
    tabuleiro1(tabuleiro,mc,ml);
    while( TAM == TAM )
    {
        teclas = getch();
        /// tecla 72 se movimenta pra cima
        if (teclas == 72)
        {

            if (tabuleiro[ml-1][mc]==2)
            {
            }
            else
            {
                ml--;
            }
        }
        /// tecla 80 se movimenta para baixo
        else if (teclas==80)
        {

            if (tabuleiro[ml+1][mc]==2 )
            {
            }
            else
            {
                ml++;
            }
        }
        /// tecla 75 se movimenta para a esquerda
        else if (teclas==75)
        {

            if (tabuleiro[ml][mc-1]==2)
            {
            }
            else
            {
                mc--;
            }
        }
        /// tecla 77 movimenta para a direita
        else if (teclas==77)
        {

            if (tabuleiro[ml][mc+1]==2)
            {
            }
            else
            {
                mc++;
            }
        }
        /// tecla espaço ( se aperta mais de uma vez causa desistencia do jogo)
        else if (teclas==32)
            ///tela de derrota
        {
            printf ("voce perdeu!!!\n");
            printf("\033[31m    _                      _______                      _\n");
            printf("  _dMMMb._              .adOOOOOOOOOba.              _,dMMMb_\n");
            printf(" dP'  ~YMMb            dOOOOOOOOOOOOOOOb            aMMP~  `Yb\n");
            printf(" V      ~\"Mb          dOOOOOOOOOOOOOOOOOb          dM\"~      V\n");
            printf("          `Mb.       dOOOOOOOOOOOOOOOOOOOb       ,dM'\n");
            printf("           `YMb._   |OOOOOOOOOOOOOOOOOOOOO|   _,dMP'\n");
            printf("      __     `YMMM| OP'~\"YOOOOOOOOOOOP\"~`YO |MMMP'     __\n");
            printf("    ,dMMMb.     ~~' OO     `YOOOOOP'     OO `~~     ,dMMMb.\n");
            printf(" _,dP~  `YMba_      OOb      `OOO'      dOO      _aMMP'  ~Yb._\n");
            printf(",dMYYMba._         `OOOOOOOOOOOOOOOOO'aaaa          _,adMYYMb.\n");
            printf(",MP'   `YMMba._      OOOOOOOOOOOOOOOOOaaaa       _,adMMP'   `YM.\n");
            printf("MP'        ~YMMMba._ YOOOOPVVVVVYOOOOaaaaP  _,adMMMMP~       `YM\n");
            printf("YMb           ~YMMMM\\`OOOO`````IOOOOOaaa'/MMMMP~           dMP\n");
            printf(" `Mb.           `YMMMb`OOOI,,,,,OOOaaaa'dMMMP'           ,dM'\n");
            printf("   `'                  `OObNNNNNdOO'a                   `'\n");
            printf("                         `~OOOOO~'\n\033[0m");

            printf("peças restantes:%i",contpeca);
            break;
        }
        /// enter para confirmar
        else if (teclas==13)
        {

            if (tabuleiro[ml][mc]==1)
            {
                /// confere se tem ou não peça no tabuleiro
                control = pecalinha = ml;
                controc = pecacoluna = mc;
                while(TAM==TAM)
                {
                    teclas=getch();
                    /// seleciona a movimentção da peça para cima
                    if (teclas==72)
                    {

                        if (tabuleiro[ml-1][mc]==2 || tabuleiro[ml-2][mc]==2)
                        {
                        }
                        else
                        {
                            ml-=2;
                            pecalinha--;
                        }
                    }
                     /// seleciona a movimentção da peça para baixo
                    else if (teclas==80)
                    {

                        if (tabuleiro[ml+1][mc]==2|| tabuleiro[ml+2][mc]==2)
                        {
                        }
                        else
                        {
                            ml+=2;
                            pecalinha++;
                        }
                    }
                     /// seleciona a movimentção da peça para esquerda
                    else if (teclas==75)
                    {

                        if (tabuleiro[ml][mc-1]==2|| tabuleiro[ml][mc-2]==2)
                        {
                        }
                        else
                        {
                            mc-=2;
                            pecacoluna--;
                        }
                    }
                     /// seleciona a movimentção da peça para direita
                    else if (teclas==77)
                    {

                        if (tabuleiro[ml][mc+1]==2|| tabuleiro[ml][mc+2]==2)
                        {
                        }
                        else
                        {
                            mc+=2;
                            pecacoluna++;
                        }
                    }
                     /// executa a movimentação da peça no tabuleiro
                    else if (teclas==13)
                    {
                        if (tabuleiro[i][j]==0 && tabuleiro[pecalinha][pecacoluna]==1)
                        {
                            tabuleiro[i][j]=1;
                            tabuleiro[pecalinha][pecacoluna]=0;
                            tabuleiro[ml][mc]=0;
                            break;
                        }
                    }
                    /// sai do campo de seleção
                    else if (teclas==32)
                    {
                        break;
                    }
                    system("cls");
                    tabuleiro1(tabuleiro,mc,ml);
                    i=ml;
                    j=mc;
                    ml=control;
                    mc=controc;


                }
            }
            else
            {
            }
        }

        system("cls");
        tabuleiro1(tabuleiro,mc,ml);
        cont=0;
        for (i = 0; i < TAM; i++)
        {
            for (j = 0; j < TAM; j++)
            {
                if (tabuleiro[i][j]==1)
                {
                    cont++;
                }


            }
        }
        contpeca = cont;
        if (cont==1)
            /// tela de vitória
        {
            printf("Voce venceu:\n");
            printf("\033[35m````````````````````````````````00\n");
            printf("`````````````````````````````1¶¶¶¶¶¶¶\n");
            printf("````````````````````````````¶¶111111¶¶```01¶¶¶¶¶¶\n");
            printf("````````0``````````````````¶¶11111111¶¶¶¶¶¶10```¶¶\n");
            printf("``````¶¶¶¶¶¶¶10```````````¶¶1111111111¶¶````````0¶\n");
            printf("`````¶¶````01¶¶¶¶0`11¶¶¶¶¶¶11111111111¶¶11```````¶0\n");
            printf("````1¶`````````0¶¶¶¶¶100`1¶11111111111111¶¶¶1¶¶¶¶¶¶0\n");
            printf("````¶¶```````````````````0¶1111111¶11111111¶¶111111¶¶\n");
            printf("````¶1````````````````````¶¶111111¶111111111¶¶11111¶¶\n");
            printf("````¶¶````````````````````0¶¶¶¶¶¶¶¶¶1111111¶1111111¶¶\n");
            printf("````0¶¶0`````````````````````01100`0¶¶¶¶¶1¶¶111111¶¶\n");
            printf("````¶¶0``````````````````````````````011¶¶1111111¶¶\n");
            printf("`1¶¶¶¶¶`````````````````````````````````¶¶¶111¶¶¶¶\n");
            printf("``0¶1```````````````````````````````````0¶¶¶¶100¶¶\n");
            printf("``¶¶````````````````````````````````````````````1¶1\n");
            printf("``¶1`````````````````````````````````````````````¶¶\n");
            printf("`0¶0`````````````````````````````````````````````0¶0\n");
            printf("``¶0``````````````````````````````````````````````¶¶0\n");
            printf("``¶1`````````010``````````````````````````````0¶¶¶¶¶1\n");
            printf("¶¶¶¶1¶¶0````0¶¶¶0`````````````````````1¶¶0``````````¶¶\n");
            printf("``0¶0````````¶¶¶0`````````````````````¶¶¶¶``````````¶1\n");
            printf("```¶¶`````````0``````````011110```````1¶¶````````01¶¶11\n");
            printf("`1¶¶¶¶¶``````````````````¶0``0¶``````````````````¶¶\n");
            printf("1¶¶¶1¶¶``0``00```````````011110`````````111110`000¶¶¶¶¶\n");
            printf("``0¶0````````¶¶¶¶¶¶¶10`````````````¶¶10001¶¶1¶¶¶¶¶¶¶\n");
            printf("`````¶¶````````1¶11111¶¶¶¶0``1¶¶¶¶¶¶0````````¶¶101101\n");
            printf("`````1¶`````````¶11111¶¶¶¶¶¶¶¶¶¶¶0`````````¶000010\n");
            printf("```0¶¶0``````0`1¶11111111¶¶¶¶¶1111111¶100````¶10¶101\n");
            printf("1101¶0¶¶````0¶¶¶¶1111111111111111111111¶¶¶¶0``0¶¶101111\n");
            printf("¶¶01¶¶¶¶¶¶¶¶¶11111111111111111111111111111¶¶¶¶1¶¶01¶¶1\n");
            printf("000001¶111111111111111111111111111111111111111¶101¶0\n");
            printf("¶¶¶¶¶¶¶111111111111111111111111111111111111111¶¶¶110\n");
            printf("¶¶¶¶11¶11111111111111111111111111111111111111¶¶01¶¶¶\n");
            printf("000¶10¶¶1111111111111111111111111111111111111¶10001¶\n");
            printf("¶¶1¶¶10¶¶11111111111111111111111111111111111¶¶0100¶¶\n");
            printf("1100¶¶¶1¶¶111111111111111111111111111111111¶10000¶¶¶\n");
            printf("````¶¶111¶¶¶11111111111111111111111111111¶¶¶111¶¶¶00\n");
            printf("````¶¶00001¶¶¶11111111111111111111111111¶¶111¶11¶0\n");
            printf("````0¶¶00¶¶¶11¶¶1111111111111111111111¶¶¶¶00001¶1\n");
            printf("`````0¶¶¶¶`````1¶¶¶1111111111111111¶¶¶0``1¶¶1¶¶0\n");
            printf("```````¶¶````````1¶¶¶111111111111¶¶¶0``````¶¶\n");
            printf("```````1¶``````````0¶¶¶11111111111¶¶0````````0¶\n");
            printf("````````¶1````````````1¶¶111111¶¶¶1```````````0¶\n");
            printf("````````0¶¶10````````````1¶11¶¶0`````````````0¶1\n\033[0m");
            printf("peças restantes:%i",contpeca);
            break;
        }

    }



    return 0;
}
