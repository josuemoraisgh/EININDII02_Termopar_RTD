# Instrumentação Industrial II
## Aula Prática 02: Derivação da Expressão Aproximada da Saída da Ponte de Wheatstone

Partindo da equação geral de uma Ponte de Wheatstone:

$$
V_{a} - V_{b} = \left(\frac{R_{c}}{R_{c}+R_{a}} - \frac{R_{Pt100}}{R_{Pt100}+R_{b}}\right) V_{cc}
$$

### 1. Condição Inicial de Equilíbrio

Assuma que todos os resistores são inicialmente iguais a $( R )$:

$$
R_{a} = R_{b} = R_{c} = R_{Pt100} = R.
$$

Nesse caso:

$$
\frac{R_{c}}{R_{c}+R_{a}} = \frac{R}{R+R} = \frac{1}{2}, \quad
\frac{R_{Pt100}}{R_{Pt100}+R_{b}} = \frac{R}{R+R} = \frac{1}{2}.
$$

Substituindo na expressão inicial:

$$
V_{a} - V_{b} = \left(\frac{1}{2} - \frac{1}{2}\right) V_{cc} = 0.
$$

Isto mostra que a ponte está balanceada sem variação de resistência.

### 2. Variação do PT100

Agora, considere uma pequena variação na resistência do PT100:

$$
R_{Pt100} = R + \Delta R.
$$

Logo:

$$
\frac{R_{Pt100}}{R_{Pt100}+R_{b}} = \frac{R+\Delta R}{(R+\Delta R) + R} = \frac{R+\Delta R}{2R + \Delta R}.
$$

### 3. Aproximação por expansão de Taylor para Pequenas Variações $(\Delta R \ll R)$

Defina a função:

$$
f(\Delta R) = \frac{R + \Delta R}{2R + \Delta R}.
$$

Queremos aproximar $(f(\Delta R))$ para valores pequenos de $(\Delta R)$.

1. Avalie a função em $(\Delta R = 0)$:

$$
f(0) = \frac{R + 0}{2R + 0} = \frac{R}{2R} = \frac{1}{2}.
$$

3. Calcule a derivada de $( f )$ em relação a $(\Delta R)$:
   
$$
f'(\Delta R) = \frac{(2R + \Delta R)*1 - (R + \Delta R)*1}{(2R + \Delta R)^2}.
$$

   Simplificando o numerador:
   
$$
(2R + \Delta R) - (R + \Delta R) = R.
$$

   Portanto:
   
$$
f'(\Delta R) = \frac{R}{(2R + \Delta R)^2}.
$$

5. Avalie a derivada em $(\Delta R = 0)$:

$$
f'(0) = \frac{R}{(2R)^2} = \frac{R}{4R^2} = \frac{1}{4R}.
$$

7. Agora, utilizando a expansão de Taylor de primeira ordem em torno de $\Delta R = 0$:
   
$$
f(\Delta R) \approx f(0) + f'(0)\Delta R = \frac{1}{2} + \frac{1}{4R}\Delta R.
$$

Substituindo novamente $(\Delta R)$:

$$
\frac{R + \Delta R}{2R + \Delta R} \approx \frac{1}{2} + \frac{\Delta R}{4R}.
$$

Dessa forma, obtivemos a aproximação desejada por meio de uma expansão de Taylor.

### 4. Substituindo as Aproximações na Equação Inicial

Substituindo $(\frac{R_{c}}{R_{c}+R_{a}} = 1/2)$ e $(\frac{R_{Pt100}}{R_{Pt100}+R_{b}} \approx \frac{1}{2} + \frac{\Delta R}{4R}$):

$$
V_{a} - V_{b} = \left(\frac{1}{2} - \left(\frac{1}{2} + \frac{\Delta R}{4R}\right)\right) V_{cc}.
$$

Simplificando:

$$
V_{a} - V_{b} = \left(\frac{1}{2} - \frac{1}{2} - \frac{\Delta R}{4R}\right) V_{cc} = -\frac{\Delta R}{4R} V_{cc}.
$$

Definindo $(V_{in} = V_{cc})$ e a saída da ponte $(V_{out,Wheatstone} = V_{a} - V_{b})$:

$$
V_{out,Wheatstone} \approx -\frac{\Delta R}{4R} V_{in}.
$$

O sinal negativo depende da escolha do terminal de referência. Geralmente, a expressão é apresentada como:

$$
V_{out,Wheatstone} \approx \frac{\Delta R}{4R} V_{in}.
$$

### Conclusão

Partindo da expressão geral da ponte e assumindo pequenas variações de resistência no PT100, chega-se à relação aproximada entre a tensão de saída da Ponte de Wheatstone e a variação de resistência:

$$
V_{out,Wheatstone} \approx V_{in} \cdot \frac{\Delta R}{4R}.
$$


## Comparação entre a sensibilidade de uma Ponte de Wheatstone e de um Divisor Resistivo na medição de temperatura com PT100

### Ponte de Wheatstone

Para uma ponte com quatro resistores iguais $( R )$ e apenas um deles variando com a temperatura (PT100), a tensão de saída aproximada é dada por:

$$
V_{out,Wheatstone} \approx V_{in} \cdot \frac{\Delta R}{4R}
$$

Sabendo que a variação de resistência em função da temperatura é:

$$
\Delta R = \alpha R \Delta T
$$

substituímos na expressão da saída da ponte:

$$
V_{out,Wheatstone} = V_{in} \cdot \frac{\alpha R \Delta T}{4R} = V_{in} \cdot \frac{\alpha \Delta T}{4}
$$

A sensibilidade da Ponte de Wheatstone (derivada da saída em relação à temperatura) é:

$$
\frac{dV_{out,Wheatstone}}{dT} = \frac{\alpha V_{in}}{4}
$$

### Divisor Resistivo

Para um divisor resistivo composto por um resistor fixo $( R_{1} )$ e o PT100 (assumido como $( R_{2} )$), temos:

$$
V_{out,Divisor} = V_{in} \cdot \frac{R_2}{R_1 + R_2}
$$

O PT100 varia com a temperatura conforme:

$$
R_2 = R(1+\alpha \Delta T)
$$

No ponto de referência (por exemplo, $(\Delta T = 0)$, onde $(R_{2} = R)$), a sensibilidade do divisor resistivo é obtida derivando a expressão da saída em relação à temperatura:

$$
\frac{dV_{out,Divisor}}{dT}\bigg|_{\Delta T=0} = V_{in} \cdot \frac{\alpha R R_1}{(R_1 + R)^2}
$$

Portanto, a sensibilidade do divisor resistivo é:

$$
Sensibilidade_{Divisor} = V_{in} \cdot \frac{\alpha R R_1}{(R_1 + R)^2}
$$

### Conclusão

- **Ponte de Wheatstone:**
  
$$
Sensibilidade_{Wheatstone} = \frac{\alpha V_{in}}{4}
$$

- **Divisor Resistivo:**
  
$$
Sensibilidade_{Divisor} = V_{in} \cdot \frac{\alpha R R_1}{(R_1 + R)^2}
$$

A Ponte de Wheatstone apresenta uma relação mais simples, dependendo apenas de $(\alpha)$ e $(V_{in})$. Já o divisor resistivo depende da relação entre $(R_{1})$ e $(R)$, além de $(\alpha)$ e $(V_{in})$.
