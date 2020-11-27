void test(){

    n_words = 2;

    w_tags[0][substantivo] = 1;
    w_tags[0][adjetivo] = 1;

    w_subs[0] = 294;
    w_lists[0][666] = 1;

    // Testa caso quando já determinado
    assert(PREDET_SUB(p, substantivo, (int[]){294,0}));
    // Quando já determinado não pode olhar para listas
    assert(!PREDET_SUB(p, substantivo, (int[]){666,0}));

    w_lists[1][666] = 1;
    w_lists[1][999] = 1;
    w_tags[1][adjetivo] = 1;

    // Testa caso: quando não determinado deve olhar para listas
    assert(PREDET_SUB(s1, adjetivo, (int[]){123,666,0}));
    assert(PREDET_SUB(s1, adjetivo, (int[]){123,12,999,0}));
    assert(!PREDET_SUB(s1, adjetivo, (int[]){555,333,0}));

    // Teste só para garantir que alquer outra tag dá inválido
    assert(!PREDET_SUB(s1, verbo, (int[]){666,0}));




}
