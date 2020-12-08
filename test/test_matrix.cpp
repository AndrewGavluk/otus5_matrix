#include "../libs/lib_matrix.h"
#include <gtest/gtest.h>

TEST(gtest_matrix_test1, test_size){
	
	Matrix<int> test {42};
	test[5][7] = 49;
	test[9][15] = 56;
	test[9][7] = 45;
	test[5][7] = 42;

	ASSERT_TRUE(test.capacity () == 3);

}

TEST(gtest_matrix_test1, test_eql){
	
	Matrix<int> test {42};
	test[5][7] = 49;
	test[9][15] = 56;

	ASSERT_TRUE(test[5][7] == 49);
	ASSERT_TRUE(test[9][15] == 56);
}


int main (int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	}
