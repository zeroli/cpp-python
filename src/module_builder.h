#pragma once

#include "detail/wrap_python.h"

#include <string>

namespace cpy {
class module_builder
{
public:
    module_builder(const char* name);
    ~module_builder();

    template <typename Fn>
    void def(Fn fn, const char* name)
    {
        //add(detail::new_wrapped_func(fn), name);
    }

    static std::string name();

    PyObject* module() const { return module_; }

private:
    PyObject* module_;
    static PyMethodDef initial_methods[1];
};
}
