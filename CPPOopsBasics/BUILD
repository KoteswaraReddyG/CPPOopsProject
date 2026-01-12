cc_library(
    name = "lib",
    srcs = [
        "SampleClass.cpp",
        "StaticConstRefMembersExamples.cpp",
        "WorkingWithAbsractionRules.cpp",
        "WorkingWithInheritance.cpp",
        "WorkingWithPolymorphysim.cpp",
        "WorkingWithAbstractionClass.cpp",
    ],
    hdrs = glob(["*.hpp"]),
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["Main.cpp"],
    deps = [":lib"],
)

cc_test(
    name = "cpp_test",
    srcs = ["test.cpp"],
    deps = [
        ":lib",
        "@googletest//:gtest",
    ],
    tags = ["manual"],
)
