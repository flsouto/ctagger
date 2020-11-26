
int cond1(){
    return ABORT();
}

int cond2(){
    return 1;
}

int cond3(){
    return 1;
}

// cond1 vai invalidar a regra inteira, mesmo cond2 e cond3 retornando true, pois condi1 usa ABORT()
int rule666(){
    running_rule = 666;
    if(setjmp(abort_rule)) return 0;
    int result = cond1() || cond2() || cond3();
    running_rule = 0;
    return result;
}

// essa regra deve retornar true
int rule667(){
    running_rule = 667;
    if(setjmp(abort_rule)) return 0;
    int result = cond2() || cond3();
    running_rule = 0;
    return result;
}

void test(){

    assert(!rule666());
    assert(rule667());

    // testa se abort retorna false quando não estamos executando nenhuma regras
    assert(!cond1());

}
