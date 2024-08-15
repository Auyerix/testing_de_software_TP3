/**
 * @file modbus.c
 * @author Gustavo Auyero
 * @brief Calculo de PDU Modbus
 * @version 0.1
 * @date 2024-07-26
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "modbus.h"

/*Funciones públicas*/

uint16_t mb_pdu_calculate_N(uint16_t fn, uint16_t quantity) {
	switch (fn) {
	case MB_FN_READ_COILS:
	case MB_FN_READ_DISCRETE:
		if (quantity % 8 != 0)
			return ((quantity / 8) + 1);
		else
			return (quantity / 8);
		break;
	case MB_FN_READ_HOLDING:
	case MB_FN_READ_INPUT:
		return quantity * 2;
		break;
	default:
		return 0;
	}
}