#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> b(2);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			b[i][j] = 2;
		}
	}
	TMatrix <int>m(b);
			EXPECT_EQ(b, m);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> *p;
	p = new TMatrix<int>(2);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			(*p)[i][j] = i + j;
	}
	TMatrix<int> m(*p);
	delete p;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			EXPECT_EQ(m[i][j],i+j);
		
	}
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(2);
	EXPECT_EQ(2, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(2);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			m[i][j] = 2;
		}
	}
	ASSERT_NO_THROW(m[0][1] = 3);
	EXPECT_EQ(3, m[0][1]);
	
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(2);
	ASSERT_ANY_THROW(m[-1][2]);

}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(2);
	ASSERT_ANY_THROW(m[MAX_MATRIX_SIZE + 1][1]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(2);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			m[i][j] = 2;
		}
	}
	
	EXPECT_EQ(m, m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m1(2), m2(2);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			m1[i][j] = i + j;
		}
	}
	m2 = m1;
	EXPECT_EQ(m1, m2);
    
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m1(2), m2(4);
	m2 = m1;
	EXPECT_EQ(2, m2.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m1(2), m2(4);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			m1[i][j] = i + j;
		}
	}
	m2 = m1;
	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m1(2), m2(2);
	EXPECT_EQ(1, m1 == m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(2);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			m[i][j] = i + j;
		}
	}
	EXPECT_EQ(1, m == m);

}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m1(2), m2(4);
	EXPECT_EQ(1, m1 != m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m1(2), m2(2),rez(2);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			m1[i][j] = 1;
			m2[i][j] = 2;
			rez[i][j] = 3;
		}
	}
	EXPECT_EQ(rez, m1 + m2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m1(2), m2(3);
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m1(2), m2(2), rez(2);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			m1[i][j] = 1;
			m2[i][j] = 4;
			rez[i][j] = 3;
		}
	}
	EXPECT_EQ(rez, m2 - m1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m1(2), m2(3);
	ASSERT_ANY_THROW(m1 - m2);
}

