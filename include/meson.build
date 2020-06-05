srcs = [
    'ara/array.hpp',
]

array_lib = library(
    'array_lib',
    srcs,
    include_directories: include_directories(['./'])
)

array_lib_dep = declare_dependency(
    link_with: array_lib,
    include_directories: ['./']
)
