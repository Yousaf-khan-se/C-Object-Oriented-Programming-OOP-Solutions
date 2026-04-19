// Muhammad Yousaf_I228797_SE-F
#include <iostream>

using namespace std;

size_t len(string str)
{
	size_t size_str = 0;
	while (str[size_str] != '\0')
	{
		size_str++;
	}
	return size_str;
}
class Integer
{
	int num;
	string str;

public:
	Integer() // a default constructor
	{
		num = 0;
		str = "";
	}
	Integer(int num) // a parametrized constructor
	{
		this->num = num;
	}
	Integer(string str) // a parametrized constructor
	{
		this->str = str;
	}
	void set(int num) // set value
	{
		this->num = num;
	}
	int get() const // get value at (i,j)
	{
		return (this->num);
	}
	int bitCount() // Returns the number of one-bits in the 2's complement binary
	{
		int count = 0;
		int n = this->num;
		while (n != 0)
		{
			if (n % 2 == 1) // check if the least significant bit is a 1
			{
				count++;
			}

			n = n / 2; // to get the next value from right to left
		}
		return count;
	}
	int compareTo(Integer a) // Compares two Int objects numerically.
	{
		if (this->num < a.num)
		{
			return -1;
		}
		else if (this->num == a.num)
		{
			return 0;
		}
		else if (this->num > a.num)
		{
			return 1;
		}
	}
	double doubleValue() // Returns the value of this Int as a double.
	{
		return ((double)this->num);
	}
	float floatValue() // Returns the value of this Int as a float.
	{
		return ((float)this->num);
	}
	int plus(const Integer a) // adds two integers and return the result
	{
		return (a.num + (this->num));
	}
	int minus(const Integer a) // subtracts two integers and return the result
	{
		return ((this->num) - a.num);
	}
	int multiple(const Integer a) // multiplies two integers and return the result
	{
		return (a.num * (this->num));
	}
	int divide(const Integer a) // divides two integers and return the result
	{
		return ((this->num) / a.num);
	}
	static int numberOfLeadingZeros(int i) /*Returns the number of zero bits preceding the
   highest-order ("leftmost") one-bit in the two's complement binary representation of the
   specified int value.*/
	{
		if (i == 0)
		{
			return 32;
		}

		int count = 1;
		while (i != 1)
		{
			i = i / 2; // to get the next value from right to left
			count++;
		}
		return (32 - count);
	}
	static int numberOfTrailingZeros(int i) /*Returns the number of zero bits following the
	lowest-order ("rightmost") one-bit in the two's complement binary representation of the
	specified int value.*/
	{
		if (i == 0)
		{
			return 32;
		}
		int count = 0;
		while (i % 2 == 0)
		{
			count++;
			i /= 2;
		}
		return count;
	}
	static string toBinaryString(int i) // Returns string representation of i
	{
		if (i == 0)
		{
			return "0";
		}
		if (i == 1)
		{
			return "1";
		}

		string reverse_count, count;
		while (i != 0)
		{
			if (i % 2 == 0)
			{
				reverse_count = reverse_count + "0";
			}
			else
			{
				reverse_count = reverse_count + "1";
			}
			i = i / 2;
		}

		for (int j = len(reverse_count) - 1; j >= 0; j--)
		{
			count = count + reverse_count[j];
		}

		return count;
	}
	static string toHexString(int i) // Returns string representation of i in base16
	{
		if (i < 0)
		{
			return "-1";
		}
		if (i < 16)
		{
			string result;
			do
			{
				char digit = i % 10 + '0';
				result = digit + result;
				i /= 10;
			} while (i > 0);

			return result;
		}

		string reverse_count, count;
		while (i != 0)
		{
			if (i % 8 == 0)
			{
				reverse_count = reverse_count + "0";
			}
			else if (i % 8 == 1)
			{
				reverse_count = reverse_count + "1";
			}
			else if (i % 8 == 2)
			{
				reverse_count = reverse_count + "2";
			}
			else if (i % 8 == 3)
			{
				reverse_count = reverse_count + "3";
			}
			else if (i % 8 == 4)
			{
				reverse_count = reverse_count + "4";
			}
			else if (i % 8 == 5)
			{
				reverse_count = reverse_count + "5";
			}
			else if (i % 8 == 6)
			{
				reverse_count = reverse_count + "6";
			}
			else if (i % 8 == 7)
			{
				reverse_count = reverse_count + "7";
			}
			else if (i % 8 == 8)
			{
				reverse_count = reverse_count + "7";
			}
			else if (i % 8 == 9)
			{
				reverse_count = reverse_count + "7";
			}
			else if (i % 8 == 10)
			{
				reverse_count = reverse_count + "A";
			}
			else if (i % 8 == 11)
			{
				reverse_count = reverse_count + "B";
			}
			else if (i % 8 == 12)
			{
				reverse_count = reverse_count + "C";
			}
			else if (i % 8 == 13)
			{
				reverse_count = reverse_count + "D";
			}
			else if (i % 8 == 14)
			{
				reverse_count = reverse_count + "E";
			}
			else if (i % 8 == 15)
			{
				reverse_count = reverse_count + "F";
			}

			i = i / 16;
		}

		for (int j = len(reverse_count) - 1; j >= 0; j--)
		{
			count = count + reverse_count[j];
		}

		return count;
	}
	static string toOctString(int i) // Returns string representation of i in base 8
	{
		if (i < 0)
		{
			return "-1";
		}
		if (i < 8)
		{
			string result;
			do
			{
				char digit = i % 10 + '0';
				result = digit + result;
				i /= 10;
			} while (i > 0);

			return result;
		}

		string reverse_count, count;
		while (i != 0)
		{
			if (i % 8 == 0)
			{
				reverse_count = reverse_count + "0";
			}
			else if (i % 8 == 1)
			{
				reverse_count = reverse_count + "1";
			}
			else if (i % 8 == 2)
			{
				reverse_count = reverse_count + "2";
			}
			else if (i % 8 == 3)
			{
				reverse_count = reverse_count + "3";
			}
			else if (i % 8 == 4)
			{
				reverse_count = reverse_count + "4";
			}
			else if (i % 8 == 5)
			{
				reverse_count = reverse_count + "5";
			}
			else if (i % 8 == 6)
			{
				reverse_count = reverse_count + "6";
			}
			else if (i % 8 == 7)
			{
				reverse_count = reverse_count + "7";
			}
			i = i / 8;
		}

		for (int j = len(reverse_count) - 1; j >= 0; j--)
		{
			count = count + reverse_count[j];
		}

		return count;
	}
};

int main()
{
	
}
