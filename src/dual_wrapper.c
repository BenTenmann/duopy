//
// Created by Benjamin Tenmann on 15/02/2021.
//

#include <Python.h>
#include "duals.h"
#include "du_functions.h"

static PyObject * addDWrap(PyObject * self, PyObject * args){
    double real_a, dual_a, real_b, dual_b;
    if (!PyArg_ParseTuple(args, "dddd", &real_a, &dual_a, &real_b, &dual_b)){
        return NULL;
    }
    struct Dual A, B, C;
    A.r = real_a; A.d = dual_a;
    B.r = real_b; B.d = dual_b;
    C = addDual(&A, &B);
    return Py_BuildValue("dd", C.r, C.d);
}

static PyObject * addVWrap(PyObject * self, PyObject * args){
    double real, dual, value;
    if (!PyArg_ParseTuple(args, "ddd", &real, &dual, &value)){
        return NULL;
    }
    struct Dual A, B;
    A.r = real; A.d = dual;
    B = addVal(&A, &value);
    return Py_BuildValue("dd", B.r, B.d);
}

static PyObject * subDWrap(PyObject * self, PyObject * args){
    double real_a, dual_a, real_b, dual_b;
    if (!PyArg_ParseTuple(args, "dddd", &real_a, &dual_a, &real_b, &dual_b)){
        return NULL;
    }
    struct Dual A, B, C;
    A.r = real_a; A.d = dual_a;
    B.r = real_b; B.d = dual_b;
    C = subDual(&A, &B);
    return Py_BuildValue("dd", C.r, C.d);
}

static PyObject * subVWrap(PyObject * self, PyObject * args){
    double real, dual, value;
    if (!PyArg_ParseTuple(args, "ddd", &real, &dual, &value)){
        return NULL;
    }
    struct Dual A, B;
    A.r = real; A.d = dual;
    B = subVal(&A, &value);
    return Py_BuildValue("dd", B.r, B.d);
}

static PyObject * isubVWrap(PyObject * self, PyObject * args){
    double real, dual, value;
    if (!PyArg_ParseTuple(args, "ddd", &value, &real, &dual)){
        return NULL;
    }
    struct Dual A, B;
    A.r = real; A.d = dual;
    B = isubVal(&value, &A);
    return Py_BuildValue("dd", B.r, B.d);
}

static PyObject * mulDWrap(PyObject * self, PyObject * args){
    double real_a, dual_a, real_b, dual_b;
    if (!PyArg_ParseTuple(args, "dddd", &real_a, &dual_a, &real_b, &dual_b)){
        return NULL;
    }
    struct Dual A, B, C;
    A.r = real_a; A.d = dual_a;
    B.r = real_b; B.d = dual_b;
    C = mulDual(&A, &B);
    return Py_BuildValue("dd", C.r, C.d);
}

static PyObject * mulVWrap(PyObject * self, PyObject * args){
    double real, dual, value;
    if (!PyArg_ParseTuple(args, "ddd", &real, &dual, &value)){
        return NULL;
    }
    struct Dual A, B;
    A.r = real; A.d = dual;
    B = mulVal(&A, &value);
    return Py_BuildValue("dd", B.r, B.d);
}

static PyObject * divDWrap(PyObject * self, PyObject * args){
    double real_a, dual_a, real_b, dual_b;
    if (!PyArg_ParseTuple(args, "dddd", &real_a, &dual_a, &real_b, &dual_b)){
        return NULL;
    }
    struct Dual A, B, C;
    A.r = real_a; A.d = dual_a;
    B.r = real_b; B.d = dual_b;
    C = divDual(&A, &B);
    return Py_BuildValue("dd", C.r, C.d);
}

static PyObject * divVWrap(PyObject * self, PyObject * args){
    double real, dual, value;
    if (!PyArg_ParseTuple(args, "ddd", &real, &dual, &value)){
        return NULL;
    }
    struct Dual A, B;
    A.r = real; A.d = dual;
    B = divVal(&A, &value);
    return Py_BuildValue("dd", B.r, B.d);
}

static PyObject * idivVWrap(PyObject * self, PyObject * args){
    double real, dual, value;
    if (!PyArg_ParseTuple(args, "ddd", &value, &real, &dual)){
        return NULL;
    }
    struct Dual A, B;
    A.r = real; A.d = dual;
    B = idivVal(&value, &A);
    return Py_BuildValue("dd", B.r, B.d);
}

static PyObject * powDWrap(PyObject * self, PyObject * args){
    double real, dual;
    int exponent;
    if (!PyArg_ParseTuple(args, "ddi", &real, &dual, &exponent)){
        return NULL;
    }
    struct Dual A, B;
    A.r = real; A.d = dual;
    B = powerDual(&A, exponent);
    return Py_BuildValue("dd", B.r, B.d);
}

static PyObject * expDWrap(PyObject * self, PyObject * args){
    double real, dual;
    if (!PyArg_ParseTuple(args, "dd", &real, &dual)){
        return NULL;
    }
    struct Dual A, B;
    A.r = real;
    A.d = dual;
    B = expDual(&A, 20);
    return Py_BuildValue("dd", B.r, B.d);
}

static PyObject * lnDWrap(PyObject * self, PyObject * args){
    double real, dual;
    int iterations = 100;
    if (!PyArg_ParseTuple(args, "dd", &real, &dual)){
        return NULL;
    }
    struct Dual A, B;
    A.r = real; A.d = dual;
    B = lnDual(&A, iterations);
    return Py_BuildValue("dd", B.r, B.d);
}

static PyObject * sinhDWrap(PyObject * self, PyObject * args){
    double real, dual;
    if (!PyArg_ParseTuple(args, "dd", &real, &dual)){
        return NULL;
    }
    struct Dual A, B;
    A.r = real; A.d = dual;
    B = sinhDual(&A);
    return Py_BuildValue("dd", B.r, B.d);
}

static PyObject * coshDWrap(PyObject * self, PyObject * args){
    double real, dual;
    if (!PyArg_ParseTuple(args, "dd", &real, &dual)){
        return NULL;
    }
    struct Dual A, B;
    A.r = real; A.d = dual;
    B = coshDual(&A);
    return Py_BuildValue("dd", B.r, B.d);
}

static PyObject * tanhDWrap(PyObject * self, PyObject * args){
    double real, dual;
    if (!PyArg_ParseTuple(args, "dd", &real, &dual)){
        return NULL;
    }
    struct Dual A, B;
    A.r = real; A.d = dual;
    B = tanhDual(&A);
    return Py_BuildValue("dd", B.r, B.d);
}

static PyMethodDef du_methods[] = {
        // basic arithmetic -- implement in Python?
        {"addD", addDWrap, METH_VARARGS, "Add two dual number."},
        {"addV", addVWrap, METH_VARARGS, "Add a real and a dual number."},
        {"subD", subDWrap, METH_VARARGS, "Subtract two dual numbers."},
        {"subV", subVWrap, METH_VARARGS, "Subtract a real number from a dual number"},
        {"isubV", isubVWrap, METH_VARARGS, "Subtract a dual number from a real one."},
        {"mulD", mulDWrap, METH_VARARGS, "Multiply two dual numbers."},
        {"mulV", mulVWrap, METH_VARARGS, "Multiply a real and a dual number."},
        {"divD", divDWrap, METH_VARARGS, "Divide a dual number by another dual number."},
        {"divV", divVWrap, METH_VARARGS, "Divide a dual number by a real number."},
        {"idivV", idivVWrap, METH_VARARGS, "Divide a real number by a dual number."},
        // functions -- C-optimised procedures
        // extend this list...
        {"pow", powDWrap, METH_VARARGS, "Exponentiate a dual number."},
        {"exp", expDWrap, METH_VARARGS, "Apply the exponential function on a dual number."},
        {"log", lnDWrap, METH_VARARGS, "Apply the natural logarithm on a dual number."},
        {"sinh", sinhDWrap, METH_VARARGS, "Apply the hyperbolic sine on a dual number."},
        {"cosh", coshDWrap, METH_VARARGS, "Apply the hyperbolic cosine on a dual number."},
        {"tanh", tanhDWrap, METH_VARARGS, "Apply the hyperbolic tangent on a dual number."},
        {NULL, NULL, 0, NULL}
};

static struct PyModuleDef du_mod = {
        PyModuleDef_HEAD_INIT,
        "duopy",
        "Python module for working with dual numbers.",
        -1,
        du_methods
};

PyMODINIT_FUNC PyInit_duopy(void){
    Py_Initialize();
    return PyModule_Create(&du_mod);
}