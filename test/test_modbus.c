/**
 * @file test_leds.c
 * @author Gustavo Auyero
 * @brief Archivo de test de driver de leds
 * @version 0.1
 * @date 2024-07-26
 *
 * @copyright Copyright (c) 2024
 *
 */

/*
Comentario general:

La función a testear devuelve valores de bytes enteros según la función de lectura
requerida y es usada dentro del mensaje a ser devuleto por el protocolo Modbus. En este caso se testea
coils, discrete, holding e input. Las dos primeras son pedidos de bits que el programa tiene que 
trabajar a nivel de bytes, por eso la conversión. En el caso de las dos últimas se consulta la dirección
de un byte, pero la respuesta será de dos bytes que es donde se aloja el dato completo.

Requerimientos:

Al requerir la lectura de coils si la cantidad de coils es menos o igual a 8 devuelve 1 (byte) 
y si es mayor a 8 y menor o igual a 16 devuelve 2 (bytes)

Al requerir la lectura de discrete si la cantidad de coils es menos o igual a 8 devuelve 1 (byte) 

Al requerir la lectura de holding espero una respuesta del doble de la enviada (por ser 2 bytes en 
la respuesta modbus)

Al requerir la lectura de input espero una respuesta del doble de la enviada (por ser 2 bytes en 
la respuesta modbus)

En caso de requerir una función no listada el resultado debe ser 0


*/

#include "unity.h"
#include "modbus.h"


// Funcion que se ejecuta antes de cada pruebal
void setUp(void) { 
}

// función que se ejecuta luego de cada prueba
void tearDown(void) {
}

// al requerir hasta 8 coils debo tener un resultado de 1 (1 byte)
void test_coils_espero_resultado_igual_a_1_pidiendo_menos_que_8(void) {
    
    uint16_t fn = MB_FN_READ_COILS;
    uint16_t quantity = 7;
    uint16_t resultado_esperado = 0x1; // Acá coloco el valor esperado que debe devolver la función
    
    // Llama a la función a probar
    uint16_t resultado_obtenido = mb_pdu_calculate_N(fn, quantity);
    
    // Valida que el resultado sea el esperado
    TEST_ASSERT_EQUAL_HEX16(resultado_esperado, resultado_obtenido);

}

// al requerir mas de 8 hasta 16 coils debo tener un resultado de 2 (2 bytes)
void test_coils_espero_resultado_igual_a_2_pidiendo_9(void) {
    
    uint16_t fn = MB_FN_READ_COILS;
    uint16_t quantity = 9;
    uint16_t resultado_esperado = 0x2; // Acá coloco el valor esperado que debe devolver la función
    
    // Llama a la función a probar
    uint16_t resultado_obtenido = mb_pdu_calculate_N(fn, quantity);
    
    // Valida que el resultado sea el esperado
    TEST_ASSERT_EQUAL_HEX16(resultado_esperado, resultado_obtenido);

}

// al requerir mas de 8 hasta 16 coils debo tener un resultado de 2 (2 bytes)
void test_coils_espero_resultado_igual_a_2_pidiendo_16(void) {
    
    uint16_t fn = MB_FN_READ_COILS;
    uint16_t quantity = 16;
    uint16_t resultado_esperado = 0x2; // Acá coloco el valor esperado que debe devolver la función
    
    // Llama a la función a probar
    uint16_t resultado_obtenido = mb_pdu_calculate_N(fn, quantity);
    
    // Valida que el resultado sea el esperado
    TEST_ASSERT_EQUAL_HEX16(resultado_esperado, resultado_obtenido);

}

// al requerir hasta 8 discrete debo tener un resultado de 1 (1 byte)
void test_discrete_espero_resultado_igual_a_1_pidiendo_menos_que_8(void) {
    
    uint16_t fn = MB_FN_READ_DISCRETE;
    uint16_t quantity = 7;
    uint16_t resultado_esperado = 0x1; // Acá coloco el valor esperado que debe devolver la función
    
    // Llama a la función a probar
    uint16_t resultado_obtenido = mb_pdu_calculate_N(fn, quantity);
    
    // Valida que el resultado sea el esperado
    TEST_ASSERT_EQUAL_HEX16(resultado_esperado, resultado_obtenido);

}

// al requerir valores de holding se espera un resultado del doble del valor (por ser dos bytes)
void test_holding_espero_resultado_valor_x_2(void) {
    
    uint16_t fn = MB_FN_READ_HOLDING;
    uint16_t quantity = 10;
    uint16_t resultado_esperado = 20; // Acá coloco el valor esperado que debe devolver la función
    
    // Llama a la función a probar
    uint16_t resultado_obtenido = mb_pdu_calculate_N(fn, quantity);
    
    // Valida que el resultado sea el esperado
    TEST_ASSERT_EQUAL(resultado_esperado, resultado_obtenido);

}

// al requerir valores de inputs se espera un resultado del doble del valor (por ser dos bytes)
void test_input_espero_resultado_valor_x_2(void) {
    
    uint16_t fn = MB_FN_READ_INPUT;
    uint16_t quantity = 10;
    uint16_t resultado_esperado = 20; // Acá coloco el valor esperado que debe devolver la función
    
    // Llama a la función a probar
    uint16_t resultado_obtenido = mb_pdu_calculate_N(fn, quantity);
    
    // Valida que el resultado sea el esperado
    TEST_ASSERT_EQUAL(resultado_esperado, resultado_obtenido);

}

// al requerir valores de una función no listada (0) devuelve 0
void test_default_espero_resultado_0(void) {
    
    uint16_t fn = 0;
    uint16_t quantity = 5;
    uint16_t resultado_esperado = 0; // Acá coloco el valor esperado que debe devolver la función
    
    // Llama a la función a probar
    uint16_t resultado_obtenido = mb_pdu_calculate_N(fn, quantity);
    
    // Valida que el resultado sea el esperado
    TEST_ASSERT_EQUAL(resultado_esperado, resultado_obtenido);

}

