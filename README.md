# Jogo da Forca em C

Um simples e funcional jogo da forca feito em linguagem C, para rodar diretamente no terminal Linux. Um jogador define a palavra secreta, enquanto o outro tenta adivinhar letra por letra, com limite de tentativas.

## Sobre o Projeto

Este projeto foi criado para praticar os fundamentos da linguagem C, como:

- Manipulação de strings
- Uso de vetores
- Estruturas de controle (if, for, while)
- Funções
- Entrada e saída com scanf e printf
- Limpeza do terminal com system("clear")

## Como Executar

1. Compile o código com `gcc`:

```
gcc forca.c -o forca
```

2. Execute o jogo:

```
./forca
```

> Certifique-se de estar em um terminal que suporte `system("clear")` para uma melhor visualização.

## Regras do Jogo

- Um jogador digita a palavra secreta (sem acentos ou espaços).
- O outro jogador tenta adivinhar uma letra por vez.
- Cada erro consome uma tentativa.
- O jogador perde se errar 6 vezes.
- O jogo mostra as letras já utilizadas e o progresso da palavra.

## Exemplo de Execução

```
Digite a palavra a ser adivinhada: computador

Adivinhe a palavra: _ _ _ _ _ _ _ _ _ _
Digite uma letra: o
Boa! Adivinhe a palavra: _ o _ _ _ _ _ _ _ _

Digite uma letra: z
Letra errada! Tentativas restantes: 5
```

## Funcionalidades

- Verificação de letras já usadas
- Atualização da palavra conforme acertos
- Controle de tentativas restantes
- Mensagem de vitória ou derrota
- Limpeza do terminal a cada jogada

## Possíveis Melhorias Futuras

- Suporte a acentuação e letras maiúsculas
- Desenho da forca em ASCII
- Escolha de palavras aleatórias de um arquivo externo
- Interface com ncurses ou SDL
- Modo dois jogadores com placar

## Autor

Desenvolvido por Lukas de Souza Santos.  
Contribuições são bem-vindas!

## Licença

Este projeto está licenciado sob a licença MIT.

