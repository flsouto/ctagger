void test(){

    n_words = 5;
    w_puncts[0] = ',';
    w_puncts[4] = '?';

    assert(PONT_ANY(p, ","));
    assert(PONT_ANY(p, ",."));
    assert(PONT_ANY(p, ".,"));
    assert(!PONT_ANY(p, ";."));
    assert(PONT_ANY(s4, ";?."));
    assert(!PONT_ANY(s4, ";!."));


}
