#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(10);
	for (int i = 0; i < 10; i++)
		v[i] = i;
	TVector<int> v1(v);
	for (int i = 0; i < 10; i++)
		EXPECT_EQ(i, v1[i]);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> *p;
	p = new TVector<int>(10);
	for (int i = 0; i < 10; i++)
		(*p)[i] = i;
	TVector<int> v1(*p);
	delete p;
	for (int i = 0; i < 10; i++)
		EXPECT_EQ(i, v1[i]);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v;
	ASSERT_ANY_THROW( v[-2]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v;
	ASSERT_ANY_THROW(v[MAX_VECTOR_SIZE+1]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(5);
	for (int i = 0; i < 5; i++)
		v[i] = i;
	ASSERT_NO_THROW(v = v);
	for(int i=0;i<5;i++)
  EXPECT_EQ(i,v[i]);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v1(5), v2(5);
	for (int i = 0; i < 5; i++)
		v1[i] = i;
	ASSERT_NO_THROW(v2 = v1);
	for(int i=0;i<5;i++)
		EXPECT_EQ(i,v2[i]);
}

TEST(TVector, assign_operator_change_vector_size) 
{
	TVector<int> v1(10), v2(5);
	v1 = v2;
	EXPECT_EQ(5, v1.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v1(5), v2(10);
	for (int i = 0; i < 5; i++)
		v1[i] = i;
	ASSERT_NO_THROW(v2 = v1);
	for (int i = 0; i < 5; i++)
		EXPECT_EQ(i, v2[i]);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v1(5), v2(5);
	for (int i = 0; i < 5; i++)
		v1[i] = i;
	v2 = v1;
	EXPECT_EQ(1, v1 == v2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(5);
	for (int i = 0; i < 5; i++)
		v[i] = i;
	EXPECT_EQ(1, v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v1(5), v2(10);
	EXPECT_EQ(0, v1 == v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v1(5), v2(5);

	for (int i = 0; i < 5; i++) {
		v1[i] = 3;
		v2[i] = 4;
	}
	v1 = v1 + 1;
	EXPECT_EQ(v2, v1);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v1(5),v2(5);

	for (int i = 0; i < 5; i++) {
		v1[i] = 3;
		v2[i] = 4;
	}
	v2 = v2 - 1;
		EXPECT_EQ(v1, v2);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(5);
	int a = 3;
	for (int i = 0; i < 5; i++)
		v[i] = i;
	for (int i = 0; i < 5; i++)
		EXPECT_EQ(i * a, v[i]* a);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v1(5), v2(5),rez(5);
	for (int i = 0; i < 5; i++)
	{
		v1[i] = i;
		v2[i] = 2*i;
		rez[i] = i + 2 * i;
	}
	
	EXPECT_EQ(rez, v1+v2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v1(5), v2(10);
		ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v1(5), v2(5), rez(5);
	for (int i = 0; i < 5; i++)
	{
		v1[i] = i;
		v2[i] = 2 * i;
		rez[i] = i - 2 * i;
	}

	EXPECT_EQ(rez, v1 - v2);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v1(5), v2(10);
	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v1(4), v2(4);
	for (int i = 0; i < 4; i++)
	{
		v1[i] = 1;
		v2[i] = 2;
	}
	EXPECT_EQ(8, v1*v2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v1(4), v2(8);
	ASSERT_ANY_THROW(v1*v2);
}

