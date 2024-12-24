#pragma once

#include "detail/wrap_python.h"

namespace cpy {
namespace detail {
inline PyObject* none() {
    Py_INCREF(Py_None);
    return Py_None;
}
}  // namespace detail
}  // namespace cpy
