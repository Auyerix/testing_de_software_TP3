/**
 * @file modbus.h
 * @author Gustavo Auyero
 * @brief Declaración de funciones para calculo de PDU Modbus
 * @version 0.1
 * @date 2024-08-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef MODBUS_H
#define MODBUS_H

#include <stdint.h>
#include <stdbool.h>

// ---------COMMANDS------------------------------//
#define MB_FN_READ_COILS    (0x01)
#define MB_FN_READ_DISCRETE (0x02)
#define MB_FN_READ_HOLDING  (0x03)
#define MB_FN_READ_INPUT    (0x04)

/**
 * @brief calcula la cantidad de bytes necesarios según la función Modbus requerida
 *
 * @param fn Función Modbus requerida
 * @param quantity Cantidad de datos a leer
 * @return uint16_t Calculo para ser usado en la PDU
 */

uint16_t mb_pdu_calculate_N(uint16_t fn, uint16_t quantity);

#endif
