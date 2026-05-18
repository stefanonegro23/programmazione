#pragma once
#include "unidirected_edge.hpp"
#include <vector>
#include <unordered_map>

template<typename T>
void dfs_helper(const unidirected_graph<T>& g, const T& u, std::unordered_map<T, bool>& visitato, unidirected_graph<T>& albero_risultante) {

    visitato[u] = true;
    std::vector<T> vicini = g.neighours(u); 
    
    for(const T& nodo : vicini) {
        if(!visitato[nodo]) {
            double peso = g.restituisci_peso(u, nodo);
            albero_risultante.add_edge(u, nodo, peso);
            dfs_helper(g, nodo, visitato, albero_risultante);
        }
    }
}

template<typename T>
unidirected_graph<T> recursive_dfs(const unidirected_graph<T>& g, const T& sorgente) {
    unidirected_graph<T> albero_risultante;
    albero_risultante.add_node(sorgente); //metto la radice

    std::unordered_map<T, bool> visitato; //inizializzo i visitato
    std::vector<T> nodi = g.all_nodes();
    for(const T& nodo : nodi) {
        visitato[nodo] = false;
    }

    dfs_helper(g, sorgente, visitato, albero_risultante);

    return albero_risultante;
}