## Shift Register :twisted_rightwards_arrows:
Un dispositivo che spesso viene utilizzato per sfruttare le potenzialità della comunicazione **SPI** è lo *Shift Register*. 

Fondamentalmente, uno *Shift Register* è composto da una serie di flip-flop digitali, connessi in serie tra loro. Ognuno di essi conserva un 1 bit di informazione ed ogni volta che il segnale di clock agisce sullo *Shift Register*, ogni flip-flop trasmette la sua informazione al suo vicino successivo e riceve una nuova informazione binaria da chi lo precede. La caratteristica importante è che i valori contenuti nei flip-flop possono essere letti tutti contemporaneamente in uscita, realizzando un uscita di segnali in parallelo.

In sostanza dunque, il segnale di natura seriale che arriva in ingresso allo *Shift Register* viene trasformato in tanti diversi segnali accessibili in parallelo. Ovviamente l'operazione si può realizzare anche in maniera opposta, operando come trasmettitore seriale. Questo tipo di operazione avviene internamente in una periferica **SPI** di microcontrollore, che funziona proprio grazie a degli *Shift Register* interni. 

Spesso, si usano degli *Shift Register* esterni al microcontrollore, che permettono, tramite comunicazione **SPI** di aumentare notevolmente le possibilità di input/output.

### Texas Instruments // SN74HC595
Si analizza, ad esempio, lo *Shift Register* SN74HC595, prodotto dalla Texas Instruments. Analizzandone il [datasheet](docs/sn74hc595.pdf), si può determinare il pinout di tale dispositivo ed il suo funzionamento.

#### Features
* 8-Bit Serial-In, Parallel-Out Shift
* Wide Operating Voltage Range of 2 V to 6 V 
* ±6-mA Output Drive at 5 V
* Low Power Consumption: 80-μA (Maximum)
> The SNx4HC595 devices contain an 8-bit, serial-in parallel-out shift register that feeds an 8-bit D-type storage register. The shift register has a direct overriding clear (**<span style="text-decoration:overline">SRCLR</span>**) input, serial (**SER**) input, and serial outputs for cascading. When the output-enable (**<span style="text-decoration:overline">OE</span>**) input is high, the outputs are in the high-impedance state

Di seguito è illustrato il pinout del dispositivo; per un utilizzo dei segnali **SPI**, si connette il pin `SER` al segnale **MOSI**, il pin `SRCLK` a  **SCK** ed infine `RCLK` equivalente a **SS**.

<p align="center">
    <img src="img/Pinout-74HC595-Shift-Register.png">
</p>

Sui valori delle uscite `Q`, da `A` a `H`, si avranno in forma parallela i segnali che entrano nel dispositivo in maniera seriale sfruttando la comunicazione **SPI**.

|Pin Number |Pin Name|Description|
| :-:       |   :-:  |     :-:   |
|15, 1-7    |**QA, QB – QH** | Output Pins|
|8	|**GND**	|Ground Pin|
|9	|**QH’**	|QH’ Output|
|10	|**<span style="text-decoration:overline">SRCLR</span>**	|Reset Input|
|11	|**SRCLK**	|Clock Input|
|12	|**RCLK**	|Storage Register Clock Input|
|13	|**<span style="text-decoration:overline">OE</span>**	    |Output Enable|
|14	|**SER**	|Serial Input|
|16	|**VCC**	|Supply Voltage|

In definitiva, il sistema di funzionamento è molto semplice: al fronte di salita del clock **SRCLK**, il dato presente su **SER** viene caricato nello *Shift Register* e quando si rileva un fronte di salita su **RCLK** il dato nel registro viene portato in output su **QA**...**QH**.

***
</br>

:link: [SN74HC595](http://www.ti.com/product/SN74HC595)