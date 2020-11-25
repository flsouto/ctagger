void test(){

    n_words = 10;

    assert(INDEX(p,1));

    p = 9;

    assert(INDEX(p, -1));
    assert(INDEX(p, 10));

    p = 8;

    assert(INDEX(p, -2));
    assert(INDEX(s1, -1));

}
