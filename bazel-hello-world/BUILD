package(default_visibility = ["//visibility:public"])

py_library(
    name = "library",
    srcs = ["library.py"],
)

py_binary(
    name = "bin",
    main = 'bin.py',
    srcs = ["bin.py"],
    deps = [":library"],
)

filegroup(
    name = "srcs",
    srcs = ["BUILD"] + glob(["**/*.py"]),
)
cc_library(
    name = "greeting_lib",
    srcs = ["greeting.cc"],
    hdrs = ["greeting.hh"],
)

cc_binary(
    name = "hello",
    srcs = ["hello.cc"],
    deps = [":greeting_lib"],
)