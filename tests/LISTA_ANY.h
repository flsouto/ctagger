void test(){

    n_words = 2;
    w_lists[0][666] = 1;
    w_lists[1][999] = 1;

    assert(LISTA_ANY(p, (int[]){6,66,666,0}));
    assert(LISTA_ANY(s1, (int[]){9,99,999,0}));

}
