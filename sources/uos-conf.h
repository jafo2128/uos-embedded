/*
 * uos-conf.h
 *  Created on: 06.10.2015
 *      Author: a_lityagin <alexraynepe196@gmail.com>
 *                         <alexraynepe196@hotbox.ru>
 *                         <alexraynepe196@mail.ru>
 *                         <alexrainpe196@hotbox.ru>
 *  
 *  *\~russian UTF8
 *  это дефолтовый конфигурационный файл уОС. здесь сведены настройки модулей.
 *  для сборки своей оси, скопируйте этот файл в папку своего проекта и 
 *      переопределите настройки.
 */

#ifndef UOS_CONF_H_
#define UOS_CONF_H_

/**************************************************************************
 *                              uos.h
 ************************************************************************** */

/**\~russian
 * RECURSIVE_LOCKS задает стиль мутекса
 *  = 0 - ближайший unlock освобождает мутекс
 *  = 1 - мутекс отслеживает количество блокировок в текущей задаче и 
 *          на каждый вызов lock должен быть произведен unlock  
 * */
//#undef RECURSIVE_LOCKS
//#define RECURSIVE_LOCKS 0

/**\~russian
 * INLINE задает модификатор для инлайн функций уОС.
 * */
//#ifndef INLINE
//#define INLINE inline
//#endif


/**************************************************************************
 *                              timer.h
 ************************************************************************** */

/**\~russian
 * макро SW_TIMER отключает инициализацию обработчика прерывания системного таймера. в этом случае настраивает и запускает таймер
 * пользовательский код. обновление таймера производится вызовом timer_update
 * */
//#define SW_TIMER 1

/**\~russian
 * макро USER_TIMERS включает функционал множественных пользовательских таймеров на общем системном таймере.
 * см. функции user_timer_XXX
 * */
//#define USER_TIMERS 1

/**\~russian
 * макро USEC_TIMER дает возможность использовать прецизионный таймер сразрешением в [us]. см. timer_init_us
 * */
//#define USEC_TIMER 1

/**\~russian
 * макро TIMER_NO_DAYS опускает реализацию _timer_t.days - экономит время обработчика прерывания
 *  используется модулями: smnp
 * */
//#define TIMER_NO_DAYS 1 

/**\~russian
 * макро TIMER_NO_DECISEC опускает реализацию _timer_t.decisec - экономит время обработчика прерывания
 *  , это поле требуется для протокола TCP!!! 
 * */
//#define TIMER_NO_DECISEC 1 



/**\~russian
  * эти атрибуты используются для указания размещения кода линкеру для систем с отдельной памятью для прерываний
  *	и быстрого кода
*/
//#define CODE_FAST __attribute__((section(".text.hot")))
//#define CODE_ISR  __attribute__((section(".text.isr_used")))
//#define USED_ISR  __attribute__((section(".text.isr_used")))



#endif /* UOS_CONF_H_ */
