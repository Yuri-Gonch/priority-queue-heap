# 🏥 Sistema de Triagem — Hospital São Binário

Fila de Prioridade com **Heap Binário** para triagem do Pronto-Socorro, implementada em C++.

## 📋 Descrição

O sistema substitui a fila simples (FIFO) por uma **fila de prioridade clínica**. Pacientes são atendidos conforme a gravidade do caso, não pela ordem de chegada.

### Regras de prioridade (em cascata)
1. **Nível de urgência** — maior nível é atendido primeiro (1–5)
2. **Tempo de espera** — maior tempo tem prioridade (em caso de empate no nível)
3. **Grupo vulnerável** — pacientes com menos de 12 ou mais de 65 anos têm prioridade (em caso de empate nos anteriores)

| Nível | Cor      | Classificação |
|-------|----------|---------------|
| 5     | Vermelho | Imediato      |
| 4     | Laranja  | Muito Urgente |
| 3     | Amarelo  | Urgente       |
| 2     | Verde    | Pouco Urgente |
| 1     | Azul     | Não Urgente   |

## 🗂️ Estrutura do Projeto

```
heap_hospital/
├── Paciente.h          # Entidade Paciente e regras de prioridade
├── FilaPrioridade.h    # Heap Binário (enfileirar/desenfileirar)
├── main.cpp            # Testes com os 6 pacientes do enunciado
└── README.md
```

## ⚙️ Requisitos

- Compilador C++ com suporte a **C++11** ou superior (g++, clang++)

## 🔨 Compilação

```bash
g++ -std=c++11 -o triagem main.cpp
```

## ▶️ Execução

```bash
./triagem
```

## ✅ Saída esperada

```
1. Maria    | Vermelho | Espera: 5min
2. Pedro    | Vermelho | Espera: 2min
3. Beatriz  | Amarelo  | Espera: 35min | Vulneravel: Sim
4. Joao     | Amarelo  | Espera: 20min
5. Helena   | Verde    | Espera: 45min | Vulneravel: Sim
6. Carlos   | Verde    | Espera: 45min
```

## 📚 Algoritmos implementados

- **Sobe Heap (heapify up):** usado na inserção — o novo elemento sobe comparando com o pai até encontrar sua posição correta.
- **Desce Heap (heapify down):** usado na remoção — a raiz é removida, o último elemento vai para o topo e desce trocando com o filho de maior prioridade.
