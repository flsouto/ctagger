void test(){

    n_words = 5;
    w_puncts[0] = ',';
    w_puncts[4] = '?';

    assert(PONT(p,','));
    assert(!PONT(p,'!'));

    assert(PONT(s4, '?'));

}
