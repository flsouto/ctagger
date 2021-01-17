int * get_lists_a(wchar_t * word){
    int * result;
    result = malloc(sizeof(int));
    switch(word[1]){
        case L'l' :
            switch(word[2]){
                case L'g' :
                    switch(word[3]){
                        case L'o' :
                            switch(word[4]){
                                case '\0' :
                                // Algo
                                    result = malloc(sizeof(int) * 2);
                                    result[0] = LID_PRO;
                                    return result;
                                break;
                            }
                        break;
                    }
                break;
                case L'u' :
                    switch(word[3]){
                        case 'g' :
                            switch(word[4]){
                                case 'o' :
                                    switch(word[5]){
                                        case '\0' :
                                        // Alugo
                                            result = malloc(sizeof(int) * 2);
                                            result[0] = LID_VER;
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
