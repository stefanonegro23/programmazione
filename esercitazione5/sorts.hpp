#pragma once
#include <vector>
#include <string> 
#include <iostream>
#include <limits>

template<typename T>
void print_vector(const std::vector<T>& v)
{
    for (std::size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}


// funzione is_sorted()
template<typename T>
bool is_sorted(const std::vector<T>& vec) {
    // vettore di lunghezza zero : ordinato per definizione
    if (vec.size() == 0)  {
        return true;
    }

    // vettore di lunghezza > 0 : ciclo for
    for (size_t i = 0; i < vec.size() - 1; i++) {
        if (vec[i] > vec[i+1]) {
            return false;
        }
    }
    return true;
}

// funzione bubble-sort
template<typename T>
void bubblesort(std::vector<T>& vec) {

    if (vec.size() <= 1) {
        return;
    }

    for (size_t i = 0; i < vec.size() - 1; i++) {
        for (size_t j = vec.size() - 1; j > i; j--) {
            if (vec[j] < vec[j - 1]) {
                T temp = vec[j];
                vec[j] = vec[j - 1];
                vec[j - 1] = temp;
            }
        }
    }
}

// funzione insertion-sort 
template<typename T>
void insertionsort(std::vector<T>& vec) {

    if (vec.size() <= 1) {
        return;
    }

    for (size_t j = 1; j < vec.size(); j++) {
        T key = vec[j];
        int i = j - 1;
        while (i >= 0 && vec[i] > key) {
            vec[i + 1] = vec[i];
            i = i - 1;
        }
        vec[i + 1] = key;
    }
}

// funzione selection-sort
template<typename T>
void selectionsort(std::vector<T>& vec) {

    if (vec.size() <= 1) {
        return;
    }

    for (size_t i = 0; i < vec.size() - 1; i++) {
        size_t min = i;
        for (size_t j = i + 1; j < vec.size(); j++) {
            if (vec[j] < vec[min]) {
                min = j;
            }
        }
        T temp = vec[i];
        vec[i] = vec[min];
        vec[min] = temp;
    }
}

//funzione fusion della teoria
template<typename T>
void merge(std::vector<T>& vec,int p,int q ,int r){
    int n1 = q-p+1;
    int n2 = r-q;
    std::vector<T> L(n1);
    std::vector<T> R(n2);
    for (int i=0;i <= n1-1;i=i+1){
        L[i]=vec[p+i]; //l'ultimo elemento che metto a sinistra è quello in posizione q
    }
    for (int j=0;j <= n2-1;j=j+1){
        R[j]=vec[q+j+1];
    }
    int i = 0; // Indice iniziale del primo sottovettore (L)
    int j = 0; // Indice iniziale del secondo sottovettore (R)
    int k = p; // Indice iniziale del vettore fuso
    // 1. Confrontiamo finché entrambi i sottovettori hanno elementi
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }
    // 2. Travasiamo gli eventuali elementi rimanenti di L
    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }
    // 3. Travasiamo gli eventuali elementi rimanenti di R
    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}

//funzione mergesortfake
template<typename T>
void mergesortfake(std::vector<T>& vec,int p,int r) {
    if (p<r){
        int q = p + (r-p)/2; //lo arrotonda per difetto
        mergesortfake(vec,p,q);
        mergesortfake(vec, q+1, r);
        merge(vec,p,q,r);

    }
}

// funzione mergesort
template<typename T>
void mergesort(std::vector<T>& vec) {
    int p = 0;
    int r = vec.size()-1;
    mergesortfake(vec,p,r);
}
// funzione partition
template<typename T>
int partition(std::vector<T>& vec,int p,int r){
    T x = vec[r];
    int i = p-1; 
    for(int j=p;j<=r-1;j=j+1){
        if(vec[j]<= x){
            i = i+1;
            std::swap(vec[i],vec[j]);
        }
    }
    std::swap(vec[i+1],vec[r]);
    return i+1;
}
// funzione ricorsiva
template<typename T> 
void quicksortfake(std::vector<T>& vec,int p,int r){
    if (p<r){
        int q = partition(vec,p,r);
        quicksortfake(vec,p,q-1);
        quicksortfake(vec,q+1,r);
    }
}
//funzione quicksort
template<typename T>
void quicksort(std::vector<T>& vec){
    int p = 0;
    int r = vec.size()-1;
    quicksortfake(vec,p,r);
}
template<typename T>  //è il risultato dell'analisi del punto critico
void quicksort_ottimizzato(std::vector<T>& vec) {
    size_t N_star = 32;
    if (vec.size()<N_star) {
        insertionsort(vec);
    }
    else {
        quicksort(vec);
    }
}