void test(){

    n_words = 2;
    w_tags[0][artigo] = 1;
    w_tags[1][adjetivo] = 1;

    assert(PREDET(s1, adjetivo));
    assert(!PREDET(p, adjetivo));

}
