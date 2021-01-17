void test(){

    n_words = 2;

    w_strs[0] =  L"alugo";
    w_load_lists(0);

    w_strs[1] =  L"algo";
    w_load_lists(1);

    assert(w_lists[0][LID_VER]);
    assert(!w_lists[0][LID_PRO]);

    assert(!w_lists[1][LID_VER]);
    assert(w_lists[1][LID_PRO]);


}
