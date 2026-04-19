// Muhammad Yousaf_I228797_SE-F
#include <iostream>

using namespace std;

class String
{
private:
	char *data;
	int size;

	char convertCapital(char capital) // converts the capital character to small
	{
		if (capital >= 'A' && capital <= 'Z') // if the letter is capital
		{
			return (capital + 32); // 32 is the differece between each capital and small letter in ASCII
		}
		else
			return capital;
	}

public:
	//_________________________________________________constrctors
	String()
	{
		data = NULL;
		size = 0;
	}
	String(int length)
	{
		size = length;
		data = new char[size+1];
		for (size_t i = 0; i < (size+1); i++)
		{
			*(data + i) = '\0';
		}
		
	}
	String(char *str)
	{
		size = 0;
		while (*(str + size) != '\0')
		{
			size++;
		}
		//size++;

		data = new char[size];

		for (size_t i = 0; i < size; i++)
		{
			*(data + i) = *(str + i);
		}
		*(data + size) = '\0'; // to set the null terminator at the end of the string.
	}
	String(const String &str)
	{
		if (str.size == 0)
			cout << "The string is empty, no data to copy" << endl;
		else
		{
			this->size = str.size;
			data = new char[size];
			for (size_t i = 0; i < size; i++)
			{
				*(this->data + i) = *(str.data + i);
			}
			*(data + size) = '\0';
		}
	}
	~String()
	{
		delete[] data;
		data = NULL;
	}
	//_______________________________________________functions
	int stringLength()
	{
		return size;
	}
	void clear()
	{
		delete[] data;
		data = NULL;
		size = 0;
	}
	bool isEmpty()
	{
		if (size == 0)
			return true;
		else
			return false;
	}
	int charAt(char c)
	{
		if (isEmpty() == true)
		{
			cout << "The string is empty, no data to copy" << endl;
			return -1;
		}
		else
		{
			for (size_t i=0; i < size; i++)
			{
				if (*(data + i) == c)
				{
					return i;
				}
			}
			cout << "The character is not found" << endl;
			return -1;
		}
	}
	char *getdata()
	{
		return data;
	}
	bool isEqual(char *str)
	{
		size_t len = 0;
		while (*(str + len) != '\0')
		{
			len++;
		}
		//len++;

		if (this->size != len)
		{
			return false;
		}
		else
		{
			for (size_t i=0; i < size; i++)
			{
				if (*(this->data + i) != *(str + i))
				{
					return false;
				}
			}
			return true;
		}
	}
	bool equalsIgnoreCase(char *str)
	{
		size_t len = 0;
		while (*(str + len) != '\0')
		{
			len++;
		}
		//len++;

		if (this->size != len)
		{
			return false;
		}
		else
		{
			for (size_t i; i < size; i++)
			{
				char thislowerCase = convertCapital(*(this->data + i)); // converting every capital letter to small letters
				char strlowerCase = convertCapital(*(str + i));

				if (thislowerCase != strlowerCase) // all small letters are compared one by one
				{
					return false;
				}
			}
			return true;
		}
	}

	char *substring(char *substr, int startIndex)
	{
		if (substr == NULL)
		{
			cout << "the string is empty" << endl;
			return NULL;
		}
		if (startIndex < 0) // validation
		{
			cout << "starting index cannot be negative" << endl;
			return NULL;
		}
		if (startIndex > size)
		{
			cout << "the starting index is greater than the length of the string" << endl;
			return NULL;
		}

		bool found;
		size_t len = 0;
		while (*(substr + len) != '\0')
		{
			len++;
		}
		//len++;

		for (int i = startIndex; i <= (size - len); i++)
		{
			found = true;
			for (int j = 0; j < len; j++)
			{
				if ((*(data + (i + j))) != (*(substr + j)))
				{
					found = false;
					break;
				}
			}
			if (found == true)
			{
				return (data + i);
			}
		}
		return NULL;
	}
	char *substring(char *substr, int startIndex, int endIndex)
	{
		bool found;
		size_t len = 0;
		while (*(substr + len) != '\0')
		{
			len++;
		}
		//len++;

		if (substr == NULL)
		{
			cout << "the string is empty" << endl;
			return NULL;
		}
		if (startIndex < 0 || endIndex < 0) // validation
		{
			cout << "starting index or ending index cannot be negative negative" << endl;
			return NULL;
		}
		if (startIndex > size || endIndex > size)
		{
			cout << "the starting index or ending index is greater than the length of the string" << endl;
			return NULL;
		}
		if (startIndex > endIndex)
		{
			cout << "starting index cannot be greater than the ending index" << endl;
			return NULL;
		}
		if ((endIndex - startIndex + 1) < len)
		{
			cout << "the size of substring cannot be fitted between the given indexes" << endl
				 << "Please increase the difference between the indexes" << endl;
			return NULL;
		}

		for (int i = startIndex; i <= (endIndex - len); i++)
		{
			found = true;
			for (int j = 0; j < len; j++)
			{
				if ((*(data + (i + j))) != (*(substr + j)))
				{
					found = false;
					break;
				}
			}
			if (found == true)
			{
				char *result = new char[endIndex - len+1];
				for (size_t k = 0,l=startIndex; k <= (endIndex - len+1),l<=endIndex; k++,l++)
				{
					*(result + k) = *(data + l);
				}
				*(result + (endIndex - len+1)) = '\0';
				return (result);
			}
		}
		return NULL;
	}
	void print()
	{
		if (size == 0)
		{
			cout << "NULL" << endl;
		}
		else
		{
			cout << data << endl;
		}
	}
};

//#include <iostream>
#include "String.h"

//using namespace std;

int main()
{
	
}
