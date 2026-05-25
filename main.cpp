#include <iostream>
#include "Paciente.h"
#include "FilaPrioridade.h"

int main() {
    FilaPrioridade fila;

    std::vector<Paciente> pacientes = {
        Paciente("Carlos",  2, 45, false),
        Paciente("Maria",   5,  5, false),
        Paciente("Joao",    3, 20, false),
        Paciente("Beatriz", 3, 35, true),
        Paciente("Pedro",   5,  2, false),
        Paciente("Helena",  2, 45, true)
    };

   
    std::cout << "========================================\n";
    std::cout << "   SISTEMA DE TRIAGEM - SAO BINARIO\n";
    std::cout << "========================================\n\n";

    std::cout << ">>> INSERINDO PACIENTES <<<\n\n";

    for (const Paciente& p : pacientes) {
        std::cout << "Inserindo: " << p.nome
                  << " (Urgencia " << p.nivelUrgencia
                  << " - " << p.corUrgencia() << ")\n";
        fila.enfileirar(p);
        fila.imprimirHeap();
        std::cout << "\n";
    }

   
    std::cout << "========================================\n";
    std::cout << ">>> ORDEM DE ATENDIMENTO <<<\n";
    std::cout << "========================================\n\n";

    int ordem = 1;
    while (!fila.estaVazia()) {
        Paciente p = fila.desenfileirar();
        std::cout << ordem++ << ". " << p.nome
                  << " | " << p.corUrgencia()
                  << " | Espera: " << p.tempoEsperaMinutos << "min"
                  << " | Vulneravel: " << (p.grupoVulneravel ? "Sim" : "Nao")
                  << "\n";
    }

    std::cout << "\nAtendimento concluido!\n";
    return 0;
}
