/* ===================================================================
**  Projeto Final: Caixa D'Água Inteligente
**  
**  Taffarel Cunha Ewald 147957
**  Daniel Rodrigues Silveira Freitas 145782
**        
**  Programa implementa um reservatorio de agua inteligente, que 
**  utiliza sensores para medicao do nivel de agua e utiliza LEDs
**  e um buzzer para emitir informacoes sobre as medicoes. O motor
**  é utilizado como representacao de uma bomba d'água, que eh 
**  desligado quando o nivel de agua atinge seu nivel maximo permitido.
**  Alem disso, sua velocidade eh gradativamente reduzida enquanto o
**  reservatorio eh enchido.
** ===================================================================*/

/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/     
    
/* MODULE main */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "LEVEL1.h"
#include "BitIoLdd1.h"
#include "LEVEL2.h"
#include "BitIoLdd2.h"
#include "LEVEL3.h"
#include "BitIoLdd3.h"
#include "TI1.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
#include "LED_LEVEL3.h"
#include "BitIoLdd4.h"
#include "LED_LEVEL2.h"
#include "BitIoLdd5.h"
#include "LED_LEVEL1.h"
#include "BitIoLdd6.h"
#include "PWM1.h"
#include "PwmLdd1.h"
#include "TU2.h"
#include "PWM2.h"
#include "PwmLdd2.h"
#include "TU3.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

extern int water_level;		//variavel que armazena nivel de agua

/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  while(1){
	  
	  /*PWM1 se refere ao sinal no buzzer
	  PWM2 se refere ao sinal no motor*/
	  
	  /*condicao de reservatorio cheio (nivel 3)*/
	  if (water_level == 3) {
		 /*Buzzer eh ligado e motor eh desligado*/
		 PWM1_Enable();
		 PWM2_Disable();
		 PWM1_SetRatio8(0);
		 /*acende os 3 leds, indicando nivel 3*/
		 LED_LEVEL3_SetVal();
		 LED_LEVEL2_SetVal();
		 LED_LEVEL1_SetVal();
	  }
	  if (water_level == 2) {
		 /*Buzzer eh desligado e motor eh ligado*/
		 PWM1_Disable();
		 PWM2_Enable();
		 PWM2_SetRatio8(220);
		 /*acende 2 leds, indicando nivel 2*/
		 LED_LEVEL3_ClrVal();
		 LED_LEVEL2_SetVal();
		 LED_LEVEL1_SetVal();
	  }
	  if (water_level == 1) {
		 /*Buzzer eh desligado e motor eh ligado*/
		 PWM1_Disable();
		 PWM2_Enable();
		 PWM2_SetRatio8(135);
		 /*acende 1 led, indicando nivel 1*/
		 LED_LEVEL3_ClrVal();
		 LED_LEVEL2_ClrVal();
		 LED_LEVEL1_SetVal();
	  }
	  /*condicao de reservatorio vazio (nivel 0)*/
	  if (water_level == 0) {
		 /*Buzzer eh desligado e motor eh ligado*/
		 PWM1_Disable();
		 PWM2_Enable();
		 PWM2_SetRatio8(50);
		 /*todos os leds apagados, indicando nivel 0*/
		 LED_LEVEL3_ClrVal();
		 LED_LEVEL2_ClrVal();
		 LED_LEVEL1_ClrVal();
	  }
	  
  }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
