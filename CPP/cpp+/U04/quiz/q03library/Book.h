#ifndef BOOK_H
#define BOOK_H
#include <string>
#include<iostream>


class Book {
private:
  std::string title;
  std::string author;
  double price;
  int stock;

public:
  Book() : title("Unknown"), author("N/A"), price(0.0), stock(0) {}
  Book(const std::string& t,const std::string& a,double p,int s) : title(t),author(a),price(p),stock(s){}
  const std::string &getTitle() const {
    return title;
  };
  const std::string &getAuthor() const {
    return author;
  };
  double getPrice() const {
    return price;
  };
  int getStock() const {
    return stock;
  };

  void setPrice(double p);
  void setStock(int s);
  void printInfo();
};
#endif