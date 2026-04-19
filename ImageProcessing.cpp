// Muhammad Yousaf
#include <iostream>

using namespace std;

//_________________________________________________________________struct Pixel
struct Pixel
{

	int red;
	int green;
	int blue;

	// public:
	//_________________________________________constructors
	Pixel()
	{
		red = 0;
		green = 0;
		blue = 0;
	}
	Pixel(int r, int g, int b)
	{
		red = r;
		green = g;
		blue = b;
	}
	double getBrightness()
	{
		double colorSum = (red + green + blue);
		return (colorSum / 3.0);
	}
	bool isBright() const
	{
		return (red == 255 || green == 255 || blue == 255);
	}
};
//______________________________________________________________class Image
class Image
{
private:
	int row;
	int col;
	int depth;
	Pixel ***image;

public:
	//___________________________________________constructors
	Image(int d = 1, int r = 1, int c = 1)
	{
		row = r;
		col = c;
		depth = d;
		image = new Pixel **[depth];
		for (int i = 0; i < depth; ++i) // fix loop condition here
		{
			*(image + i) = new Pixel *[row];
			for (int j = 0; j < row; ++j)
			{
				*(*(image + i) + j) = new Pixel[col];
			}
		}
	}
	Image(const Image &img) //__copy constructor
	{
		this->row = img.row;
		this->col = img.col;
		this->depth = img.depth;
		image = new Pixel **[depth];
		for (int i = 0; i < row; i++)
		{
			*(image + i) = new Pixel *[row];
			for (int j = 0; j < col; j++)
			{
				*(*(image + i) + j) = new Pixel[col];
				for (int k = 0; k < depth; k++)
				{
					(*(*(*(image + i) + j) + k)) = (*(*(*(img.image + i) + j) + k));
				}
			}
		}
	}
	~Image() //_______________destructor
	{
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				delete[] (*(*(image + i) + j));
				*(*(image + i) + j) = nullptr;
			}
			delete[] (*(image + i));
			*(image + i) = nullptr;
		}
		delete[] image;
		image = nullptr;
	}
	//_______________________________________getters & setters functions
	void setRow(int r)
	{
		row = r;
	}
	void setCol(int c)
	{
		col = c;
	}
	void setDepth(int d)
	{
		depth = d;
	}
	int getRow()
	{
		return row;
	}
	int getCol()
	{
		return col;
	}
	int getDepth()
	{
		return depth;
	}
	Pixel getPixel(int x, int y, int z)
	{
		return (*(*(*(image + x) + y) + z));
	}
	void setPixel(int x, int y, int z, Pixel p)
	{
		(*(*(*(image + x) + y) + z)) = p;
	}
	//_______________________________other functions for manipulation of image
	void fill(Pixel p)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				for (int k = 0; k < depth; k++)
				{
					(*(*(*(image + i) + j) + k)) = p;
				}
			}
		}
	}
	void clear()
	{
		Pixel clear;
		fill(clear);
	}
	double getAverageBrightness()
	{
		double sum = 0.0, totalpixels;
		for (int i = 0; i < depth; ++i)
		{
			for (int j = 0; j < row; ++j)
			{
				for (int k = 0; k < col; ++k)
				{
					sum += (*(*(*(image + i) + j) + k)).getBrightness();
				}
			}
		}
		totalpixels = (depth * row * col);
		return (sum / totalpixels);
	}
	int getMaximumBrightness(int depth)
	{
		int maxbrightness = 0;

		for (int a = 0; a < row; a++)
		{
			for (int b = 0; b < col; b++)
			{
				if ((*(*(*(image + depth) + a) + b)).getBrightness() > maxbrightness)
				{
					maxbrightness = (*(*(*(image + depth) + a) + b)).getBrightness();
				}
			}
		}

		return maxbrightness;
	}

	int countBrightPixel()
	{
		int count = 0;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				for (int k = 0; k < depth; k++)
				{
					if ((*(*(*(image + i) + j) + k)).isBright())
					{
						count++;
						break;
					}
				}
			}
		}

		return count;
	}
	void transposePixel(int depth)
	{
		Pixel temp;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				temp = (*(*(*(image + depth) + i) + j));
				(*(*(*(image + depth) + i) + j)) = (*(*(*(image + depth) + j) + i));
				(*(*(*(image + depth) + j) + i)) = temp;
			}
		}
	}
};

int main()
{
	
}
