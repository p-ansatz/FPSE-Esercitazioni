# FPSE-Esercitazioni
Esercitazioni del corso di **F**ondamenti di **P**rogrammazione dei **S**istemi **E**mbedded. 


## Riferimenti ed utilità

### Software e Ambienti di Sviluppo
* [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html#tools-software)

### Hardware -consigliato-
* [STM32 Nucleo-F446RE](https://www.st.com/en/evaluation-tools/nucleo-f446re.html)
* [Kit componenti base](https://www.amazon.it/dp/B01MQIO78W)
* [Kit sensori](https://www.amazon.it/dp/B01N79PG4G)
* [Elenco dettagliato del materiale utilizzato](https://github.com/p-ansatz/FPSE-Esercitazioni#elenco-dettagliato-del-materiale-utilizzato)

### Documentazione
* [Nucleo 64 - User Manual](https://www.st.com/resource/en/user_manual/dm00105823-stm32-nucleo-64-boards-mb1136-stmicroelectronics.pdf)
* [STM32F446xx - Reference Manual](https://www.st.com/resource/en/reference_manual/dm00135183-stm32f446xx-advanced-arm-based-32-bit-mcus-stmicroelectronics.pdf)
* [STM32F446xC/E - Datasheet](https://www.st.com/resource/en/datasheet/stm32f446mc.pdf)
* [STM32 Cortex M4 Programming Manual](https://www.st.com/resource/en/programming_manual/dm00046982-stm32-cortexm4-mcus-and-mpus-programming-manual-stmicroelectronics.pdf)
* [STM32 Description of STM32F4 HAL and LL drivers](https://www.st.com/resource/en/user_manual/dm00105879-description-of-stm32f4-hal-and-ll-drivers-stmicroelectronics.pdf)
* [Developing applications on STM32Cube with RTOS - User Manual](https://www.st.com/resource/en/user_manual/dm00105262-developing-applications-on-stm32cube-with-rtos-stmicroelectronics.pdf)
* [STM32CubeMX for STM32 user manual](https://www.st.com/content/ccc/resource/technical/document/user_manual/10/c5/1a/43/3a/70/43/7d/DM00104712.pdf/files/DM00104712.pdf/jcr:content/translations/en.DM00104712.pdf)


### Libri
* [**Modern C** | Jens Gustedt](https://www.manning.com/books/modern-c)
* [**Mastering the STM32 Microcontroller** | Carmine Noviello](https://leanpub.com/mastering-stm32)
* [**The Definitive Guide to ARM Cortex-M3 and Cortex-M4 Processors** | Joseph Yiu](https://www.amazon.it/Definitive-Guide-Cortex®-M3-Cortex®-M4-Processors/dp/0124080820)
* [**STM32 Arm Programming for Embedded Systems** |  M.A. Mazidi, S. Chen, E. Ghaemi](https://www.amazon.it/STM32-Arm-Programming-Embedded-Systems/dp/0997925949/)

### Header pinout
* [CN5 Header Pinout](https://github.com/p-ansatz/FPSE-Esercitazioni/blob/2020_2021/HeadersPinout.md#cn5-header-pinout)
* [CN6 Header Pinout](https://github.com/p-ansatz/FPSE-Esercitazioni/blob/2020_2021/HeadersPinout.md#cn6-header-pinout)
* [CN7 Header Pinout](https://github.com/p-ansatz/FPSE-Esercitazioni/blob/2020_2021/HeadersPinout.md#cn7-header-pinout)
* [CN10 Header Pinout](https://github.com/p-ansatz/FPSE-Esercitazioni/blob/2020_2021/HeadersPinout.md#cn10-header-pinout)


## Indice degli argomenti trattati
* [Basi di programmazione in C](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/01%20-%20Programmazione%20C)
* [Programmazione per microcontrollori STM32](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/02%20-%20STM32%20Programmazione%20Base)
    * [Architettura a Registri](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/02%20-%20STM32%20Programmazione%20Base#architettura-arm-registri)
    * [Operazioni bitwise](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/03%20-%20Digital%20IO%20e%20GPIO#dettagli-per-lo-sviluppo)
* [GPIO](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/03%20-%20Digital%20IO%20e%20GPIO#gpio-e-registri-per-la-loro-gestione)
    * [Programmazione base con GPIO in STM32Cube](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/03%20-%20Digital%20IO%20e%20GPIO#implementazione)
* [Interrupt](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/04%20-%20GPIO%20e%20Interrupt#requisiti-teorici)
    * [Utilizzo delle interrupts in STM32Cube](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/04%20-%20GPIO%20e%20Interrupt#implementazione-e-altri-dettagli)
* [ADC](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/05%20-%20IO%20Analogico#requisiti-teorici)
    * [Utilizzo dell'ADC in STM32Cube](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/05%20-%20IO%20Analogico#io-analogico-con-stm32cube)
        * [Polling Mode](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/05%20-%20IO%20Analogico#polling-mode)
        * [Interrupt Mode](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/05%20-%20IO%20Analogico#interrupt-mode)
* [Timers](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/06%20-%20Timers%20e%20PWM#timers)
    * [Basic Timers in STM32Cube](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/06%20-%20Timers%20e%20PWM#alarm_clock-basic-timers)
    * [General Purpose Timers in STM32Cube](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/06%20-%20Timers%20e%20PWM#watch-general-timers)
* [PWM](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/06%20-%20Timers%20e%20PWM#pulse-width-modulation-pwm)
    * [Generazione PWM in STM32Cube](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/06%20-%20Timers%20e%20PWM#generazione-pwm-in-stm32cube)
* [Comunicazione Seriale](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/07%20-%20Comunicazione%20Seriale#requisiti-teorici)
    * [UART/USART](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/07%20-%20Comunicazione%20Seriale#uart-e-usart)
        * [UART in STM32Cube](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/07%20-%20Comunicazione%20Seriale#comunicazione-usart-con-stm32cube)
    * [I<sup>2</sup>C](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/07%20-%20Comunicazione%20Seriale#i2c)
        * [I<sup>2</sup>C in STM32Cube](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/07%20-%20Comunicazione%20Seriale#comunicazione-i2c-in-stm32cube)
    * [SPI](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/07%20-%20Comunicazione%20Seriale#spi)
        * [SPI in STM32Cube](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/07%20-%20Comunicazione%20Seriale#comunicazione-spi-in-stm32cube)
* [Sistemi Embedded e RTOS](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/08%20-%20RTOS#sistemi-embedded-e-rtos)
    * [CMSIS-RTOS](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/08%20-%20RTOS#cmsis-rtos)
    * [RTOS in STM32Cube // FreeRTOS](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2020_2021/08%20-%20RTOS#rtos-in-stm32cube--freertos)

Di seguito una serie di riferimenti utili alla conoscenza base della piattaforma di sviluppo [mbed](https://os.mbed.com). I riferimenti sono relativi alle esercitazioni dell'anno accademico 2019-2020.
* [Mbed online compiler](https://ide.mbed.com/compiler)
* [Mbed Studio](https://os.mbed.com/studio)
* [Piattaforma Mbed](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2019_2020/Esercitazione%205%20-%20IO%20Digitale%20con%20mbed#overview)
    * [Programmazione GPIO con mbed](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2019_2020/Esercitazione%205%20-%20IO%20Digitale%20con%20mbed#implementazione-ed-altri-dettagli)
    * [Utilizzo delle interrupts con mbed](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2019_2020/Esercitazione%205%20-%20IO%20Digitale%20con%20mbed#interruptin)
    * [Utilizzo di ADC e DAC con mbed](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2019_2020/Esercitazione%206%20-%20IO%20Analogico#io-analogico-con-mbed)
    * [Utilizzo dei Timers con mbed](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2019_2020/Esercitazione%207%20-%20Timers%20e%20PWM#utilizzo-dei-timers-in-mbed)
    * [Generazione PWM con mbed](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2019_2020/Esercitazione%207%20-%20Timers%20e%20PWM#generazione-pwm-con-mbed)
    * [Comunicazione UART con mbed](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2019_2020/Esercitazione%208%20-%20Comunicazione%20Seriale#comunicazione-uart-con-mbed)
    * [Comunicazione I<sup>2</sup>C con mbed](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2019_2020/Esercitazione%208%20-%20Comunicazione%20Seriale#comunicazione-i2c-con-mbed) 
    * [Comunicazione  SPI con mbed](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2019_2020/Esercitazione%208%20-%20Comunicazione%20Seriale#comunicazione-spi-con-mbed)
     * [RTOS con mbed // RTX](https://github.com/p-ansatz/FPSE-Esercitazioni/tree/2019_2020/Esercitazione%209%20-%20RTOS#rtos-con-mbed--rtx)


***

## Elenco dettagliato del materiale utilizzato

- STM32 Nucleo-F446RE
- Cavo Mini-USB<->USB
- Breadboard
- Cavi
- Resistori
- Condensatori
- Pulsanti
- LED
- Sensore di Movimento (Tipo: HC-SR501)
- Potenziometro Rotativo
- Sensore di temperatura analogico (Tipo: LMT84, LM35, NTC Termistore 10K)
- Buzzer
- Shift Register (Tipo: 74HC595N)
- IMU I2C (Tipo: MPU-6050 in modulo GY-521)

##### Materiale di utilizzo esclusivo nel secondo modulo del corso
- Motore DC con driver di controllo
- Servomotore
- Encoder rotativo digitale
- Sensore ad Ultrasuoni (Tipo: HC-SR04)
-------------------
