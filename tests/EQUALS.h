void test(){

    n_words = 2;
    w_strs[0] = L"çatã";
    w_strs[1] = L"blah";

    assert(EQUALS(p, L"çATã"));
    assert(EQUALS(s1, L"blah"));
    assert(DIFF(s1, L"halb"));
}
