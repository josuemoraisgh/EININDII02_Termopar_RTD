#include <Arduino.h>

#define MAXLENGTHJQUEUE 5
#define NUM_TASKS 2
#include "util/jtask.h"

double getTempRTD(int pin)
{
  const double r1 = 1000.0;
  const double r2 = 1000.0;
  const double r3 = 1000.0;
  const double rg = 1000.0;

  const double rc = 200.0;
  const double ra = 100.0;
  const double rb = 100.0;

  double k = (rc / (rc + ra)) - (((double)analogRead(pin)) * r2 * rg / (1023.0 * r3 * (rg + 2.0 * r1)));

  double r = ((double)rb) / ((1.0 / k) - 1.0);

  return (((r / 100.0) - 1.0) / 0.0038459);
}

void printRTDValue()
{
  double temperature = getTempRTD(A5); // VARIÁVEL DO TIPO INTEIRO QUE RECEBE O VALOR DE TEMPERATURA CALCULADO PELA BIBLIOTECA
  Serial.print(">Temp:");              // IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.print(temperature, 2);        // IMPRIME NO MONITOR SERIAL A TEMPERATURA MEDIDA
  Serial.println("§ºC");               // IMPRIME O TEXTO NO MONITOR SERIAL
}

void setup()
{
  Serial.begin(115200);
  jtaskSetup(1000);    // Configura o timer para 1000 Hz (1 ms)
  jtaskAttachFunc(printRTDValue, 1000); // Executa a cada 1s (1000 ms)
}

void loop() {
  jtaskLoop(); // Executa as tarefas enfileiradas
}
