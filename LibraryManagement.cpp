// Muhammad Yousaf_I228797_SE-F
#include <iostream>

using namespace std;


size_t len(char *str)
{
	size_t size_str = 0;
	while (str[size_str] != '\0')
	{
		size_str++;
	}
	return size_str;
}
class Library
{
	char *bookTitle;
	char *author;
	int bookID;
	int quantity;
	float price;
	static int totalBooks;

public:
	//_______________________________________________constructor
	Library()
	{
		bookTitle = "";
		author = "";
		bookID = 0;
		quantity = 0;
		price = 0.0;
		// totalBooks++;
	}
	Library(char *bookTitle, char *author, int bookID, int quantity, float price)
	{
		this->bookTitle = new char[len(bookTitle) + 1];
		for (int i = 0; i < len(bookTitle); i++)
		{
			this->bookTitle[i] = bookTitle[i];
		}
		this->bookTitle[len(bookTitle)] = '\0';

		this->author = new char[len(author) + 1];
		for (int i = 0; i < len(author); i++)
		{
			this->author[i] = author[i];
		}
		this->author[len(bookTitle)] = '\0';
		this->bookID = bookID;
		this->quantity = quantity;
		this->price = price;
	}
	//____________________________________________________Getter & Setter
	char *getBookTitle() // – a getter for book title
	{
		return bookTitle;
	}
	char *getAuthor() // – a getter for author name
	{
		return author;
	}
	int getBookID() // – a getter for book ID
	{
		return bookID;
	}
	int getQuantity() // – a getter for number of copies of the book
	{
		return quantity;
	}
	float getPrice() // – a getter for the price of each book
	{
		return price;
	}
	void setBookTitle(char *title) // – a setter for book title
	{
		bookTitle = new char[len(title) + 1];
		for (size_t i = 0; i < len(title); i++)
		{
			*(bookTitle + i) = *(title + i);
		}
		*(bookTitle + len(title)) = '\0';
	}
	void setAuthor(char *authorName) // – a setter for author name
	{
		author = new char[len(authorName) + 1];
		for (size_t i = 0; i < len(authorName); i++)
		{
			*(author + i) = *(authorName + i);
		}
		*(author + len(authorName)) = '\0';
	}
	void setBookID(int bookID) // – a setter for book ID
	{
		// for (size_t i = 0; i < quantity; i++)
		//{
			/*	if (bookID == books[i].getBookID())
				{
					cout << "This bookId have already been taken" << endl;
				}
				else*/
			this->bookID = bookID;
		//}
	}
	void setQuantity(int quantity) // – a setter for number of copies of the book
	{
		if (quantity < 0)
			cout << "the quantity cannot be negative" << endl;
		else
			this->quantity = quantity;
	}
	void setPrice(float price) // – a setter for the price of each book
	{
		if (price < 0)
			cout << "the price value cannot be negative" << endl;
		else
			this->price = price;
	}
	static void setTotalBooks(int totalBooks); // – a setter for total number of books
	static int getTotalBooks();
	float calcTotalPrice()
	{
		return (price * quantity);
	}
};
int Library ::totalBooks = 0;
void Library::setTotalBooks(int totalBooks)
{
	Library::totalBooks = totalBooks;
}
int Library::getTotalBooks()
{
	return (Library::totalBooks);
}
//_________________________________________________global functions
Library getBook_at(Library books[100], int index) // – returns the Library object at the given array index
{
	return books[index];
}
void addBook(Library books[100], Library newBook) // – adds a new book to the library array
{
	size_t total_books = Library::getTotalBooks();
	if (total_books > 99)
	{
		cout << "No space to add book" << endl;
		return;
	}

	books[total_books].setBookTitle(newBook.getBookTitle());
	books[total_books].setAuthor(newBook.getAuthor());
	books[total_books].setBookID(newBook.getBookID());
	books[total_books].setQuantity(newBook.getQuantity());
	books[total_books].setPrice(newBook.getPrice());
	Library::setTotalBooks(total_books + 1);
}
void removeBook(Library books[100], int bookID) // – removes the book with the given book ID from the library array
{
	size_t total_books = Library::getTotalBooks();
	if (total_books == 99)
	{
		books[total_books] = Library();
	}
	else
	{
		for (size_t i = 0; i <= total_books; i++)
		{
			if (books[i].getBookID() == bookID)
			{
				cout<<"book is removed"<<endl;
				for (size_t j = i; j <= total_books; j++)
				{
					books[j] = books[j + 1];
				}
				books[(total_books - 1)] = Library();
				Library::setTotalBooks(total_books - 1);
				return;
			}
		}
			cout << "BookId is not found" << endl;
	}
}
void SortByTitle(Library books[100]) // – sorts the books in ascending order based on title
{
	string a, b;
	Library temporary;
	for (size_t j = 0; j < Library::getTotalBooks(); j++)
	{
		if (books[j].getBookTitle()[0] >= 'a' && books[j].getBookTitle()[0] <= 'z') // if the letter is capital
			a = books[j].getBookTitle()[0] - 32;									// 32 is the differece between each capital and small letter in ASCII
		else
			a = books[j].getBookTitle()[0];
		for (size_t i = 0; i < Library::getTotalBooks(); i++)
		{
			if (books[i].getBookTitle()[0] >= 'a' && books[i].getBookTitle()[0] <= 'z') // if the letter is capital
				b = books[i].getBookTitle()[0] - 32;									// 32 is the differece between each capital and small letter in ASCII
			else
				b = books[i].getBookTitle()[0];

			if (a < b)
			{
				temporary = books[j];
				books[j] = books[i];
				books[i] = temporary;
			}
		}
	}
}
void SortByAuthor(Library books[100]) // – sorts the books in ascending order based on author name
{
	string a, b;
	Library temporary;
	for (size_t j = 0; j < Library::getTotalBooks(); j++)
	{
		if (books[j].getAuthor()[0] >= 'a' && books[j].getAuthor()[0] <= 'z') // if the letter is capital
			a = books[j].getAuthor()[0] - 32;									// 32 is the differece between each capital and small letter in ASCII
		else
			a = books[j].getAuthor()[0];
		for (size_t i = 0; i < Library::getTotalBooks(); i++)
		{
			if (books[i].getAuthor()[0] >= 'a' && books[i].getAuthor()[0] <= 'z') // if the letter is capital
				b = books[i].getAuthor()[0] - 32;									// 32 is the differece between each capital and small letter in ASCII
			else
				b = books[i].getAuthor()[0];

			if (a < b)
			{
				temporary = books[j];
				books[j] = books[i];
				books[i] = temporary;
			}
		}
	}
}
void SortByPrice(Library books[100]) // – sorts the books in ascending order based on price
{
	Library temporary;
	for (size_t j = 0; j < Library::getTotalBooks(); j++)
	{
		for (size_t i = 0; i < Library::getTotalBooks(); i++)
		{
			if (books[i].getPrice() < books[j].getPrice())
			{
				temporary = books[j];
				books[j] = books[i];
				books[i] = temporary;
			}
		}
	}
}
bool searchByTittle(Library books[10], char *titlename) //- returns true if the book with the titlename is found in the list
{
	string a = titlename;
	bool found = false;
	for(size_t i= 0; i<Library::getTotalBooks(); i++)
	{
		if(books[i].getBookTitle() == a)
		found = true;
	}
	return found;
}
Library mostExpensiveBook(Library books[10]) //- returns the book with the most expensive price from the list
{
	Library temporary;
	for(size_t i=0; i<Library::getTotalBooks(); i++)
	{
		if (temporary.getPrice() < books[i].getPrice())
		{
			temporary = books[i];
		}
		
	}
	return temporary;
}
int main()
{
  
}
