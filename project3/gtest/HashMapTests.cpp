// HashMapTests.cpp
//
// ICS 45C Winter 2019
// Project #3: Maps and Legends
//
// Write unit tests for your HashMap class here.  I've provided one test already,
// though I've commented it out, because it won't compile until you've implemented
// three things: the HashMap constructor, the HashMap destructor, and HashMap's
// size() member function.

#include <gtest/gtest.h>
#include "HashMap.hpp"


TEST(TestHashMap, sizeOfNewlyCreatedHashMapIsZero)
{
    HashMap empty;
    ASSERT_EQ(0, empty.size());
}

TEST(TestHashMap, sizeOfNewlyCreatedHashMapAfterAddingSomethingIsOne)
{
    HashMap empty;
    empty.add("abcd.edu", "abcdefg");
    ASSERT_EQ(1, empty.size());
}

TEST(TestHashMap, sizeOfHashMapAfterAddingMultipleThingsWillContinuesGrowing)
{
    HashMap empty;
    empty.add("abcd.edu", "abcdefg");
    empty.add("bcde.edu", "abcdefg");
    empty.add("edfg.edu", "abcdefg");
    ASSERT_EQ(3, empty.size());
}

TEST(TestHashMap, TheKeyIsNotContainedAfterNewlyConstructingAHashMap)
{
    HashMap empty;
    ASSERT_EQ(empty.contains("abcd.edu"), false);
}

TEST(TestHashMap, TheKeyIsContainedAfterAddingingAHashMap)
{
	HashMap empty;
    empty.add("abcd.edu", "abcdefg");
    empty.add("bcde.edu", "abcdefg");
	ASSERT_EQ(empty.contains("abcd.edu"), true);
    ASSERT_EQ(empty.contains("bcde.edu"), true);
}

TEST(TestHashMap, OtherKeysAreNotContainedAfterAddingingAKey)
{
    HashMap empty;
    empty.add("abcd.edu", "abcdefg");
    ASSERT_EQ(empty.contains("bcde.edu"), false);
    ASSERT_EQ(empty.contains("zxcv.edu"), false);
}

TEST(TestHashMap, THeKeyIsNotContainedAfterRemoving)
{
    HashMap empty;
    empty.add("abcd.edu", "abcdefg");
    empty.add("fghi.edu", "abcdefg");
    empty.add("ghil.edu", "abcdefg");
    ASSERT_EQ(empty.contains("abcd.edu"), true);
    ASSERT_EQ(empty.contains("fghi.edu"), true);
    ASSERT_EQ(empty.size(), 3);
    empty.remove("abcd.edu");
    empty.remove("fghi.edu");
    ASSERT_EQ(empty.contains("fghi.edu"), false);
    ASSERT_EQ(empty.contains("abcd.edu"), false);
    ASSERT_EQ(empty.size(), 1);
}


TEST(TestHashMap, CanGetTheValueByGivingAKey)
{
    HashMap empty;
    empty.add("abcd.edu", "abcdefg");
    ASSERT_EQ(empty.value("abcd.edu"), "abcdefg");
}


TEST(TestHashMap, CanClearTheHashTable)
{
    HashMap empty;
    empty.add("abcd.edu", "abcdefg");
    empty.add("fghi.edu", "abcdefg");
    empty.add("ghil.edu", "abcdefg");
    ASSERT_EQ(empty.size(), 3);
    empty.clear();
    ASSERT_EQ(empty.size(), 0);
    ASSERT_EQ(empty.contains("fghi.edu"), false);
    ASSERT_EQ(empty.contains("ghil.edu"), false);
    ASSERT_EQ(empty.contains("abcd.edu"), false);
}

TEST(TestHashMap, loadFactorWillIncreaseOneAfterAddingAKey)
{
    HashMap empty;
    empty.add("abcd.edu", "abcdefg");
    ASSERT_EQ(empty.loadFactor(), 0.1);
    empty.add("fghiasd.edu", "abcdefg");
    ASSERT_EQ(empty.loadFactor(), 0.2);
}


TEST(TestHashMap, MaxSizeBucketsWillBeZeroForANewlyCreatedHashMap)
{
    HashMap empty;
    ASSERT_EQ(empty.maxBucketSize(), 0);
}

TEST(TestHashMap, BucketsCountWillBeTenForANewlyCreatedHashMap)
{
    HashMap empty;
    ASSERT_EQ(empty.bucketCount(), 10);
}

TEST(TestHashMap, CanCopyAHashMap)
{
    HashMap hashmap1, hashmap2;
    hashmap1.add("bcde.edu", "abcdefg");
    hashmap1.add("edfg.edu", "abcdefg");
    hashmap1.add("abcd.edu", "abcdefg");
    hashmap1.add("efgh.edu", "abcdefg");
    hashmap1.add("ghil.edu", "abcdefg");
    hashmap2=hashmap1;
    ASSERT_EQ(hashmap2.contains("bcde.edu"), true);
    ASSERT_EQ(hashmap2.contains("abcd.edu"), true);
    ASSERT_EQ(hashmap2.contains("efgh.edu"), true);
    ASSERT_EQ(hashmap2.contains("ghil.edu"), true);
    ASSERT_EQ(hashmap2.contains("edfg.edu"), true);
    ASSERT_EQ(hashmap2.size(), 5);
}

TEST(TestHashMap, ChangeTheOriginalHashMapHasNoInfluenceToTheCopiedOne)
{
    HashMap hashmap1, hashmap2;
    hashmap1.add("bcde.edu", "abcdefg");
    hashmap1.add("edfg.edu", "abcdefg");
    hashmap1.add("abcd.edu", "abcdefg");
    hashmap2=hashmap1;
    hashmap1.remove("bcde.edu");
    ASSERT_EQ(hashmap2.contains("bcde.edu"), true);
    ASSERT_EQ(hashmap1.contains("bcde.edu"), false);
}

TEST(TestHashMap, HashMapWillRehashIfTheLoadFactorIsBigEnough)
{
    HashMap hashmap1;
    hashmap1.add("bcde.edu", "abcdefg");
    hashmap1.add("defg.edu", "abcdefg");
    hashmap1.add("efgh.edu", "abcdefg");
    hashmap1.add("fghi.edu", "abcdefg");
    hashmap1.add("1234.edu", "abcdefg");
    hashmap1.add("12345.edu", "abcdefg");
    hashmap1.add("123456.edu", "abcdefg");
    ASSERT_EQ(hashmap1.bucketCount(), 10);
    ASSERT_EQ(hashmap1.loadFactor(), 0.7);
    ASSERT_EQ(hashmap1.size(), 7);
    hashmap1.add("12.edu", "abcdefg");
    ASSERT_EQ(hashmap1.bucketCount(), 21);
    ASSERT_EQ((hashmap1.loadFactor()<0.8), true);
    hashmap1.add("1234567.edu", "abcdefg");
    ASSERT_EQ(hashmap1.size(), 9);
    ASSERT_EQ(hashmap1.contains("fghi.edu"), true);
    ASSERT_EQ(hashmap1.contains("12.edu"), true);
}