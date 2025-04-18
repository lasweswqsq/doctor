#include<iostream>
#include<list>

class Library;

class Book{
    friend class Library;
    private:
        std::string const title;
        std::string const author;
        int const ISBN;
        double const price;
        int status; // 0 for available, 1 for borrowed, 2 for bought
    public:
        Book(std::string const t, std::string const a, int const i, double const p):
            title(t), author(a), ISBN(i), price(p), status(0) {}
};

class Library{
    private:
        std::list <Book> books;
    public:
        void add_book(Book b){
            books.push_back(b);
        }
        void delete_book(int ISBN){
            for(std::list<Book>::iterator it=books.begin();it!=books.end();it++){
                if(it->ISBN==ISBN){
                    books.erase(it);
                    break;
                }
            }
        }
        void buy_book(int ISBN){
            for(std::list<Book>::iterator it=books.begin();it!=books.end();it++){
                if(it->ISBN==ISBN){
                    if(it->status==0){
                        std::cout<<"You have bought the book: "<<it->title<<" by "<<it->author<<" for "<<it->price<<" yuan."<<std::endl;
                        it->status=2;
                        break;
                    }
                    else{
                        std::cout<<"The book is not available for purchase."<<std::endl;
                        break;
                    }
                }
            }
        }
        void borrow_book(int ISBN){
            for(std::list<Book>::iterator it=books.begin();it!=books.end();it++){
                if(it->ISBN==ISBN){
                    if(it->status==0){
                        std::cout<<"You have borrowed the book."<<std::endl;
                        it->status=1;
                        break;
                    }
                    else{
                        std::cout<<"The book isn't available for borrowing."<<std::endl;
                        break;
                    }
                }
            }
        }
        void return_book(int ISBN){
            for(std::list<Book>::iterator it=books.begin();it!=books.end();it++){
                if(it->ISBN==ISBN){
                    if(it->status==1){
                        std::cout<<"You have returned the book successfully."<<std::endl;
                        it->status=0;
                        break;
                    }
                    else{
                        std::cout<<"The book wasn't borrowed by you."<<std::endl;
                        break;
                    }
                }
            }
        }
};
        