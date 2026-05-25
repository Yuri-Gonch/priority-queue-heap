#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>

/**
 * @brief 
 */
class Paciente {
public:
    std::string nome;
    int nivelUrgencia;     
    int tempoEsperaMinutos; 
    bool grupoVulneravel;   

    /**
     * @brief
     */
    Paciente(std::string nome, int nivelUrgencia, int tempoEsperaMinutos, bool grupoVulneravel)
        : nome(nome), nivelUrgencia(nivelUrgencia),
          tempoEsperaMinutos(tempoEsperaMinutos), grupoVulneravel(grupoVulneravel) {}

    /**
     * @brief 
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
     * @brief
     * @return
     */
    bool temMaiorPrioridade(const Paciente& outro) const {

        if (nivelUrgencia != outro.nivelUrgencia)
            return nivelUrgencia > outro.nivelUrgencia;
   
        if (tempoEsperaMinutos != outro.tempoEsperaMinutos)
            return tempoEsperaMinutos > outro.tempoEsperaMinutos;

        return grupoVulneravel && !outro.grupoVulneravel;
    }
};

#endif
