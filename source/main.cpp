#include <iostream>
#include <random>
#include <vector>
#include <chrono>

using namespace std;

int
tam = 10000, //numero de vectores
dim = 15; //dimension

void llenarVectorDeVectores(vector<vector<double>>& X) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(1.0, 2.0);
    for (int i = 0; i < tam; i++) {
        vector<double> temp;
        for (int j = 0; j < dim; j++) {
            temp.push_back(dis(gen));
        }
        X.push_back(temp);
    }
}

void imprimirVectorDeVectores(vector<vector<double>> X) {
    for (int i = 0; i < X.size(); i++) {
        for (int j = 0; j < X[i].size(); j++) {
            cout << X[i][j] << "\t";
        }
        cout << endl;
    }cout << endl;
}

float distanciaEuclidiana(vector<double> X, vector<double> Y) {
    float aux = 0;
    for (int i = 0; i < dim; i++) {
        aux += pow(X[i] - Y[i], 2);
    }
    return sqrt(aux);
}

int main() {    
    vector<vector<double>> X;
    llenarVectorDeVectores(X);    
    //imprimirVectorDeVectores(X);
    
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < X.size(); i++) {
        for (int j = i + 1; j < X.size(); j++) {
            distanciaEuclidiana(X[i], X[j]);
        }
    }

    end = std::chrono::high_resolution_clock::now();
    int64_t duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); // duration is holding the elapsed time.

    cout << duration << endl;

	return 0;
}