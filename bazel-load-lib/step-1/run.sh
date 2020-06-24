bazel clean

bazel build //:libmylib-macos.dylib 

tree bazel-bin

rm -fr lib-macos.dylib

cp bazel-bin/libmylib-macos.dylib lib-macos.dylib

export DYLD_LIBRARY_PATH=$(pwd):DYLD_LIBRARY_PATH
export LD_LIBRARY_PATH=$(pwd):LD_LIBRARY_PATH
# bazel run //:main-with-lib

bazel run //:main-with-imp1

# bazel clean

# rm -fr lib-macos.dylib