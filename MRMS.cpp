#include <iostream>
#include <string>

using namespace std;

class Customer {
public:
    int customerID;
    string name;
    string address;
    string phoneNumber;
    int movieID;

    // Constructors
    Customer() : customerID(0), name(""), address(""), phoneNumber(""){}
    Customer(int id, string name, string address, string phoneNum)
        : customerID(id), name(name), address(address), phoneNumber(phoneNum) {}

    void registerCust() {
        cout << "--------------------CUSTOMER REGISTRATION----------------------" << endl;
        cout << "Enter customer ID: ";
        cin >> customerID;
        cin.ignore();
        cout << "Enter customer name: ";
        getline(cin, name);
        cout << "Enter customer address: ";
        getline(cin, address);
        cout << "Enter customer phone number: ";
        getline(cin, phoneNumber);
        cout << "Customer registered!" << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
    }

    void displayCust() {
        cout << "--------------------CUSTOMER INFO----------------------" << endl;
        cout << "Customer Id: " << customerID << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
    }
};

class Rental {
public:
    int rentalID;
    string rentalDate;
    string returnDate;
    int customerID;

    // Constructors
    Rental() : rentalID(0), rentalDate(""), returnDate(""), customerID(0) {}
    Rental(int rId, string rDate, string retDate, int cID)
        : rentalID(rId), rentalDate(rDate), returnDate(retDate), customerID(cID) {}

    void displayRental() {
        cout << "--------------------RENTAL INFO----------------------" << endl;
        cout << "Rental ID: " << rentalID << endl;
        cout << "Rental Date: " << rentalDate << endl;
        cout << "Return Date: " << returnDate << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
    }
};

class Movie {
public:
    int movieID;
    string title;
    string genre;
    string releaseDate;
    bool isAvailable;

    // Constructors
    Movie() : movieID(0), title(""), genre(""), releaseDate(""), isAvailable(true) {}
    Movie(int id, string title, string genre, string relDate, bool available = true)
        : movieID(id), title(title), genre(genre), releaseDate(relDate), isAvailable(available) {}

    static void displayMovies(const Movie movies[], int movieCount) {
        cout << "--------------------MOVIE LIST----------------------" << endl;
        for (int i = 0; i < movieCount; ++i) {
            cout << "Movie ID: " << movies[i].movieID << endl;
            cout << "Title: " << movies[i].title << endl;
            cout << "Genre: " << movies[i].genre << endl;
            cout << "Release Date: " << movies[i].releaseDate << endl;
            if (movies[i].isAvailable) {
                cout << "Status: Available" << endl;
            } else {
                cout << "Status: Rented" << endl;
            }
        }
        cout << "---------------------------------------------------------------------------------" << endl;
    }

    void updateStatus() {
        if (isAvailable) {
            cout << "Movie: " << title << " is Available" << endl;
        } else {
            cout << "Movie: " << title << " is Rented" << endl;
        }
        cout << "---------------------------------------------------------------------------------" << endl;
    }
};

class Payment {
public:
    int paymentID;
    float amount;
    string paymentDate;
    string method;

    // Constructors
    Payment() : paymentID(0), amount(0.0), paymentDate(""), method("") {}
    Payment(int id, float amount, string pDate, string method)
        : paymentID(id), amount(amount), paymentDate(pDate), method(method) {}

    void displayP() {
        cout << "--------------------PAYMENT INFO----------------------" << endl;
        cout << "Enter payment ID: ";
        cin >> paymentID;
        cout << "Enter payment amount: ";
        cin >> amount;
        cin.ignore();
        cout << "Enter payment date: ";
        getline(cin, paymentDate);
        cout << "Enter payment method: ";
        getline(cin, method);
        cout << "---------------------------------------------------------------------------------" << endl;
    }

    void processPayment() {
        cout << "Processed payment of amount " << amount << " on " << paymentDate << " via " << method << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
    }
};

class Staff {
public:
    int staffID;
    string name;
    string role;
    string contactInfo;

    // Constructors
    Staff() : staffID(0), name(""), role(""), contactInfo("") {}
    Staff(int id, string name, string role, string cInfo)
        : staffID(id), name(name), role(role), contactInfo(cInfo) {}

    void displayS() {
        cout << "--------------------STAFF INFO----------------------" << endl;
        cout << "Staff ID: " << staffID << endl;
        cout << "Name: " << name << endl;
        cout << "Role: " << role << endl;
        cout << "Contact Info: " << contactInfo << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
    }
};


int main() {
    Customer cust1;
    cust1.registerCust();
    cust1.displayCust();

    const int movieCount = 5;
    Movie movieList[movieCount] = {
        {1, "The Shawshank Redemption", "Drama", "1994-09-23", true},
        {2, "The Godfather", "Crime", "1972-03-15", true},
        {3, "The Dark Knight", "Action", "2008-07-18", false},
        {4, "Inception", "Sci-Fi", "2010-07-16", true},
        {5, "Forrest Gump", "Drama", "1994-07-06", true}
    };

    Movie::displayMovies(movieList, movieCount);

    int chosenMovieID;
    cout << "Enter the ID of the movie you want to rent: ";
    cin >> chosenMovieID;

    bool movieFound = false;
    for (int i = 0; i < movieCount; ++i) {
        if (movieList[i].movieID == chosenMovieID && movieList[i].isAvailable) {
            movieList[i].updateStatus(); // Corrected: No arguments needed
            cust1.movieID = chosenMovieID;
            cout << "You have rented \"" << movieList[i].title << "\"" << endl;
            movieFound = true;
            break;
        }
    }

    if (!movieFound) {
        cout << "Movie ID not found or the movie is already rented." << endl;
    }

    Movie::displayMovies(movieList, movieCount);

    Payment payment1;
    payment1.displayP();
    payment1.processPayment();

    Staff staff1(1, "Alice", "Clerk", "alice@example.com");
    staff1.displayS();

    return 0;
}
