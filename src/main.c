/*
* 2048
* Autores: Eduardo, Jorge e João Matheus;
* DREs: 120047675, 120063312, 120023786;
* Testado no GNU/Linux 5.9.1-arch1-1 e 4.19.101-2-lts;
* Esse software é licenciado sob licença MIT.
*/

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <locale.h>
#include <time.h>
#include "controles.h"
#include "interface.h"
#include "game.h"
#include "handle.h"

int main(int argc, char *argv[]) {
    static short int matrix[SIZE][SIZE];
    short int controle, movimentos;

    srand(time(NULL)); /*Adiciona uma seed vinculada ao tempo nos rand()'s*/
    setlocale(LC_ALL, ""); /* Para poder imprimir os caracteres acentuados corretamente */

    /* Impede que o jogo pare sem desativar a interface, desativando o comportamento
    padrão do Ctrl + C e do Ctrl + Z*/
    signal(SIGINT, killHandle);
    signal(SIGTSTP, killHandle);

    if (argc > 1) iniciaUnicode(argv[1]); /*Confere se o usuário adicionou 
                                            a flag que desativa interface unicode*/

    novoJogo(matrix);
    verificaTamanhoDoTerminal();
    /*Enquanto a função oJogoContinua continuar retornando true, imprime a interface de jogo
    e recebe input de novos movimentos*/
    while (oJogoContinua(matrix)) {
        controle = getch();
        movimentos = 0;

        switch (controle) {
            case 'w': case KEY_UP:
                movimentos = paraCima(matrix);
            break;

            case 'a': case KEY_LEFT:
                movimentos = paraEsquerda(matrix);
            break;

            case 's': case KEY_DOWN:
                movimentos = paraBaixo(matrix);
            break;

            case 'd': case KEY_RIGHT:
                movimentos = paraDireita(matrix);
            break;

            case '0':
                fimDeJogo();
                return 0;

            default:
                break;
        }

        if (movimentos) {
            adicionaNovoValor(matrix);
            printInterface(matrix);
        }
    }

    /*Encerra o processo do jogo caso não tenha sido feito anteriormente, 
    geralmente o programa só chegara aqui caso o jogador vença ou perca e escolha
    sair no lugar de reiniciar o jogo*/
    fimDeJogo();
    return 0;
}
