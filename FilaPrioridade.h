#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#include "Paciente.h"
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iomanip>

/**
 * @brief Fila de Prioridade implementada com Heap Binário (Max-Heap).
 *
 * O paciente com maior prioridade clínica fica sempre na raiz (índice 0).
 * Operações principais: enfileirar (Sobe Heap) e desenfileirar (Desce Heap).
 */
class FilaPrioridade {
private:
    std::vector<Paciente> heap; ///< Vetor interno que representa o heap

    /**
     * @brief Retorna o índice do pai de um nó.
     */
    int pai(int i) const { return (i - 1) / 2; }

    /**
     * @brief Retorna o índice do filho esquerdo de um nó.
     */
    int filhoEsq(int i) const { return 2 * i + 1; }

    /**
     * @brief Retorna o índice do filho direito de um nó.
     */
    int filhoDir(int i) const { return 2 * i + 2; }

    /**
     * @brief Algoritmo "Sobe Heap" (heapify up).
     *
     * Após inserir um elemento no final, sobe até a posição correta
     * comparando com o pai e trocando se necessário.
     *
     * @param i Índice do elemento recém-inserido.
     */
    void sobeHeap(int i) {
        while (i > 0 && heap[i].temMaiorPrioridade(heap[pai(i)])) {
            std::swap(heap[i], heap[pai(i)]);
            i = pai(i);
        }
    }

    /**
     * @brief Algoritmo "Desce Heap" (heapify down).
     *
     * Após remover a raiz, coloca o último elemento na raiz e desce
     * até a posição correta, trocando com o filho de maior prioridade.
     *
     * @param i Índice do elemento a descer (normalmente 0).
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
     * @brief Insere um paciente na fila de prioridade.
     *
     * O paciente é adicionado ao final do heap e depois sobe
     * até sua posição correta (Sobe Heap).
     *
     * @param p Paciente a ser inserido.
     */
    void enfileirar(const Paciente& p) {
        heap.push_back(p);
        sobeHeap(heap.size() - 1);
    }

    /**
     * @brief Remove e retorna o paciente de maior prioridade.
     *
     * A raiz (maior prioridade) é removida, o último elemento
     * vai para a raiz e desce até sua posição correta (Desce Heap).
     *
     * @return Paciente com maior prioridade.
     * @throws std::runtime_error Se a fila estiver vazia.
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
     * @brief Retorna o paciente de maior prioridade sem removê-lo.
     */
    const Paciente& topo() const {
        if (estaVazia())
            throw std::runtime_error("Fila de prioridade vazia!");
        return heap[0];
    }

    /**
     * @brief Verifica se a fila está vazia.
     */
    bool estaVazia() const { return heap.empty(); }

    /**
     * @brief Retorna o número de pacientes na fila.
     */
    int tamanho() const { return heap.size(); }

    /**
     * @brief Imprime o estado interno do heap (vetor).
     *
     * Exibe cada paciente com seus dados para fins de depuração.
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
