/*
 * ====================================================================================================================================
 *  Project		: Task Scheduler
 * 	File Name	: main.h
 *	Author		: Omar Ahmed Anwar
 *  ===================================================================================================================================
 */

#ifndef MAIN_H_
#define MAIN_H_


#include "Std_Types.h"
#include "Gpio.h"
#include "Rcc.h"
#include "Delay.h"
#include "Led.h"
#include "lcd.h"

#define MAX_TASKS			5

#define SIZE_TASK_STACK		1024U
#define SIZE_SCHED_STACK	1024U

#define SRAM_START			0x20000000U
#define SRAM_SIZE			( (96) * (1024) )
#define SRAM_END			( (SRAM_START) + (SRAM_SIZE) )

#define T1_STACK_START		SRAM_END
#define T2_STACK_START		( (SRAM_END) - (1 * SIZE_TASK_STACK) )
#define T3_STACK_START		( (SRAM_END) - (2 * SIZE_TASK_STACK) )
#define T4_STACK_START		( (SRAM_END) - (3 * SIZE_TASK_STACK) )
#define IDLE_STACK_START	( (SRAM_END) - (4 * SIZE_TASK_STACK) )
#define SCHED_STACK_START	( (SRAM_END) - (5 * SIZE_TASK_STACK) )

#define TICK_HZ 				1000U

#define HSI_CLOCK         		16000000U
#define SYSTICK_TIM_CLK   		HSI_CLOCK

#define SYSTICK_BASE_ADDRESS	0xE000E010U
#define STK_LOAD				(SYSTICK_BASE_ADDRESS + (0X04))

#define DUMMY_XPSR				(1<<24)

#define SCB_BASE_ADDRESS		 0xE000ED00U
#define SCB_SHCSR_OFFSET		 0x24
#define SCB_SHCSR				 ( (SCB_BASE_ADDRESS) + (SCB_SHCSR_OFFSET) )
#define SCB_CCR_OFFSET			 0X14
#define SCB_CCR			 		 ( (SCB_BASE_ADDRESS) + (SCB_CCR_OFFSET) )
#define SCB_ICSR_OFFSET			 0x04
#define SCB_ICSR				 ( (SCB_BASE_ADDRESS) + (SCB_ICSR_OFFSET) )

#define MEMORY_FAULT_ENABLE		 (1<<16)
#define BUS_FAULT_ENABLE		 (1<<17)
#define USAGE_FAULT_ENABLE		 (1<<18)
#define DIVISION_BY_ZERO_TRAP	 (1<<4)
#define	PENDSV_SET_PENDING_BIT	 (1<<28)

#define DELAY_COUNT_1S  		(1000U)
#define DELAY_COUNT_500MS  		(500U)
#define DELAY_COUNT_250MS 		(250U)
#define DELAY_COUNT_125MS 		(125U)

#define TASK_READY_STATE		0X00
#define TASK_BLOCK_STATE		0XFF

#define INTERRUPT_DISABLE()  do{__asm volatile ("MOV R0,#0x1"); __asm volatile("MSR PRIMASK,R0"); } while(0)

#define INTERRUPT_ENABLE()  do{__asm volatile ("MOV R0,#0x0"); __asm volatile("MSR PRIMASK,R0"); } while(0)

typedef struct{
	uint32 psp_value;
	uint32 block_count;
	uint8 current_state;
	void (*task_handler)(void);
}TCB;

void idle_task(void);
void task1_handler(void);
void task2_handler(void);
void task3_handler(void);
void task4_handler(void);

void init_systick_timer(uint32 tick_hz);

__attribute__((naked)) void init_scheduler_stack(uint32 sched_top_of_stack);

void init_tasks_stack(void);

void enable_processor_faults(void);

uint32 get_psp_address(void);
__attribute__((naked)) void switch_sp_to_psp(void);

void save_psp_value(uint32 current_psp_value);
void update_next_task(void);

void task_delay(uint32 tick_count);

void update_global_tick(void);
void unblock_tasks(void);
void schedual(void);



#endif /* MAIN_H_ */
