#include <stdio.h>

// função que caucula a media das notas dos aluno
float calcularMediaTurma(float notaFinal[], int numAluno) {
    float soma = 0.00;
    //Repetição para armazenar as notas e somar
    for (int i = 0; i < numAluno; i++) {
        soma += notaFinal[i];
    }
    //validação do codigo
    if (numAluno > 0) {
        float media = soma / numAluno;
        //retorna a media das notas caso o numero de aluno for menor de 0
        return media;
    } else {
        return 0.0f;
    }
}


void exibirStatusAlunos(float notaFinal[], int numAluno){
    for (int i = 0; i < numAluno; i++) {
        

        if (notaFinal[i] >= 7.0) {
            printf("Aprovado\n");
        } else if (notaFinal[i] >= 5.0 && notaFinal[i] < 7.0) {
            printf("Em recuperacao\n");
        } else { 
            printf("Reprovado\n");
        }
    }
}

int main() {
    int numAluno;
    //solicita o numero de alunos
    printf("Quantos alunos a turma possui? ");
    scanf("%d", &numAluno);

    // vetor que armazena as notas
    float notaFinal[numAluno];

    // laço de repetição para inserir as notas ao vetor
    for (int i = 0; i < numAluno; i++) {
        printf("Qual a nota final do aluno?");
       
        scanf("%f", &notaFinal[i]); 
    }

    float mediaTurma = calcularMediaTurma(notaFinal, numAluno);
    printf("A media da turma e: %.2f\n", mediaTurma);
    exibirStatusAlunos(notaFinal, numAluno);
}