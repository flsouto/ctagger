void test(){

    n_words = 2;
    w_strs[0] = L"blah";
    w_strs[1] = L"casco";

    // Test case: start with X
    assert(LIKE(p, L"b*"));
    assert(LIKE(p, L"bl*"));
    assert(LIKE(p, L"bla*"));
    assert(!LIKE(p, L"blah*"));

    // Test case: contains X in middle
    assert(LIKE(s1, L"*s*"));
    assert(LIKE(s1, L"*sc*"));
    assert(LIKE(s1, L"*asc*"));
    assert(!LIKE(s1, L"*esc*"));
    assert(!LIKE(s1, L"*e*"));
    assert(!LIKE(s1, L"*o*"));
    assert(!LIKE(s1, L"*casco*"));

    // Test case: ends with X
    assert(LIKE(s1,L"*o"));
    assert(LIKE(s1,L"*co"));
    assert(LIKE(s1,L"*sco"));
    assert(LIKE(s1,L"*asco"));
    assert(!LIKE(s1,L"*casco"));


}
