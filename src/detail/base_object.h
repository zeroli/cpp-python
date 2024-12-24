#pragma once

#include "detail/wrap_python.h"

namespace cpy {
namespace detail {
// base_object - adds a constructor and non-virtual destructor to a
// base Python type(e.g. PyObject, PyTypeObject)
template <typename python_type>
struct base_object : python_type
{
    using base_python_type = python_type;

    /// initialize type and reference count
    base_object(PyTypeObject* type_obj) {
        base_python_type* bp = this;
        memset(bp, 0, sizeof(base_python_type));
        this->ob_refcnt = 1;
        this->ob_type = type_obj;
        Py_INCREF(this->ob_type);
    }

    /// decrements reference count on the type
    ~base_object() {
        Py_DECREF(this->ob_type);
    }
};

// easy typedefs for common usage
using python_object = base_object<PyObject>;
using python_type   = base_object<PyTypeObject>;

}  // namespace detail
}  // namespace cpy
