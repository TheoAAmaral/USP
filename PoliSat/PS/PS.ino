	// Definir pinos
#define MOTOR      8
#define VIBRA      9
#define SENS_TEMP A5
#define PAINEL    A4

	// Tempo arbitrário que é usado para controlar a frequência na qual o LED pisca
#define TEMPO 1000


	// Define as portas do LED RGB
#define LED_VERM   2
#define LED_AZUL   3
#define LED_VERD   4

	// Definir variáveis
  int tempoMilissegundos;
  int temp;
  float painelSolar;
  int tempoPisca = 0;
  bool estadoLed = 1; // Definida como 1 para, quando ter de piscar, já começar ligado

void setup()
{
  	// Definir modo dos pinos
  pinMode(MOTOR, OUTPUT);
  pinMode(VIBRA,OUTPUT);
	
  	// Inicializa os pinos colocando-os em LOW
  digitalWrite(MOTOR, LOW);
  digitalWrite(VIBRA, LOW);
  
}
  

	// Define uma função para piscar a cor azul
void piscaAzul()
{
  	// Checa se a variável alcançou o tempo necessário
  if(tempoPisca < TEMPO)
    // Senão, adiciona 1 até chegar ao valor
  	tempoPassado++;
  else
  {
  	tempoPassado = 0; // Reinicia a variável tempo
    estadoLed = estadoLed ^ 1; // Alterna o valor da variável booleana, utilizando uma comparação do tipo XOR
  }
  	// Desliga as cores não usadas e usa a variável estadoLed para definir o estado do LED utilizado
  digitalWrite(LED_VERM, LOW);
  digitalWrite(LED_VERD, LOW);
  digitalWrite(LED_AZUL,estadoLed);
}

	// Define uma função para piscar a cor amarela
void piscaAmarelo()
{
  	// Checa se a variável alcançou o tempo necessário
  if(tempoPassado < TEMPO)
    // Senão, adiciona 1 até chegar ao valor
  	tempoPassado++;
  else
  {
  	tempoPassado = 0; // Reinicia a variável tempo
    estadoLed = estadoLed ^ 1; // Alterna o valor da variável booleana, utilizando uma comparação do tipo XOR
  }
  // Desliga a cor não usada e usa a variável estadoLed para definir o estado do LED utilizado
  digitalWrite(LED_VERM, estadoLed);
  digitalWrite(LED_VERD, estadoLed);
  digitalWrite(LED_AZUL, LOW);
}

void loop()
{
  tempoMilissegundos = millis(); // Armazena o tempo atual numa variável (em milissegundos)
  
  	// Ligar o motor de vibração entre 3s e 8s
  if(tempoMilissegundos >= 3000 && tempoMilissegundos <= 8000)
  	digitalWrite(VIBRA, HIGH);
  else 
    digitalWrite(VIBRA, LOW);
  
  
  temp = analogRead(SENS_TEMP); // Lê a temperatura
  painelSolar = analogRead(PAINEL)*0.00488; // Lê a tensão do painel solar e mapeia os valores no intervalo de 0 a 5, com casas decimais.
  
  	// Verifica se a temperatura está maior ou igual a 45° E se o painel solar está com tensão menor que 3.33V 
  if(temp >= 200 && painelSolar < 3.33)
    	//  Caso as condições estejam desfavoráveis, liga o motor
    digitalWrite(MOTOR, HIGH);
  else
    digitalWrite(MOTOR, LOW);
  
  
  	// Controle do LED
  if(digitalRead(VIBRA))
  {
    // Prioridade máxima, pisca azul o LED se o motor de vibração está ligado
    piscaAzul();
  }
  else if(digitalRead(MOTOR))
  {
    // Pisca o LED em amarelo quando o motor estiver ligado, prioridade menor que o piscar azul
    piscaAmarelo();
  }
  else if(temp >= 200 || painelSolar < 3.33)
  {
    // Deixa o LED ligado em vermelho caso algum dos 2 sensores esteja em condição desfavorável
    digitalWrite(LED_VERM, HIGH);
    digitalWrite(LED_AZUL, LOW);
    digitalWrite(LED_VERD, LOW);
    estadoLed = 1; // Recoloca a variável em 1 para começar o processo de piscar com o LED ligado
  }
  else
  {
    // Menor prioridade, deixa o LED ligado em verde se não há nenhuma situação desfavorável
    digitalWrite(LED_VERM,LOW);
    digitalWrite(LED_AZUL, LOW);
    digitalWrite(LED_VERD, HIGH);
    estadoLed = 1; // Recoloca a variável em 1 para começar o processo de piscar com o LED ligado
  }
}