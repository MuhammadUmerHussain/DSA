#include<iostream>

using namespace std;


class Book {
 string Name;
 string ISBN;
 string Author;
 string Publisher;
public:
 Book() {
Name = NULL;
ISBN = NULL;
Author = NULL;
Publisher = NULL;
}

 Book(string name, string isbn, string author, string publisher) {
Name = name;
ISBN = isbn;
Author = author;
Publisher = publisher;
}

void setName(string Name) {
this->Name = Name;
}
 string getName() {
return Name;
}
 void setISBN(string ISBN) {
this->ISBN = ISBN;
}
 string getISBN() {
return ISBN;
}
 void setAuthor(string Author) {
this->Author = Author;
}
 string getAuthor() {
return Author;
}
 void setPublisher(string Publisher) {
this->Publisher = Publisher;
}
 string getPublisher() {
return Publisher;
}

 void getBookInfo() {
cout<<"Name: "<< Name<<"ISBN: "<<ISBN<<"Author: "<<Author<<"Publisher: "<<Publisher<<endl;
}


//filename: SavingsAccountTest.java
// SavingsAccount testing class with the main() method
 class BookTest {
 static void (string[] args) {

Book test[] = new Book[13];
test[1] = new Book();
test[1].getBookInfo();

}
}
