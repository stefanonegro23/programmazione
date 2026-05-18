#pragma once
#include"unidirected_edge.hpp"
#include <unordered_map>
#include <vector>
#include <limits>
#include <utility>
#include <queue>
#include <functional>
template <typename T>
struct RisultatoDijkstra {
    std::unordered_map<T, T> pred;
    std::unordered_map<T, double> distanze;
}; //questa roba qua mi serve visto che devo restituire due mappe
template <typename T>
RisultatoDijkstra<T> algoritmo(const T& nodo_iniziale,const unidirected_graph<T>& g){
    RisultatoDijkstra<T> risultato; //inizializzo quello che restituirò
    std::vector<T> nodi = g.all_nodes();
    for(const T& nodo : nodi ){
        risultato.distanze[nodo] = std::numeric_limits<double>::infinity();
    }
    risultato.pred[nodo_iniziale] = nodo_iniziale;
    risultato.distanze[nodo_iniziale] = 0.0;
    using elemento = std::pair<double,T>; //definisco in questo ordine perchè così inizia ad ordinare prima sulla distanza
    std::priority_queue<elemento, std::vector<elemento>, std::greater<elemento>> pq; //definisco la coda di tuple
    pq.push({0.0,nodo_iniziale});
    while(!pq.empty()){
        auto [distanza, nodo] = pq.top();
        pq.pop();
        std::vector<T> vicini = g.neighours(nodo);
        for(const T& vicino : vicini){
            if(risultato.distanze[vicino]>risultato.distanze[nodo] + g.restituisci_peso(vicino,nodo)){
                risultato.distanze[vicino]=risultato.distanze[nodo] + g.restituisci_peso(vicino,nodo);
                risultato.pred[vicino] = nodo;
                pq.push({risultato.distanze[vicino], vicino});
            }
        }
    }
    return risultato;
}