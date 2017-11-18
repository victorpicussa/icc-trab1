/**
 * @file       double_operations.h
 * @author     Pedro Luiz de Souza Moreira  GRR20163064
 * @author     Victor Picussa   GRR20163068
 * @date       24 Sep 2017
 * @brief      Esse arquivo contém a definição de algumas constantes e macros
 *             para trabalhar com numeros em ponto flutuante de precisão dupla
 */

#include "datatypes.h"
#include "float.h"
#ifndef __DOUBLE_OPERATIONS__
#define __DOUBLE_OPERATIONS__


/** @brief     Zero em ponto fluntuante */
#define TRUE_ZERO 0.0

/** @brief     Um em ponto fluntuante */
#define TRUE_ONE 1.0


/**
 * @brief      Retorna valor absoluto de um valor
 *
 * @param      x     o valor
 */
#define ABS(x) (((x)<TRUE_ZERO) ? -(x) : (x))

/**
 * @brief      Determines if zero.
 *
 * @param      NUM   The num
 *
 * @return     Verdadeiro se zero, ou Falso se não.
 */
#define IS_ZERO(NUM) ABS(NUM) < DBL_EPSILON

/**
 * @brief      Efetua uma soma de Kahan
 *
 * @param      K      Estrutura auxiliar
 * @param      input  Valor a ser somados
 */
#define KAHAN_SUM(K, input){ \
    double _y,_t; \
    _y = (input) - K->c; \
    _t = K->sum + _y; \
    K->c = (_t - K->sum) - _y; \
    K->sum = _t; \
}

#endif