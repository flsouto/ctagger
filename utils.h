#define LID_MAS 268
#define LID_FEM 254
#define LID_SUB 277
#define LID_ADJ 275
#define LID_ADV 258
#define LID_VER 698
#define LID_INF 257
#define LID_PRO 263
#define LID_SIN 428
#define LID_PLU 269

#include <lists/a.h>

// Retorna array de listas em que uma palavra está inserida
// Último elemento será um int 0
// Caso a palavra não esteja em nenhuma lista será retornado apenas um ponteiro para int 0
int * get_lists(wchar_t * word){
    switch(word[0]){
        case L'a' :
            return get_lists_a(word);
        break;
    }
    return malloc(sizeof(int));
}

// Carrega listas de uma palavra pelo seu índice dentro da frase
// Irá popular a variável w_lists[index] com as listas encontradas
void w_load_lists(int index){
    int * id = get_lists(w_strs[index]);
    while(*id){
        w_lists[index][*id] = 1;
        id++;
    }
}

// Converte uma referência (a1...a9, s1..s9) para a sua posição correspondente
// Retorna -1 caso não for uma referência válida
int ref2index(wchar_t * ref){

    if(ref[0]=='p' && !ref[1]){
        return p;
    }
    else if((ref[0] == L'a' || ref[0] == L's') && ref[1] >= L'0' && ref[1] <= L'9'){

        if(ref[0] == L'a'){
            return p - (ref[1] - L'0');
        } else {
            return p + (ref[1] - L'0');
        }
    }

    return -1;
}

// Roda uma lista de regras sobre as palavras da frase
// até que não haja mais mudanças ou esteja tudo determinado
int iterate(int (*rules[10000])(void)){

    int changes;

    do {
        changes = 0;

        for(p=0; p < n_words; p++){

            // Pula palavras já determinadas
            if(w_determined[p]){
                continue;
            }

            // Percorre todas as regras
            for(int r=0;rules[r];r++){
                running_rule = r;
                if(setjmp(abort_rule)) continue;
                if(rules[r]()) changes++;
            }
        }

        iterations++;

    } while(changes);

    return iterations;
}
