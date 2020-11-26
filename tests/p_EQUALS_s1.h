void test(){

    n_words = 3;
    w_strs[0] = L"blah";
    w_strs[1] = L"blah";
    w_strs[2] = L"blahblah";

    assert(EQUALS(p, L"s1"));
    assert(!EQUALS(p, L"s2"));

    p++;

    assert(EQUALS(p, L"a1"));

    // Verifica se aborta ao comparar com uma referência inexistente
    running_rule = 666;
    int aborted = setjmp(abort_rule);
    if(!aborted){
        EQUALS(p, L"s4");
    }

    assert(aborted);

}
