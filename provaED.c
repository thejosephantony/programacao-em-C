// 2

typedef struct Atleta{
    char nome[100];
    int matricula;
    float NotaFinal;
    struct Atleta *proxNo;
    struct Atleta *antNo;
} Atleta;


Atleta* inserirAtleta(Atleta *inicio, char nome[100], int matricula, float notaFinal){
    
}