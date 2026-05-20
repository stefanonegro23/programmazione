#include <iostream>
#include <Eigen/Dense>
#include <stdexcept>
#include "gradiente_coniugato.hpp" 

int main() {
    const unsigned int n = 5; 
    const unsigned int itermax = 1000;
    const double res_tol = 1.0e-12;

    std::cout << "--- INIZIO TEST GRADIENTE CONIUGATO ---" << std::endl;
    Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
    Eigen::MatrixXd A = B.transpose() * B;
    Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n); //impongo che la soluzione sia un vettore di soli 1
    Eigen::VectorXd b = A * x_ex; //questo è il termine noto associato alla soluzione unitaria
    Eigen::VectorXd x0; // inizializzo il vettore iniziale da cui parte la ricerca (poi se lo gestisce l'algoritmo)

    try {
        std::cout << "Risoluzione del sistema in corso..." << std::endl;
        Eigen::VectorXd x_calc = gradiente_coniugato(A, b, x0, itermax, res_tol);
        double err_rel = (x_calc - x_ex).norm() / x_ex.norm(); //calcolo dell'errore relativo

        std::cout << std::scientific; // Stampa i numeri in notazione scientifica
        std::cout << "\nSoluzione esatta:\n" << x_ex.transpose() << std::endl;
        std::cout << "Soluzione calcolata:\n" << x_calc.transpose() << std::endl;
        std::cout << "\nErrore relativo finale: " << err_rel << std::endl;

        // definisco un modo di verificare se ho convergenza o no
        if (err_rel < 1e-10) {
            std::cout << "\nConvergenza" << std::endl;
        } else {
            std::cout << "\nNon ho convergenza" << std::endl;
        }

    } 
    //devo gestire ora i casi in cui l'algoritmo non parta
    catch (const std::invalid_argument& e) {
        std::cerr << "\nerrore " << e.what() << std::endl; //e.what() mi legge qual è l'errore che ha fermato il tutto
        return -1;
    }
    return 0;
}