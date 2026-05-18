#include <iostream>
#include <fstream>
#include <string>
#include "unidirected_edge.hpp"
#include "contenitori.hpp"
#include "graph_visit.hpp"
#include "dijkstra.hpp" 
#include "recursive_dfs.hpp"
//funzione che traduce i risultati in codice per Graphviz
template<typename T>
void esporta_dot(const unidirected_graph<T>& g, const std::string& filename) {
    std::ofstream out(filename);
    out << "graph G {\n";
    for (const auto& arco : g.all_edges()) {
        out << "    " << arco.from() << " -- " << arco.to() << ";\n"; //scrivo gli archi nel formato Graphviz
    }
    out << "}\n";
    out.close();
    std::cout << "File GraphViz generato: " << filename << "\n";
}
//testo gli algoritmi sul grafo d'esempio dato dall'esercitatore
int main() {
    unidirected_graph<int> g;

    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(1, 6);

    g.add_edge(2, 4);
    g.add_edge(2, 5);
    g.add_edge(2, 7); 

    g.add_edge(3, 6);

    g.add_edge(4, 6);
    g.add_edge(4, 7);

    g.add_edge(5, 7);

    g.add_edge(6, 7);
    g.add_edge(6, 8);

    g.add_edge(7, 9);
    g.add_edge(8, 9);

    std::cout << "Grafo originale costruito con successo!\n\n";

    coda_fifo<int> q;
    auto bfsG = graph_visit(g, 1, q);
    esporta_dot(bfsG, "bfs.dot"); 

    pila_lifo<int> s;
    auto dfsG_iter = graph_visit(g, 1, s);
    esporta_dot(dfsG_iter, "dfs_iterativa.dot"); 

    
    auto dfsG_ric = recursive_dfs(g, 1);
    esporta_dot(dfsG_ric, "dfs_ricorsiva.dot");

    auto risultato_dijkstra = algoritmo(1, g);
    std::cout << "\nRisultati Dijkstra (Distanze minime dal nodo 1):\n";
    for(int i = 1; i <= 9; ++i) {
        std::cout << "Nodo 1 -> Nodo " << i << " : Costo = " << risultato_dijkstra.distanze[i] << "\n";
    }

    return 0;
}