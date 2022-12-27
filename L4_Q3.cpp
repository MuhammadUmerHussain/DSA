#include <iostream>

using namespace std;

class BookType{
	
	string name;
	string* author;
	string publisher;
	int isbnNum;
	int yearPublished;
	double price;
	int numInStock;
	
	public:
	
	void set(string n, string pub, int isbn, int yp, int prc, int nis)
	{
		name = n;
		publisher = pub;
		isbnNum = isbn;
		yearPublished = yp;
		price = prc;
		numInStock = nis;
	}	
	
	void askForAuthor()
	{
		int num;
		while(1)
		{
			cout << "Enter 1 for adding an author and 0 for moving forward : ";
			cin >> num;
			if (num == 1)
			{
				addAuthor();	
			}
			else
			{
				return;
			}
		}
	}
	
	void addAuthor()
	{
		string auth;
		author = new string;
		cout << "Enter the name of author : ";
		cin >> auth;
		setAuthor(auth);
	}
	
	void setAuthor(string auth)
	{
		*author = auth;
	}
	
	void setNumInStock()
	{
		numInStock += 1;
	}
	
	string getName()
	{
		return name;
	}	
	string getAuthor()
	{
		return *author;
	}
	string getPublisher()
	{
		return publisher;
	}
	int getISBN()
	{
		return isbnNum;
	}
	int getYearPublished()
	{
		return yearPublished;
	}
	int getPrice()
	{
		return price;
	}
	int getNumInStocks()
	{
		return numInStock;
	}
	
	void removeAuthor()
	{
		delete author;
	}
	
	~BookType()
	{
		if (author == NULL)
		{
			delete author;
		}
	}
};

int main()
{
	BookType b[100];
	int i,j, k = -1;
	int isbn, yearPublished, NumInStock;
	string name, publName;
	double price;
	
	
	for(i = 0; i < 10; i++)
	{
		cout << "Enter the book " << i+1 << " name : ";
		cin >> name; 
	
		b[i].askForAuthor();
		
		cout << "Enter the book " << i+1 << " publisher's name : ";
		cin >> publName;
	
		cout << "Enter the book " << i+1 << " ISBN Number : ";
		cin >> isbn;
		
		cout << "Enter the book " << i+1 << " Year Of Publishing : ";
		cin >> yearPublished;
		
		cout << "Enter the book " << i+1 << " Price : ";
		cin >> price;
		
		cout << "Enter the book " << i+1 << " Amount in Stock : ";
		cin >> NumInStock;		
	
		b[i].set(name, publName, isbn, yearPublished, price, NumInStock);
	}
	
	cout << "\n\n Information Stored for all 10 books. Now you can add the books in stock.";
	
	for(i = 10; i < 100; i++)
	{
		cout << "Enter the book " << i+1 << " name : ";
		cin >> name; 	
	
		for(j = 0; j < 10; i++ )
		{
			if (name == b[j].getName())
			{
				k = j;
			} 
		}
		
		if (k != -1)
		{
			b[k].setNumInStock();
			NumInStock = b[k].getNumInStocks();
			b[i] = b[k];
		}
		else
		{
			cout << "There is no book with this name in the stock."; 
			i -= 1;
		}
	}
}
