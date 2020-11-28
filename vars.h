enum tag {
    artigo = 1,
    substantivo = 2,
    adjetivo = 3,
    adverbio = 4,
    pronome = 5,
    verbo = 6,
    infinitivo = 7,
    infinitivoPessoal = 8,
    locucaoVerbal = 9,
    gerundio = 10,
    participio = 11,
    verboTempoComposto = 12,
    tag_end
};

#define N_TAGS tag_end-1
#define N_LISTS 1000
#define W_MAX 50

#define s1 (p + 1)
#define s2 (p + 2)
#define s3 (p + 3)
#define s4 (p + 4)
#define s5 (p + 5)
#define s6 (p + 6)
#define s7 (p + 7)
#define s8 (p + 8)
#define s9 (p + 9)

#define a1 (p - 1)
#define a2 (p - 2)
#define a3 (p - 3)
#define a4 (p - 4)
#define a5 (p - 5)
#define a6 (p - 6)
#define a7 (p - 7)
#define a8 (p - 8)
#define a9 (p - 9)

// Posição atual da iteração
int p = 0;

// Indica número de palavras na frase
int n_words;

// Indica tags determinadas para cada palavra na frase
int w_tags[W_MAX][N_TAGS];

// Indica as listas em que cada palavra da frase está
int w_lists[W_MAX][N_LISTS];

// Indica a subclasse que foi determinada para cada palavra da frase
int w_subs[W_MAX];

// Indica se há ponto depois de cada palavra
char w_puncts[W_MAX];

// Strings das palavras
wchar_t * w_strs[W_MAX];

// Indica quais palavras já foram determinadas
int w_determined[W_MAX];

// Indica o número de mudanças ocorridas durante a iteração
int n_changes = 0;

// Indica qual a regra que está sendo executada no momento
int running_rule = 0;

// Utilizada para "pular fora" da regra caso alguma incompatibilidade ocorra em uma de suas condições
static jmp_buf abort_rule;
