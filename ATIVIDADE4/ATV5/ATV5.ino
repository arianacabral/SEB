/*******************************************************************************

     EXPERIMENTO 4 - CONTROLADOR DE DISPLAY LCD

*******************************************************************************/

#include <LiquidCrystal.h>

// LCD

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // instanciando a variável e definido os pinos do LCD

// ENTRADA ANALÓGICA
# define POT A0 // durante a compilação, o compilador substituirá qualquer menção de POT por A0.

// VARIÁVEIS GLOBAIS
int analog_POT, graph;
float tensao;

void setup() {

  pinMode(POT, INPUT); // definindo o potenciômetro como um pino de entrada

  lcd.begin(16, 2); // definindo o tipo de LCD (número de colunas e linhas)

  lcd.setCursor(0, 0); // setando a posição do cursor no LCD

  lcd.print("Tensao = "); // apresentando a mensagem no LCD

}

void loop() {

  lcd.setCursor(9, 0); // setando a posição para apresentar a informação no LCD

  analog_POT = analogRead(POT); // lendo a entrada no pino analógico A0 do ARDUINO (potenciômetro)

  tensao = analog_POT * (5.0 / 1023.0); // convertando a leitura analógico, compreendida entre 0 e 1023, para um valor de tensao de 0 a 5 V

  lcd.print(tensao); // apresentando o valor de tensão definido por meio do potenciômetro
  lcd.print(" V");

  lcd.setCursor(0, 1); // setando a posição do cursor para apresentar as barras no LCD

  graph = map(analog_POT, 0, 1023, 0, 16); // mapeando a escala de 0 a 1023 do potenciômetro para uma escala de 0 a 16
  
  for (int nC = 0; nC < graph; nC++) { // imprimindo a barra no LCD para o aumento da tensão definida no potenciômetro
    lcd.write(B11111111);
  }
  for (int nC = graph; nC < 16; nC++) {// imprimindo a espaço no LCD para a redução da tensão definida no potenciômetro
    lcd.print(" ");
  }

  delay(200); // delay de 200 ms
}
