# Introdução a Técnicas de Programação - Unidade 1
**Aluno**: Arthur Lucas Costa Ciriaco da Silva
**Matrícula**: 20250030524
**Período**: 2025.2
## 📁 Estrutura do Projeto
- `projeto/`: Projeto principal da unidade
- `listas/`: Soluções das listas de exercícios
- `README.md`: Este arquivo
## 🚀 Projeto: Jogo da Velha com IA
**Descrição**: Permite o usuario jogar jogo da velha com uma maquina.
**Repositório**: https://github.com/arthur-lucas-ccs/silva-arthur-itp-2025.2
**Vídeo de Demonstração**: https://youtu.be/d26mgDzFvLk
### Funcionalidades Implementadas:
- Algoritimo minimax
- Deep Copy
- Bit wise 
### Conceitos da U1 Aplicados:
- Estruturas condicionais: em diversos lugares foram usadas, mas sua principal utilização foi na função onde verifica quem ganhou.
- Estruturas de repetição: as principais utilidades das esturas de repetição no meu codigo, foi referente a ação de percorrer um vetor.
- Vetores: Os vetores foram um dos principais pilares do codigo, pois ele representa a situação de um tabuleiro de jogo da velha.
- Funções: Principais partes, pois com elas eu pude deixar meu main mais limpo, e me auxiliou na manutenção do codigo, e no codigo tem cerca de 11 funções de diferentes tipos e usabilidades, logo devido a quantidade, optei por deixar mais detalhado dentro do relatório a utilização de cada função.
### Conceitos da U2 Aplicados: está bem explicado no relatório
## 📚 Listas de Exercícios
### Semana 2 - Variáveis, Tipos e Operadores ✅
### Semana 3 - Condicionais ✅
### Semana 4A - Repetições ✅
### Semana 4B - Análise e Padrões ✅
### Semana 5 - Funções (Parte 1) ✅
### Semana 6 - Vetores ✅
### Semana 7 - Strings✅
### Semana 8 - repeticoes aninhadas✅
### Semana 9 - matrizes✅
### Semana 10 - ponteiros alocacao✅

## 🎯 Principais Aprendizados
-Ponteiros
-Bitwise
-Minimax
Apesar de já ter usado C para desenvolvimento de sistemas embarcados, nunca tive a oportunidade de fazer um projeto nesse ambito de inteligencia artificial, e por conta desse fator, diria que foi um apreendizado imenso.
## 🔧 Ambiente de Desenvolvimento
- **SO**: Windows 11
- **Compilador**: GCC versão 6.3.0
- **Editor**: VsCode
## 🔧 Instruções de Compilação
Estando na pasta de projeto, use esse comando para fazer a compilação:

gcc -Iinclude src/main.c lib/manipulacaoTabuleiro.c lib/minimax.c -o meu_programa

Observação: o programa utiliza a biblioteca windows disponibilizada pela microsoft, tal biblioteca foi usada para fazer uma pausa no programa, que por sua vez foi uma das possibilidades para realizar a gamificação das strings.

para executar o codigo use 
./meu_programa 
onde será executado o programa.
