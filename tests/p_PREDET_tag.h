void test(){

    n_words = 2;
    w_tags[0][artigo] = 1;
    w_tags[1][adjetivo] = 1;

    assert(PREDET(p, artigo));

    p++;

    assert(PREDET(p, adjetivo));

    assert(!PREDET(p, artigo));

}
