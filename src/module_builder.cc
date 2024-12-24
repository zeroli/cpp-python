#include "module_builder.h"

namespace cpy {
std::string module_builder::name()
{
    return "TODO";
}

PyMethodDef module_builder::initial_methods[] = {
    {0, 0, 0, 0}
};

module_builder::module_builder(const char* name)
    : module_(Py_InitModule(const_cast<char*>(name), initial_methods))
{
}

module_builder::~module_builder()
{
}
}  // namespace cpy
