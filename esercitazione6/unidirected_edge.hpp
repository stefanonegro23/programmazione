#include <iostream>
#include <vector>
#include <concepts>
#include <algorithm>
#include <set>
template<typename I> requires std::integral<I>

class unidirected_edge{
    private:
        I nodo_iniziale;
        I nodo_finale;
        double peso;
    public:
        unidirected_edge(I n1, I n2, double w = 1.0){
            nodo_iniziale = std::min(n1,n2);
            nodo_finale = std::max(n1,n2);
            peso = w;
        }
        I from() const {return nodo_iniziale;}
        I to() const {return nodo_finale;}
        bool operator<(const unidirected_edge& other) const {
            if(nodo_iniziale< other.nodo_iniziale){
                return true;
            }
            else if(nodo_iniziale== other.nodo_iniziale){
                if(nodo_finale<other.nodo_finale){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        bool operator==(const unidirected_edge& other) const {
            if(nodo_iniziale==other.nodo_iniziale && nodo_finale==other.nodo_finale){
                return true;
            }
            else{
                return false;
            }
        }
};
template<typename I>
    std::ostream&
    operator<<(std::ostream& os, const unidirected_edge<I>& a){
        os << "(" << a.from() << "," << a.to() << ")";
        return os;
        }

template<typename I> requires std::integral<I>
class unidirected_graph {
    private:
        std::set<unidirected_edge<I>> archi;
        std::set<I> nodi;
    public:
        unidirected_graph(){} //inizializza un grafo vuoto, di default
        unidirected_graph(const unidirected_graph& other){
            this-> archi = other.archi;    //this è un puntatore
            this-> nodi = other.nodi;
        }
        std:: vector<I> neighours(I nodoscelto) const{
            std::vector<I> vicini;
            for(const auto& arco : archi){
            if (arco.from() == nodoscelto){
                vicini.push_back(arco.to());
            }
            else if (arco.to() == nodoscelto){
                vicini.push_back(arco.from());
            }
        }
        return vicini;
    }
        void add_edge(I nodo1, I nodo2, double w=1.0){
            archi.emplace(nodo1,nodo2,w);
            nodi.insert(nodo1); //aggiungo i nodi tanto il set mi toglie il problema delle ripetizioni
            nodi.insert(nodo2);
        }  //mi basta chiamare g.add_edge(n1,n2,w)
        std:: vector <unidirected_edge<I>> all_edges() const{
            return std:: vector<unidirected_edge<I>>(archi.begin(),archi.end()); //devo dare solo i due estremi
        }
        std:: vector <I> all_nodes() const{
            return std:: vector<I>(nodi.begin(),nodi.end());
        }
        int edge_number(const unidirected_edge<I>& arcoscelto) const{
            int i = 0;
            for (const auto& arco:archi){
                if(arco == arcoscelto){
                    return i;
                }
                else{
                    i++;
                }
            }
            return -1; // significa che non ho trovato l'arco di cui chiedevo il numero
        }
        unidirected_edge<I> edge_at(int posizione){
            int i = 0;
            for (const auto& arco:archi){
                if (i==posizione){
                    return arco;
                }
                else{
                    i++;
                }
            }
            std::cout << "ERRORE: Posizione " << posizione << " non valida!";
            return unidirected_edge<I>(0, 0); // Restituiamo un arco fittizio che va da 0 a 0
        }
        unidirected_graph<I> operator-(const unidirected_graph& g)const {
            unidirected_graph<I> differenza; //creo un grafo vuoto che poi compilerò come quello risultato della differenza
            for (const auto& nodo:nodi){
                differenza.nodi.insert(nodo);
            }
            for (const auto& arco:archi){
                if (g.edge_number(arco)==-1){
                    differenza.add_edge(arco.from(),arco.to());
                }
            }
        return differenza;
        }
};