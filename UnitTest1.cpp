#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/head.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
     public:

	TEST_METHOD(TestMethod1) //n<0
	{
		int arr[] = { 1,2,3,4,5 };
		int n = -5;
		int k;
		k = getmax(arr, n);
		Assert::AreEqual(k, 0);
	}
	TEST_METHOD(TestMethod2) // sum<arr[i]
	{
		int arr[] = { -2,11,-4,13,-5,-2 };
		int n = 6;
		int k;
		k = getmax(arr, n);
		Assert::AreEqual(k, 20);
	}

	TEST_METHOD(TestMethod3) //sum>arr[i]
	{
		int arr[] = { 2,11,-4,13,-5,-2 };
		int n = 6;
		int k;
		k = getmax(arr, n);
		Assert::AreEqual(k, 22);
	}

	TEST_METHOD(TestMethod4)
	{
		int arr[] = { 1,2,3,4,5 };
		int n = 5;
		int k;
		k = getmax(arr, n);
		Assert::AreEqual(k, 15);
	}
};
}
