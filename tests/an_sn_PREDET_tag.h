void test(){

    n_words = 10;
    w_tags[0][artigo] = 1;
    w_tags[1][substantivo] = 1;
    w_tags[2][adjetivo] = 1;
    w_tags[3][pronome] = 1;
    w_tags[4][adverbio] = 1;

    p = 2;

    assert(PREDET(a1, substantivo));
    assert(PREDET(a2, artigo));

    assert(PREDET(s1, pronome));
    assert(PREDET(s2, adverbio));

}
