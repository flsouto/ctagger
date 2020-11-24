
// Determina artigos
int rule1(){

   if(PREDET(p, artigo) && ( PREDET_EXACT(s1, substantivo) || LISTA(s1, 522) )){
       return artigo;
   }

   return 0;

}

// Remove substantivo
int rule2(){

   if(PREDET(p, substantivo) && !PREDET(a1, artigo)){
       return -substantivo;
   }

   return 0;

}

// Determina adjetivo
int rule3(){

   if(PREDET(p, adjetivo) && PREDET_EXACT(a1, artigo) && PREDET_EXACT(s1, pronome)){
       return adjetivo;
   }

   return 0;

}

// Determina adverbio
int rule4(){

   if(PREDET_EXACT_MULTI(p, (enum tag[]){pronome,artigo,adverbio,0}) && PREDET_EXACT(a1, pronome) && PREDET_EXACT(a2, adjetivo) && PREDET_EXACT(a3, artigo)){
       return adverbio;
   }

   return 0;

}

typedef int (*rule)();
rule rules[] = {&rule1, &rule2, &rule3, &rule4, NULL};
