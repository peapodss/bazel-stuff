bazel clean
rm -fr libmyfunctions.so

ls -l

bazel build //src/myfunctions:myfunctions
cp bazel-bin/src/myfunctions/libmyfunctions.so .
export DYLD_LIBRARY_PATH=$(pwd)/:DYLD_LIBRARY_PATH
export LD_LIBRARY_PATH=$(pwd)/:LD_LIBRARY_PATH
echo $LD_LIBRARY_PATH
echo $DYLD_LIBRARY_PATH



bazel build //:main_dlopen
./bazel-bin/main_dlopen
#bazel run main_dlopen
