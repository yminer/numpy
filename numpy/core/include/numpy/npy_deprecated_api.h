#ifndef _NPY_DEPRECATED_API_H
#define _NPY_DEPRECATED_API_H

#if defined(_WIN32)
#define _WARN___STR2__(x) #x
#define _WARN___STR1__(x) _WARN___STR2__(x)
#define _WARN___LOC__ __FILE__ "("_WARN___STR1__(__LINE__)") : Warning Msg: "
#pragma message(_WARN___LOC__"Using deprecated NumPy API, disable it by " \
                            "#defining NPY_NO_DEPRECATED_API")
#elif defined(__GNUC__)
#warning "Using deprecated NumPy API, disable it by #defining NPY_NO_DEPRECATED_API"
#endif
/* TODO: How to do this warning message for other compilers? */

/*
 * This header exists to collect all dangerous/deprecated NumPy API.
 *
 * This is an attempt to remove bad API, the proliferation of macros,
 * and namespace pollution currently produced by the NumPy headers.
 */

#ifdef NPY_NO_DEPRECATED_API
#error Should never include npy_deprecated_api directly.
#endif

/* These array flags are deprecated as of NumPy 1.7 */
#define NPY_CONTIGUOUS NPY_ARRAY_C_CONTIGUOUS
#define NPY_FORTRAN NPY_ARRAY_F_CONTIGUOUS

/*
 * The consistent NPY_ARRAY_* names which don't pollute the NPY_*
 * namespace were added in NumPy 1.7.
 *
 * These versions of the carray flags are deprecated, but
 * probably should only be removed after two releases instead of one.
 */
#define NPY_C_CONTIGUOUS   NPY_ARRAY_C_CONTIGUOUS
#define NPY_F_CONTIGUOUS   NPY_ARRAY_F_CONTIGUOUS
#define NPY_OWNDATA        NPY_ARRAY_OWNDATA
#define NPY_FORCECAST      NPY_ARRAY_FORCECAST
#define NPY_ENSURECOPY     NPY_ARRAY_ENSURECOPY
#define NPY_ENSUREARRAY    NPY_ARRAY_ENSUREARRAY
#define NPY_ELEMENTSTRIDES NPY_ARRAY_ELEMENTSTRIDES
#define NPY_ALIGNED        NPY_ARRAY_ALIGNED
#define NPY_NOTSWAPPED     NPY_ARRAY_NOTSWAPPED
#define NPY_WRITEABLE      NPY_ARRAY_WRITEABLE
#define NPY_UPDATEIFCOPY   NPY_ARRAY_UPDATEIFCOPY
#define NPY_BEHAVED        NPY_ARRAY_BEHAVED
#define NPY_BEHAVED_NS     NPY_ARRAY_BEHAVED_NS
#define NPY_CARRAY         NPY_ARRAY_CARRAY
#define NPY_CARRAY_RO      NPY_ARRAY_CARRAY_RO
#define NPY_FARRAY         NPY_ARRAY_FARRAY
#define NPY_FARRAY_RO      NPY_ARRAY_FARRAY_RO
#define NPY_DEFAULT        NPY_ARRAY_DEFAULT
#define NPY_IN_ARRAY       NPY_ARRAY_IN_ARRAY
#define NPY_OUT_ARRAY      NPY_ARRAY_OUT_ARRAY
#define NPY_INOUT_ARRAY    NPY_ARRAY_INOUT_ARRAY
#define NPY_IN_FARRAY      NPY_ARRAY_IN_FARRAY
#define NPY_OUT_FARRAY     NPY_ARRAY_OUT_FARRAY
#define NPY_INOUT_FARRAY   NPY_ARRAY_INOUT_FARRAY
#define NPY_UPDATE_ALL     NPY_ARRAY_UPDATE_ALL

/* This way of accessing the default type is deprecated as of NumPy 1.7 */
#define PyArray_DEFAULT NPY_DEFAULT_TYPE

/* These DATETIME bits aren't used internally */
#if PY_VERSION_HEX >= 0x03000000
#define PyDataType_GetDatetimeMetaData(descr)                                 \
    ((descr->metadata == NULL) ? NULL :                                       \
        ((PyArray_DatetimeMetaData *)(PyCapsule_GetPointer(                   \
                PyDict_GetItemString(                                         \
                    descr->metadata, NPY_METADATA_DTSTR), NULL))))
#else
#define PyDataType_GetDatetimeMetaData(descr)                                 \
    ((descr->metadata == NULL) ? NULL :                                       \
        ((PyArray_DatetimeMetaData *)(PyCObject_AsVoidPtr(                    \
                PyDict_GetItemString(descr->metadata, NPY_METADATA_DTSTR)))))
#endif


#endif