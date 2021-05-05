# CMake generated Testfile for 
# Source directory: /Users/fredericofalcao/Desktop/CodeConverter
# Build directory: /Users/fredericofalcao/Desktop/CodeConverter
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Runs "sh" "-c" "./CodeConverter < /dev/null")
set_tests_properties(Runs PROPERTIES  _BACKTRACE_TRIPLES "/Users/fredericofalcao/Desktop/CodeConverter/CMakeLists.txt;10;add_test;/Users/fredericofalcao/Desktop/CodeConverter/CMakeLists.txt;0;")
add_test(HidesMultiLineComments "sh" "-c" "./CodeConverter --hide-comments < CodeSample1.txt")
set_tests_properties(HidesMultiLineComments PROPERTIES  PASS_REGULAR_EXPRESSION "^
Hello Mars
\$" _BACKTRACE_TRIPLES "/Users/fredericofalcao/Desktop/CodeConverter/CMakeLists.txt;12;add_test;/Users/fredericofalcao/Desktop/CodeConverter/CMakeLists.txt;0;")
add_test(SingleLineComments "sh" "-c" "./CodeConverter --hide-comments < CodeSample2.txt")
set_tests_properties(SingleLineComments PROPERTIES  _BACKTRACE_TRIPLES "/Users/fredericofalcao/Desktop/CodeConverter/CMakeLists.txt;17;add_test;/Users/fredericofalcao/Desktop/CodeConverter/CMakeLists.txt;0;")
