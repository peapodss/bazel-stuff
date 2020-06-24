bazel clean

#bazel build //:hello-greet
bazel build //:hello-dl


cp $(pwd)/bazel-bin/libhello-greet.so .
export DYLD_LIBRARY_PATH=$(pwd)/:DYLD_LIBRARY_PATH
export LD_LIBRARY_PATH=$(pwd)/:LD_LIBRARY_PATH



bazel run hello-dl
