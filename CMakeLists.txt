cmake_minimum_required(VERSION 3.10)

project(CodeConverter)
add_executable(CodeConverter main.c)


enable_testing()

# does the application run
add_test(NAME Runs COMMAND sh -c "./CodeConverter < /dev/null")

add_test(NAME HidesMultiLineComments COMMAND sh -c "./CodeConverter --hide-comments < CodeSample1.txt")
set_tests_properties(HidesMultiLineComments
  PROPERTIES PASS_REGULAR_EXPRESSION "^\nHello Mars\n$"
  )

add_test(NAME SingleLineComments COMMAND sh -c "./CodeConverter --hide-comments < CodeSample2.txt")
set_tests_properties(HidesMultiLineComments
  PROPERTIES PASS_REGULAR_EXPRESSION "^\nHello Mars\n$"
  )

