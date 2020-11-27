void test(){

    n_words = 9;

    w_puncts[2] = ',';
    w_puncts[6] = ',';

    p = 3;

    assert(NOP(p, s3));
    assert(!NOP(p, s4));
    assert(NOP(p,p));
    assert(!NOP(s1,p));

}
