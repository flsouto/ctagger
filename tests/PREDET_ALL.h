void test(){

    n_words = 2;
    w_tags[0][artigo] = 1;
    w_tags[0][adjetivo] = 1;
    w_tags[0][pronome] = 1;

    assert(PREDET_ALL(p, (enum tag[]){artigo,adjetivo,0}));
    assert(!PREDET_ALL(p, (enum tag[]){artigo,substantivo,0}));


}
