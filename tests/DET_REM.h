void test(){

    n_words = 1;

    w_tags[0][adjetivo] = 1;
    w_tags[0][substantivo] = 1;
    w_tags[0][adverbio] = 1;

    DET(adjetivo);

    assert(w_determined[p] == adjetivo);
    assert(n_changes == 1);

    n_words = 2;
    p++;

    w_tags[1][adjetivo] = 1;
    w_tags[1][substantivo] = 1;
    w_tags[1][adverbio] = 1;

    REM(adjetivo);

    assert(!w_determined[p]);
    assert(n_changes == 2);

    REM(substantivo);

    assert(w_determined[p] == adverbio);

    assert(n_changes == 3);

}
