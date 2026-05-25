#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>

/**
 * @brief Representa um paciente do sistema de triagem do Pronto-Socorro.
 *
 * A prioridade é determinada em cascata:
 * 1. Maior nivelUrgencia
 * 2. Maior tempoEsperaMinutos (em caso de empate no nível)
 * 3. grupoVulneravel == true (em caso de empate nos anteriores)
 */
class Paciente {
public:
    std::string nome;
    int nivelUrgencia;        ///< 1 (Azul) a 5 (Vermelho)
    int tempoEsperaMinutos;   ///< Minutos aguardando atendimento
    bool grupoVulneravel;     ///< true se < 12 anos ou > 65 anos

    /**
     * @brief Construtor do Paciente.
     */
    Paciente(std::string nome, int nivelUrgencia, int tempoEsperaMinutos, bool grupoVulneravel)
        : nome(nome), nivelUrgencia(nivelUrgencia),
          tempoEsperaMinutos(tempoEsperaMinutos), grupoVulneravel(grupoVulneravel) {}

    /**
     * @brief Retorna a cor do nível de urgência.
     */
    std::string corUrgencia() const {
        switch (nivelUrgencia) {
            case 5: return "Vermelho";
            case 4: return "Laranja";
            case 3: return "Amarelo";
            case 2: return "Verde";
            case 1: return "Azul";
            default: return "Desconhecido";
        }
    }

    /**
     * @brief Verifica se este paciente tem maior prioridade que outro.
     * @return true se THIS deve ser atendido ANTES de outro.
     */
    bool temMaiorPrioridade(const Paciente& outro) const {
        // 1. Maior nível de urgência
        if (nivelUrgencia != outro.nivelUrgencia)
            return nivelUrgencia > outro.nivelUrgencia;

        // 2. Maior tempo de espera
        if (tempoEsperaMinutos != outro.tempoEsperaMinutos)
            return tempoEsperaMinutos > outro.tempoEsperaMinutos;

        // 3. Grupo vulnerável
        return grupoVulneravel && !outro.grupoVulneravel;
    }
};

#endif
