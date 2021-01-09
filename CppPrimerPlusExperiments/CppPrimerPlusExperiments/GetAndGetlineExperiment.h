/**
	@author: xuekt
	@date: 2021.1.9
	C++ 面向行的输入 cin.get(), cin.getline()
	1. cin.get
	（1）读入单个字符的cin.get()两种形式
		
		int get();
			从指定的输入流中提取一个字符（包括空白字符），函数的返回值就是读入的字符。 
		若遇到输入流中的文件结束符，则函数值返回文件结束标志EOF(End Of File)，一般
		以-1代表EOF，用-1而不用0或正值，是考虑到不与字符的ASCII代码混淆，但不同的
		C++系统所用的EOF值有可能不同。
			因此cin.get()可以处理遗留在输入队列中的换行符
		
		istream& get (char& c);
			从输入流中读取一个字符，赋给字符变量ch。如果读取成功则函数返回true(真)，
		如失败(遇文件结束符) 则函数返回false(假)。

	(2) 读入C风格字符串两种形式
		istream& get (char* s, streamsize n);
		istream& get (char* s, streamsize n, char delim);
			读取整行到s中，直到读满n（读取n-1个字符）或者遇到换行符或者遇到给定的delim字符。但是会把换行符
		留在输入队列之中，跳不过去这个换行符。因此需要调用cin.get()来读取这个换行符，
		之后才能继续输入，

	(3) 读入streambuf两种形式
		istream& get (streambuf& sb);
		istream& get (streambuf& sb, char delim);
	
	2. cin.getline
		读取整行C风格字符串
		istream& getline (char* s, streamsize n );
		istream& getline (char* s, streamsize n, char delim );
		基本与cin.get读取C风格字符串相同，有三个区别：
		（1）cin.get会把换行符保留在输入队列中，cin.getline把换行符读取并转换成'\0'
		（2）再输入空行的时候，
			-- cin.get会设置failbit，之后所有的输入都会被阻断，需要用cin.clear()恢复输入,
			此时，换行符仍保留在输入队列之中，需要再调用一次cin.get();
			-- cin.getline会把换行符读取并换成'\n'存储在字符串中
		（3）在读取的内容超过n的时候，都会产生截断。
			-- cin.get会把截断之后的内容都保留在输入队列中，因此可以继续cin.get读取剩余的内容
			-- cin.getline会置失效位，之后再调用cin.getline只能读取空字符串，
			需要用cin.clear()才能继续读取截断剩余的内容。
			例如：
				char s[10]; cin.get(s, 10); cin.getline(s, 10);
				输入为：1234567890
				对于cin.get(s, 10)：
					第一次：cin.get(s, 10); 输出 123456789
					第二次：cin.get(s, 10); 输出 0
					之后会一直输出空字符串，因为cin.get不能越过保留的换行符'\n'
					需要调用一次cin.get()才能继续
				对于cin.getline(s, 10):
					第一次：cin.getline(s, 10); 输出 123456789
					之后会一直输出空字符串，因为失效位
					需要调用一次cin.clear()才能继续
					cin.clear()之后再一次：cin.getline(s, 10); 输出 0

	3. getline (string)	
		使用时除需要#include <iostream> 还要#include <string>
		istream& getline (istream&  is, string& str, char delim);
		istream& getline (istream&& is, string& str, char delim);
		istream& getline (istream&  is, string& str);
		istream& getline (istream&& is, string& str);
**/

#ifndef GETANDGETLINEEXPERIMENT_H
#define GETANDGETLINEEXPERIMENT_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void testCinGet() {
	cout << "testing cin.get\n" << endl;
	
	int i;
	char c;
	char s[10];

	/*
	//test1: int get();
	cout << "test1: int get();" << endl;
	cout << "enter a sentence" << endl;
	//while((i = cin.get()) != EOF) {
	while((i = cin.get()) != '\n') {
		cout.put(i);
	}
	cout << "test1 end\n" << endl;

	//test2: istream& get (char& c);
	cout << "test2: istream& get (char& c);" << endl;
	cout << "enter a sentence" << endl;
	while(cin.get(c)) {
		cout.put(c);
	}
	cout << "test2 end\n" << endl;
	*/

	//test3: istream& get (char* s, streamsize n);
	cout << "test3: istream& get (char* s, streamsize n);" << endl;
	cout << "enter a sentence" << endl;
	cin.get(s, 10);
	cout << s << endl;
	cout << "test3 end\n" << endl;
	
	cout << "test cin.get end\n\n" << endl;
}

void testCinGetline() {
	cout << "testing cin.getline\n" << endl;

	char s[10];

	//test: istream& getline (char* s, streamsize n);
	cout << "test: istream& getline (char* s, streamsize n);" << endl;
	cout << "enter a sentence" << endl;
	cin.getline(s, 10);
	cout << s << endl;
	cout << "test end\n" << endl;
	
	cout << "test cin.getline end\n\n" << endl;
}

void testGetAndGetline() {
	testCinGet();
	testCinGetline();
}
#endif // ~GETANDGETLINEEXPERIMENT_H