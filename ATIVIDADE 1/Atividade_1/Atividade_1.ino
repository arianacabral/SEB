/*******************************************************************************
*
*    EXPERIMENTO 1 - PORTAS DIGITAIS NO ARDUINO
*
*******************************************************************************/
const int CH = 8; // chave 
const int RED = 11; // led vermelho 
const int YELLOW = 12; // led amarelo
const int GREEN = 13; // led verde

void setup() {

  // CHAVE
  pinMode(CH,INPUT_PULLUP); // pino de entrada (resistor pull up interno)

  // LEDS
  pinMode(RED,OUTPUT); // pino de saída 
  pinMode(YELLOW,OUTPUT); // pino de saída 
  pinMode(GREEN,OUTPUT); // pino de saída 


  // Definindo os estados iniciais dos LEDS em nível baixo (LOW)
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
    
}

void loop(){

  if(digitalRead(CH)){ // verifica se a chave continua aberta
    
    digitalWrite(YELLOW, LOW); // apaga o led AMARELO
    
    // LED VERMELHO
    digitalWrite(RED, HIGH); // acende o led VERMELHO
    delay(3000); // aguarda 3000 ms (3 s)
    digitalWrite(RED, LOW); // apaga o led VERMELHO

    if(digitalRead(CH)){ // verifica se a chave continua aberta
    
      // LED AMARELO
      digitalWrite(YELLOW, HIGH); // acende o led AMARELO
      delay(1000); // aguarda 1000 ms (1 s)
      digitalWrite(YELLOW, LOW); // apaga o led AMARELO
      
      if(digitalRead(CH)){// verifica se a chave continua aberta
        
        // LED VERDE
        digitalWrite(GREEN, HIGH); // acende o led VERDE
        delay(2000); // aguarda 2000 ms (2 s)
        digitalWrite(GREEN, LOW); // apaga o led VERDE
        }
      else{
        // LED AMARELO INTERMITENTE
        digitalWrite(YELLOW, HIGH);  // acende o led AMARELO
        delay(500); // aguarda 500 ms (0.5 s)
        digitalWrite(YELLOW, LOW); // apaga o led AMARELO
        delay(500); // aguarda 500 ms (0.5 s)
        }
      }
    else{
      // LED AMARELO INTERMITENTE
      digitalWrite(YELLOW, HIGH); // acende o led AMARELO
      delay(500); // aguarda 500 ms (0.5 s)
      digitalWrite(YELLOW, LOW); // apaga o led AMARELO
      delay(500); // aguarda 500 ms (0.5 s)
      }  
    }
  else{ // chave fechada
    // LED AMARELO INTERMITENTE    
    digitalWrite(YELLOW, HIGH); // acende o led AMARELO
    delay(500); // aguarda 500 ms (0.5 s)
    digitalWrite(YELLOW, LOW); // apaga o led AMARELO
    delay(500); // aguarda 500 ms (0.5 s)
    }
  }
