int * get_lists_c(wchar_t * word){
    int * result;
    result = malloc(sizeof(int));
    switch(word[1]){
        case L'a' :
            switch(word[2]){
                case L'r' :
                    switch(word[3]){
                        case 'o' :
                            switch(word[4]){
                                case '\0' :
                                // Caro
                                    result = malloc(sizeof(int) * 3);
                                    result[0] = LID_ADJ;
                                    result[1] = LID_MAS;
                                break;
                            }
                        break;
                    }
                break;
            }
        break;
    }
    return result;
}
