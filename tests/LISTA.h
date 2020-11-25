void test(){

    n_words = 2;
    w_lists[0][666] = 1;
    w_lists[1][666] = 1;

    assert(LISTA(p, 666));
    assert(!LISTA(p, 777));
    assert(LISTA(s1, 666));

    p++;
    assert(LISTA(p, 666));

}
