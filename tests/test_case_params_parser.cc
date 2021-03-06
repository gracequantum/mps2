// SPDX-License-Identifier: LGPL-3.0-only
/*
* Author: Rongyang Sun <sun-rongyang@outlook.com>
* Creation Date: 2019-06-04 20:20
* 
* Description: GraceQ/mps2 project. Unittests for simulation case parameters parser.
*/
#include "gqmps2/gqmps2.h"
#include "gtest/gtest.h"

#include <string>


using namespace gqmps2;


// Input arguments.
char *json_file;


// Custom case parameter parser.
struct CustomCaseParamsParser : public CaseParamsParserBasic {
  CustomCaseParamsParser(const char *f) : CaseParamsParserBasic(f) {
    case_int = ParseInt("Int"); 
    case_double = ParseDouble("Double");
    case_char = ParseChar("Char");
    case_str = ParseStr("String");
    case_bool = ParseBool("Boolean");
  }

  int case_int;
  double case_double;
  char case_char;
  std::string case_str;
  bool case_bool;
};


TEST(TestCaseParamsParser, Case1) {
  CustomCaseParamsParser params(json_file);
  EXPECT_EQ(params.case_int, 1);
  EXPECT_DOUBLE_EQ(params.case_double, 2.33);
  EXPECT_EQ(params.case_char, 'c');
  EXPECT_EQ(params.case_str, "string");
  EXPECT_EQ(params.case_bool, false);
}


int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  json_file = argv[1];
  return RUN_ALL_TESTS();
}
