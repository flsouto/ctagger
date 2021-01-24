int * get_lists_m(wchar_t * word){
    int * result;
    result = malloc(sizeof(int));
    switch(word[1]){
        case L'u' :
            switch(word[2]){
                case L'i' :
                    switch(word[3]){
                        case 't' :
                            switch(word[4]){
                                case 'o' :
                                    switch(word[5]){
                                        case '\0' :
                                        // Muito
                                            result = malloc(sizeof(int) * 2);
                                            result[0] = LID_ADV;
                                        break;
                                    }
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
