// Converte uma referência (a1...a9, s1..s9) para a sua posição correspondente
// Retorna -1 caso não for uma referência válida
int ref2index(wchar_t * ref){

    if(ref[0]=='p' && !ref[1]){
        return p;
    }
    else if((ref[0] == L'a' || ref[0] == L's') && ref[1] >= L'0' && ref[1] <= L'9'){

        if(ref[0] == L'a'){
            return p - (ref[1] - L'0');
        } else {
            return p + (ref[1] - L'0');
        }
    }

    return -1;
}

// Roda uma lista de regras sobre as palavras da frase
// até que não haja mais mudanças ou esteja tudo determinado
int iterate(int (*rules[10000])(void)){

    int changes;

    do {
        changes = 0;

        for(p=0; p < n_words; p++){

            // Pula palavras já determinadas
            if(w_determined[p]){
                continue;
            }

            // Percorre todas as regras
            for(int r=0;rules[r];r++){
                running_rule = r;
                if(setjmp(abort_rule)) continue;
                if(rules[r]()) changes++;
            }
        }

        iterations++;

    } while(changes);

    return iterations;
}
