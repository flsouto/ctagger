void test(){

    n_words = 2;
    w_strs[0] = L"arcaico";
    w_strs[1] = L"lesma";

    assert(EQUALS_ANY(p, (wchar_t *[]){L"arca",L"arcaico",0}));
    assert(!EQUALS_ANY(s1, (wchar_t *[]){L"less",L"esmo",0}));

}
