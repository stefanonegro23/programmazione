#pragma once
#include <vector>
#include <iostream>
#include <Eigen/Dense>
Eigen::VectorXd gradiente_coniugato(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, Eigen::VectorXd& x0, unsigned int itermax, double res_tol){ //VectorXd è un vettore di double
    if (A.rows() != A.cols()) {
        throw std::invalid_argument("Errore: La matrice A deve essere quadrata."); //throw mi lancia un'eccezione da gestire
    }

    if (A.rows() != b.size()) {
        throw std::invalid_argument("Errore: Dimensioni incompatibili tra la matrice A e il vettore b.");
    } //verifico che il prodotto sia ben definito

    if(x0.size() == 0){
        x0 = Eigen::VectorXd::Zero(b.size()); //per il gradiente coniugato il punto di partenza standard è zero
    } else if (x0.size() != b.size()) {
        throw std::invalid_argument("Errore: Il vettore iniziale x0 ha una dimensione errata.");
    }
   
    Eigen::VectorXd x_k = x0;
    Eigen::VectorXd r_k = b - A*x_k;
    Eigen::VectorXd p_k = r_k;
    double norm0 = r_k.norm();
    unsigned int iter = 0;
    while(iter < itermax && r_k.norm()>res_tol*norm0){
        double alpha_k = (p_k.dot(r_k))/(p_k.dot(A*p_k));
        x_k = x_k + alpha_k*p_k;
        r_k = b - A*x_k;
        double beta_k = (p_k.dot(A*r_k))/(p_k.dot(A*p_k));
        p_k = r_k - beta_k*p_k;
        iter++;
    }
    return x_k;
}
