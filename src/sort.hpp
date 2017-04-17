#include <string>
#include <iostream>
#include<fstream>
#include <ctime>
#include <cstdlib>
#include <vector>


using namespace std;

class Sort{

  protected:

    vector<int> vetor;
    long int comparacoes;
    long int trocas;


  public:


    Sort(){
      comparacoes = 0;
      trocas = 0;
    }

    int getSize(){
      return vetor.size();
    }

    
    void randomPop(int tamanho){
      int i = 0;
      srand((int)time(0));
      for(i=0;i<tamanho;i++){
        vetor.push_back((rand() % 100) + 1);
      }
      
    }

    int getElementAt(int index){
      return vetor[index];
    }

    void mergeSort(int inicio, int fim){
      int meio = (inicio + fim)/2;
      if (inicio < fim){
        mergeSort(inicio, meio);
        mergeSort(meio+1, fim);
        merge(inicio, meio, fim);
      }
    }

    void merge(int inicio, int meio, int fim){
      int aux[fim - inicio + 1];
      int pos = 0;
      int pos_esquerda = inicio;
      int pos_direita = meio+1;

      while (pos_esquerda <= meio && pos_direita <= fim){
        if (vetor[pos_esquerda] < vetor[pos_direita])
        {
          aux[pos] = vetor[pos_esquerda];
          pos++;
          pos_esquerda++;
        }
        else
        {
          aux[pos] = vetor[pos_direita];
          pos++;
          pos_direita++;
        }
      }
      while (pos_esquerda <= meio){
        aux[pos] = vetor[pos_esquerda];
        pos++;
        pos_esquerda++;
      }
      while (pos_direita <= fim) {
        aux[pos] = vetor[pos_direita];
        pos++;
        pos_direita++;
      }
      int iter;
      for (iter = 0; iter < pos; iter++) {
        vetor[iter + inicio] = aux[iter];
      }
    }

    void quickSortRandom(int inicio, int fim){
      int pivo, aux, esquerda, direita, meio;

      esquerda = inicio;
      direita = fim;
      srand((int)time(0));
      pivo = vetor[inicio + (rand() % (fim - inicio + 1))];
      
      do{
        while (vetor[esquerda] < pivo) esquerda++;
        while (vetor[direita] > pivo) direita--;

        if(esquerda <= direita){
           aux = vetor[esquerda];
           vetor[esquerda] = vetor[direita];
           vetor[direita] = aux;
           esquerda++;
           direita--;
        }
      }while(direita > esquerda);

      if(inicio < direita) quickSortRandom(inicio, direita);
      if(esquerda < fim) quickSortRandom(esquerda, fim);
    }

    void quickSortFirst(int inicio, int fim){
      int pivo, aux, esquerda, direita, meio;

      esquerda = inicio;
      direita = fim;

      // meio = (int) ((esquerda + direita) / 2);
      pivo = vetor[inicio];

      do{
        while (vetor[esquerda] < pivo) esquerda++;
        while (vetor[direita] > pivo) direita--;

        if(esquerda <= direita){
           aux = vetor[esquerda];
           vetor[esquerda] = vetor[direita];
           vetor[direita] = aux;
           esquerda++;
           direita--;
        }
      }while(direita > esquerda);

      if(inicio < direita) quickSortFirst(inicio, direita);
      if(esquerda < fim) quickSortFirst(esquerda, fim);
    }

    void quickSortLast(int inicio, int fim){
      int pivo, aux, esquerda, direita, meio;

      esquerda = inicio;
      direita = fim;

      // meio = (int) ((esquerda + direita) / 2);
      pivo = vetor[fim];

      do{
        while (vetor[esquerda] < pivo) esquerda++;
        while (vetor[direita] > pivo) direita--;

        if(esquerda <= direita){
           aux = vetor[esquerda];
           vetor[esquerda] = vetor[direita];
           vetor[direita] = aux;
           esquerda++;
           direita--;
        }
      }while(direita > esquerda);

      if(inicio < direita) quickSortLast(inicio, direita);
      if(esquerda < fim) quickSortLast(esquerda, fim);
    }
    

    void quickSortMedium(int inicio, int fim){
      int pivo, aux, esquerda, direita, meio;

      esquerda = inicio;
      direita = fim;

      meio = (int) ((esquerda + direita) / 2);
      pivo = vetor[meio];

      do{
        while (vetor[esquerda] < pivo) esquerda++;
        while (vetor[direita] > pivo) direita--;

        if(esquerda <= direita){
           aux = vetor[esquerda];
           vetor[esquerda] = vetor[direita];
           vetor[direita] = aux;
           esquerda++;
           direita--;
        }
      }while(direita > esquerda);

      if(inicio < direita) quickSortMedium(inicio, direita);
      if(esquerda < fim) quickSortMedium(esquerda, fim);
    }

    void insertionSort()    
    {
      int elementos = vetor.size();
      int iter,jter;
      for(iter=1;iter<elementos;iter++)
      {
        int elem_atual = vetor[iter];
        jter = iter-1;
        while(jter>=0 && vetor[jter] > elem_atual)
        {
          comparacoes++;
          vetor[jter+1] = vetor[jter];
          trocas++;
          jter--;
        }
        vetor[jter+1] = elem_atual;
      }
    }

    void selectionSort()
    {
      int elementos = vetor.size();
      int iter,jter,minIndex,temp;
      for(iter = 0;iter<elementos;iter++)
      {
        minIndex = iter;
        for(jter = iter+1; jter<elementos;jter++)
        {
          comparacoes++;
          if(vetor[jter] < vetor[minIndex]){
            minIndex = jter;
          }
        }
          temp = vetor[iter];
          vetor[iter] = vetor[minIndex];
          vetor[minIndex] = temp;
          trocas++;
      }
    }

    int readFile(char  const *arquivo){
      ifstream File;
      File.open(arquivo);

      int n;                     // ****
      while (File >> n) {        // ****
        vetor.push_back(n);      // ****
      }
      File.close();

      

      return 0;
    }

    int printData(){
      int n;
      for (auto n : vetor) {      // ****
        cout << n << endl;    // ****
      }
      return 0;
    }

    
	



};
