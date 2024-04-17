#include <stdio.h>
#include <stdlib.h>

#define MAX_TIMES 20

int main() {
    int n;
    int vitorias[MAX_TIMES] = {0};
    int empates[MAX_TIMES] = {0};
    int derrotas[MAX_TIMES] = {0};
    int gols_mandante[MAX_TIMES][MAX_TIMES] = {{0}};
    int gols_visitante[MAX_TIMES][MAX_TIMES] = {{0}};

    int i, j;

    printf("Entre com o numero de times participantes: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("\nNumero de times participantes deve ser maior ou igual a 2\n");
         printf("\nEntre com o numero de times participantes: ");
    scanf("%d", &n);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) continue;

            int gols_mand, gols_visit;
            do {
                printf("\nPlacar time%d x time%d: ", i + 1, j + 1);
                scanf("%d %d", &gols_mand, &gols_visit);

                if (gols_mand < 0 || gols_visit < 0) {
                    printf("\nNumero de gols de cada time no placar deve ser maior ou igual a zero\n");
                }
            } while (gols_mand < 0 || gols_visit < 0);

            gols_mandante[i][j] = gols_mand;
            gols_visitante[i][j] = gols_visit;

            if (gols_mandante[i][j] > gols_visitante[i][j])
                vitorias[i]++;
            else if (gols_mandante[i][j] < gols_visitante[i][j])
                derrotas[i]++;
            else
                empates[i]++;

            if (gols_visitante[i][j] > gols_mandante[i][j])
                vitorias[j]++;
            else if (gols_visitante[i][j] < gols_mandante[i][j])
                derrotas[j]++;
            else
                empates[j]++;
        }
    }

    int max_vitorias = 0, max_derrotas = 0, max_empates = 0;
    printf("\nTime(s) com mais vitorias:");
    for (i = 0; i < n; i++) {
        if (vitorias[i] > max_vitorias)
            max_vitorias = vitorias[i];
    }
    for (i = 0; i < n; i++) {
        if (vitorias[i] == max_vitorias)
            printf(" %d com %d vitorias", i + 1, max_vitorias);
    }

    printf("\nTime(s) com mais derrotas:");
    for (i = 0; i < n; i++) {
        if (derrotas[i] > max_derrotas)
            max_derrotas = derrotas[i];
    }
    for (i = 0; i < n; i++) {
        if (derrotas[i] == max_derrotas)
            printf(" %d com %d derrotas", i + 1, max_derrotas);
    }

    printf("\nTime(s) com mais empates:");
    for (i = 0; i < n; i++) {
        if (empates[i] > max_empates)
            max_empates = empates[i];
    }
    for (i = 0; i < n; i++) {
        if (empates[i] == max_empates)
            printf(" %d com %d empates", i + 1, max_empates);
    }

    int max_diff = 0;
    printf("\nMaior diferenca de gols foi de ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) continue;
            int diff = abs(gols_mandante[i][j] - gols_visitante[i][j]);
            if (diff > max_diff) max_diff = diff;
        }
    }
    printf("%d gols nos jogos:", max_diff);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) continue;
            int diff = abs(gols_mandante[i][j] - gols_visitante[i][j]);
            if (diff == max_diff) {
                printf(" time%d x time%d;", i + 1, j + 1); }
        }
    }
    printf("\n");

    return 0;
}




