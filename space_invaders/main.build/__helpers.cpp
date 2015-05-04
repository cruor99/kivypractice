// This file contains helper functions that are automatically created from
// templates.

#include "nuitka/prelude.hpp"

extern PyObject *callPythonFunction( PyObject *func, PyObject **args, int count );


PyObject *CALL_FUNCTION_WITH_ARGS1( PyObject *called, PyObject *arg1 )
{
    CHECK_OBJECT( called );

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    PyObject *args_for_test[] = { arg1 };

    for( size_t i = 0; i < sizeof( args_for_test ) / sizeof( PyObject * ); i++ )
    {
        CHECK_OBJECT( args_for_test[ i ] );
    }
#endif

    if ( Nuitka_Function_Check( called ) )
    {
        if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
        {
            return NULL;
        }

        Nuitka_FunctionObject *function = (Nuitka_FunctionObject *)called;
        PyObject *result;

        PyObject *args[] = { arg1 };

        if ( function->m_direct_arg_parser )
        {
            result = function->m_direct_arg_parser(
                function,
                args,
                sizeof( args ) / sizeof( PyObject * )
            );
        }
        else
        {
            result = function->m_code(
                function,
                args,
                sizeof( args ) / sizeof( PyObject * ),
                NULL
            );
        }

        Py_LeaveRecursiveCall();

        return result;
    }
    else if ( Nuitka_Method_Check( called ) )
    {
        Nuitka_MethodObject *method = (Nuitka_MethodObject *)called;

        // Unbound method without arguments, let the error path be slow.
        if ( method->m_object != NULL )
        {
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }

            PyObject *args[] = {
                method->m_object,
                arg1
            };

            PyObject *result;

            if ( method->m_function->m_direct_arg_parser )
            {
                result = method->m_function->m_direct_arg_parser(
                    method->m_function,
                    args,
                    sizeof( args ) / sizeof( PyObject * )
                );
            }
            else
            {
                result = method->m_function->m_code(
                    method->m_function,
                    args,
                    sizeof( args ) / sizeof( PyObject * ),
                    NULL
                );
            }

            Py_LeaveRecursiveCall();

            return result;
        }
    }
    else if ( PyCFunction_Check( called ) )
    {
        // Try to be fast about wrapping the arguments.
        int flags = PyCFunction_GET_FLAGS( called );

        if ( flags & METH_NOARGS )
        {
#if 1 == 0
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, NULL );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            // Some buggy C functions do this, and Nuitka inner workings can get
            // upset from it.
            if (unlikely( result != NULL )) DROP_ERROR_OCCURRED();

            return result;
#else
            PyErr_Format(
                PyExc_TypeError,
                "%s() takes no arguments (1 given)",
                ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_O )
        {
#if 1 == 1
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, arg1 );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            // Some buggy C functions do this, and Nuitka inner workings can get
            // upset from it.
            if (unlikely( result != NULL )) DROP_ERROR_OCCURRED();

            return result;
#else
            PyErr_Format(PyExc_TypeError,
                "%s() takes exactly one argument (1 given)",
                 ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else
        {
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            PyObject *args[] = { arg1 };
            PyObject *pos_args = MAKE_TUPLE( args, sizeof( args ) / sizeof( PyObject * ) );

            PyObject *result;

            assert( flags && METH_VARARGS );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            if ( flags && METH_KEYWORDS )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else
            {
                result = (*method)( self, pos_args );
            }

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            // Some buggy C functions do this, and Nuitka inner workings can get
            // upset from it.
            if ( result != NULL ) DROP_ERROR_OCCURRED();

            Py_DECREF( pos_args );

            return result;
        }
    }
    else if ( PyFunction_Check( called ) )
    {
        PyObject *args[] = { arg1 };

        return callPythonFunction(
            called,
            args,
            sizeof( args ) / sizeof( PyObject * )
        );
    }

    PyObject *args[] = { arg1 };
    PyObject *pos_args = MAKE_TUPLE( args, sizeof( args ) / sizeof( PyObject * ) );

    PyObject *result = CALL_FUNCTION(
        called,
        pos_args,
        NULL
    );

    Py_DECREF( pos_args );

    return result;
}

PyObject *CALL_FUNCTION_WITH_ARGS2( PyObject *called, PyObject *arg1, PyObject *arg2 )
{
    CHECK_OBJECT( called );

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    PyObject *args_for_test[] = { arg1, arg2 };

    for( size_t i = 0; i < sizeof( args_for_test ) / sizeof( PyObject * ); i++ )
    {
        CHECK_OBJECT( args_for_test[ i ] );
    }
#endif

    if ( Nuitka_Function_Check( called ) )
    {
        if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
        {
            return NULL;
        }

        Nuitka_FunctionObject *function = (Nuitka_FunctionObject *)called;
        PyObject *result;

        PyObject *args[] = { arg1, arg2 };

        if ( function->m_direct_arg_parser )
        {
            result = function->m_direct_arg_parser(
                function,
                args,
                sizeof( args ) / sizeof( PyObject * )
            );
        }
        else
        {
            result = function->m_code(
                function,
                args,
                sizeof( args ) / sizeof( PyObject * ),
                NULL
            );
        }

        Py_LeaveRecursiveCall();

        return result;
    }
    else if ( Nuitka_Method_Check( called ) )
    {
        Nuitka_MethodObject *method = (Nuitka_MethodObject *)called;

        // Unbound method without arguments, let the error path be slow.
        if ( method->m_object != NULL )
        {
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }

            PyObject *args[] = {
                method->m_object,
                arg1, arg2
            };

            PyObject *result;

            if ( method->m_function->m_direct_arg_parser )
            {
                result = method->m_function->m_direct_arg_parser(
                    method->m_function,
                    args,
                    sizeof( args ) / sizeof( PyObject * )
                );
            }
            else
            {
                result = method->m_function->m_code(
                    method->m_function,
                    args,
                    sizeof( args ) / sizeof( PyObject * ),
                    NULL
                );
            }

            Py_LeaveRecursiveCall();

            return result;
        }
    }
    else if ( PyCFunction_Check( called ) )
    {
        // Try to be fast about wrapping the arguments.
        int flags = PyCFunction_GET_FLAGS( called );

        if ( flags & METH_NOARGS )
        {
#if 2 == 0
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, NULL );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            // Some buggy C functions do this, and Nuitka inner workings can get
            // upset from it.
            if (unlikely( result != NULL )) DROP_ERROR_OCCURRED();

            return result;
#else
            PyErr_Format(
                PyExc_TypeError,
                "%s() takes no arguments (2 given)",
                ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_O )
        {
#if 2 == 1
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, arg1, arg2 );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            // Some buggy C functions do this, and Nuitka inner workings can get
            // upset from it.
            if (unlikely( result != NULL )) DROP_ERROR_OCCURRED();

            return result;
#else
            PyErr_Format(PyExc_TypeError,
                "%s() takes exactly one argument (2 given)",
                 ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else
        {
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            PyObject *args[] = { arg1, arg2 };
            PyObject *pos_args = MAKE_TUPLE( args, sizeof( args ) / sizeof( PyObject * ) );

            PyObject *result;

            assert( flags && METH_VARARGS );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            if ( flags && METH_KEYWORDS )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else
            {
                result = (*method)( self, pos_args );
            }

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            // Some buggy C functions do this, and Nuitka inner workings can get
            // upset from it.
            if ( result != NULL ) DROP_ERROR_OCCURRED();

            Py_DECREF( pos_args );

            return result;
        }
    }
    else if ( PyFunction_Check( called ) )
    {
        PyObject *args[] = { arg1, arg2 };

        return callPythonFunction(
            called,
            args,
            sizeof( args ) / sizeof( PyObject * )
        );
    }

    PyObject *args[] = { arg1, arg2 };
    PyObject *pos_args = MAKE_TUPLE( args, sizeof( args ) / sizeof( PyObject * ) );

    PyObject *result = CALL_FUNCTION(
        called,
        pos_args,
        NULL
    );

    Py_DECREF( pos_args );

    return result;
}

PyObject *CALL_FUNCTION_WITH_ARGS3( PyObject *called, PyObject *arg1, PyObject *arg2, PyObject *arg3 )
{
    CHECK_OBJECT( called );

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    PyObject *args_for_test[] = { arg1, arg2, arg3 };

    for( size_t i = 0; i < sizeof( args_for_test ) / sizeof( PyObject * ); i++ )
    {
        CHECK_OBJECT( args_for_test[ i ] );
    }
#endif

    if ( Nuitka_Function_Check( called ) )
    {
        if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
        {
            return NULL;
        }

        Nuitka_FunctionObject *function = (Nuitka_FunctionObject *)called;
        PyObject *result;

        PyObject *args[] = { arg1, arg2, arg3 };

        if ( function->m_direct_arg_parser )
        {
            result = function->m_direct_arg_parser(
                function,
                args,
                sizeof( args ) / sizeof( PyObject * )
            );
        }
        else
        {
            result = function->m_code(
                function,
                args,
                sizeof( args ) / sizeof( PyObject * ),
                NULL
            );
        }

        Py_LeaveRecursiveCall();

        return result;
    }
    else if ( Nuitka_Method_Check( called ) )
    {
        Nuitka_MethodObject *method = (Nuitka_MethodObject *)called;

        // Unbound method without arguments, let the error path be slow.
        if ( method->m_object != NULL )
        {
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }

            PyObject *args[] = {
                method->m_object,
                arg1, arg2, arg3
            };

            PyObject *result;

            if ( method->m_function->m_direct_arg_parser )
            {
                result = method->m_function->m_direct_arg_parser(
                    method->m_function,
                    args,
                    sizeof( args ) / sizeof( PyObject * )
                );
            }
            else
            {
                result = method->m_function->m_code(
                    method->m_function,
                    args,
                    sizeof( args ) / sizeof( PyObject * ),
                    NULL
                );
            }

            Py_LeaveRecursiveCall();

            return result;
        }
    }
    else if ( PyCFunction_Check( called ) )
    {
        // Try to be fast about wrapping the arguments.
        int flags = PyCFunction_GET_FLAGS( called );

        if ( flags & METH_NOARGS )
        {
#if 3 == 0
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, NULL );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            // Some buggy C functions do this, and Nuitka inner workings can get
            // upset from it.
            if (unlikely( result != NULL )) DROP_ERROR_OCCURRED();

            return result;
#else
            PyErr_Format(
                PyExc_TypeError,
                "%s() takes no arguments (3 given)",
                ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_O )
        {
#if 3 == 1
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, arg1, arg2, arg3 );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            // Some buggy C functions do this, and Nuitka inner workings can get
            // upset from it.
            if (unlikely( result != NULL )) DROP_ERROR_OCCURRED();

            return result;
#else
            PyErr_Format(PyExc_TypeError,
                "%s() takes exactly one argument (3 given)",
                 ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else
        {
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            PyObject *args[] = { arg1, arg2, arg3 };
            PyObject *pos_args = MAKE_TUPLE( args, sizeof( args ) / sizeof( PyObject * ) );

            PyObject *result;

            assert( flags && METH_VARARGS );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            if ( flags && METH_KEYWORDS )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else
            {
                result = (*method)( self, pos_args );
            }

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            // Some buggy C functions do this, and Nuitka inner workings can get
            // upset from it.
            if ( result != NULL ) DROP_ERROR_OCCURRED();

            Py_DECREF( pos_args );

            return result;
        }
    }
    else if ( PyFunction_Check( called ) )
    {
        PyObject *args[] = { arg1, arg2, arg3 };

        return callPythonFunction(
            called,
            args,
            sizeof( args ) / sizeof( PyObject * )
        );
    }

    PyObject *args[] = { arg1, arg2, arg3 };
    PyObject *pos_args = MAKE_TUPLE( args, sizeof( args ) / sizeof( PyObject * ) );

    PyObject *result = CALL_FUNCTION(
        called,
        pos_args,
        NULL
    );

    Py_DECREF( pos_args );

    return result;
}
