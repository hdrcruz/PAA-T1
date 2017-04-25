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
    string algoritmo;
    double tempo;


  public:


    Sort(){
      comparacoes = 0;
      trocas = 0;
    }

    void setAlgoritmo(string algoritmo){
      this->algoritmo = algoritmo;
    }

    void setTempo(double tempo){
      this->tempo = tempo;
    }

    int getSize(){
      return vetor.size();
    }

    
    void randomPop(int tamanho){
      int i = 0;
      srand((int)time(0));
      for(i=0;i<tamanho;i++){
        vetor.push_back((rand() % tamanho) + 1);
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
        comparacoes++;
        if (vetor[pos_esquerda] <= vetor[pos_direita])
        {
          // trocas++;
          aux[pos] = vetor[pos_esquerda];
          pos++;
          pos_esquerda++;
        }
        else
        {
          trocas++;
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

    

    
    void quickSortMedium(int inicio, int fim){
      int pivo, aux, esquerda, direita, meio;

      esquerda = inicio;
      direita = fim;

      meio = (int) ((esquerda + direita) / 2);
      pivo = vetor[meio];

      do{
        while (vetor[esquerda] < pivo){
          esquerda++;
          comparacoes++;
        }
        while (vetor[direita] > pivo){
          direita--;
          comparacoes++;
        }

        if(esquerda <= direita){
          trocas++;
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

    void quickSortFirst(int inicio, int fim){
      int pivo, aux, esquerda, direita, meio;

      esquerda = inicio;
      direita = fim;

      // meio = (int) ((esquerda + direita) / 2);
      pivo = vetor[inicio];

      do{
        while (vetor[esquerda] < pivo){
          esquerda++;
          comparacoes++;
        }
        while (vetor[direita] > pivo){
          direita--;
          comparacoes++;
        }

        if(esquerda <= direita){
          trocas++;
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
        while (vetor[esquerda] < pivo){
          esquerda++;
          comparacoes++;
        }
        while (vetor[direita] > pivo){
          direita--;
          comparacoes++;
        }

        if(esquerda <= direita){
          trocas++;
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



    void quickSortRandom(int inicio, int fim){
      int pivo, aux, esquerda, direita, meio;

      esquerda = inicio;
      direita = fim;

      // meio = (int) ((esquerda + direita) / 2);
      srand((int)time(0));
      pivo = vetor[inicio + (rand() % (fim - inicio + 1))];

      do{
        while (vetor[esquerda] < pivo){
          esquerda++;
          comparacoes++;
        }
        while (vetor[direita] > pivo){
          direita--;
          comparacoes++;
        }

        if(esquerda <= direita){
          trocas++;
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

    void insertionSort()    
    {
      int i,j,temp;
      int elementos = vetor.size();
      // int iter,jter;
      // for(iter=1;iter<elementos;iter++)
      // {
      //   int elem_atual = vetor[iter];
      //   jter = iter+1;
      //   // comparacoes++;
      //   while(jter>=0 && vetor[jter] > elem_atual)
      //   {
      //     comparacoes++;
      //     vetor[jter+1] = vetor[jter];
      //     trocas++;
      //     jter--;
      //   }
      //   vetor[jter+1] = elem_atual;
      // }
      for (i = 1; i < elementos; i++)
      {
          for (j = i; j >= 1; j--)
          {
              comparacoes++;
              if (vetor[j] < vetor[j-1])
              {
                  trocas++;
                  temp = vetor[j];
                  vetor[j] = vetor[j-1];
                  vetor[j-1] = temp;
              }
              else
                  break;
          }
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

    int saveFile(char  const *arquivo){
      ofstream myfile (arquivo);
      int n;
      if (myfile.is_open()){
        for (auto n : vetor) {      // ****
          myfile << n << " ";    // ****
        }
        myfile.close();
      }
      
      return 0;
    }

    int saveStats(char *arquivo){
      ofstream myfile (arquivo);
      if (myfile.is_open()){
        myfile << "Algoritmo: " << algoritmo << endl;
        myfile << "Tamanho de N: " << vetor.size() << endl;
        myfile << "Comparacoes: " << comparacoes << endl;
        myfile << "Trocas: " << trocas << endl;
        myfile << "Tempo de Execucao: " << tempo << endl;
        myfile.close();
      }
      
      return 0;

    }

    void printStats(){
      cout << "Tamanho de N: " << vetor.size() << endl;
      cout << "Comparacoes: " << comparacoes << endl;
      cout << "Trocas: " << trocas << endl;
      cout << "Tempo de Execucao: " << tempo << endl;
    }

    void bubbleSort(){
      
      int elementos = vetor.size();
      int iter, jter, aux;
      for (iter=0; iter < elementos; iter++){
        for (jter = iter+1; jter < elementos; jter++){
          comparacoes++;
          if (vetor[iter] > vetor[jter]){
            trocas++;
            aux = vetor[iter];
            vetor[iter] = vetor[jter];
            vetor[jter] = aux;
          }
        }
      }
      
    }

    
	



};
