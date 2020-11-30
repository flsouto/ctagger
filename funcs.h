#define EXISTS(index) ( index > -1 && index < n_words )
#define PREDET(index, tag) ( EXISTS(index) && w_tags[index][tag] )
#define LISTA(index, list) ( EXISTS(index) && w_lists[index][list] )
#define VERBEX(index) ( \
    EXISTS(index) && (\
        PREDET(index, verbo) \
        || PREDET(index, infinitivo) \
        || PREDET(index, infinitivoPessoal) \
        || PREDET(index, locucaoVerbal) \
        || PREDET(index, gerundio) \
        || PREDET(index, participio) \
        || PREDET(index, verboTempoComposto) \
    ) \
)

// Deterina a palavra atual (p) com uma única tag
void DET(enum tag tag){
    if(!w_tags[p][tag]){
        return;
    }
    for(int t=1; t<=N_TAGS; t++){
        w_tags[p][t] = t == tag;
    }
    w_determined[p] = tag;
    n_changes++;
}

// Remove uma tag da palavra atual (p) e verifica se ela ficou determina
void REM(enum tag tag){
    if(!w_tags[p][tag]){
        return;
    }
    w_tags[p][tag] = 0;
    enum tag determined_as = 0;
    for(int t=1; t<=N_TAGS; t++){
        if(!w_tags[p][t]) {
            continue;
        }
        if(!determined_as) {
            determined_as = t;
        } else {
            determined_as = w_determined[p] = 0;
            break;
        }
    }
    if(determined_as){
        w_determined[p] = determined_as;
    }
    n_changes++;
}

// Aborta regra sendo executada, ignorando/pulando todas as outras condições
int ABORT(){
    if(running_rule){
        longjmp(abort_rule, 1);
    }
    return 0;
}

// Verifica se a palavra possui exatamente uma tag
int PREDET_EXACT(int index, enum tag tag){
    if(!PREDET(index, tag)){
        return 0;
    }
    for(int t=0; t<=N_TAGS; t++){
        if(t != tag && w_tags[index][t]){
            return 0;
        }
    }
    return 1;
}

// Verifica se a palavra possui exatamente as N tags passadas
int PREDET_EXACT_MULTI(int index, enum tag tags[]){
    for(int i=0; tags[i]; i++){
        if(!PREDET(index, tags[i])){
            return 0;
        }
    }
    for(int t=1; t<=N_TAGS; t++){
        if(w_tags[index][t]){
            int found = 0;
            for(int i=0; tags[i]; i++){
                if(tags[i] == t){
                    found = 1;
                    break;
                }
            }
            if(!found){
                return 0;
            }
        }
    }
    return 1;
}

// Verifica se palavra está em determinada posição
int INDEX(int index, int pos){
    if(pos < 0){
        return index == n_words + pos;
    }
    return index == pos-1;
}

// Verifica se a palavra tem determinada pontuação
int PONT(int index, char punct){
    if(punct == '*' && w_puncts[index]){
        return w_puncts[index];
    }
    return w_puncts[index] == punct;
}

// Verifica se a palavra tem pelo menos algum das pontuações listadas
int PONT_ANY(int index, char * puncts){

    if(!w_puncts[index]){
        return 0;
    }

    for(int i = 0; puncts[i]; i++){
        if(w_puncts[index] == puncts[i]){
            return 1;
        }
    }

    return 0;

}

// Verifica se a palavra na posição X é igual a outra
int EQUALS(int index, wchar_t * str){

    // Impossível comparar com algo não existente
    if(!EXISTS(index)){
        return ABORT();
    }

    int index2 = ref2index(str);
    wchar_t * cmpwith;

    if(index2 != -1){
        if(!EXISTS(index2)){
            return ABORT();
        }
        cmpwith = w_strs[index2];
    } else {
        cmpwith = str;
    }

    return wcscasecmp(w_strs[index], cmpwith) == 0;
}

// Verifica se a palavra atende um padrão de pesquisa
// Formatos suportados: prefix*, *sufix, *middle*
int LIKE(int index, wchar_t * pattern){

    if(!EXISTS(index)){
        return ABORT();
    }

    int plen = wcslen(pattern);
    int slen = wcslen(w_strs[index]);

    // A string precisa ser no mínimo do mesmo tamanho que o pattern
    if(slen < plen){
        return 0;
    }

    // PREFIX: não começa com * (exemplo: anti*)
    if(pattern[0] != L'*'){

        // Verifica se todos os chars até * são iguais ao da string
        for(int i = 0; pattern[i] && pattern[i]!=L'*'; i++){
            if(!w_strs[index][i]){
                return 0;
            }
            if(towlower(pattern[i]) != towlower(w_strs[index][i])){
                return 0;
            }
        }
        return 1;
    } else {
        // MIDDLE: começa e termina com * (ex.: *sc*)
        if(pattern[plen-1] == L'*'){
            // temos que verificar se, por exemplo, "sc" está dentro da string
            // desconsiderando primeiro e último caracteres
            for(int si = 1; si < slen - (plen - 2); si++){
                if(towlower(pattern[1]) != towlower(w_strs[index][si])){
                    continue;
                }
                int found = 1;
                for(int pi = 2; pi <= plen-2; pi++){
                    if(towlower(pattern[pi]) != towlower(w_strs[index][si+(pi-1)])){
                        found = 0;
                        break;
                    }
                }
                if(found){
                    return 1;
                }
            }
            return 0;
        } else {
            // SUFIX: Apenas começa com * (ex.: *ar)
            for(int pi=1; pi < plen; pi++){
                if(towlower(pattern[pi]) != towlower(w_strs[index][slen - (plen-pi)])){
                    return 0;
                }
            }
            return 1;
        }

    }

    return 0;

}

// Verifica se há pontuação entre duas posições,
int NOP(int from, int to){
    // Casos de invalidez
    if(from > to || !EXISTS(from) || !EXISTS(to)){
        return ABORT();
    }
    // Não tem como haver pontuação entre uma palavra e ela mesma
    if(from == to){
        return 1;
    }
    // Retorna falso na primeira pontuação encontrada
    for(int i=from; i<to; i++){
        if(w_puncts[i]){
            return 0;
        }
    }
    // Nenhuma pontuação encontrada
    return 1;
}

// Verifica se a palavra possui tag com uma subclasse predeterminada ou lista
// Exemplo na sintaxe conhecida do tagger: p PREDET substantivo[320,259]
int PREDET_SUB(int index, enum tag tag, int subs[]){
    if(!PREDET(index, tag)){
        return 0;
    }
    // Quando a subclasse já foi determinada
    if(w_subs[index]){
        for(int i=0; subs[i]; i++){
            // Algum tem que ser igual ao que já está determinado
            if(w_subs[index] == subs[i]){
                return 1;
            }
        }
        return 0;
    } else {
    // Quando a subclasse ainda não foi determinada
        for(int i=0; subs[i]; i++){
            // Algum tem que ser igual ao que está numa das possíveis listas para esta palavra
            if(w_lists[index][subs[i]]){
                return 1;
            }
        }
        return 0;
    }
}

// Verifica se a palavra é igual a qualquer uma de uma lista de strings
int EQUALS_ANY(int index, wchar_t * strs[]){
    for(int i=0; strs[i]; i++){
        if(EQUALS(index, strs[i])){
            return 1;
        }
    }
    return 0;
}

// Verifica se a palavra está em alguma das listas
int LISTA_ANY(int index, int lists[]){
    for(int i=0; lists[i]; i++){
        if(LISTA(index, lists[i])){
            return 1;
        }
    }
    return 0;
}

// Verifica se a palavra possui todas as tags
int PREDET_ALL(int index, enum tag tags[]){
    for(int i=0; tags[i]; i++){
        if(!PREDET(index, tags[i])){
            return 0;
        }
    }
    return 1;
}

// Verifica se o número de caracteres da palavra está dentro de um range
int LEN(int index, int min, int max){
    if(!EXISTS(index)){
        return ABORT();
    }
    int len = wcslen(w_strs[index]);
    return len >= min && len <= max;
}
