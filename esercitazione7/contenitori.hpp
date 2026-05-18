#pragma once
#include<queue>
#include<stack>
template<typename T>
class coda_fifo{    //implemento la classe coda
    private: 
        std::queue<T> q;
    public:
        coda_fifo(){} //inizializzo un elemento della classe 
        void put(const T& elemento){ //in input ho solo l'elemento tanto la funzione è già implementata nella classe che voglio
           q.push(elemento);  
        }
        T get(){
            T primo_elemento = q.front(); //devo farmelo restituire
            q.pop(); //lo toglie
            return primo_elemento;
        }
        bool empty(){
            return (q.empty());
        }
};
template<typename T>
class pila_lifo{
    private:
        std::stack<T> s;
    public:
        pila_lifo(){}
        void put(const T& elemento){
            s.push(elemento);
        }
        T get(){
            T primo_elemento=s.top();
            s.pop();
            return primo_elemento;
        }
        bool empty(){
            return (s.empty());
        }

};