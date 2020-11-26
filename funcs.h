#define EXISTS(index) ( index > -1 && index < n_words )
#define PREDET(index, tag) ( EXISTS(index) && w_tags[index][tag] )
#define LISTA(index, list) ( EXISTS(index) && w_lists[index][list] )

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

// Aborta regra sendo executada, ignorando todas as outras condiçõe
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

    // todo check if str is a1 - a9 / s1 - s9 and use VAR instead

    return wcscasecmp(w_strs[index], str) == 0;
}


// todo EQUALS_ANY
// todo LISTA_ANY
// todo PREDET ALL
// todo LISTA_SUB
// todo NOP(from, to)
// todo VERBEX
// todo LIKE
// todo LEN
