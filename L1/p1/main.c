#include <stdio.h>
#include <stdlib.h>
 
#define MAX_ALUNOS 50
 
typedef struct {
    float notas[4];
    float media_final;
} Aluno;
 
float calcular_media_final(float notas[]) {
    float pesos[4] = {2.5, 2.5, 2.5, 2.5};
    int i, j, k;
    float media_final = 0;
 
    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 4; j++) {
            if (notas[i] < notas[j]) {
                float temp = notas[i];
                notas[i] = notas[j];
                notas[j] = temp;
            }
        }
    }
 
    if (notas[0] != notas[1] && notas[1] != notas[2] && notas[2] != notas[3]) {
        for (i = 0; i < 4; i++) {
            pesos[i] = 4 - i;
        }
    } else if (notas[0] == notas[1] && notas[0] == notas[2] && notas[0] == notas[3]) {
        for (i = 0; i < 4; i++) {
            pesos[i] = pesos[i];
        }
    } else if (notas[0] == notas[1] && notas[2] != notas[3]) { 
        pesos[3] = 1;
        for (i = 0; i < 3; i++) { 
            pesos[i] = 3; 
        }
    } else if (notas[3] == notas[2] && notas[0] != notas[1]) { 
        pesos[0] = 4;
        for (i = 1; i < 4; i++) { 
            pesos[i] = 2;
        }
    }
 
    for (i = 0; i < 4; i++) {
        media_final += notas[i] * pesos[i];
    }
    media_final /= 10;
 
    return media_final;
}
 
int main() {
    int num_alunos, i;
    Aluno alunos[MAX_ALUNOS];
    float soma_medias = 0, media_geral, maior_media = 0, menor_media = 10;
 
    printf("Entre com o numero de alunos da turma: ");
    scanf("%d", &num_alunos);
 
    while(num_alunos == 0 || num_alunos > MAX_ALUNOS) {
        printf("\nO numero de alunos na turma deve ser maior do que zero e menor ou igual a 50\n");
        printf("\nEntre com o numero de alunos da turma: ");
        scanf("%d", &num_alunos);
    }
 
    for (i = 0; i < num_alunos; i++) {
        printf("\nNotas aluno %d: ", i + 1);
        scanf("%f %f %f %f", &alunos[i].notas[0], &alunos[i].notas[1], &alunos[i].notas[2], &alunos[i].notas[3]);
int j;
        for (j = 0; j < 4; j++) {
            while (alunos[i].notas[j] < 0 || alunos[i].notas[j] >= 10) {
                printf("\nTodas as notas do aluno devem ser maiores ou iguais a zero e menores ou iguais a 10\n");
                printf("\nNotas aluno %d: ", i + 1);
                scanf("%f %f %f %f", &alunos[i].notas[0], &alunos[i].notas[1], &alunos[i].notas[2], &alunos[i].notas[3]);
            }
        }
 
        alunos[i].media_final = calcular_media_final(alunos[i].notas);
 
        printf("\nMedia final do aluno %d: %.1f\n", i + 1, alunos[i].media_final);
 
        soma_medias += alunos[i].media_final;
 
        if (alunos[i].media_final > maior_media) {
            maior_media = alunos[i].media_final;
        }
        if (alunos[i].media_final < menor_media) {
            menor_media = alunos[i].media_final;
        }
    }
 
    media_geral = soma_medias / num_alunos;
 
    printf("\nMedia geral da turma: %.1f\n", media_geral);
    printf("\nMaior media da turma: %.1f (Alunos:", maior_media);
    for (i = 0; i < num_alunos; i++) {
        if (alunos[i].media_final == maior_media) {
            printf(" %d", i + 1);
        }
    }
    printf(")\n");
    printf("\nMenor media da turma: %.1f (Alunos:", menor_media);
    for (i = 0; i < num_alunos; i++) {
        if (alunos[i].media_final == menor_media) {
            printf(" %d", i + 1);
        }
    }
    printf(")\n");
 
    return 0;
}