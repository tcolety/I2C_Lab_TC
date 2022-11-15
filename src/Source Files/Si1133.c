/**
 * @file   Si1133.c
 * @author Taylor Colety
 * @date   10/05/21
 * @brief  Working with the Si1133 Sensor.
 *
 */

//***********************************************************************************
// Include files
//***********************************************************************************
#include "Si1133.h"

//***********************************************************************************
// private define statements
//***********************************************************************************

//***********************************************************************************
// private variables
//***********************************************************************************
uint32_t si1133_read_result;

//***********************************************************************************
// private function prototypes
//***********************************************************************************

//***********************************************************************************
// private functions
//***********************************************************************************

//***********************************************************************************
// global functions
//***********************************************************************************
/***************************************************************************//**
 * @brief
 *  Initializing our Si1133 data
 *
 * @details
 *  Passing in the I2C struct, we can store each required parameter to fill our Si1133
 *  sensor with required data defined in the HAL documentation and Si1133 datasheet.
 *  Then, i2c_open is called to start the i2c peripheral
 *
 * @note
 *  Called in app.c when opening all other peripherals and drivers.
 *
 ******************************************************************************/
void Si1133_i2c_open(void){
   I2C_OPEN_STRUCT i2c_setup_struct;

   timer_delay(HARDWARE_DELAY);

   i2c_setup_struct.enable = true;
   i2c_setup_struct.master = true;
   i2c_setup_struct.refFreq = 0;
   i2c_setup_struct.freq = I2C_FREQ_FAST_MAX;
   i2c_setup_struct.clhr = i2cClockHLRAsymetric;
   i2c_setup_struct.out_pin_route_scl = SCL_ROUTE;
   i2c_setup_struct.out_pin_route_sda = SDA_ROUTE;
   i2c_setup_struct.out_pin_scl_en = true;   // enable out 0 route
   i2c_setup_struct.out_pin_sda_en = true;   // enable out 1 route

   i2c_open(I2C1, &i2c_setup_struct);
}
 /***************************************************************************//**
  * @brief
  *  Calls the i2c_start function with correct values to start process of reading
  *  with I2C
  *
  * @details
  *  This function begins the i2c read process or reading the Si1133 part ID,
  *  however it can also be used to read from other registers
  *
  * @note
  *  Called with the comp1 callback function is triggered
  *
  * @param [in] callback
  *  Parameters for each input to I2C_TypeDef Struct to pass into other function.
  *
  *  @param [in] register_address
  *   Parameter defines the register address in si1133 that i2c is reading from
  *
  *  @param [in] bytes
  *   Specifies number of bytes I2C is reading
  ******************************************************************************/
void Si1133_read(uint32_t callback, uint32_t register_address, uint32_t bytes){ //bytes ==1
   i2c_start(I2C1, true, bytes, DEVICE_ADDRESS, register_address, callback, &si1133_read_result);
 }


/******************************************************************************
 * @brief
 *      Function to get the part ID
 * @details
 *      Si1133_get_PartID reads and returns the private variable Si1133_read_result
 *      which stores the Si1133 Part ID which has been read with I2C
 *
 ******************************************************************************/

 uint32_t Si1133_get_partID(void) {
   uint32_t Si1133_partID;
   Si1133_partID = si1133_read_result;
   return Si1133_partID;
 }
