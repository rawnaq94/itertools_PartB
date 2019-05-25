#include <iostream>
#include <iostream>
#include "badkan.hpp"
#include "chain.hpp"
#include "powerset.hpp"
#include "product.hpp"
#include "range.hpp"
#include "zip.hpp"
#include <list>
#include <set>
#include <string>
#include <vector>

using namespace std;
using namespace itertools;


int main()
{
	badkan::TestCase testcase;
	int grade = 0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0)
	{
	testcase.setname("range test");
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
	}
	arr=2;
	for (int i: range(2,2))
	{
	    testcase.CHECK_EQUAL(i, arr);
	}
	char arr1='a';
	for (char i: range('a','j'))
	{
	    testcase.CHECK_EQUAL(i, arr1);
	    arr1++;
	}
	arr1='d';
	for (char i: range('d','d'))
	{
	    testcase.CHECK_EQUAL(i, arr1);
	}
	arr1='u';
	for (char i: range('u','l'))
	{
	    testcase.CHECK_EQUAL(i, arr1);
	    arr1++;
	}
	arr1='~';
	for (char i: range('~','*'))
	{
	    testcase.CHECK_EQUAL(i, arr1);
	    arr1++;
	} 
		//end of range test.
	
		
	testcase.setname("chain test");
		arr=0;
		int arr_1[]={0,1,2,3,4,5,10,11,12,13,14};
		for(auto i: chain(range(0,6), range(10,15)))
		{
			testcase.CHECK_EQUAL(i, arr_1[arr]);
			arr++;				
		}
		arr=0;
		int arr_2[]={0,1,2,3,4,5,0,1,2,3,4,5};
		for(auto i: chain(range(0,6), range(0,6)))
		{
			testcase.CHECK_EQUAL(i, arr_2[arr]);
			arr++;				
		}
                arr=0;
		char arr_3[]={'a','b','c','e','f','g'};
		for(auto i: chain(range('a','d'), range('e','h')))
		{
			testcase.CHECK_EQUAL(i, arr_3[arr]);
			arr++;				
		}
		arr=0;
		char arr_4[]={'a','b','c','d','e','f','g'};
		for(auto i: chain(range('a','d'), range('d','h')))
		{
			testcase.CHECK_EQUAL(i, arr_4[arr]);
			arr++;				
		}
		arr=0;
		char arr_5[]={'a','b','c','A','B','C','D'};
		for(auto i: chain(range('a','d'), range('A','E')))
		{
			testcase.CHECK_EQUAL(i, arr_5[arr]);
			arr++;				
		}
		arr=0;
		char arr_6[]={'a','b','c','h','l','l','o'};
		for(auto i: chain(range('a','d'), string("hello")))
		{
			testcase.CHECK_EQUAL(i, arr_6[arr]);
			arr++;				
		}
		//end chain test.
		
	testcase.setname("zip test");
		arr=0;
		string arr_11[]={"1,h","2,e","3,l","4,l","5,o"};
		for(auto it: zip(range(1,6), string("hello")))
		{
			testcase.CHECK_OUTPUT(it, arr_11[arr]);
			arr++;				
		}
	        arr=0;
		string arr_22[]={"1,1","2,2","3,3","4,4","5,5"};
		for(auto i: zip(range(1,6), range(1,6)))
		{
			testcase.CHECK_OUTPUT(i, arr_22[arr]);
			arr++;				
		}
		arr=0;
		string arr_33[]={"1,6","2,7","3,8","4,9","5,10"};
		for(auto i: zip(range(1,6), range(6,11)))
		{
			testcase.CHECK_OUTPUT(i, arr_33[arr]);
			arr++;				
		}
		arr=0;
		string arr_44[]={"e,t","x,e","a,s","m,t","p,i","l,n","e,g"};
		for(auto i: zip(string("example), string("testing")))
		{
			testcase.CHECK_OUTPUT(i, arr_44[arr]);
			arr++;				
		}
		  //end zip test.
				   
	testcase.setname("product test");
				      
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
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


