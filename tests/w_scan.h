void test(){

    wchar_t * text = L"Alugo algo, muito caro.";

    for(int w_index=0, t_pos=0; w_scan(w_index, text, &t_pos); w_index++, t_pos++){
        w_load_lists(w_index);
    }
    assert(!wcscmp(w_strs[0],L"Alugo"));
    assert(!wcscmp(w_strs[1],L"algo"));
    assert(w_puncts[1] == ',');
    assert(!wcscmp(w_strs[2],L"muito"));
    assert(!wcscmp(w_strs[3],L"caro"));
    assert(w_puncts[3] == '.');
    assert(w_lists[0][LID_VER]);
    assert(w_lists[1][LID_PRO]);
    assert(w_lists[2][LID_ADV]);
    assert(w_lists[3][LID_ADJ]);
    assert(w_lists[3][LID_MAS]);

}
