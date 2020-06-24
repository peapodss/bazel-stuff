# cc_binary(
#     name = "hello-dl",
#     srcs = ["hello-dl.cc"],
#     linkopts = ['-ldl', '-lm'],
# 	deps = [
# 		"@system_libs//:hello-greet",
#         "@system_libs_headers//:hello-greet-header",
# 	],
# )
# cc_library(
#     name = "hello-greet",
#     srcs = ["hello-greet.cc"],
#     #hdrs = ["include/hello-greet.h"],
# 	deps = [
#         "@system_libs_headers//:hello-greet-header",
# 	],
# )

# ## https://github.com/bazelbuild/bazel/issues/7059
# cc_import(
#     name = "hello-greet",
#     interface_library = "libhello-greet.so",  # ld searches for this w/ -lmylib
#     shared_library = "libhello-greet.so",  # soname embedded in library; runtime linker searches for this
# )

## https://stackoverflow.com/questions/61487115/link-archive-to-shared-library-with-bazel
cc_binary(
    name = "libhello-greet.so",
    srcs = ["hello-greet.cc"],
    linkshared = True,
)

cc_library(
    name = "hello-greet",
    srcs = ["libhello-greet.so"],
    hdrs = ["include/hello-greet.h"],
)
cc_binary(
    name = "hello-dl",
    srcs = ["hello-dl.cc"],
    linkopts = ['-ldl', '-lm'],
    deps = [":hello-greet"],
)