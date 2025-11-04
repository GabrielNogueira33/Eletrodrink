#include <SoftwareSerial.h>
SoftwareSerial HC05(0,1);

//definindo os pinos
#define BO1 2
#define BO2 3
#define BO3 4
#define BO4 5

int state= 0;
//quanto tempo até a substituição da próxima bomba
int TempoEjecao = 500;

void Mix(int DelayBO1, int DelayBO2, int DelayBO3, int DelayBO4) {
  
  state= 0;
  delay(800);
  digitalWrite(BO1, LOW);   
  delay(DelayBO1);            
  digitalWrite(BO1, HIGH); 
  delay(TempoEjecao);    

  digitalWrite(BO2, LOW);   
  delay(DelayBO2);            
  digitalWrite(BO2, HIGH); 
  delay(TempoEjecao); 

  digitalWrite(BO3, LOW);   
  delay(DelayBO3);            
  digitalWrite(BO3, HIGH); 
  delay(TempoEjecao);

  digitalWrite(BO4, LOW);   
  delay(DelayBO4);            
  digitalWrite(BO4, HIGH); 
  delay(TempoEjecao);
  
  Serial.println("A sua bebida está pronta!"); 
  state = 0;
}
void setup()
{
  Serial.begin(9600); 
  Serial.println("O bluetooth está disponível, conecte-se ao HC-05 com outro aparelho compatível, senha 1234 de pareamento. ");
  HC05.begin(9600);

  // Define os pinos 2-9 como pinos de saída para acionar a placa de relé
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
 
// se a placa relé for "low true",define a saída para baixa energização do relé. Para que todos não liguem ao ligar a coqueteleira
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH); 
}
 
void loop(){
if(HC05.available()){ // Verifica se os dados estão vindo do módulo bluetooth
    state = HC05.read(); // Lê os dados da módulo bluetooth
    HC05.println(state);
    
// Bebidas:


// suco 1
if (state == 'a') {
Serial.println("Fazendo Tang limão");
  Mix(1200,0,0,0); 
 }

// suco 2
if (state == 'b') {
  Serial.println("Fazendo Tang Uva");
  Mix(0,1200,0,0); 
 }
  

// Suco 3
if (state == 'c') {
  Serial.println("Fazendo Tang Laranja");
  Mix(0,0,1200,0); 
 }

// Suco 4
if (state == 'd') {
  Serial.println("Fazendo Tang Maracujá");
  Mix(0,0,0,1200); 
 }

// Mistureba 
if (state == 'e') {
  Serial.println("Fazendo Mistureba");
  Mix(1100,1100,1100,1100);
  }

 }

// teste e manutenção

// Set-up BO1
if (state == 'f') {
  Serial.println("Set-up BO1");
  Mix(1100,0,0,0); 
 }

// Set-up BO2
if (state == 'g') {
  Serial.println("Set-up BO2");
  Mix(0,1100,0,0); 
 }

// Set-up BO3
if (state == 'h') {
  Serial.println("Set-up BO3");
  Mix(0,0,1000,0); 
 }

// Set-up BO4
if (state == 'i') {
  Serial.println("Set-up BO4");
  Mix(0,0,0,1000); 
 }



// LIMPAR
if (state == 'j') {
  Serial.println("Set-up LIMPAR");
  Mix(4000,4000,4000,4000); 
 }

// Set-up TESTE GERAL (primeira vez após a limpeza)
if (state == 'k') {
  Serial.println("Set-up Teste geral");
  Mix(800,800,800,800); 
 }
    
}
