
```
bazel build bin
bazel-bin/bin
bazel query 'deps(bin)'
bazel query 'kind("source file", deps(bin))'
```

```
bazel build hello-world
bazel-bin/hello-world

bazel build //main:hello-world
bazel-bin/main/hello-world
```