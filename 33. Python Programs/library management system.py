class library:
    def __init__(self, list_of_book_names):
        self.books= list_of_book_names

    def display_books_in_library(self):
        print("Books available in this library are: \n")
        for index,books in enumerate(self.books):
            print(index,books)
    
    def want_book(self, student_name,book_name):
        count=0
        for book in self.books:
            if book==book_name:
                print(f"The book {book_name} is issued to {student_name}. Please keep it safe and return within 30 days")
                self.books.remove(book_name)
                count= count+1
            
        if count==0:
            print(f"The book {book_name} is issued to someone else. Please try another book")

    def return_book(self, student_name, book_name):
        print(f"The book {book_name} is returned by {student_name}")
        self.books.append(book_name) 

    


    
a=library(["python", "c++", "java", "cobra", "c"])
a.display_books_in_library()
g=1
while g!=0:
    f=input("press r to return and i to issue: ")
    if f=='i': 
        c=input("Enter the ur name : ")
        b=input("Enter the name of book, which u want from the above list : ")
        a.want_book(c,b)
    if f=='r':
        j=input("Enter the ur name : ")
        k=input("Enter the name of book which u want to return : ")
        a.return_book(j,k)


    f=input("Do you want to further try or want to quit LMS, write q to quit : ")

    if f=='q':
        print("Thanks for visiting LMS, hope u will come again")
        break
    else:
        g==1