#include <iostream>
using namespace std;
#include "badkan.hpp"
#include "chain.hpp"
#include "powerset.hpp"
#include "product.hpp"
#include "range.hpp"
#include "zip.hpp"
using namespace itertools;

int main()
{
	badkan::TestCase testcase;
	int grade = 0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0)
	{
	testcase.setname("Range test");
	int arr=0;
	for (int i: range(0,35))
	{
	    testcase.CHECK_EQUAL(i, arr);
	    arr++;
	}
	arr=5;
	for (int i: range(5,7))
	{
	    testcase.CHECK_EQUAL(i, arr);
	    arr++;
	}
        arr=-10;
	for (int i: range(-10,0))
	{
	    testcase.CHECK_EQUAL(i, arr);
	    arr++;
	}
	arr=101;
	for (int i: range(101,102))
	{
	    testcase.CHECK_EQUAL(i, arr);
	    arr++;
	}
	arr=2;
	for (int i: range(2,2))
	{
	    testcase.CHECK_EQUAL(i, arr);
	    arr++;
	}
	char arr1='a';
	for (int i: range('a','j'))
	{
	    testcase.CHECK_EQUAL(i, arr1);
	    arr1++;
	}
	arr1='d';
	for (int i: range('d','d'))
	{
	    testcase.CHECK_EQUAL(i, arr1);
	    arr1++;
	}
	arr1='u';
	for (int i: range('u','l'))
	{
	    testcase.CHECK_EQUAL(i, arr1);
	    arr1++;
	}
	arr1='~';
	for (int i: range('~','*'))
	{
	    testcase.CHECK_EQUAL(i, arr1);
	    arr1++;
	}
	
	testcase.setname("Chain test");

		arr=0;
		int arr_1[]={0,1,2,3,4,5,10,11,12,13,14};
		for(int i: chain(range(0,6), range(10,15)))
		{
			testcase.CHECK_EQUAL(i, arr_1[arr]);
			arr++;				
		}
		arr=0;
		int arr_2[]={0,1,2,3,4,5,0,1,2,3,4,5};
		for(int i: chain(range(0,6), range(0,6)))
		{
			testcase.CHECK_EQUAL(i, arr_2[arr]);
			arr++;				
		}
                arr=0;
		char arr_3[]={'a','b','c','d','e','f','g'};
		for(int i: chain(range('a','d'), range('d','h')))
		{
			testcase.CHECK_EQUAL(i, arr_3[arr]);
			arr++;				
		}
		arr=0;
		char arr_4[]={'a','b','c','A','B','C','D'};
		for(int i: chain(range('a','d'), range('A','E')))
		{
			testcase.CHECK_EQUAL(i, arr_4[arr]);
			arr++;				
		}
		
    grade = testcase.grade();
	}
	else
	{
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}


