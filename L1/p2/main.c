#include <stdio.h>
#include <stdlib.h>

void recebeTemperatura(int *v, int tam){
  printf("Temperaturas medidas (em graus Celsius):\n\n");
  
  int *ponteiroArray = v;
  int verif = -101;
  int i;

  for (i = 0; i < tam; i++) {
    do { 
    
      printf("Dia %d: ", i+1);
        scanf("%d", &verif);
    printf("\n");
   
    if (verif < -100 || verif > 100) {
      printf("Temperatura deve ser maior ou igual a -100 graus e menor ou igual a 100 graus\n\n");
      }
    } while (verif < -100 || verif > 100);
    
    *(ponteiroArray) = verif;

    ponteiroArray++;
  }
}

int tempe(int *v, int tam){
  int maior = v[0];
  int i;

  for (i = 1; i<tam; i++) {
    if (maior < v[i]) {
      maior = v[i];
    }
  }
  return maior;
}

int quantidadeDias(int *v, int tam, int maiorTemp){
  int quantidade = 0;
  int i;

  for (i = 0; i < tam; i++) {
    if(v[i] == maiorTemp) {
      quantidade++;
    }
  }
  return quantidade;
}

void maiorDia(int *v, int tam, int maiorTemp, int *maiorDias){
  int contador = 0;
  int i;

  for (i = 0; i<tam; i++) {
    if (v[i] == maiorTemp) {
      maiorDias[contador] = i+1;
      contador++;
    } 
  }
}

void imprimeDias(int *v, int tam) {
  int i;

  for (i = 0; i < tam; i++) {
    printf(" %d", v[i]);
  }
}

float Media(int *v, int tam){
  float media;
  float soma = 0;
  int i;
    
  for (i = 0; i < tam; i++) {
    soma = soma + v[i];
  }
  media = soma / tam;
  
  return media;
}

int main(int argc, char *argv[])
{

  int ano = 0;
  int mes = 0;
  int numDias;



  printf("Entre com o ano da medicao das temperaturas: ");
    scanf("%d", &ano);
  printf("\n");


  if (ano <= 2000 || ano>2024){
    printf("Ano deve ser maior ou igual a 2000 e menor ou igual a 2024\n\n");
    printf("Entre com o ano da medicao das temperaturas: ");
      scanf("%d", &ano);
    printf("\n");
    }


  printf("Entre com o mes da medicao das temperaturas: ");
    scanf("%d", &mes);
printf("\n");
    

  if (mes <= 0 || mes > 12){
    printf("Mes deve ser maior do que zero e menor ou igual a 12\n\n");
      printf("Entre com o mes da medicao das temperaturas: ");
    scanf("%d", &mes);
    printf("\n");
    }

 
  switch(mes) {
      case 1: case 3: case 5: case 7: case 8: case 10: case 12:
          numDias = 31;
          break;
      case 4: case 6: case 9: case 11:
          numDias = 30;
          break;
      case 2:
          if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
            numDias = 29;
          } else {
            numDias = 28;
          }
          break;
      default:
          printf("Mês inválido!\n");
    }

  int *temperaturas = malloc(numDias * sizeof(int));

  recebeTemperatura(temperaturas, numDias);
  int maiorTemperatura = tempe(temperaturas, numDias);

  int numMaiorDias = quantidadeDias(temperaturas, numDias, maiorTemperatura);

  int *maioresDias = malloc(numMaiorDias * sizeof(int));
  
  maiorDia(temperaturas, numDias, maiorTemperatura, maioresDias);
 

  printf("A maior temperatura maxima do mes foi de %d e aconteceu nos dias: ", maiorTemperatura);
  imprimeDias(maioresDias,numMaiorDias);
  printf("\n\n");

  printf("A temperatura maxima media no mes foi de: %.1f graus Celsius", Media(temperaturas, numDias));

  
  free(temperaturas);
  free(maioresDias);

  return 0;
}

