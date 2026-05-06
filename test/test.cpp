#include "anaros.h"

#include <iostream>
#include <yaml-cpp/yaml.h>

#include <gtest/gtest.h>

struct TestStruct {
    int a;
    std::string b;
};

TEST(AnarosTest, BasicParsing) {
    YAML::Node yaml = YAML::Load("{a: 42, b: 'Hello'}");
    auto result = anaros::parse_from_yaml<TestStruct>(yaml);

    ASSERT_TRUE(result.has_value());
    EXPECT_EQ(result->a, 42);
    EXPECT_EQ(result->b, "Hello");
}