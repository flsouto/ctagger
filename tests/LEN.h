void test(){

    n_words = 1;
    w_strs[0] = L"grotesque";

    assert(LEN(p, 3, 10));
    assert(!LEN(p, 3, 5));
    assert(!LEN(p, 20, 25));
}
