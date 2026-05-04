#include <iostream>
#include <vector>
#include <algorithm> 
#include "sorts.hpp"
#include "randfiller.h"
#include "timecounter.h"
int main()
{
    std::vector<double> bubble_times(99);
    std::vector<double> selection_times(99);
    std::vector<double> insertion_times(99);
    std::vector<double> merge_times(99);
    std::vector<double> quick_times(99);
    std::vector<double> quickmod_times(99);
    std::vector<double> stdsort_times(99);
    randfiller rf;
    timecounter tc;
    for(int dim=2; dim<=100; dim++){
        std::vector<std::vector<double>> vec(100);
        for(int i=0; i<100;i++){
            vec[i].resize(dim);
            rf.fill(vec[i],-10000.0,10000.0);
        }
        tc.tic();
        for(int i=0;i<100;i++){
            mergesort(vec[i]);
        }
        double merge_secs = tc.toc()/100;
        merge_times[dim-2] = merge_secs; //merge

        for(int i=0; i<100;i++){
            vec[i].resize(dim);
            rf.fill(vec[i],-10000.0,10000.0);
        }
        tc.tic();
        for(int i=0;i<100;i++){
            quicksort(vec[i]);
        }
        double quick_secs = tc.toc()/100;
        quick_times[dim-2] = quick_secs; //quick

        for (int i=0; i<100; i=i+1) {
            vec[i].resize(dim);
            rf.fill(vec[i],-10000.0,10000.0);
        }
        tc.tic();
        for (int i=0; i<100; i=i+1) {
            bubblesort(vec[i]);
        }
        double bubble_secs = tc.toc()/100;
        bubble_times[dim-2] = bubble_secs;  //bubble

        
        for (int i=0; i<100; i=i+1) {
            vec[i].resize(dim);
            rf.fill(vec[i],-10000.0,10000.0);
        }
        tc.tic();
        for (int i=0; i<100; i=i+1) {
            selectionsort(vec[i]);
        }
        double selection_secs = tc.toc()/100;
        selection_times[dim-2] = selection_secs;  //selection

        for (int i=0; i<100; i=i+1) {
            vec[i].resize(dim);
            rf.fill(vec[i],-10000.0,10000.0);
        }
        tc.tic();
        for (int i=0; i<100; i=i+1) {
            insertionsort(vec[i]);
        }
        double insertion_secs = tc.toc()/100;
        insertion_times[dim-2] = insertion_secs;  //insertion

        for (int i=0; i<100; i=i+1) {
            vec[i].resize(dim);
            rf.fill(vec[i],-10000.0,10000.0);
        }
        tc.tic();
        for (int i=0; i<100; i=i+1) {
            std::sort( vec[i].begin() , vec[i].end() );
        }
        double stdsort_secs = tc.toc()/100;
        stdsort_times[dim-2] = stdsort_secs;  //std implementato

        for (int i=0; i<100; i=i+1) {
            vec[i].resize(dim);
            rf.fill(vec[i],-10000.0,10000.0);
        }
        tc.tic();
        for (int i=0; i<100; i=i+1) {
            quicksort_ottimizzato(vec[i]);
        }
        double quickmod_secs = tc.toc()/100;
        quickmod_times[dim-2] = quickmod_secs;
    }

    std::cout << "Vettore dei tempi del bubblesort: \n";
    print_vector(bubble_times);
    std::cout << "Vettore dei tempi del insertionsort: \n";
    print_vector(insertion_times);
    std::cout << "Vettore dei tempi del selectionsort: \n";
    print_vector(selection_times);
    std::cout << "Vettore dei tempi del mergesort: \n";
    print_vector(merge_times);
    std::cout << "Vettore dei tempi del quicksort: \n";
    print_vector(quick_times);
    std::cout << "Vettore dei tempi del std::sort: \n";
    print_vector(stdsort_times);
    std::cout << "Vettore dei tempi del quicksort ottimizzato: \n";
    print_vector(quickmod_times);
}
    