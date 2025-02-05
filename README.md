# README - Atividade 2: Temporizador Periódico One Shot

## Descrição da Atividade

Utilizando o ambiente de simulação Wokwi e o Pico W, por meio deste projeto foi desenvolvido um sistema onde ao pressionar um botão os LEDs presentes no Kit de desenvolvimento
BitDogLab acendem e em seguida apagam em intervalos de 3 segundos. Enquanto pelo menos um dos LEDs estiver acesso, não é possível efetuar um novo "disparo".

## Componentes Necessários

1. **Microcontrolador**: Raspberry Pi Pico W;
2. **LEDs**: 03 LEDs (vermelho, azul e verde);
3. **Resistores**: 03 resistores de 330 Ω (220, 220 e 150 na BitDog);
4. **Botão** (botão A).

## Fluxo de Funcionamento

1. O usuário pressiona o botão pushbutton, acionando os três LEDs simultaneamente;
2. Após 3 segundos, um dos LEDs será desligado;
3. Depois de mais 3 segundos, mais um LED será desligado;
4. Finalmente, após mais 3 segundos, o último LED será desligado.

Durante a sequência de temporização, o botão não deve reiniciar o processo. Somente após o desligamento do último LED, o botão pode iniciar uma nova sequência.

## Como Executar

Para utilizar o programa com o simulador Wokwi, o usuário deve:

1. Clonar este repositório: git clone https://github.com/saturnino028/U4C51234E_Temporizadores_Q2.git;
2. Usando a extensão Raspberry Pi Pico importar o projeto;
3. Compilar o código e clicar no arquivo diagram.json.

---
Desenvolvido para a capacitação em Sistemas Embarcados oferecida pela CEPEDI utilizando o Raspberry Pi Pico W, o simulador Wokwi, o Pico SDK e p kit BitDogLab.
