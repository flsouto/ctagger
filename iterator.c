#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include "vars.h"
#include "funcs.h"
#include "rules.h"

void test1(){

    // Dado que temos 10 palavras em sequencia
    n_words = 10;

    // Dado que a primeira palavra pode ser um artigo ou pronome
    w_tags[0][artigo] = 1;
    w_tags[0][pronome] = 1;

    // Dado que a segunda palavra pode ser substantivo ou adejtivo
    w_tags[1][substantivo] = 1;
    w_tags[1][adjetivo] = 1;

    // Dado que a segunda palavra está na lista 522
    w_lists[1][522] = 1;

    // Dado que a terceira palavra pode ser substantivo ou pronome
    w_tags[2][substantivo] = 1;
    w_tags[2][pronome] = 1;

    // Dado que a quarta palavra pode ser um adverbio ou pronome ou artigo
    w_tags[3][adverbio] = 1;
    w_tags[3][pronome] = 1;
    w_tags[3][artigo] = 1;

    w_puncts[3] = '.';


}

void log_action(int iteration, int word, int rule, int output){
    printf("I%d W%d R%d O%d\n", iteration, word, rule, output);
}

void iterate(){

    int output;
    int changes;
    int iter = 1;

    do {
        changes = 0;

        for(p=0; p < n_words; p++){

            // Pula palavras já determinadas
            if(w_determined[p]){
                continue;
            }

            // Percorre todas as regras
            for(int r=0;rules[r];r++){
                output = rules[r]();
                if(output > 0){
                    // Seta essa tag pra TRUE e todas as outras tags pra FALSE
                    log_action(iter, p, r, output);
                    for(int t=1; t<=N_TAGS; t++){
                        w_tags[p][t] = t == output;
                    }
                    w_determined[p] = output;
                    changes++;
                } else if(output < 0){
                    // Seta essa tag pra FALSE
                    log_action(iter, p, r, output);
                    w_tags[p][-output] = 0;
                    changes++;
                }
            }
        }
        iter++;

    } while(changes);

}

int main(){

    test1();
    iterate();

    return 0;

}
