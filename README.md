# FPSE-Esercitazioni
Esercitazioni del corso di **F**ondamenti di **P**rogrammazione dei **S**istemi **E**mbedded. 

## Riferimenti ed utilità

### Software e Ambienti di Sviluppo
* [STM32Cube](https://www.st.com/en/ecosystems/stm32cube.html)
* [Mbed online compiler](https://ide.mbed.com/compiler)
* [Mbed Studio](https://os.mbed.com/studio)

### Hardware -consigliato-
* [STM32 Nucleo-F446RE](https://www.st.com/en/evaluation-tools/nucleo-f446re.html)
* [Kit componenti base](https://www.amazon.it/dp/B01MQIO78W)
* [Kit sensori](https://www.amazon.it/dp/B01N79PG4G)

### Documentazione
* [Nucleo 64 - User Manual](https://www.st.com/resource/en/user_manual/dm00105823-stm32-nucleo-64-boards-mb1136-stmicroelectronics.pdf)
* [STM32F446xx - Reference Manual](https://www.st.com/resource/en/reference_manual/dm00135183-stm32f446xx-advanced-arm-based-32-bit-mcus-stmicroelectronics.pdf)
* [STM32F446xC/E - Datasheet](https://www.st.com/resource/en/datasheet/stm32f446mc.pdf)
* [STM32 Cortex M4 Programming Manual](https://www.st.com/resource/en/programming_manual/dm00046982-stm32-cortexm4-mcus-and-mpus-programming-manual-stmicroelectronics.pdf)
* [STM32 Description of STM32F4 HAL and LL drivers](https://www.st.com/resource/en/user_manual/dm00105879-description-of-stm32f4-hal-and-ll-drivers-stmicroelectronics.pdf)

### Libri
* [**Modern C** | Jens Gustedt](https://www.manning.com/books/modern-c)
* [**Mastering the STM32 Microcontroller** | Carmine Noviello](https://leanpub.com/mastering-stm32)
* [**The Definitive Guide to ARM Cortex-M3 and Cortex-M4 Processors** | Joseph Yiu](https://www.amazon.it/Definitive-Guide-Cortex®-M3-Cortex®-M4-Processors/dp/0124080820)
* [**Fast and effective embedded systems design - Applying the ARM mbed** | Rob Toulson, Tim Wilmshurst](https://www.amazon.it/Fast-Effective-Embedded-Systems-Design/dp/0081008805)

### Header pinout
* [CN5 Header Pinout](HeadersPinout.md#CN5-Header-Pinout)
* [CN6 Header Pinout](HeadersPinout.md#CN6-Header-Pinout)
* [CN7 Header Pinout](HeadersPinout.md#CN7-Header-Pinout)
* [CN10 Header Pinout](HeadersPinout.md#CN10-Header-Pinout)


## Indice degli argomenti trattati
* [Basi di programmazione in C](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%201%20-%20Programmazione%20C)
* [Programmazione per microcontrollori STM32](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%202%20-%20STM32%20Programmazione%20Base)
    * [Architettura a Registri](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%202%20-%20STM32%20Programmazione%20Base#architettura-arm-registri)
    * [Operazioni bitwise](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%203%20-%20Digital%20IO%20e%20GPIO#dettagli-per-lo-sviluppo)
* [GPIO](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%203%20-%20Digital%20IO%20e%20GPIO#gpio-e-registri-per-la-loro-gestione)
    * [Programmazione base con GPIO in STM32Cube](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%203%20-%20Digital%20IO%20e%20GPIO#implementazione)
    * [Programmazione GPIO con mbed](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%205%20-%20IO%20Digitale%20con%20mbed#implementazione-ed-altri-dettagli)
* [Interrupt](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%204%20-%20GPIO%20e%20Interrupt#requisiti-teorici)
    * [Utilizzo delle interrupts in STM32Cube](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%204%20-%20GPIO%20e%20Interrupt#implementazione-e-altri-dettagli)
    * [Utilizzo delle interrupts con mbed](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%205%20-%20IO%20Digitale%20con%20mbed#interruptin)
* [ADC](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%206%20-%20IO%20Analogico#requisiti-teorici)
    * [Utilizzo dell'ADC in STM32Cube](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%206%20-%20IO%20Analogico#io-analogico-con-stm32cube)
        * [Polling Mode](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%206%20-%20IO%20Analogico#polling-mode)
        * [Interrupt Mode](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%206%20-%20IO%20Analogico#interrupt-mode)
    * [Utilizzo di ADC e DAC con mbed](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%206%20-%20IO%20Analogico#io-analogico-con-mbed)
* [Timers](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%207%20-%20Timers%20e%20PWM#timers)
    * [Basic Timers in STM32Cube](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%207%20-%20Timers%20e%20PWM#alarm_clock-basic-timers)
    * [General Purpose Timers in STM32Cube](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%207%20-%20Timers%20e%20PWM#watch-general-timers)
    * [Utilizzo dei Timers con mbed](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%207%20-%20Timers%20e%20PWM#utilizzo-dei-timers-in-mbed)
* [PWM](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%207%20-%20Timers%20e%20PWM#pulse-width-modulation-pwm)
    * [Generazione PWM in STM32Cube](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%207%20-%20Timers%20e%20PWM#generazione-pwm-in-stm32cube)
    * [Generazione PWM con mbed](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%207%20-%20Timers%20e%20PWM#generazione-pwm-con-mbed)
* [Comunicazione Seriale](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%208%20-%20Comunicazione%20Seriale#requisiti-teorici)
    * [UART/USART](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%208%20-%20Comunicazione%20Seriale#uart-e-usart)
        * [UART in STM32Cube](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%208%20-%20Comunicazione%20Seriale#comunicazione-usart-con-stm32cube)
        * [UART con mbed](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%208%20-%20Comunicazione%20Seriale#comunicazione-usart-con-mbed)

    * [I<sup>2</sup>C](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%208%20-%20Comunicazione%20Seriale#i2c)
        * [I<sup>2</sup>C in STM32Cube](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%208%20-%20Comunicazione%20Seriale#comunicazione-i2c-in-stm32cube)
        * [I<sup>2</sup>C con mbed](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%208%20-%20Comunicazione%20Seriale#comunicazione-i2c-con-mbed) 
     * [SPI](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%208%20-%20Comunicazione%20Seriale#spi)
        * [SPI in STM32Cube](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%208%20-%20Comunicazione%20Seriale#comunicazione-spi-in-stm32cube)
        * [SPI con mbed](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/master/Esercitazione%208%20-%20Comunicazione%20Seriale#comunicazione-spi-con-mbed)



