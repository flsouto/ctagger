void test(){

    n_words = 1;
    w_tags[0][verbo] = 1;
    w_tags[0][infinitivo] = 1;
    assert(VERBEX(p));

    n_words++;
    w_tags[n_words-1][substantivo] = 1;
    assert(!VERBEX(s1));

    n_words++;
    w_tags[n_words-1][gerundio] = 1;
    w_tags[n_words-1][substantivo] = 1;
    assert(VERBEX(s2));


}
