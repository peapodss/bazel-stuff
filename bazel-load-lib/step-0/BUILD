# Usage on Linux:
#  1.    bazel build //:libmylib-linux.so 
#  2.    cp bazel-bin/libmylib-linux.so lib-linux.so
#  3.a   bazel run //:main-with-lib
#  3.b   bazel run //:main-with-imp
#
# Usage on macOS:
#  1.    bazel build //:libmylib-macos.dylib 
#  2.    cp bazel-bin/libmylib-macos.dylib lib-macos.dylib
#  3.a   bazel run //:main-with-lib
#  3.b   bazel run //:main-with-imp


cc_library(
    name = "my-lib",
    srcs = select({
        "@bazel_tools//src/conditions:darwin": ["lib-macos.dylib"],
        "//conditions:default": ["lib-linux.so"],
    }),
    hdrs = ["my-lib.h"],
)

cc_import(
    name = "my-imp",
    # shared_library = select({
    #     "@bazel_tools//src/conditions:darwin": "lib-macos.dylib",
    #     "//conditions:default": "lib-linux.so",
    # }),
    hdrs = ["my-lib.h"],
    system_provided=1,
)

cc_binary(
    name = "main-with-lib",
    srcs = ["main.cc"],
    deps = [":my-lib"],
)

cc_binary(
    name = "main-with-imp",
    srcs = ["main.cc"],
    deps = [":my-imp"],
    #linkstatic=False,
)

cc_library(
  name = "bayesopt",
  linkopts = [ "-L/usr/local/lib", "-lbayesopt", "-lnlopt" ],
  ...
)

tf_py_wrap_cc(
  name = "pywrap_tensorflow_internal",
  deps = ["//path/to/bayesopt"],
)
