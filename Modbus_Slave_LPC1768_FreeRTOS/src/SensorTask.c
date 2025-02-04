/*
 * SensorTask.c
 *
 *  Created on: 29/lug/2014
 *      Author: enrico
 */


#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#include "sensors.h"
#include "DHT11.h"


extern xSemaphoreHandle xSemaphore;

extern dht11 actual_DHT11;
extern Sensors sensors;


/**
 *
 * TASK DI CONTROLLO SENSORI
 *
 * mutua esclusione sulla cpu durante l'interrogazione del
 * sensore temperatura
 *
 */


void SensorsTask(void *pvParameters){



	//Delay(1000000);
	//while(1){
		// See if we can obtain the semaphore.  If the semaphore is not available
		// wait 50 ticks to see if it becomes free.
		//if( xSemaphoreTake( xSemaphore,  50 ) == pdTRUE )
			actual_DHT11 = test_temperature();

	//		xSemaphoreGive(xSemaphore);

		//controllo sensori
		sensors = check_all_sensors();


	//}

}
