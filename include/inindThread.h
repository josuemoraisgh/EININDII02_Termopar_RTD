//O timer0 é utilizado pelo Arduino para funções como delay(), millis() e micros(). Então não se deve utilizar esse timer para evitar comprometer essas funções.
//O timer1 no Arduino UNO esse é o timer utilizado pela biblioteca de controle de servos. Caso você não esteja utilizando essa biblioteca, esse timer está livre para ser utilizado para outros propósitos. No Arduino Mega esse timer só será utilizado para controlar os servos se você estiver usando mais de 12 servos. (timer utilizado no projeto)
//O timer2 é utilizado pela função tone(). Então se você não precisar da função tone() esse timer está livre para outras aplicações.
#include <Arduino.h>
#include <stdarg.h>

using CallbackFunc = void (*)(); // Definição de tipo para callback.
volatile CallbackFunc threadFunc[5];
volatile int numThread, threadInterval[5], threadTime[5];


void threadSetup(CallbackFunc callback, int threadIntervalFunc, ...)
{
    numThread = 0;
    va_list args;
    va_start(args, threadIntervalFunc);

    threadFunc[numThread] = callback;
    threadInterval[numThread] = threadIntervalFunc;
    threadTime[numThread] = 0;
    numThread++;

    while (numThread < 5)
    {
        CallbackFunc nextCallback = va_arg(args, CallbackFunc);
        if (!nextCallback) break;

        int nextInterval = va_arg(args, int);
        threadFunc[numThread] = nextCallback;
        threadInterval[numThread] = nextInterval;
        threadTime[numThread] = 0;
        numThread++;
    }
    va_end(args);

    cli(); // Desativa interrupções durante a configuração.
    TCCR1A = 0b01000000; // Modo comparação.
    TCCR1B = 0b00001011; // Prescaler em 64.
    TIMSK1 = 0b00000010; // Habilita interrupção por comparação.
    OCR1A = 249;         // Compare match register.
    sei(); // Habilita interrupções globais.
}

ISR(TIMER1_COMPA_vect)
{
    for (int i = 0; i < numThread; i++)
    {
        if (threadTime[i] >= threadInterval[i])
        {
            threadFunc[i]();
            threadTime[i] = 0;
        }
        else
        {
            threadTime[i]++;
        }
    }
}


