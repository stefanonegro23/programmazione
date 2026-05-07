#include "unidirected_edge.hpp"
int main(){
    unidirected_graph<int> grafo;
    grafo.add_edge(1,2);
    grafo.add_edge(2,4);
    grafo.add_edge(3,4);
    grafo.add_edge(5,3);
    std::cout << "I nodi sono:";
    for(int n:grafo.all_nodes()) {
        std::cout << n << " "<<std::endl;
    }
    std::cout << "Gli archi sono:";
    for (auto& n: grafo.all_edges()){
        std::cout << n << " "<<std::endl;
    }
    std::cout << "I vicini di 4 sono:";
    for(int n : grafo.neighours(4)){
        std::cout << n << " "<< std::endl;
    }
    std::cout << "L'arco in posizione 3 è" << grafo.edge_at(3)<< std::endl;
    return 0;
}