#include <iostream>
#ifndef CARROMODEL_H
#define CARROMODEL_H

class CarroModel
{
public:
    CarroModel();
    std::string placa;
    std::string cor;
    std::string marca;
    std::string modelo;
    std::string cidade;
    std::string uf;

    bool validarCarro(
            std::string placa,
            std::string cor,
            std::string marca,
            std::string modelo,
            std::string cidade,
            std::string uf);

    bool encontrarCarro(std::string placa);
    bool salvarEntrada(std::string placa);
    bool salvarSaida(std::string placa);
    bool salvarNovoCarro(CarroModel newCarro);
    bool salvarNewCor(std::string newCor);
    bool salvarNewModelo(std::string newModelo);
    bool salvarNewMarca(std::string newMarca);
    bool salvarNewCidade(std::string newCidade);
    bool salvarNewUf(std::string newUf);
};

#endif // CARROMODEL_H
