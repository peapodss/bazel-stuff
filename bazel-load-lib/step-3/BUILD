load("@rules_cc//cc:defs.bzl", "cc_binary")

## https://stackoverflow.com/questions/61487115/link-archive-to-shared-library-with-bazel
cc_binary(
    name = "main_dlopen",
    srcs = ["src/main_dlopen.c"],
    linkopts = ['-ldl', '-lm'],
    #deps = [":myfunctions"],
	deps = [
        "@system_libs//:myfunctions",
	],
)