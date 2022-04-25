/*******************************************************************************
*
*    EXPERIMENTO 2 - PORTAS ANALÓGICAS NO ARDUINO
*
*******************************************************************************/
# define POT A0 // durante a compilação, o compilador substituirá qualquer menção de POT por A0.

const int CH = 8; // chave
const int RED = 11; // led vermelho
const int YELLOW = 12; // led amarelo
const int GREEN = 13; // led verde

void setup() {

  pinMode(CH,INPUT_PULLUP); // definindo a chave como um pino de entrada com conexão com o resistor interno pull up do ARDUINO

  pinMode(RED,OUTPUT); // definindo o led vermelho como um pino de saída
  pinMode(YELLOW,OUTPUT); // definindo o led amarelo como um pino de saída
  pinMode(GREEN,OUTPUT); // definindo o led verde como um pino de saída

  digitalWrite(RED,LOW);
  digitalWrite(YELLOW,LOW);
  digitalWrite(GREEN,LOW);
 
  Serial.begin(19200); // definindo a taxa de transmissão da comunicação serial (bits/s)
}

void loop() {

  int analog_POT, analog_conv_POT;

  float volt_POT;
  
  analog_POT = analogRead(POT); // lendo a entrada no pino analógico A0 do ARDUINO
 
  volt_POT = (float) analog_POT*(5.0/1023);// convertendo a leitura analógica para um valor de tensão compreendida entre 0 e 5 V

  if(!digitalRead(CH)){ // enquanto a chave permanecer fechada, fazer:
   
    if(volt_POT < 2.0){// ligar o led verde se a tensão for menor do que 2 V
      digitalWrite(RED,LOW);
      digitalWrite(YELLOW,LOW);
      digitalWrite(GREEN,HIGH);
      }
    if((volt_POT >= 2.0) && (volt_POT < 4.0)){ // ligar o amarelo se a tensão maior ou igual a 2 V e menor do que 4 V
      digitalWrite(RED,LOW);
      digitalWrite(GREEN,LOW);
      digitalWrite(YELLOW,HIGH);
      }
    if(volt_POT >= 4.0){ // ligar o led vermelho se a tensão for maior do que 4 V
      digitalWrite(GREEN,LOW);
      digitalWrite(YELLOW,LOW);
      digitalWrite(RED,HIGH);
      }
    }
    else{
      digitalWrite(RED,LOW);
      digitalWrite(YELLOW,LOW);
      digitalWrite(GREEN,LOW);
      }
      
  Serial.print("A tensao na entrada A0 = ");Serial.print(volt_POT);Serial.println(" volts");

  delay(300); // espera 300 ms antes da próxima leitura
}
