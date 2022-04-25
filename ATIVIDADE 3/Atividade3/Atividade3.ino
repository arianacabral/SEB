/*******************************************************************************

     EXPERIMENTO 3 - CONTROLE DE LUMINOSIDADE

*******************************************************************************/

// ENTRADAS ANALÓGICAS
# define LDR A0 // durante a compilação, o compilador substituirá qualquer menção de LDR por A0.
# define POT A1 // durante a compilação, o compilador substituirá qualquer menção de POT por A1.

// ENTRADAS DIGITAIS
const int CH = 11; // chave
const int LAMP = 10; // lâmpada

// VARIÁVEIS GLOBAIS
int analog_POT, analog_LDR;
int lum_POT, lum_LDR;
int luminosidade;

void setup() {

  pinMode(CH, INPUT_PULLUP); // definindo a chave como um pino de entrada com conexão com o resistor interno pull up do ARDUINO

  pinMode(LAMP, OUTPUT); // definindo a lâmpada como um pino de saída

  pinMode(POT, INPUT); // definindo o potenciômetro como um pino de entrada

  pinMode(LDR, INPUT); // definindo o LDR como um pino de entrada

  Serial.begin(19200); // definindo a taxa de transmissão da comunicação serial (em bits/s)
}

void loop() {

  if (!digitalRead(CH)) {// se a chave está fechada, fazer:

    analog_POT = analogRead(POT); // lendo a entrada no pino analógico A0 do ARDUINO (potenciômetro)

    lum_POT = map(analog_POT, 0, 1023, 0, 255); // convertendo a escala de 10 bits para uma escala de 8 bits

    analog_LDR = analogRead(LDR); // lendo a entrada no pino analógico A1 do ARDUINO (LDR)

    lum_LDR =  map(analog_LDR, 11, 990, 0, 255); // convertendo a escala do LDR, compreendida entre 11 e 990 (Proteus), para uma escala entre 0 e 255

    if (!lum_LDR == 0) { // se o valor lido no LDR é diferente de 0, então há luminosidade além da luminosidade vinda da lâmpada

      luminosidade = lum_POT - lum_LDR; // portanto, pode-se reduzir o nível de luminosidade vindo da lâmpada

      analogWrite(LAMP, luminosidade); // acionando uma onda PWM na entrada correspondente a lâmpada
    }
    else {// se o valor lido no LDR é igual a 0, então a luminosidade provém da lâmpada apenas

      luminosidade = lum_POT; // portanto, o nível de luminosidade da lâmpada é o valor de referência apenas

      analogWrite(LAMP, luminosidade); // acionando uma onda PWM na entrada correspondente a lâmpada

    }
    
  Serial.print("LUMINOSIDADE DE REFERENCIA = "); Serial.println(lum_POT); // apresentando no serial terminal
  Serial.print("LUMINOSIDADE EXTERNA = "); Serial.println(lum_LDR); // apresentando no serial terminal
  Serial.print("LUMINOSIDADE NA LAMPADA = "); Serial.println(luminosidade); // apresentando no serial terminal

  delay(500); // esperando 500 ms antes da próxima leitura

  }

  else {// se a chave está aberta:
    
    analogWrite(LAMP, 0); // garantir que a lâmpada estará desligada
    
  }
}
