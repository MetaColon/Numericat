#include <stdio.h>
#include <math.h>
#include <check.h>
#include <stdlib.h>
#include "../Parser/Parser.h"
#include "TestHelper.h"
#include "TestHelper.h"

void assertFunctionsEq(char *func, Function expected, Function actual)
{
    printf(">>> %s\n", func);
    printf("=== ");
    printFunction(expected);
    printf("<<< ");
    printFunction(actual);

    for (int i = 0;; i++)
    {
        ck_assert(actual[i].atomType == expected[i].atomType);
        switch(actual[i].atomType)
        {
            case value:
                ck_assert(actual[i].atom.value.real == expected[i].atom.value.real);
                ck_assert(actual[i].atom.value.imaginary == expected[i].atom.value.imaginary);
                break;
            case operator:
                ck_assert(actual[i].atom.op == expected[i].atom.op);
                break;
            case variable:
                ck_assert(actual[i].atom.variable == expected[i].atom.variable);
                break;
            case paranthesis:
                ck_assert(actual[i].atom.paranthesis == expected[i].atom.paranthesis);
                break;
            case function:
                ck_assert(actual[i].atom.function == expected[i].atom.function);
                break;
            case end:
                return;
            default:
                fprintf(stderr, "Unknown atom type: %d\n", actual[i].atomType);
                continue;
        }
    }
}

void assertComplexEq(Complex expected, Complex actual)
{
    printf(">>> ");
    printComplex(expected);
    printf("\n<<< ");
    printComplex(actual);
    printf("\n");
    double diff = (expected.real - actual.real) * (expected.real - actual.real) +
                  (expected.imaginary - actual.imaginary) * (expected.imaginary - actual.imaginary);
    if (diff > 0.001)
        fprintf(stderr, "UNEQUAL\n");
    ck_assert(diff < 0.001);
}

void assertFloatEq(double expected, double actual)
{
    printf(">>> %lf\n<<< %lf\n", expected, actual);
    double diff = expected - actual;
    if (diff < 0)
        diff = -diff;
    ck_assert(!isnan(actual));
    ck_assert(!isinf(actual));
    ck_assert(diff < 0.001);
}

void assertMatrixEq(Matrix expected, Matrix actual)
{
    ck_assert(expected.columnCount == actual.columnCount);
    ck_assert(expected.rowCount == actual.rowCount);

    for (int r = 0; r < expected.rowCount; r++)
        for (int c = 0; c < expected.columnCount; c++)
            assertComplexEq(expected.matrix[r][c], actual.matrix[r][c]);
}
