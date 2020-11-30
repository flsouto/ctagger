// Determina artigos
int rule1(){

   if(PREDET(p, artigo) && ( PREDET_EXACT(s1, substantivo) || LISTA(s1, 522) )){
       DET(artigo);
       return 1;
   }

   return 0;

}

// Remove substantivo
int rule2(){

   if(PREDET(p, substantivo) && !PREDET(a1, artigo)){
        REM(substantivo);
        return 1;
   }

   return 0;

}

// Determina adjetivo
int rule3(){

   if(PREDET(p, adjetivo) && PREDET_EXACT(a1, artigo) && PREDET_EXACT(s1, pronome)){
       DET(adjetivo);
       return 1;
   }

   return 0;

}

// Determina adverbio
int rule4(){

   if(PREDET_EXACT_MULTI(p, (enum tag[]){pronome,artigo,adverbio,0}) && PREDET_EXACT(a1, pronome) && PREDET_EXACT(a2, adjetivo) && PREDET_EXACT(a3, artigo)){
       DET(adverbio);
       return 1;
   }

   return 0;

}

typedef int (*rule)();
rule rules[] = {&rule1, &rule2, &rule3, &rule4};


void test(){

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

    iterate(rules);

    assert(w_determined[0] == artigo);
    assert(w_determined[1] == adjetivo);
    assert(w_determined[2] == pronome);
    assert(w_determined[3] == adverbio);

}
