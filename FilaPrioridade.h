#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#include "Paciente.h"
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iomanip>

/**
 * @brief 
 */
class FilaPrioridade {
private:
    std::vector<Paciente> heap; 

    /**
     * @brief
     */
    int pai(int i) const { return (i - 1) / 2; }

    /**
     * @brief
     */
    int filhoEsq(int i) const { return 2 * i + 1; }

    /**
     * @brief
     */
    int filhoDir(int i) const { return 2 * i + 2; }

    /**
     * @brief 
     * @param i
     */
    void sobeHeap(int i) {
        while (i > 0 && heap[i].temMaiorPrioridade(heap[pai(i)])) {
            std::swap(heap[i], heap[pai(i)]);
            i = pai(i);
        }
    }

    /**
     * @brief 
     * @param 
     */
    void desceHeap(int i) {
        int tamanho = heap.size();
        int maior = i;

        int esq = filhoEsq(i);
        int dir = filhoDir(i);

        if (esq < tamanho && heap[esq].temMaiorPrioridade(heap[maior]))
            maior = esq;

        if (dir < tamanho && heap[dir].temMaiorPrioridade(heap[maior]))
            maior = dir;

        if (maior != i) {
            std::swap(heap[i], heap[maior]);
            desceHeap(maior);
        }
    }

public:
    /**
     * @brief 
     * @param 
     */
    void enfileirar(const Paciente& p) {
        heap.push_back(p);
        sobeHeap(heap.size() - 1);
    }

    /**
     * @brief 
     * @return 
     * @throws 
     */
    Paciente desenfileirar() {
        if (estaVazia())
            throw std::runtime_error("Fila de prioridade vazia!");

        Paciente topo = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!estaVazia())
            desceHeap(0);

        return topo;
    }

    /**
     * @brief 
     */
    const Paciente& topo() const {
        if (estaVazia())
            throw std::runtime_error("Fila de prioridade vazia!");
        return heap[0];
    }

    /**
     * @brief 
     */
    bool estaVazia() const { return heap.empty(); }

    /**
     * @brief 
     */
    int tamanho() const { return heap.size(); }

    /**
     * @brief 
     */
    void imprimirHeap() const {
        std::cout << "  Estado do heap (" << heap.size() << " paciente(s)):\n";
        for (int i = 0; i < (int)heap.size(); i++) {
            const Paciente& p = heap[i];
            std::cout << "    [" << i << "] "
                      << std::left << std::setw(10) << p.nome
                      << " | Urgencia: " << p.nivelUrgencia
                      << " (" << p.corUrgencia() << ")"
                      << " | Espera: " << p.tempoEsperaMinutos << "min"
                      << " | Vulneravel: " << (p.grupoVulneravel ? "Sim" : "Nao")
                      << "\n";
        }
    }
};

#endif
