//***********************************************************************************
// Include files
//***********************************************************************************
#ifndef APP_HG
#define APP_HG

/* System include statements */


/* Silicon Labs include statements */
#include "em_cmu.h"
#include "em_assert.h"

/* The developer's include statements */
#include "cmu.h"
#include "gpio.h"
#include "letimer.h"
#include "brd_config.h"
#include "scheduler.h"
#include "LEDs_thunderboard.h"
#include "Si1133.h"


//***********************************************************************************
// defined files
//***********************************************************************************
#define   PWM_PER         3.0   // PWM period in seconds
#define   PWM_ACT_PER     0.002  // PWM active period in seconds

// Application scheduled events
#define LETIMER0_COMP0_CB     0x00000001 //0b0001
#define LETIMER0_COMP1_CB     0x00000002 //0b0010
#define LETIMER0_UF_CB        0x00000004 //0b0100
#define SI1133_LIGHT_READ_CB  0x00000008 //0b1000

#define EXPECTED_RESULTS       0x33

#define REGISTER_ADDRESS       0
#define BYTES                  1

//***********************************************************************************
// global variables
//***********************************************************************************


//***********************************************************************************
// function prototypes
//***********************************************************************************
void app_peripheral_setup(void);
void app_led_init(void);
void scheduled_letimer0_comp0_cb (void);
void scheduled_letimer0_comp1_cb (void);
void scheduled_letimer0_uf_cb (void);
void schedule_si1133_light_read_cb(void);

#endif
