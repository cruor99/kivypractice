
#include "nuitka/prelude.hpp"

// Sentinel PyObject to be used for all our call iterator endings. It will
// become a PyCObject pointing to NULL. It's address is unique, and that's
// enough for us to use it as sentinel value.
PyObject *_sentinel_value = NULL;

PyObject *const_dict_empty;
PyObject *const_int_0;
PyObject *const_int_pos_1;
PyObject *const_str_digest_04d542fe40e298e5929a23f3bb806b3d;
PyObject *const_str_digest_268060527bc6c0022bb231d71f93eb88;
PyObject *const_str_digest_3451707491a177b52280801d2b61e76a;
PyObject *const_str_digest_6f69449e3cbe19d8aaa066664eccb812;
PyObject *const_str_digest_bcd8b0c2eb1fce714eab6cef0d771acc;
PyObject *const_str_empty;
PyObject *const_str_plain___all__;
PyObject *const_str_plain___builtins__;
PyObject *const_str_plain___class__;
PyObject *const_str_plain___cmp__;
PyObject *const_str_plain___delattr__;
PyObject *const_str_plain___dict__;
PyObject *const_str_plain___doc__;
PyObject *const_str_plain___enter__;
PyObject *const_str_plain___exit__;
PyObject *const_str_plain___file__;
PyObject *const_str_plain___getattr__;
PyObject *const_str_plain___import__;
PyObject *const_str_plain___internal__;
PyObject *const_str_plain___iter__;
PyObject *const_str_plain___main__;
PyObject *const_str_plain___metaclass__;
PyObject *const_str_plain___module__;
PyObject *const_str_plain___name__;
PyObject *const_str_plain___setattr__;
PyObject *const_str_plain_called;
PyObject *const_str_plain_compile;
PyObject *const_str_plain_dict;
PyObject *const_str_plain_exc_traceback;
PyObject *const_str_plain_exc_type;
PyObject *const_str_plain_exc_value;
PyObject *const_str_plain_inspect;
PyObject *const_str_plain_int;
PyObject *const_str_plain_iter;
PyObject *const_str_plain_keys;
PyObject *const_str_plain_len;
PyObject *const_str_plain_long;
PyObject *const_str_plain_open;
PyObject *const_str_plain_range;
PyObject *const_str_plain_repr;
PyObject *const_str_plain_site;
PyObject *const_str_plain_star_arg_dict;
PyObject *const_str_plain_type;
PyObject *const_str_plain_xrange;
PyObject *const_tuple_empty;

#if defined(_WIN32) && defined(_NUITKA_EXE)
#include <Windows.h>
const unsigned char* constant_bin;
struct __initResourceConstants
{
    __initResourceConstants()
    {
        constant_bin = (const unsigned char*)LockResource(
            LoadResource(
                NULL,
                FindResource(NULL, MAKEINTRESOURCE(3), RT_RCDATA)
            )
        );
    }
} __initResourceConstants_static_initializer;
#else
extern "C" const unsigned char constant_bin[];
#endif

static void _createGlobalConstants( void )
{
    NUITKA_MAY_BE_UNUSED PyObject *exception_type, *exception_value;
    NUITKA_MAY_BE_UNUSED PyTracebackObject *exception_tb;

#ifdef _MSC_VER
    // Prevent unused warnings in case of simple programs, the attribute
    // NUITKA_MAY_BE_UNUSED doesn't work for MSVC.
    (void *)exception_type; (void *)exception_value; (void *)exception_tb;
#endif

    const_dict_empty = _PyDict_NewPresized( 0 );
    assert( PyDict_Size( const_dict_empty ) == 0 );
    const_int_0 = PyInt_FromLong( 0l );
    const_int_pos_1 = PyInt_FromLong( 1l );
    const_str_digest_04d542fe40e298e5929a23f3bb806b3d = UNSTREAM_STRING( &constant_bin[ 683 ], 9, 0 );
    const_str_digest_268060527bc6c0022bb231d71f93eb88 = UNSTREAM_STRING( &constant_bin[ 692 ], 7, 0 );
    const_str_digest_3451707491a177b52280801d2b61e76a = UNSTREAM_STRING( &constant_bin[ 699 ], 12, 0 );
    const_str_digest_6f69449e3cbe19d8aaa066664eccb812 = UNSTREAM_STRING( &constant_bin[ 711 ], 46, 0 );
    const_str_digest_bcd8b0c2eb1fce714eab6cef0d771acc = UNSTREAM_STRING( &constant_bin[ 757 ], 2, 0 );
    const_str_empty = UNSTREAM_STRING( &constant_bin[ 0 ], 0, 0 );
    const_str_plain___all__ = UNSTREAM_STRING( &constant_bin[ 759 ], 7, 1 );
    const_str_plain___builtins__ = UNSTREAM_STRING( &constant_bin[ 766 ], 12, 1 );
    const_str_plain___class__ = UNSTREAM_STRING( &constant_bin[ 778 ], 9, 1 );
    const_str_plain___cmp__ = UNSTREAM_STRING( &constant_bin[ 787 ], 7, 1 );
    const_str_plain___delattr__ = UNSTREAM_STRING( &constant_bin[ 794 ], 11, 1 );
    const_str_plain___dict__ = UNSTREAM_STRING( &constant_bin[ 805 ], 8, 1 );
    const_str_plain___doc__ = UNSTREAM_STRING( &constant_bin[ 813 ], 7, 1 );
    const_str_plain___enter__ = UNSTREAM_STRING( &constant_bin[ 820 ], 9, 1 );
    const_str_plain___exit__ = UNSTREAM_STRING( &constant_bin[ 829 ], 8, 1 );
    const_str_plain___file__ = UNSTREAM_STRING( &constant_bin[ 837 ], 8, 1 );
    const_str_plain___getattr__ = UNSTREAM_STRING( &constant_bin[ 845 ], 11, 1 );
    const_str_plain___import__ = UNSTREAM_STRING( &constant_bin[ 856 ], 10, 1 );
    const_str_plain___internal__ = UNSTREAM_STRING( &constant_bin[ 866 ], 12, 1 );
    const_str_plain___iter__ = UNSTREAM_STRING( &constant_bin[ 878 ], 8, 1 );
    const_str_plain___main__ = UNSTREAM_STRING( &constant_bin[ 886 ], 8, 1 );
    const_str_plain___metaclass__ = UNSTREAM_STRING( &constant_bin[ 894 ], 13, 1 );
    const_str_plain___module__ = UNSTREAM_STRING( &constant_bin[ 907 ], 10, 1 );
    const_str_plain___name__ = UNSTREAM_STRING( &constant_bin[ 917 ], 8, 1 );
    const_str_plain___setattr__ = UNSTREAM_STRING( &constant_bin[ 925 ], 11, 1 );
    const_str_plain_called = UNSTREAM_STRING( &constant_bin[ 936 ], 6, 1 );
    const_str_plain_compile = UNSTREAM_STRING( &constant_bin[ 942 ], 7, 1 );
    const_str_plain_dict = UNSTREAM_STRING( &constant_bin[ 25 ], 4, 1 );
    const_str_plain_exc_traceback = UNSTREAM_STRING( &constant_bin[ 949 ], 13, 1 );
    const_str_plain_exc_type = UNSTREAM_STRING( &constant_bin[ 962 ], 8, 1 );
    const_str_plain_exc_value = UNSTREAM_STRING( &constant_bin[ 970 ], 9, 1 );
    const_str_plain_inspect = UNSTREAM_STRING( &constant_bin[ 979 ], 7, 1 );
    const_str_plain_int = UNSTREAM_STRING( &constant_bin[ 466 ], 3, 1 );
    const_str_plain_iter = UNSTREAM_STRING( &constant_bin[ 880 ], 4, 1 );
    const_str_plain_keys = UNSTREAM_STRING( &constant_bin[ 986 ], 4, 1 );
    const_str_plain_len = UNSTREAM_STRING( &constant_bin[ 990 ], 3, 1 );
    const_str_plain_long = UNSTREAM_STRING( &constant_bin[ 993 ], 4, 1 );
    const_str_plain_open = UNSTREAM_STRING( &constant_bin[ 997 ], 4, 1 );
    const_str_plain_range = UNSTREAM_STRING( &constant_bin[ 1001 ], 5, 1 );
    const_str_plain_repr = UNSTREAM_STRING( &constant_bin[ 1006 ], 4, 1 );
    const_str_plain_site = UNSTREAM_STRING( &constant_bin[ 1010 ], 4, 1 );
    const_str_plain_star_arg_dict = UNSTREAM_STRING( &constant_bin[ 16 ], 13, 1 );
    const_str_plain_type = UNSTREAM_STRING( &constant_bin[ 966 ], 4, 1 );
    const_str_plain_xrange = UNSTREAM_STRING( &constant_bin[ 1014 ], 6, 1 );
    const_tuple_empty = PyTuple_New( 0 );
}

// In debug mode we can check that the constants were not tampered with in any
// given moment. We typically do it at program exit, but we can add extra calls
// for sanity.
#ifndef __NUITKA_NO_ASSERT__
void checkGlobalConstants( void )
{

}
#endif


void createGlobalConstants( void )
{
    if ( _sentinel_value == NULL )
    {
#if PYTHON_VERSION < 300
        _sentinel_value = PyCObject_FromVoidPtr( NULL, NULL );
#else
        // The NULL value is not allowed for a capsule, so use something else.
        _sentinel_value = PyCapsule_New( (void *)27, "sentinel", NULL );
#endif
        assert( _sentinel_value );

        _createGlobalConstants();
    }
}
