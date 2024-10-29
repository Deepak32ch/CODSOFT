#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip> // for fine formatting

// Structure to represent a Book
struct Book {
    std::string title;
    std::string author;
    std::string ISBN;
    bool isAvailable = true;

    Book(const std::string& t, const std::string& a, const std::string& i)
        : title(t), author(a), ISBN(i), isAvailable(true) {}
};

// Structure to represent a Borrower
struct Borrower {
    std::string name;
    int borrowerID;

    Borrower(const std::string& n, int id) : name(n), borrowerID(id) {}
};

// Structure to represent a Transaction (for book checkout and return)
struct Transaction {
    Book* book;
    Borrower* borrower;
    time_t checkoutDate;
    time_t returnDate;

    Transaction(Book* b, Borrower* br, time_t coDate)
        : book(b), borrower(br), checkoutDate(coDate), returnDate(0) {}
};

// Class for Library System to manage books, borrowers, and transactions
class LibrarySystem {
private:
    std::vector<Book> books;
    std::vector<Borrower> borrowers;
    std::vector<Transaction> transactions;

public:
    // Add a book to the library
    void addBook(const std::string& title, const std::string& author, const std::string& ISBN) {
        books.emplace_back(title, author, ISBN);
        std::cout << "📚 Book added: \"" << title << "\" by " << author << " (ISBN: " << ISBN << ")\n";
    }

    // Add a borrower to the library
    void addBorrower(const std::string& name, int borrowerID) {
        borrowers.emplace_back(name, borrowerID);
        std::cout << "👤 Borrower added: " << name << " (ID: " << borrowerID << ")\n";
    }

    // Search for books by title, author, or ISBN
    void searchBooks(const std::string& query) const {
        bool found = false;
        std::cout << "\n🔎 Searching for books matching: \"" << query << "\"\n";
        for (const auto& book : books) {
            if (book.title.find(query) != std::string::npos ||
                book.author.find(query) != std::string::npos ||
                book.ISBN.find(query) != std::string::npos) {
                std::cout << " Title: " << book.title << ", Author: " << book.author
                          << ", ISBN: " << book.ISBN << " - "
                          << (book.isAvailable ? " Available" : " Checked Out") << "\n";
                found = true;
            }
        }
        if (!found) std::cout << " No matching books found.\n";
    }

    // Checkout a book to a borrower
    void checkoutBook(const std::string& ISBN, int borrowerID) {
        Book* book = findBookByISBN(ISBN);
        Borrower* borrower = findBorrowerByID(borrowerID);

        if (!book) {
            std::cout << " Book not found. Please check the ISBN.\n";
            return;
        }
        if (!borrower) {
            std::cout << " Borrower not found. Please check the ID.\n";
            return;
        }
        if (!book->isAvailable) {
            std::cout << " Book is currently checked out.\n";
            return;
        }

        time_t now = time(0);
        transactions.emplace_back(book, borrower, now);
        book->isAvailable = false;
        std::cout << " \"" << book->title << "\" has been checked out to " << borrower->name << ".\n";
    }

    // Return a book and update availability
    void returnBook(const std::string& ISBN, int borrowerID) {
        Book* book = findBookByISBN(ISBN);
        Borrower* borrower = findBorrowerByID(borrowerID);

        if (!book) {
            std::cout << " Book not found.\n";
            return;
        }
        if (!borrower) {
            std::cout << " Borrower not found.\n";
            return;
        }

        for (auto& transaction : transactions) {
            if (transaction.book == book && transaction.borrower == borrower && transaction.returnDate == 0) {
                transaction.returnDate = time(0);
                book->isAvailable = true;
                double fine = calculateFine(transaction.checkoutDate, transaction.returnDate);
                std::cout << " \"" << book->title << "\" has been returned by " << borrower->name
                          << ". Fine: $" << std::fixed << std::setprecision(2) << fine << "\n";
                return;
            }
        }
        std::cout << " No active transaction found for this book and borrower.\n";
    }

private:
    // Find book by ISBN
    Book* findBookByISBN(const std::string& ISBN) {
        for (auto& book : books) {
            if (book.ISBN == ISBN) return &book;
        }
        return nullptr;
    }

    // Find borrower by ID
    Borrower* findBorrowerByID(int borrowerID) {
        for (auto& borrower : borrowers) {
            if (borrower.borrowerID == borrowerID) return &borrower;
        }
        return nullptr;
    }

    // Calculate fine based on overdue days
    double calculateFine(time_t checkoutDate, time_t returnDate) const {
        double finePerDay = 0.50;  // Fine per day in dollars
        int overdueDays = (difftime(returnDate, checkoutDate) / (60 * 60 * 24)) - 14;  // Assuming 2-week loan period
        return overdueDays > 0 ? overdueDays * finePerDay : 0.0;
    }
};

// Function to display the menu
void displayMenu() {
    std::cout << "\n---  Library Management System  ---\n";
    std::cout << "1.  Add Book\n";
    std::cout << "2.  Add Borrower\n";
    std::cout << "3.  Search Book\n";
    std::cout << "4.  Checkout Book\n";
    std::cout << "5.  Return Book\n";
    std::cout << "6.  Exit\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Choose an option (1-6): ";
}

int main() {
    LibrarySystem library;
    int choice;
    std::string title, author, ISBN, name;
    int borrowerID;

    std::cout << " Welcome to the Library Management System!\n";

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter book title: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter book author: ";
                std::getline(std::cin, author);
                std::cout << "Enter book ISBN: ";
                std::getline(std::cin, ISBN);
                library.addBook(title, author, ISBN);
                break;
            case 2:
                std::cout << "Enter borrower name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter borrower ID: ";
                std::cin >> borrowerID;
                library.addBorrower(name, borrowerID);
                break;
            case 3:
                std::cout << "Enter title, author, or ISBN to search: ";
                std::cin.ignore();
                std::getline(std::cin, title);  // Using title as a generic search term
                library.searchBooks(title);
                break;
            case 4:
                std::cout << "Enter book ISBN: ";
                std::cin.ignore();
                std::getline(std::cin, ISBN);
                std::cout << "Enter borrower ID: ";
                std::cin >> borrowerID;
                library.checkoutBook(ISBN, borrowerID);
                break;
            case 5:
                std::cout << "Enter book ISBN: ";
                std::cin.ignore();
                std::getline(std::cin, ISBN);
                std::cout << "Enter borrower ID: ";
                std::cin >> borrowerID;
                library.returnBook(ISBN, borrowerID);
                break;
            case 6:
                std::cout << "Thank you for using the Library Management System! Goodbye! \n";
                return 0;
            default:
                std::cout << " Invalid choice. Please enter a number from 1 to 6.\n";
        }
    }
}
