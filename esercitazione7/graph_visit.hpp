#pragma once
#include"unidirected_edge.hpp"
#include"contenitori.hpp" // questo mi serve per fare algoritmi di visita in profondità e ampiezza
#include<vector>
#include<unordered_map>
#include <limits>
template<typename T>
unidirected_graph<T> graph_visit(const unidirected_graph<T>& g, const T& v, auto& c){
    unidirected_graph<T> albero_risultante;
    albero_risultante.add_node(v);
    std::vector<T> nodi = g.all_nodes();
    std::unordered_map<T,bool> visitato; //questo lavoro mi serve perchè nello pseudocodice mi bloccavo nell'estrarre l'indice del nodo u da togliere
    for(T nodo : nodi){ //devo scorrere su tutti i nodi
        visitato[nodo]= false;
    }
    c.put(v);
    while(!c.empty()){
        T u = c.get();
        visitato[u] = true;
        
        std::vector<T> adiacenti = g.neighours(u);
        for(T nodo : adiacenti){
            if(!visitato[nodo]){
                visitato[nodo] = true;
                double peso = g.restituisci_peso(u,nodo);
                albero_risultante.add_edge(u,nodo,peso);
                c.put(nodo);
            }
        }
    }
    return albero_risultante;
};
