void test(){

    n_words = 1;
    w_tags[0][artigo] = 1;
    w_tags[0][adjetivo] = 1;

    assert(!PREDET_EXACT(p, artigo));

}
