load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
cc_binary(
    name = "libmyfunctions.so",
    srcs = ["add.c"],
    #srcs = ["add.c","result.c", "include/add.h"],
    linkshared = True,
    copts = ["-fPIC"],
)

cc_library(
    name = "myfunctions",
    srcs = ["libmyfunctions.so"],
    hdrs = ["include/add.h"],
)