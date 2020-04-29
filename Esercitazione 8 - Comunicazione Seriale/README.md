# Esercitazione 8
### Comunicazione Seriale

***
</br>

## Overview
In questa esercitazione si utilizzeranno le principali interfacce di comunicazione seriale - **UART**, **SPI** e **I2C** - per la comunicazione con diversi dispositivi e sensori.

Inizialmente sarà presentata solo la comunicazione asincrona, utilizzandola in *STM32Cube* e successivamente facendo uso della piattaforma *mbed*.

## Requisiti Teorici
Una comunicazione di tipo seriale utilizza in maniera efficiente un singolo filo per il trasferimento di dati, sotto forma di bit, in maniera sequenziale.

I diversi protocolli di comunicazione seriale risolvono i principali problemi che riguardano la comunicazione tra due dispositivi; ad esempio stabilire, da parte del ricevitore, quando comincia e finisce un singolo bit o un'intera sequenza.

Un approccio utilizzato da diversi protocolli consiste nell'utilizzare un *segnale di clock* "accoppiato" ai dati, in questo modo si riesce a stabilire dunque una sincronizzazione tra dati e clock ed il tipo di comunicazione si dice **sincrona**: ad ogni impulso del *segnale di clock* il trasmettitore invia un bit e il ricevitore si sincronizza su uno dei fronti del *segnale di clock* per effettuare la lettura.

![Comunicazione sincrona](img/synchronous_serial_data.png)

Il *segnale di clock* stabilisce quanto veloce vengono trasferiti i dati, con la sua frequenza, e quanto dura l'intera trasmissione. 

Nel caso in cui entrambi i dispositivi, che vogliono comunicare, siano già d'accordo sulla velocità e sul tempo di trasmissione di un singolo bit si può evitare di utilizzare un *segnale di clock* e concordare tra i due una comunicazione **asincrona**.

![Comunicazione asincrona](img/asynchronous_serial_data.png)

Diversi dispositivi possono essere interconnessi in diversi modi per realizzare delle comunicazioni di tipo seriale; si possono realizzare, ad esempio, anche delle "reti" con la classica architettura *master-slave*, in cui assume il ruolo di master il dispositivo che gestisce il clock. Secondo questa logica funzionano sistemi di comunicazione quali **SPI** e **I2C**.

<p align="center">
    <img src="img/master_slave.png" width="70%"> 
</p>

### UART e USART
Sebbene la comunicazione seriale **sincrona** sia utilizzata con moltissimi dispositivi, la gestione di un segnale (*il clock*) che ha bisogno sia di una linea dedicata che di una certa banda a disposizione risulta essere un peso, che ha indotto quindi allo sviluppo di criteri di comunicazione **asincroni**. Questi offrono anche il vantaggio di essere affidabili su lunghe distanze, rispetto alle quali un *segnale di clock* potrebbe degradarsi e far perdere la sincronizzazione. 

La logica di funzionamento si basa sullo stabilire la durata di trasmissione di un singolo bit ed evitare l'utilizzo di un clock di sincronizzazione. Questo meccanismo viene realizzato tramite un dispositivo hardware dedicato chiamato **UART** (**U**niversal **A**synchronous **R**eceiver-**T**ransmitter), che è presente in ogni microcontrollore e permette la comunicazione con una miriade di dispositivi.

Nella forma più semplice, una comunicazione **UART** utilizza una sola connessione per la trasmissione (indicata con **TX**) ed una sola per la ricezione (indicata con **RX**). È importante stabilire il *data rate* con cui operano il trasmettitore ed il ricevitore, e questo valore prende il nome di *baud rate*.

Oltre a questo valore ci sono una serie di altri parametri che entrano in gioco quando si vuole inviare un flusso di dati con comunicazione **UART**, i principali sono i seguenti:
- **Data bits**: Numero di bits per singolo valore trasmesso (default: 8);
- **Stop bits**: Numero di bits usati per identificare la fine, lo stop, del flusso dati (default: 1);
- **Parity bit**: Presenza ed eventuale tipologia del bit di parità.

Per la gestione della **UART** in un microcontrollore entrano in gioco altri parametri di configurazione importanti, che permettono di mettere in pratica anche diverse modalità di funzionamento.

Spesso, questo metodo di comunicazione viene accompagnato anche da un segnale di clock, dando luogo ad una comunicazione chiamata **USART** (**U**niversal **S**ynchronous/**A**synchronous **R**eceiver-**T**ransmitter).
<p align="center">
    <img src="img/uart_usart.png" width="90%"> 
</p>

Mentre per la comunicazione **UART** un segnale di clock viene generato internamente nel microcontrollore -a partire dalla conoscenza del *baud rate* ed appena si identifica il primo bit del flusso dati- per la **USART** non vi è bisogno di specificare alcun *baud rate*: il segnale di clock viaggia su un canale dedicato e ciò permette di ottenere anche risultati migliori, arrivando in alcuni casi a trasferimenti con *rate* di 4 Mbps. Questa però porta con sé gli svantaggi legati alla presenza di un segnale di clock.

### UART/USART nei microcontrollori STM32
Ogni microcontrollore della famiglia STM32 esporta almeno una porta di comunicazione **UART**, nel caso del microcontrollore utilizzato per queste esercitazioni si hanno a disposizione due **UART** (UART4 e UART5) e quattro **USART** (USART1, USART2, USART3 e USART6). 

La gestione di questo tipo di comunicazione passa, ovviamente, per l'utilizzo di opportuni registri che permettono di configurare sia una comunicazione **USART** che una comunicazione **UART**, a seconda dei campi utilizzati. Di seguito, ed anche in fase di implementazione, si utilizzeranno spesso in maniera equivalente le due parole, specificando la distinzione tra le due solo se necessario.

Per quanto riguarda la configurazione del *baud rate*, si ricorre ovviamente al clock del sistema, che deve essere opportunamente scalato per essere adeguato, sulla periferica **UART**, e permettere di ottenere il *rate* desiderato.

<p align="center">
    <img  width="33%" src="https://render.githubusercontent.com/render/math?math=%5Ctext%7Bbaud%7D%20%3D%20%5Cfrac%7Bf_%7Bck%7D%7D%7B8%5Ccdot(2-%5Ctext%7BOVER8%7D)%20%5Ccdot%20%5Ctext%7BUSARTDIV%7D%7D">
</p>

I valori che permettono di definire il *baud rate* e tutti gli altri parametri di configurazione si ritrovano all'interno di un set di registri, che si ritrovano completamente descritti nel [reference manual](https://www.st.com/resource/en/reference_manual/dm00135183-stm32f446xx-advanced-arm-based-32-bit-mcus-stmicroelectronics.pdf) del microcontrollore, insieme alla descrizione delle modalità di utilizzo e dei meccanismi di configurazione.

:information_source: Per il microcontrollore STM32F446RE, la comunicazione **USART2** passa attraverso i pin PA_2 e PA_3, questi mettono in comunicazione internamente il microcontrollore ed il modulo ST-Link. Sono utilizzati quindi per instaurare una comunicazione tra i due elementi e dunque per mettere in comunicazione il microcontrollore con il PC, tramite porta USB. Questa comunicazione è utilizzata implicitamente in tutte le fasi di programmazione e debugging del microcontrollore.  Dunque, finché si farà uso del modulo ST-Link sarà impossibile utilizzare questi pin per altri scopi.

La comunicazione mediante **UART** si può mettere in pratica in tre modalità: *polling*, *interrupt* o *DMA mode*.

- *Polling Mode*
> The main application, or one of its threads, synchronously waits for the data transmission and reception. This is the most simple form of data communication using this peripheral, and it can be used when the transmit rate is not too much low and when the UART is not used as critical peripheral in our application 
- *Interrupt Mode*
> The main application is freed from waiting for the completion of data transmission and reception. The data transfer routines terminate as soon as they complete to configure the peripheral. When the data transmission ends, a subsequent interrupt will signal the main code about this.

## Comunicazione USART con STM32Cube

Nell'ambiente di sviluppo di *STM32Cube* è possibile realizzare comunicazione di tipo **UART** a diversi livelli di astrazione, come sarà mostrato di seguito. Si partirà con un esempio mostrato utilizzando direttamente i registri (per comprenderne il funzionamento) e successivamente utilizzando il driver **HAL**.

Nell'esempio si farà uso delle porte **USART** che si trovano su PA_2 e PA_3 per comunicare con il pc, tramite porta USB; se non si dispone di un convertitore UART/USB esterno si farà quindi uso della comunicazione implicita fornita dal modulo ST-Link.

<p align="center" width="30%">
    <img src="img/uart_usb.jpg">
</p>
</br>

Lo scopo di un primo semplice esercizio è quello di mandare dei caratteri al PC; le fasi indispensabili per procedere a tale scopo sono le seguenti:
1. Attivazione del segnale di clock su periferica **USART** e **GPIO**
```c
RCC->APB1ENR |= (0x01 << 17); // Abilitazione USART2 clock
RCC->AHB1ENR |= (0x01 << 0);  // Abilitazione GPIOA clock
```
2. Configurazione dei pin PA_2 e PA_3 in modalità veloce e *alternate function mode*
```c
GPIOA->MODER &= ~(0x0F << 6);  // Clear MODER GPIOA2/3
GPIOA->MODER |= (0x0A << 6);   // Set Alternate function mode
GPIOA->OSPEEDR |= (0x0A << 6); // Set Fast Speed

GPIOA->AFR[0] |= (0b111 << 8);
GPIOA->AFR[0] |= (0b111 << 12);
```
 &nbsp; si noti che i registri **AFRL** e **AFRH** sono implementati utilizzando un array di due elementi `AFR[0]` e `AFR[1]`. </br> &nbsp; Per la loro configurazione fare riferimento al datasheet ed alle tabelle, come [quella estratta](docs/AlternateFunctionTab.pdf) e messa nella sottocartella *docs*.

3. Configurazione della lunghezza di trasmissione, dei valori di parità e di altri eventuali parametri
```c
USART2->CR1 |= (0b0 << 12); // 1 Start bit, 8 Data bits, n Stop bit (DEFAULT)
USART2->CR1 |= (0b0 << 9); // Even parity
```
4. Abilitazione di trasmissione/ricezione sulla porta **USART** desiderata
```c
USART2->CR1 |= (0b1 << 3); // Transmitter enable
USART2->CR1 |= (0b1 << 2); // Receiver enable
```
5. Calcolo dei valori per determinare il *baud rate* desiderato e configurazione con i registri
```c
USART2->BRR |= (22 << 4); // Mantissa - Configurato come valore decimale
USART2->BRR |= (13 << 0); // Fraction - Configurato come valore decimale
```
6. Avvio della comunicazione tramite abilitazione della **USART**
```c
USART2->CR1 |= (0b1 << 13);
```

A questo punto è possibile procedere all'invio dei dati facendo uso dei registri:
- **USART_DR** (**D**ata **R**egister)
> Che contiene il valore che si vuole trasmettere (oppure il valore appena ricevuto); 
- **USART_SR** (**S**tatus **R**egister)
> Usato in lettura per individuare diversi stati come, ad esempio, la fine della trasmissione.

Il programma implementato si trova nella cartella di progetto `uart_simpleTX`.

##

Ovviamente, è possibile fare uso delle funzioni e strutture del driver **HAL** per instaurare una comunicazione **UART**, in questa ottica implementativa si passa per una prima configurazione con *STM32CubeMX*.

<p align="center">
    <img src="img/UART_MX_config.png">
</p>

Come applicazione d'esempio si realizza la comunicazione tra MCU e PC scambiandosi, come valori, le successive letture di una valore analogico tramite **ADC** (usando un **timer** per dare una precisa frequenza alla lettura).

La generazione del codice agirà configurando una particolare struttura, come per tutte le periferiche gestite con la libreria **HAL**. La struttura in questione è 
```c
typedef struct {
uint32_t BaudRate;      // The connection Speed
uint32_t WordLength;    // The number of data bits transmitted or received in a frame
uint32_t StopBits;      // The number of stop bits transmitte
uint32_t Parity;        // Indicates the parity mode
uint32_t Mode;          // Specifies RX o TX mode
uint32_t HwFlowCtl;     // it specifies whether the RS232 Hardware Flow Control mode is enabled or disabled.
uint32_t OverSampling;  // Specification about oversampling method
} UART_InitTypeDef;
```
e la sua configurazione è la seguente:
```c
huart2.Instance = USART2;
huart2.Init.BaudRate = 115200;
huart2.Init.WordLength = UART_WORDLENGTH_8B;
huart2.Init.StopBits = UART_STOPBITS_1;
huart2.Init.Parity = UART_PARITY_NONE;
huart2.Init.Mode = UART_MODE_TX_RX;
huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
huart2.Init.OverSampling = UART_OVERSAMPLING_16;
```

Per mettere in pratica una comunicazione seriale di questo tipo, la libreria **HAL** offre diverse funzioni, a seconda che si voglia usare una modalità *polling* o *interrupt*. Per la prima, si fa utilizzo della funzione:
```c
HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
```
in cui `huart` è il puntatore ad una istanza della struttura mostrata precedentemente; `pData` è il puntatore ad un array che contiene la sequenza di bytes da inviare; `Size` è la dimensione di quest'array ed infine `Timeout` è il massimo tempo di attesa per il completamento della comunicazione (per aspettare in maniera indefinita si può usare la costante `HAL_MAX_DELAY`).

Questa funzione permette di inviare i dati contenuti nell'array specificato, in maniera equivalente esisterà una funzione per mettersi in ricezione in *polling*:
```c
HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
```

Per inviare i dati con una frequenza di 1Hz, si dovrà fare, in questo caso, una cosa del genere nel ciclo di vita principale del programma:
```c
while (1){
    // Temperature value "printed" on uart_data for serial output
    sprintf(uart_data_buff, "\r%.3f°C\n", temp);
    // Polling TX - a transmission every second
    HAL_UART_Transmit(&huart2, (uint8_t *)uart_data_buff, sizeof(uart_data_buff), HAL_MAX_DELAY);
    HAL_Delay(1000);
}
```
utilizzando un particolare accorgimento per inviare l'intero numero `float` sotto forma di bytes (come una stringa di caratteri che rappresentano il numero). L'alternativa sarebbe stata trasformare in maniera più "manuale" il valore decimale in una valore ad 8 bit, mettendo magari nell'array, in maniera separata, parte intera e parte decimale. In entrambi i casi si lascia al ricevitore l'onere di ricostruire il valore ricevuto.

Si faccia attenzione al fatto che, per utilizzare la funzione `sprintf()` è necessario attivare un campo di configurazione della sezione *Tool Setting* del progetto; come illustrato nello screenshot seguente.

<p align="center">
    <img src="img/printf_set.png">
</p>

##

Per usare invece la periferica **UART** in *modalità interrupt* è necessario utilizzare la interrupt associata a tale periferica ed intercettata dalla funzione `USARTx_IRQHandler()`. All'interno di questa funzione deve essere invocata `HAL_UART_IRQHandler()`, che si occuperà di invocare tutte le funzioni relative alle attività della periferica **UART**, gestendola in questa modalità *interrupt*.

Oltre a queste si farà uso delle funzioni per abilitare la periferica in questa modalità:
```c
HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
```
o
```c
HAL_StatusTypeDef HAL_UART_Receive_IT (UART_HandleTypeDef * huart, uint8_t * pData, uint16_t Size)
```
a seconda che si voglia effettuare la trasmissione o la ricezione. 

L'utilizzo di questa periferica con il meccanismo delle *interrupt* non è immediato, in quanto sono diversi i segnali che farebbero scattare un *interrupt* per una comunicazione **UART**, tra cui anche le segnalazioni di stato e di errore:
- *IRQs generate in trasmissione*: Transmission Complete, Clear to Send or Transmit Data Register empty interrupt;
- *IRQs generate in ricezione*: Idle Line detection, Overrun error, Receive Data register not empty, Parity error, LIN break detection, Noise Flag (only in multi buffer communication) and
Framing Error (only in multi buffer communication).

Ovviamente la gestione di tutti questi eventi d'errore è mediata dalla configurazione di alcuni bit di controllo che devono essere controllati nel programma per gestire opportunamente sia la trasmissione che la ricezione con le *interrupts*. 

Tendenzialmente, la fase di ricezione è quella che più si presta ad essere utilizzata con il meccanismo delle *interrutps* e ne viene mostrato un esempio: si mostra un'applicazione che riceve un singolo carattere, interpretato come un numero, tramite comunicazione **UART**.

Si implementa la funzione:
```c
void read_UART_input() {
	if(UartReady == SET) {
		UartReady = RESET;
		HAL_UART_Receive_IT(&huart2, (uint8_t*)readBuf, 1);
		read_value = atoi(readBuf);
	}
}
```
che viene invocata nel ciclo di vita principale del programma, ma non è bloccante per il sistema, infatti il microcontrollore può continuare ad eseguire altre operazioni mentre attende di ricevere un carattere. 

Si noti che, la non ripetuta invocazione della funzione 
`HAL_UART_Receive_IT` è garantita dall'utilizzo adeguato della flag `UartReady`, definita come tipo `ITStatus`, si tratta di una `enum` definita per essere usata in queste situazioni con i valori **SET** (=1) e **RESET** (=0).


## Comunicazione USART con mbed
La piattaforma *mbed* esporta le funzionalità necessarie per instaurare comunicazioni seriali con periferiche **UART**, per uno scambio di dati tra microcontrollore ed altri dispositivi. Come si può immaginare, il procedimento per una comunicazione seriale di questo tipo è abbastanza semplificato e si basa sull'uso di un particolare oggetto.

### Serial

> The Serial interface provides **UART** functionality. The serial link has two unidirectional channels, one for sending and one for receiving. 

Sebbene internamente sia un oggetto molto complesso, il suo utilizzo è abbastanza semplificato, permettendo comunque la configurazione delle principali caratteristiche necessarie ad una comunicazione **UART**; in questo caso si tratta propriamente di comunicazione *asincrona*.

Per utilizzare questo oggetto, [Serial](https://os.mbed.com/docs/mbed-os/v5.15/apis/serial.html), i metodi principali di configurazione sono `baud()` e `format()`, usati come mostrato:
```cpp
Serial uart_com(PA_2, PA_3);  // PA_2: TX pin | PA_: RX_pin

#define BAUDRATE    115200
#define BITS        8
#define PARITY      SerialBase::None
#define STOP_BITS   1

void UART_Init(){
    uart_com.baud(BAUDRATE);
    uart_com.format(BITS, PARITY, STOP_BITS);
}
```

Si può quindi realizzare un'applicazione che legga il valore di un sensore analogico tramite **ADC** e invi tale valore al PC tramite comunicazione **UART**. Per l'invio si farà uso della funzione `printf()` invocata come metodo dell'oggetto `uart_com` definito. In questo modo sarà possibile mandare in maniera molto immediata una stringa di testo, che contiene ad esempio il valore che vogliamo inviare. 
```cpp
while(1) {
    if(adc_read_flag){
        // Read the analog input value (value from 0.0 to 1.0 = full ADC conversion range)
        raw_in = lmt84.read(); 
        // Converts value in the 0V-3.3V range
        lmt84_mv = raw_in * 3300; 
        // Convert mV to temperature
        temp = (1035 - lmt84_mv)/5.50f;
        // UART Send values
        uart_com.printf("\r%.3f°C\n",temp);
        // Reset flag
        adc_read_flag = false;
    }
}
```

:information_source: Grazie all'ausilio del modulo ST-Link integrato nella scheda di sviluppo Nucleo-F446RE, è possibile utilizzare la comunicazione seriale implicita fornita da questo modulo. Questo infatti è sempre in comunicazione con il microcontrollore tramite la periferica **USART2** ed è per questo che è possibile invocare la funzione `printf()` anche senza inizializzare alcun oggetto **Serial**. La piattaforma di sviluppo riconosce che una stringa si vorrebbe esportare sullo *Standard output stream* e viene effettuata una redirezione dell'output sulla periferica **USART** inizializzata per default.

Questa comunicazione seriale, che arriva al PC tramite la porta USB, è indispensabile per programmare il microcontrollore ed operare con il debugger, ecco perché, di default, viene sempre attivata su una scheda di sviluppo del genere (con un *baud rate* di 9600).

Comunque, per un utilizzo appropriato della funzione `printf()` è bene passare per l'inizializzazione di un oggetto **Serial**, anche per semplici scopi di debugging; si può far riferimento a quanto riportato dalla [documentazione](https://os.mbed.com/docs/mbed-os/v5.15/tutorials/debugging-using-printf-statements.html) di *mbed* per chiarire questo funzionamento.


***

:computer:
Per analizzare/valutare e "interagire" con la comunicazione **UART** è possibile utilizzare uno tra diversi software che si trovano facilmente in rete. Uno di questi è [*Real Term*](https://realterm.sourceforge.io), che offre la possibilità di aprire la comunicazione **UART** a con diversi *baud rate* e diverse configurazioni. Inoltre può essere usato anche come trasmettitore per inviare dati ad una periferica **UART** connessa al PC. Di seguito sono illustrate le due interfacce principali, evidenziando le principali sezioni di interazione.

<p align="center">
    <img src="img/realterm1.png">
</p>

<p align="center">
    <img src="img/realterm2.png">
</p>


Delle alternative potrebbero essere [Putty](https://www.putty.org) o [TeraTerm](https://ttssh2.osdn.jp/index.html.en).