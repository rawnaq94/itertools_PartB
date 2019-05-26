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
		for(auto i: zip(string("example"), string("testing")))
		{
			testcase.CHECK_OUTPUT(i, arr_44[arr]);
			arr++;				
		}
		  //end zip test.
				   
	testcase.setname("product test");
		arr=0;
		string arr_10[]={"1,h","1,e","1,l","1,l","1,o","2,h","2,e","2,l","2,l","2,o","3,h","3,e","3,l","3,l","3,o","4,h","4,e","4,l","4,l","4,o","5,h","5,e","5,l","5,l","5,o"};
		for(auto it: product(range(1,6), string("hello")))
		{
			testcase.CHECK_OUTPUT(it, arr_10[arr]);
			arr++;				
		}		       
		arr=0;
		string arr_20[]={"1,1","1,2","2,1","2,2"};
		for(auto it: product(range(1,3), range(1,3)))
		{
			testcase.CHECK_OUTPUT(it, arr_20[arr]);
			arr++;				
		}
		arr=0;
		string arr_30[]={"1,4","1,5","1,6","1,7","1,8","1,9","2,4","2,5","2,6","2,7","2,8","2,9","3,4","3,5","3,6","3,7","3,8","3,9"};
		for(auto it: product(range(1,4), range(4,10)))
		{
			testcase.CHECK_OUTPUT(it, arr_30[arr]);
			arr++;				
		}
		arr=0;
		string arr_40[]={"e,t","e,e","e,s","e,t","e,i","e,n","e,g","x,t","x,e","x,s","x,t","x,i","x,n","x,g","a,t","a,e","a,s","a,t","a,i","a,n","a,g","m,t","m,e","m,s","m,t","m,i","m,n","m,g","p,t","p,e","p,s","p,t","p,i","p,n","p,g","l,t","l,e","l,s","l,t","l,i","l,n","l,g","e,t","e,e","e,s","e,t","e,i","e,n","e,g"};
		for(auto it: product(string("example"), string(testing)))
		{
			testcase.CHECK_OUTPUT(it, arr_40[arr]);
			arr++;				
		}
		//end product test.
		
       testcase.setname("powerset test");	
		int _cd=0;
		string arr_50[]={"{}","{a}","{b}","{a,b}","{c}","{a,c}","{b,c}","{a,b,c}"};
		for(auto it: powerset(string("abc")))
		{
			testcase.CHECK_OUTPUT(it, arr_50[_cd]);
			_cd++;				
		}
		int _cd=0;
		string arr_60[]={"{}","{1}","{2}","{1,2}"};
		for(auto it: powerset(range(1,3)))
		{
			testcase.CHECK_OUTPUT(it, arr_60[_cd]);
			_cd++;				
		}
		//end powerset test.		
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


