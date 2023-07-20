//The sequential version
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "main.h"
#include "sequential.h"
#include <limits.h>
int st,n,cost;
int** graph;

int min(int a,int b){
    return (a<b) ? a : b;
}
void pswap(int *l, int *r) {
    int temp = *l;
    *l = *r;
    *r = temp;
}
void reverse(int A[], int l, int r) {
    while (l < r) {
        pswap(&A[l++], &A[r--]);
    }
}
bool next_permutation(int A[],int l,int r){
     int j = r; // j will point to the highest peak of the interval [i,r].
  // this loop will find the first increasing [i,j] from r to l.
  while (j > l) {
      if (A[j-1] < A[j]) {
          break;
      }
      --j;
  }
  if (j > l) {
      int k = r;
      // find the first A[k] where A[k] > A[j-1].
      while (!(A[j-1] < A[k])) {
          --k;
      }
      pswap(&A[j-1], &A[k]);
      reverse(A, j, r);
      return true;
  }

  reverse(A, j, r);
  return false;
}



//Travelling salesman fonction
int tsp(int last_city,int current_cost,int** graph){
    int t=n;
    int* vec=(int*)malloc(t*sizeof(int));
    //Le tableau du reste de ville qui serait permuter
    for (int i = 0; i < t; i++)
            vec[i]=i;
    //Elimination de la ville du depart dans le tableau
    for(int c=last_city;c<n;c++)
            vec[c]=vec[c+1];
    t--;
    int min_path=INT_MAX;
    int j=1;
    do{
        printf("Le chemin : %d \n%d",j,st);
        for (int i = 0; i < t; i++){
        printf("--->%d\t ",vec[i]);
        }
        printf("--->%d",st);
        printf("\n");
        int current_pathweight = 0;
        int k=last_city;
        for (int i = 0; i < t; i++){
            if (i != last_city); {
                current_pathweight += graph[k][vec[i]];
                k=vec[i];
            }
            
        }
        current_pathweight += graph[k][last_city];
        printf("\nLe cout de se chemin est :%d\n",current_pathweight);
        min_path = min(min_path,current_pathweight);
        j++;
    } while (next_permutation(vec,0,t-1));
    
  return min_path;     
}


