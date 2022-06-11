#include <iostream>
#include "Poly.h"
#include <gtest/gtest.h>

TEST(must_be_49, polyTest) {
    Poly<4> pol({1,2,3,4});
    EXPECT_EQ(49,pol.countValue(2,3));
}


TEST(must_be_129,polyTest1){
    Poly<5> pol({1,2,3,4,5});
    EXPECT_EQ(129,pol.countValue(2,4));
}

TEST(must_be_ZERO,polyTest2){
    Poly<5> pol({0,0,0,0,0});
    EXPECT_EQ(0,pol.countValue(2,4));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc,argv);
    int status = RUN_ALL_TESTS();
    std::cout << status << std::endl; // tests status output
    Poly<4> pol({1,2,3,4});
    std::cout << pol; // overloaded <<
    return 0;
}
